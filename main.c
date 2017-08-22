#include <stdio.h>
#include <stdlib.h>
#define lung_max 5

typedef int nod;
typedef struct {
    nod elemente[lung_max];
    int ultim;
    int aparitii[lung_max];
}lista;

lista l;

int nre;

typedef void proc;

//Lista vida

int Lista_vida(proc)
{
    if(l.ultim < 0) return 0;
    else return 1;
}

//Afisare Lista

proc Listare(proc)
{
    int i;
    printf("\nLista este : ");
    for(i=0; i<=l.ultim-1; i++) printf("%d ", l.elemente[i]);
    printf("%d\n", l.elemente[l.ultim]);
}

//Inserarea unui element la SFARSITUL LISTEI

proc Inserare(proc)
{
    if(l.ultim >=lung_max-1) printf("Depasire !!!");
    else
    {
        l.ultim=l.ultim+1;
        printf("Introduceti elementul: ");
        scanf("%d",&l.elemente[l.ultim]);
    }
}

//Stergerea unui element al listei

proc Stergere(proc)
{
    if(Lista_vida()==0) printf("Lista este vida ! \n");
    else l.ultim=l.ultim-1;
}

//Inserarea in interiorul tabloului

proc Inserare_int(proc)
{
    int k,i;
    printf("Introduceti pozitia pe care vreti sa inserati un nod: ");
    scanf("%d", &k);
    if(k<0 || k>=lung_max || k>=l.ultim) printf("\nNu se poate insera pe pozitia ceruta\n");
    else{
        l.ultim++;
        for(i=l.ultim; i>k; i--) l.elemente[i]=l.elemente[i-1];
        printf("\nIntroduceti elementul: ");
        fflush(stdin);
        scanf("%d",&l.elemente[k]);
    }
}
proc Stergere_in(proc)
{
    int j,i;
    if(Lista_vida()==0) printf("Subdepasire ! \n");
    else
    {
        printf("Introduceti pozitia la care se va face stergerea :");
        scanf("%d", &j);
        for(i=j; i<l.ultim; i++) l.elemente[i] = l.elemente[i+1];
        l.ultim = l.ultim-1;
    }
}

proc Creare_lista(proc)
{
    char c;
    //Initializarea structurii
    l.ultim= -1;
    //Inserari
    printf("Mai adaugi? (D/N): ");
    fflush(stdin);
    scanf("%c", &c);
    c = toupper(c);
    while(c=='D')
    {
        nre++;
        Inserare();
        printf("Mai adaugi?(D/N): ");
        fflush(stdin);
        scanf("%c",&c);
        c=toupper(c);

    }
}

proc cauta(int k)
{
    int el,i;
    int er = 1;
    for(i=0; i<l.ultim; i++)
        if(l.elemente[i]==k){
            el = l.elemente[i];
            i= l.ultim+1;
            er = 0;
        }
}

proc sortare(proc){
    int i,j,aux;

    for(i=0; i<nre-1; i++){
        for(j=i+1; j<nre; j++){
            if (l.elemente[i]>l.elemente[j]){
                aux = l.elemente[i];
                l.elemente[i] = l.elemente[j];
                l.elemente[j] = aux;
            }
        }
    }

}

proc aparitii(proc){
    int i,j;

    for (i=0; i<nre-1; i++){
        for(j=i+1; j<nre; j++){
            if(l.elemente[i]==l.elemente[j]){
                l.aparitii[i]++;
                l.aparitii[j]++;
            }
        }
    }

    for(i=0; i<nre; i++){
        l.aparitii[i]++;
    }

    for (i=0; i<nre; i++){
        printf("%d a aparut de %d ori \n", l.elemente[i], l.aparitii[i]);
    }
}

int main()
{
    int r;
    do{
    printf("\n0.Creeaza lista \n1.Adaugati un element \n2.Stergeti un element \n3.Adaugati un element la sfarsit \n4.Stergeti un element de la sfarsit \n5.Afisare \n6.Sortare\n7.Numar de aparitii \n8.Iesire");
    printf("\nOptiune: "); scanf("%d",&r);
    switch(r){
        case 0:
            Creare_lista();
            break;
        case 1:
            Inserare_int();
            break;
        case 2:
            Stergere_in();
            break;
        case 3:
            Inserare();
        case 4:
            Stergere();
            break;
        case 5:
            Listare();
            break;
        case 6:
            sortare();
            break;
        case 7:
            aparitii();
            break;
        default:
            printf("\nNu exista optiunea !!!\n");
            break;
    }

    }while(r!=8);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct nod{
    int cheie;
    char info[10];
    struct nod *urm;
};

typedef struct nod Tnod;
typedef Tnod *ref;

ref p, q, r, s;

void ins_p(void)
{
    q = (ref)malloc(sizeof(Tnod));
    printf("Introduceti cheia: ");
    scanf("%d", &q->cheie);
    printf("Introduceti informatia: ");
    fflush(stdin);
    scanf("%s",q->info);
    q->urm = NULL;
    p=q;
}

//Inserarea unui nod in fata
void ins_cf(void)
{
    q = (ref)malloc(sizeof(Tnod));
    printg("Introduceti cheia: ");
    scanf("%d", &q->cheie);
    printf("Introduceti informatia: ");
    fflush(stdin);
    scanf("%s", q->info);
    q->urm=p;
    p = q;
}

//Inserarea unui nod in spate

void ins_cs(void)
{
    s = (ref)malloc(sizeof(Tnod));
    printf("Introduceti cheia :");
    scanf("%d", &s->cheie);
    printf("Introduceti informatia: ");
    scanf("%s", s->info);
    s->urm = NULL;
    q->urm = s;
    q = s;

}

//Inserarea unui nod intr-un loc oarecare

void ins_d(void)
{
    s = (ref)malloc(sizeof(Tnod));
    printf("Introduceti cheia: ");
    scanf("%d" &s->cheie);
    printf("Introcudeti informatia: ");
    fflush(stdin);
    scanf("%s", s->info);
    s->urm = r->urm;
    r->urm = s;
}

void ins_i(void)
{
    s=(ref)malloc(sizeof(Tnod));
    *s = *r;
    r->urm = s;
    printf("Introduceti cheia: ");
    scanf("%d", &r->cheie);
    printf("Introduceti informatia: ");
    fflush(stdin);
    scanf("%s", r->info);

}

void listare(void)
{
    r=p;
    while(r!=NULL){
        printf("Cheia: %d;\tInformatia: %s\n",r->cheie, r->info);
        r=r->urm;
    }
}

void cautare(void){
    int b = 0;
    r = p;
    while((b==0)&&(r!=NULL))
        if(r->cheie == k)
            b=1;
        else r = r->urm;
}

//Stergerea unui element din lista

void sterge_d(void)
{
    int er;
    if(r->urm==NULL){
        printf("Nu avem ce sterge !\n");
        er=1;
    }
    else{
        s=r->urm;
        r->urm = s->urm;
        free(s);
    }
}

//Suprimarea unei liste simplu inlt

void stergere_n(void)
{
    if(r->urm==NULL)
    if(r==p){
        p=NULL;
        free(r);
    }else{
        s=p;
        while(s->urm!=r)
            s=s->urm;
            s->urm = NULL;
            free(r);
    }
    else{
        s=r->urm;
        *r=*s;
        free(s);
    }
}

int main()
{
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTSMSPRIM.h"

#include <malloc.h>


//creation des anciens messages avec liste sms
LISTE_SMS historique_SMS(void){

    char chx[200];
LISTE_SMS x=listeCreer_SMS();
 x->elements[1]=elementCreer_SMS();
 x->lg++;
strcpy (chx,"Bonjouuuuuuuuuuuur <3");
strcpy(x->elements[1]->texte,chx);


x->elements[1]->taille=strlen(chx);
return x;
}

//2
LISTE_SMS historique2_SMS(void){

    char chx[200];
LISTE_SMS x=listeCreer_SMS();
 x->elements[1]=elementCreer_SMS();
 x->lg++;
strcpy (chx,"Bonsoiiiiiiiir <3");
strcpy(x->elements[1]->texte,chx);


x->elements[1]->taille=strlen(chx);
return x;
}
//3
LISTE_SMS historique3_SMS(void){

    char chx[200];
LISTE_SMS x=listeCreer_SMS();
 x->elements[1]=elementCreer_SMS();
 x->lg++;
strcpy (chx,"Sahit continue le bon travail Latifette <3");
strcpy(x->elements[1]->texte,chx);


x->elements[1]->taille=strlen(chx);
return x;
}
//4
LISTE_SMS historique4_SMS(void){

    char chx[200];
LISTE_SMS x=listeCreer_SMS();
 x->elements[1]=elementCreer_SMS();
 x->lg++;
strcpy (chx,"Nchlh idek mabroooook ma chère <3");
strcpy(x->elements[1]->texte,chx);


x->elements[1]->taille=strlen(chx);
return x;
}
//5
LISTE_SMS historique5_SMS(void){

    char chx[200];
LISTE_SMS x=listeCreer_SMS();
 x->elements[1]=elementCreer_SMS();
 x->lg++;
strcpy (chx,"bonjour je suis vraiment désolé mais je ne peux pas venir aujourd’hui mais demain je peux venir ");
strcpy(x->elements[1]->texte,chx);


x->elements[1]->taille=strlen(chx);
return x;
}


LISTE_SMS listeCreer_SMS(void){
LISTE_SMS L;
L=(LISTE_SMS)malloc(sizeof(laStructSMS));
if(!L){
    printf("\nprobeleme de memoire !");
    return 0;
}
L->lg=0;
return L;
}

void listeDetruire_SMS(LISTE_SMS L){
int i;
for(i = 1;i <= L->lg; i++){
    elementDetruire_SMS(L->elements[i]);
}
free(L);
}

int estVide_SMS(LISTE_SMS L){
return (L->lg ==0);
}

int estSaturee_SMS(LISTE_SMS L){
return (L->lg == LongMax);
}

int listeTaille_SMS(LISTE_SMS L){
return(L->lg);
}

ELEMENT_SMS recuperer_SMS(LISTE_SMS L,int pos){

ELEMENT_SMS elt=elementCreer_SMS();
if (estVide_SMS(L)){
    printf("\nListe vide");
}
else {
    if ((pos<1)||(pos> L->lg))
    {
        printf("\n position invalide");
    }
    else{
        elt=(L->elements[pos]);
    }
}
return elt;
}

int inserer_SMS(LISTE_SMS L,ELEMENT_SMS e,int pos){
int i;
int succee=1;

if (estSaturee_SMS(L)){
    printf("nListe saturee");
    succee=0;
}
else {
    if ((pos<1)||(pos> L->lg+1)){
        printf("_nPosition invalide");
        succee=0;
    }
    else {
        for (i=L->lg;i>=pos;i--){
            elementAffecter_SMS(&L->elements[i+1],L->elements[i]);

        }
        elementAffecter_SMS(&L->elements[pos],e);
        (L->lg)++;
    }
}
return succee;
}

int supprimer_SMS(LISTE_SMS L,int pos){
int i;
int succee=1;

if (estVide_SMS(L)){
    printf("\nListe vide");
    succee=0;
}
else{
    if ((pos<1)||(pos> L->lg)){
        printf("\nPostion invalide");
        succee=0;
    }
    else{
        elementDetruire_SMS(L->elements[pos]);
        for(i=pos;i<=L->lg;i++)
        {
            elementAffecter_SMS(&L->elements[i],L->elements[i+1]);
        }
        (L->lg)--;
    }
}
return succee;
}

void listeAfficher_SMS(LISTE_SMS L){
int i;
char  res[2000];
res[2000]='\0';
if((L->lg)>1){

  // printf("%s",L->elements[1]->texte);

 // else{
    for(i=1;i<=L->lg;i++)
  {
      strcpy(res,(strcat(res,L->elements[i]->texte)));

}
printf(" %s ",res);
 }
 else printf("%s",L->elements[1]->texte);
}

LISTE_SMS listeCopier_SMS(LISTE_SMS L){
LISTE_SMS LC =listeCreer_SMS();
int i;
ELEMENT_SMS elt;

for(i=1;i<=L->lg;i++){
    elt=elementCreer_SMS();
    elementCopier_SMS(&elt,recuperer_SMS(L,i));
    inserer_SMS(LC,elt,i);
}
return LC;
}


//Retourne 1 si les listes sont égales et 0 sinon
int listeComparer_SMS(LISTE_SMS L1,LISTE_SMS L2){
int test=1;
int i=1;
if (listeTaille_SMS(L1)!=listeTaille_SMS(L2))
{
    test=0;
}
while((i<=listeTaille_SMS(L1))&&(test)){
    if (elementComparer_SMS(recuperer_SMS(L1,i),recuperer_SMS(L2,i))!=0)
    {
        test=0;
    }
i++;
}
return test;
}


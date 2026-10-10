#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ELTCONPRIM.h"
#include "ELTCONSDD.h"
#include <malloc.h>
#define ELEMENT_CON_VIDE

/*
ELEMENT_CONT infocontact(void)
{
  ELEMENT_CONT e= elementCreer_CONT();
  e->email
  return e;
}
*/
//creation d'un element con
ELEMENT_CONT elementCreer_CONT(void){
ELEMENT_CONT L;
L = (ELEMENT_CONT)malloc(sizeof(CONTACT));
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

return L;
}

void elementDetruire_CONT(ELEMENT_CONT elt){
free(elt);
}


void elementLire_CONT(ELEMENT_CONT* elt) {

char ch[100];
do{
printf("\ndonnez le nom dun conatct: \n");
//gets(ch);
getchar();
gets(ch);
printf("r");
}while (alpha(ch)==0);
strcpy((*elt)->nom,ch);
do{
printf("donnez le numero du conatct: \n");
gets(ch);
}while (numer(ch)==0);
strcpy((*elt)->numero,ch);
do{
printf("donnez l'email du conatct: \n");
gets(ch);
}while (verifemail(ch)==0);
strcpy((*elt)->email,ch);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}



void elementAfficher_CONT (ELEMENT_CONT elt){
printf("Nom: %s \n Numero: %s \n Email: %s \n",elt->nom,elt->numero,elt->email);
}

void elementAffecter_CONT(ELEMENT_CONT* e1,ELEMENT_CONT e2){
*e1=e2;
}

void elementCopier_CONT(ELEMENT_CONT* e1,ELEMENT_CONT e2){
strcpy((*e1)->nom,e2->nom);
strcpy((*e1)->numero,e2->numero);
strcpy((*e1)->email,e2->email);

}

int elementComparer_CONT(ELEMENT_CONT e1, ELEMENT_CONT e2){
return (strcmp(e1->numero,e2->numero));
}



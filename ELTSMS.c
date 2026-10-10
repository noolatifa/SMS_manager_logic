#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ELTSMSPRIM.h"
#include <malloc.h>
#define ELEMENT_SMS_VIDE


//creation d'un element sms
ELEMENT_SMS elementCreer_SMS(void){
ELEMENT_SMS L;
L = (ELEMENT_SMS)malloc(sizeof(SMS));
L->texte=(char*)malloc(161*sizeof(char));
strcpy(L->texte,"\0");
L->taille=0;

return L;
}

void elementDetruire_SMS(ELEMENT_SMS elt){
free(elt);
}


void elementLire_SMS(ELEMENT_SMS* elt) {

printf(" \nDonnez un sms svp :") ;
//fgets((*elt)->texte, 100, stdin);
gets((*elt)->texte);
(*elt)->taille=strlen((*elt)->texte);


//printf(" %s",(*elt)->texte);

}



void elementAfficher_SMS(ELEMENT_SMS elt){
//printf("texte: %s \n taille du texte : %d ",elt->texte);
printf("%s",elt->texte);
}

void elementAffecter_SMS(ELEMENT_SMS* e1,ELEMENT_SMS e2){
*e1=e2;
}

void elementCopier_SMS(ELEMENT_SMS* e1,ELEMENT_SMS e2){
strcpy((*e1)->texte,e2->texte);
(*e1)->taille = e2->taille;

}

int elementComparer_SMS(ELEMENT_SMS e1, ELEMENT_SMS e2){
return ((e1->taille)-(e2->taille));
}







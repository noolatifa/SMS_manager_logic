#include <stdlib.h>
#include <stdio.h>
#include "PILEPRIM.H"

Pile PileCreer(void) {
Pile P;
P = (Pile) malloc(sizeof(laStruct));
if(!P) {

printf(" \nProblème de mémoire") ;

}
else P->Sommet = 0; //puisque l’indice le plus faible est 1
return(P);

}

void PileDetruire(Pile P){
int i;
for(i = 1; i <= P->Sommet; i++)

elementDetruire(P->elements[i]);

free(P);
}

void PileAfficher(Pile P) {
int i;
for(i = P->Sommet; i >= 1; i--)

elementAfficher(P->elements[i]);

}


int EstVide(Pile P) {
return (P->Sommet == 0);
}

int EstSaturee(Pile P) {
return (P->Sommet == LongMax);
}

int PileTaille(Pile P) {
return (P->Sommet);
}

int Empiler (Pile P, ELEMENT e) {
int succes=1;

if (EstSaturee(P)){

printf ("\n Pile saturée");
succes=0;}

else
{
(P->Sommet)++;
elementAffecter(&P->elements[P->Sommet], e);

}
return(succes);
}

ELEMENT Depiler (Pile P ) {
ELEMENT elt = elementCreer();
if (EstVide(P)) {

printf ("\n Pile vide");
}

else {

elementCopier(&elt, (P->elements)[P->Sommet]);
elementDetruire(P->elements[P->Sommet]);
(P->Sommet)--;
}
return (elt);
}

ELEMENT Sommet (Pile P) {

ELEMENT elt= elementCreer();
if (EstVide(P))

printf (" \n Pile vide");

else

elt = (P->elements[P->Sommet]);

return(elt);
}


/////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTCONPRIM.h"
#include "LSTMSGPRIM.h"
#include "LSTMSGSDD.h"

#include <malloc.h>
//liste repertoire
LISTE_CONT repertoire_CONT(void)
{
 LISTE_CONT L=listeCreer_CONT();

 //insertion des contacts
ELEMENT_CONT e=elementCreer_CONT();
strcpy(e->email,"latifanoomen16@gmail.com");
strcpy(e->nom,"Latifa");
strcpy(e->numero,"26831301");
inserer_CONT(L,e,1);
//elementDetruire_CONT(e);

ELEMENT_CONT e1=elementCreer_CONT();
strcpy(e1->email,"yassinebarguellil22@gmail.com");
strcpy(e1->nom,"Yassine");
strcpy(e1->numero,"21298410");
inserer_CONT(L,e1,2);

ELEMENT_CONT e2=elementCreer_CONT();
strcpy(e2->email,"aouissauoisaadia@gmail.com");
strcpy(e2->nom,"Mamie");
strcpy(e2->numero,"94413832");
inserer_CONT(L,e2,3);

ELEMENT_CONT e3=elementCreer_CONT();
strcpy(e3->email,"rimmekni02@gmail.com");
strcpy(e3->nom,"rim");
strcpy(e3->numero,"20502308");
inserer_CONT(L,e3,4);

ELEMENT_CONT e4=elementCreer_CONT();
strcpy(e4->email,"rideneghada10@gmail.com");
strcpy(e4->nom,"Ghada");
strcpy(e4->numero,"95360147");
inserer_CONT(L,e4,5);

ELEMENT_CONT e5=elementCreer_CONT();
strcpy(e5->email,"nawresnoomen1999@gmail.com");
strcpy(e5->nom,"nawres");
strcpy(e5->numero,"98931608");
inserer_CONT(L,e5,6);


ELEMENT_CONT e6=elementCreer_CONT();
strcpy(e6->email,"noomenfarhat@gmail.com");
strcpy(e6->nom,"papa");
strcpy(e6->numero,"94000164");
inserer_CONT(L,e6,7);

ELEMENT_CONT e7=elementCreer_CONT();
strcpy(e7->email,"hanenjeday71@gmail.com");
strcpy(e7->nom,"Mamma");
strcpy(e7->numero,"58328549");
inserer_CONT(L,e7,8);


return L;
}



NOEUD_CONT noeudCreer_CONT(ELEMENT_CONT e)
 {
     NOEUD_CONT n;

n =(NOEUD_CONT)malloc(sizeof(structNoeudCONT));
if(!n)
printf ("\nPlus d'espace");
else
{
elementAffecter_CONT(&n->info, e);
n->suivant = NULL;

}
return n;
 }


void noeudDetruire_CONT(NOEUD_CONT n){
elementDetruire_CONT(n->info);
free(n);
}

int estVide_CONT(LISTE_CONT L)
{
    return(L->lg==0);
}

int estSaturee_CONT(LISTE_CONT L)
{
    NOEUD_CONT temp;
int saturee = 1; /* on suppose mémoire saturée */
temp = (NOEUD_CONT) malloc ( sizeof ( structNoeudCONT ) );
if(temp != NULL) {
saturee = 0; /* mémoire non saturée */
free(temp);
}
return saturee;
}

int listeTaille_CONT(LISTE_CONT L)
{
    return(L->lg);
}

int inserer_CONT(LISTE_CONT L,ELEMENT_CONT e,int pos)
{
int succee=1;
int i;
NOEUD_CONT n, p, q; // c des pointeurs sur noeud c equivalent à:

// structNoeud * n

if (estSaturee_CONT(L)){

printf ("\nListe message saturée");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;

}
else {

n=noeudCreer_CONT(e);

/*on est sûr que la réservation va se faire car la mémoire
n'est pas saturée*/

if (pos == 1) /*insertion en tête de liste*/

{
n->suivant=L->tete;
L->tete = n;
}
else /*cas général (pos > 1) */

{
q= L->tete;
for (i=1; i<pos; i++) {

p = q;
q = q->suivant;

}

// q désigne l’élément de rang pos et p son prédécesseur

p->suivant=n;
n->suivant=q;
}
(L->lg)++;
}

}
return succee;
}

int supprimer_CONT(LISTE_CONT L,int pos)
{
    int i;
int succee=1;
NOEUD_CONT p, q;
if (estVide_CONT(L)) {

printf ("\nListe message vide");
succee=0;
}
else {

if ((pos < 1) || (pos > L->lg))

{
printf ("\nPosition invalide");
succee=0;
}

else
{
q = L->tete;
/*suppression en tête de liste*/
if (pos == 1)
L->tete=L->tete->suivant;

else { /*cas général (pos > 1) */
for (i=1; i<pos; i++) {
p = q;
q = q->suivant;
}
p->suivant=q->suivant;
}
// q désigne l’élément de rang pos et p son prédécesseur
noeudDetruire_CONT(q);
(L->lg)--;

}
}
return succee;
}

ELEMENT_CONT recuperer_CONT(LISTE_CONT L,int pos)
{
    /* s'il ya une erreur on affiche un message et on
retourne un element vide */
ELEMENT_CONT elt= elementCreer_CONT();
int i;
NOEUD_CONT p;
if (estVide_CONT(L))
printf ("\nListe vide");
else {
if ((pos < 1) || (pos > L->lg))
printf ("\nPosition invalide");

else {

p= L->tete;
for (i=1; i<pos; i++)
p = p->suivant;

elementAffecter_CONT(&elt,p->info);
}

}
return(elt);
}

LISTE_CONT listeCreer_CONT(void)
{
    LISTE_CONT L;
L=(LISTE_CONT)malloc(sizeof(laStructCONT));
if (! L)
printf("\nProblème de mémoire");
else {
L->lg = 0;
L->tete = NULL; /* initialiser la tête */
}
return(L);
}

void listeDetruire_CONT(LISTE_CONT L)
{
    int i;
NOEUD_CONT p, q;
q= L->tete;
for(i = 1;i <= L->lg; i++)
{
p=q;
q=q->suivant;
noeudDetruire_CONT(p);
}
free(L);
}

void listeAfficher_CONT(LISTE_CONT L)
{
    int i=1;
NOEUD_CONT p;
p= L->tete;

for(i = 1;i <= L->lg; i++) {
elementAfficher_CONT(p->info);
p= p->suivant;
}
}

LISTE_CONT listeCopier_CONT(LISTE_CONT L)
{
  LISTE_CONT LR = listeCreer_CONT();
int i;
ELEMENT_CONT elt;
for(i = 1;i <= L->lg; i++) {
elt=elementCreer_CONT();
elementCopier_CONT(&elt, recuperer_CONT(L,i));
inserer_CONT(LR,elt, i);
}
return LR;
}

int listeComparer_CONT(LISTE_CONT L1,LISTE_CONT L2)
{
    int test= 1;
int i=1;
if (listeTaille_CONT (L1) != listeTaille_CONT(L2)) test= 0;
while ((i<=listeTaille_CONT(L1)) && (test)) {
if
(elementComparer_CONT(recuperer_CONT(L1,i),recuperer_CONT(L2,i))!=0)
test=0;
i++;
}
return test;
}


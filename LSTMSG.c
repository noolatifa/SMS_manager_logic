

//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTSMSPRIM.h"
#include "LSTMSGPRIM.h"
#include "LSTMSGSDD.h"

#include <malloc.h>

LISTE_MSG historique_msg(void)
{
    LISTE_MSG L=listeCreer_MSG();


    ELEMENT_MSG e=elementCreer_MSG();

    e->msg=historique_SMS();
    e->date_envoi.annee=2002;
    e->date_envoi.jour=16;
    e->date_envoi.mois=8;
    e->heure_envoi.heure=1;
    e->heure_envoi.minute=20;
    e->heure_envoi.seconde=37;
    e->prix=2.5;
    strcpy(e->recepteur,"26831301");
    inserer_MSG(L,e,1);



    ELEMENT_MSG e1=elementCreer_MSG();
    e1->msg=historique2_SMS();
    e1->date_envoi.annee=2022;
    e1->date_envoi.jour=16;
    e1->date_envoi.mois=8;
    e1->heure_envoi.heure=1;
    e1->heure_envoi.minute=20;
    e1->heure_envoi.seconde=37;
    e1->prix=2.5;
    strcpy(e1->recepteur,"98931608");
    inserer_MSG(L,e1,2);

    ELEMENT_MSG e2=elementCreer_MSG();
    e2->msg=historique3_SMS();
    e2->date_envoi.annee=2002;
    e2->date_envoi.jour=16;
    e2->date_envoi.mois=8;
    e2->heure_envoi.heure=1;
    e2->heure_envoi.minute=20;
    e2->heure_envoi.seconde=37;
    e2->prix=2.5;
    strcpy(e2->recepteur,"26831301");
    inserer_MSG(L,e2,3);

    ELEMENT_MSG e3=elementCreer_MSG();
    e3->msg=historique4_SMS();
    e3->date_envoi.annee=2014;
    e3->date_envoi.jour=16;
    e3->date_envoi.mois=8;
    e3->heure_envoi.heure=1;
    e3->heure_envoi.minute=20;
    e3->heure_envoi.seconde=37;
    e3->prix=2.5;
    strcpy(e3->recepteur,"94000164");
    inserer_MSG(L,e3,4);

    ELEMENT_MSG e4=elementCreer_MSG();
    e4->msg=historique5_SMS();
    e4->date_envoi.annee=2016;
    e4->date_envoi.jour=16;
    e4->date_envoi.mois=8;
    e4->heure_envoi.heure=1;
    e4->heure_envoi.minute=20;
    e4->heure_envoi.seconde=37;
    e4->prix=0.5;
    strcpy(e4->recepteur,"26831301");
    inserer_MSG(L,e4,5);


    return L;
}

NOEUD_MSG noeudCreer_MSG(ELEMENT_MSG e)
 {
     NOEUD_MSG n;

n =(NOEUD_MSG)malloc(sizeof(structNoeudMSG));
if(!n)
printf ("\nPlus d'espace");
else
{
elementAffecter_MSG(&n->info_MSG, e);
n->suivant_MSG = NULL;
n->precedent_MSG =NULL;
}
return n;
 }


void noeudDetruire_MSG(NOEUD_MSG n){
elementDetruire_MSG(n->info_MSG);
free(n);
}

int estVide_MSG(LISTE_MSG L)
{
    return(L->lg_MSG==0);
}

int estSaturee_MSG(LISTE_MSG L)
{
    NOEUD_MSG temp;
int saturee = 1;
temp = (NOEUD_MSG) malloc ( sizeof ( structNoeudMSG ) );
if(temp != NULL) {
saturee = 0; /* mémoire non saturée */

free(temp);
}
return saturee;
}

int listeTaille_MSG(LISTE_MSG L)
{
    return(L->lg_MSG);
}

int inserer_MSG(LISTE_MSG L,ELEMENT_MSG e,int pos)
{
NOEUD_MSG n, p, q;
int succee,i;/* c’est des pointeurs sur des neouds c’est
équivalent à: structNoeud * n */
if (estSaturee_MSG(L))
{
printf ("\nListe message saturée");
succee=0;}
else{
if ((pos < 1) || (pos > L->lg_MSG +1))
{
printf ("\nPosition invalide nnnn");
succee=0;
}
else
{
n=noeudCreer_MSG (e); /*on est sûr que la
réservation va se faire car la mémoire n'est pas saturée*/


if (L->lg_MSG== 0) /* la liste est vide */
{
L->tete_MSG = n;
L->queue_MSG= n;
}
else
{
if (pos == 1) /*insertion en tête de liste*/
{
L->tete_MSG->precedent_MSG = n;
n->suivant_MSG=L->tete_MSG;
L->tete_MSG = n;
}
else
{
if (pos == (L->lg_MSG+1)) /* ajout à la fin */
{
L->queue_MSG->suivant_MSG = n;
n->precedent_MSG = L->queue_MSG;
L->queue_MSG = n;
}
else
{
q= L->tete_MSG;
for (i=1; i<pos; i++)
{
p = q;
q = q->suivant_MSG;
}
/* q désigne l’élément de rang pos et p son prédécesseur*/
p->suivant_MSG=n;
n->precedent_MSG =p;
n->suivant_MSG=q;
q->precedent_MSG =n;
}
}
}


(L->lg_MSG)++;
}
//(L->lg_MSG)++;
}

return succee;
}


int supprimer_MSG(LISTE_MSG L,int pos)
{
    int i;
int succee=1;
NOEUD_MSG p, q;
if (estVide_MSG(L)) {

printf ("\nListe message vide");
succee=0;
}
else {

if ((pos < 1) || (pos > L->lg_MSG))

{
printf ("\nPosition invalide");
succee=0;
}
else
{
if (L->lg_MSG ==1) /* un seul element donc pos == 1*/
{
q=L->tete_MSG;
L->tete_MSG = NULL;
L->queue_MSG = NULL;
}
    else
{
if (pos == 1) /*suppression en tête de liste*/
{
q=L->tete_MSG;
L->tete_MSG=L->tete_MSG->suivant_MSG;
L->tete_MSG->precedent_MSG = NULL;
}
else
{
if (pos == L->lg_MSG)
{
q=L->queue_MSG;
L->queue_MSG = L->queue_MSG->precedent_MSG;
L->queue_MSG->suivant_MSG= NULL;
}
else
{
q= L->tete_MSG;
for (i=1; i<pos; i++)
{ p = q; q = q->suivant_MSG; }

q->suivant_MSG->precedent_MSG = p;
p->suivant_MSG=q->suivant_MSG;
}
}
}
noeudDetruire_MSG(q);
(L->lg_MSG)--;
}
}
return succee;
}



ELEMENT_MSG recuperer_MSG(LISTE_MSG L,int pos)
{

ELEMENT_MSG elt= elementCreer_MSG();
int i;
NOEUD_MSG p;
if (estVide_MSG(L))
printf ("\nListe vide");
else {
if ((pos < 1) || (pos > L->lg_MSG))
printf ("\nPosition invalide");

else {

p= L->tete_MSG;
for (i=1; i<pos; i++)
p = p->suivant_MSG;

elementAffecter_MSG(&elt,p->info_MSG);
}

}
return(elt);
}

LISTE_MSG listeCreer_MSG(void)
{
    LISTE_MSG L;
L=(LISTE_MSG)malloc(sizeof(laStructMSG));
if (! L)
printf("\nProblème de mémoire");
else {
L->lg_MSG = 0;
L->tete_MSG = NULL;
return(L);
}
}
void listeDetruire_MSG(LISTE_MSG L)
{
    int i;
NOEUD_MSG p, q;
q= L->tete_MSG;
for(i = 1;i <= L->lg_MSG; i++)
{
p=q;
q=q->suivant_MSG;
noeudDetruire_MSG(p);
}
free(L);
}

void listeAfficher_MSG(LISTE_MSG L)
{
    int i=1;
NOEUD_MSG p;
p= L->tete_MSG;

for(i = 1;i < L->lg_MSG; i++) {
elementAfficher_MSG(p->info_MSG);
p= p->suivant_MSG;
}
}

LISTE_MSG listeCopier_MSG(LISTE_MSG L)
{
  LISTE_MSG LR = listeCreer_MSG();
int i;
ELEMENT_MSG elt;
for(i = 1;i <= L->lg_MSG; i++) {
elt=elementCreer_MSG();
elementCopier_MSG(&elt, recuperer_MSG(L,i));
inserer_MSG(LR,elt, i);
}
return LR;

}


int listeComparer_MSG(LISTE_MSG L1,LISTE_MSG L2)
{
    int test= 1;
int i=1;
if (listeTaille_MSG(L1) != listeTaille_MSG(L2)) test= 0;
while ((i<=listeTaille_MSG(L1)) && (test)) {
if
(elementComparer_MSG(recuperer_MSG(L1,i),recuperer_MSG(L2,i))!=0)
test=0;
i++;
}
return test;

}




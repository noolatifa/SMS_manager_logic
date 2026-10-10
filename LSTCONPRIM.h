#ifndef LSTCONPRIM_H_INCLUDED
#define LSTCONPRIM_H_INCLUDED
#include "LSTCONSDD.h"
NOEUD_CONT noeudCreer_CONT(ELEMENT_CONT) ;

LISTE_CONT repertoire_CONT(void);

void noeudDetruire_CONT(NOEUD_CONT);

int estVide_CONT(LISTE_CONT);

int estSaturee_CONT(LISTE_CONT);

int listeTaille_CONT(LISTE_CONT);

int inserer_CONT(LISTE_CONT,ELEMENT_CONT,int);

int supprimer_CONT(LISTE_CONT,int);

ELEMENT_CONT recuperer_CONT(LISTE_CONT,int);

LISTE_CONT listeCreer_CONT(void);

void listeDetruire_CONT(LISTE_CONT);

void listeAfficher_CONT(LISTE_CONT);

LISTE_CONT listeCopier_CONT(LISTE_CONT);

int listeComparer_CONT(LISTE_CONT,LISTE_CONT);

#endif // LSTCONPRIM_H_INCLUDED

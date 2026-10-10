#ifndef LSTMSGPRIM_H_INCLUDED
#define LSTMSGPRIM_H_INCLUDED
#include "ELTMSGPRIM.h"
#include "LSTMSGSDD.h"
#include "LSTSMSSDD.h"
#include "LSTCONSDD.h"

LISTE_MSG historique_msg();

NOEUD_MSG noeudCreer_MSG(ELEMENT_MSG) ;

void noeudDetruire_MSG(NOEUD_MSG);

int estVide_MSG(LISTE_MSG);

int estSaturee_MSG(LISTE_MSG);

int listeTaille_MSG(LISTE_MSG);

int inserer_MSG(LISTE_MSG,ELEMENT_MSG,int);

int supprimer_MSG(LISTE_MSG,int);

ELEMENT_MSG recuperer_MSG(LISTE_MSG,int);

LISTE_MSG listeCreer_MSG(void);

void listeDetruire_MSG(LISTE_MSG);

void listeAfficher_MSG(LISTE_MSG);

LISTE_MSG listeCopier_MSG(LISTE_MSG);

int listeComparer_MSG(LISTE_MSG,LISTE_MSG);




#endif // LSTMSGPRIM_H_INCLUDED

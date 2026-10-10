#ifndef LSTMSG_H_INCLUDED
#define LSTMSG_H_INCLUDED
#include "ELTMSGPRIM.h"

typedef struct structNoeudMSG{
ELEMENT_MSG info_MSG;
struct structNoeudMSG *suivant_MSG;
struct structNoeudMSG *precedent_MSG;

}structNoeudMSG, *NOEUD_MSG;

typedef struct
{
    NOEUD_MSG tete_MSG;
    NOEUD_MSG queue_MSG ;
    int lg_MSG;
}laStructMSG,*LISTE_MSG;




#endif // LSTMSG_H_INCLUDED

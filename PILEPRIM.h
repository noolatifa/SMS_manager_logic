#ifndef PILEPRIM_H_INCLUDED
#define PILEPRIM_H_INCLUDED


#include "ELTPRIM.H"
#include "PILESDD.H"
Pile PileCreer(void);
void PileDetruire(Pile);
int EstVide(Pile);
int EstSaturee(Pile);
int PileTaille(Pile);
ELEMENT Sommet(Pile);
int Empiler(Pile, ELEMENT);
ELEMENT Depiler(Pile);
void PileAfficher(Pile);
Pile PileCopier(Pile);
int PileComparer(Pile, Pile);

#endif // PILEPRIM_H_INCLUDED

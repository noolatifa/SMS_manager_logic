#ifndef ELTCONPRIM_H_INCLUDED
#define ELTCONPRIM_H_INCLUDED

#include "ELTCONSDD.h"
ELEMENT_CONT infocontact(void);

void elementLire_CONT(ELEMENT_CONT* );

void elementAfficher_CONT(ELEMENT_CONT);

void elementAffecter_CONT(ELEMENT_CONT*, ELEMENT_CONT);

void elementCopier_CONT(ELEMENT_CONT*, ELEMENT_CONT);

int elementComparer_CONT(ELEMENT_CONT , ELEMENT_CONT);

ELEMENT_CONT elementCreer_CONT(void);

void elementDetruire_CONT(ELEMENT_CONT);

#endif // ELTCONPRIM_H_INCLUDED

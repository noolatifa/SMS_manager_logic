#ifndef ELTMSGPRIM_H_INCLUDED
#define ELTMSGPRIM_H_INCLUDED

#include "ELTMSGSDD.h"

void elementLire_MSG(ELEMENT_MSG* );

void elementAfficher_MSG(ELEMENT_MSG);

void elementAffecter_MSG(ELEMENT_MSG*, ELEMENT_MSG);

void elementCopier_MSG(ELEMENT_MSG*, ELEMENT_MSG);

int elementComparer_MSG(ELEMENT_MSG , ELEMENT_MSG);

ELEMENT_MSG elementCreer_MSG(void);

void elementDetruire_MSG(ELEMENT_MSG);

#endif // ELTMSGPRIM_H_INCLUDED

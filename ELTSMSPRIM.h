#ifndef ELTSMSPRIM_H_
#define ELTSMSPRIM_H_
//sddddd
#include "ELTSMSSDD.h"

void elementLire_SMS(ELEMENT_SMS* );

void elementAfficher_SMS(ELEMENT_SMS);

void elementAffecter_SMS(ELEMENT_SMS*, ELEMENT_SMS);

void elementCopier_SMS(ELEMENT_SMS*, ELEMENT_SMS);

int elementComparer_SMS(ELEMENT_SMS , ELEMENT_SMS);

ELEMENT_SMS elementCreer_SMS(void);

void elementDetruire_SMS(ELEMENT_SMS);

#endif // ELTSMSPRIM_H_

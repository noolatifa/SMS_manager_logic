#include <stdio.h>
#include "ELTPRIM.H"
//#define ELEMENT_VIDE 32767

ELEMENT elementCreer (void) {
    ELEMENT e;
e = (ELEMENT)malloc(sizeof(el));}

void elementDetruire (ELEMENT elt) {

}

void elementAffecter(ELEMENT * e1, ELEMENT e2) {

*e1 = e2 ;}

void elementCopier(ELEMENT * e1, ELEMENT e2) {

*e1 = e2 ;}



void elementAfficher(ELEMENT elt) {
printf(" %s ",elt);
}

int elementComparer(ELEMENT e1, ELEMENT e2)
{
return strcmp(e1-e2);
}


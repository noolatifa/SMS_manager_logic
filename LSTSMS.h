#ifndef LSTSMS_H_
#define LSTSMS_H_

#include "ELTSMSPRIM.H"
#define LongMax 8 /* longueur maximale d'une liste de SMS */
typedef struct
{
ELEMENT_SMS elements[LongMax]; /* tableau statique */
int lg; /* taille logique de la liste */
}
laStructSMS,*LISTE_SMS;

#endif // LSTSMS_H_

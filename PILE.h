#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#define LongMax 100 /* longueur maximale d'une pile */
typedef struct {
ELEMENT elements[LongMax]; /* tableau automatique */
int Sommet; /* indice du Sommet de la Pile */
} laStruct,*Pile;

#endif // PILE_H_INCLUDED

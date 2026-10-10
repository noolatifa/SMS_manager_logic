#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ELTMSGPRIM.h"
#include "ELTSMSPRIM.h"
#include "ELTCON.h"
#include "LSTSMS.h"
#include "LSTSMSSDD.h"
#include "ELTSMSSDD.h"
#include <malloc.h>
#define ELEMENT_MSG_VIDE
#include <time.h>


//creation d'un element msg
ELEMENT_MSG elementCreer_MSG(void){
ELEMENT_MSG L;
L = (ELEMENT_MSG)malloc(sizeof(MESSAGE));

return L;
}

void elementDetruire_MSG(ELEMENT_MSG elt){
free(elt);
}


void elementLire_MSG(ELEMENT_MSG * elt) {
char  ch[1000],chtemp[1000];
int tmsg,i,j,lm,k,nouvtmsg,fois,posc,test,a=0;
float lml;
//time
int h, min, s, day, mois, an;
  time_t now;

  // Renvoie l'heure actuelle
  time(&now);
  // Convertir au format heure locale
 // printf("Aujourd'hui est : %s", ctime(&now));
  struct tm *local = localtime(&now);
  /*h = local->tm_hour;
  min = local->tm_min;
  s = local->tm_sec;
  day = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;
*/

ELEMENT_CONT elem=elementCreer_CONT();
elementLire_CONT(&elem);
elementAfficher_CONT(elem);

do{
printf("taper votre message: \n");
gets(ch);
}while (strlen(ch)>=1224);
tmsg=strlen(ch);
//1er cas

if((tmsg<=160)&&(carspeciaux(ch))==0){

(*elt)->msg=listeCreer_SMS();
(*elt)->msg->elements[1]=elementCreer_SMS();


strcpy(((*elt)->msg->elements[1]->texte),ch);
//printf("%s",(*elt)->msg->elements[1]->texte);
(*elt)->msg->elements[1]->taille=strlen(ch);//taille de whaque chat =1 //cas car non sepec

printf("\n");
//(*elt)->msg->lg=160;

(*elt)->date_envoi.annee=local->tm_year+1900;

(*elt)->date_envoi.jour=local->tm_mday;

(*elt)->date_envoi.mois=local->tm_mon+1;

(*elt)->prix=0.5;

strcpy((*elt)->recepteur,elem->numero);

(*elt)->heure_envoi.heure= local->tm_hour;

(*elt)->heure_envoi.minute=local->tm_min;

(*elt)->heure_envoi.seconde=local->tm_sec;
}

//2eme cas

else if((tmsg<=70)&&(carspeciaux(ch))==1){

(*elt)->msg=listeCreer_SMS();
(*elt)->msg->elements[1]=elementCreer_SMS();
i=0;
//searching for ç

while(i<strlen(ch)){
 if (ch[i]=='ç')
  {
     ch[i]='Ç';
  }
  i++;
}
k=-1;

strcpy(((*elt)->msg->elements[1]->texte),ch);

//printf("%s",(*elt)->msg->elements[1]->texte);
(*elt)->msg->elements[1]->taille=taillechspeciale(ch);//taille de whaque chat =1 //cas car non sepec

printf("\n");
//(*elt)->msg->lg=160;

(*elt)->date_envoi.annee=local->tm_year+1900;

(*elt)->date_envoi.jour=local->tm_mday;

(*elt)->date_envoi.mois=local->tm_mon+1;

(*elt)->prix=0.5;

strcpy((*elt)->recepteur,elem->numero);

(*elt)->heure_envoi.heure= local->tm_hour;

(*elt)->heure_envoi.minute=local->tm_min;

(*elt)->heure_envoi.seconde=local->tm_sec;
}
//3eme cas

else if ((tmsg>160)&&(carspeciaux(ch))==0)
{
    i=0;
    j=1;
    (*elt)->msg=listeCreer_SMS();
    //lml=ceil(tmsg/5);
   // printf("\nceil %f: ",lml);
    if ((tmsg%153)!=0){a=1;}
    (*elt)->msg->lg=(tmsg/153)+a;
lm=(*elt)->msg->lg;


for(j=1;j<=(lm);j++){
(*elt)->msg->elements[j]=elementCreer_SMS();
}
lm=(*elt)->msg->lg;
printf("\ntaille liste sms : %d\n",lm);

j=1;
i=0;

while(j<=lm){
    k=-1;
    fois=0;
    while((tmsg>=0)&&(fois<153))
    {
     (*elt)->msg->elements[j]->texte[k+1]=ch[i];
     (*elt)->msg->elements[j]->texte[153]='\0';
     (*elt)->msg->elements[j]->taille=fois+1;
     fois++;
     tmsg--;
     i++;
     k++;

    }
  //  printf("%d tmsg \n",tmsg);
     j++;
  //   printf("%d commpttt:  ",j);
fois=0;
}

    printf("\n");
//(*elt)->msg->lg=160;

(*elt)->date_envoi.annee=local->tm_year+1900;

(*elt)->date_envoi.jour=local->tm_mday;

(*elt)->date_envoi.mois=local->tm_mon+1;

(*elt)->prix=0.5*((*elt)->msg->lg);

strcpy((*elt)->recepteur,elem->numero);

(*elt)->heure_envoi.heure= local->tm_hour;

(*elt)->heure_envoi.minute=local->tm_min;

(*elt)->heure_envoi.seconde=local->tm_sec;
}

//4eme cas

else if((tmsg>70)&&(carspeciaux(ch))==1)
{
    i=0;
    j=1;
    (*elt)->msg=listeCreer_SMS();
    lml=ceil(tmsg/67);
   // printf("\nceil %f: ",lml);
    (*elt)->msg->lg=tmsg/67;
lm=tmsg/67;


for(j=1;j<=(lm);j++){
(*elt)->msg->elements[j]=elementCreer_SMS();
}
lm=(*elt)->msg->lg;
//printf("taille liste sms : %d",lm);
//printf("taille liste sms max: %d",LongMax);
j=1;
i=0;

while(j<=lm){
    k=-1;
    fois=0;
    while((tmsg>0)&&(fois<67))
    {
     (*elt)->msg->elements[j]->texte[k+1]=ch[i];
     (*elt)->msg->elements[j]->texte[67]='\0';


//printf("%s",(*elt)->msg->elements[1]->texte);
(*elt)->msg->elements[j]->taille=taillechspeciale(ch);
     (*elt)->msg->elements[j]->taille=fois+1;
     fois++;
     tmsg--;
     i++;
     k++;

    }
  //  printf("%d tmsg \n",tmsg);
     j++;
  //   printf("%d commpttt:  ",j);
fois=0;
}

    printf("\n");
//(*elt)->msg->lg=160;

(*elt)->date_envoi.annee=local->tm_year+1900;

(*elt)->date_envoi.jour=local->tm_mday;

(*elt)->date_envoi.mois=local->tm_mon+1;

(*elt)->prix=0.5*((*elt)->msg->lg);

strcpy((*elt)->recepteur,elem->numero);

(*elt)->heure_envoi.heure= local->tm_hour;

(*elt)->heure_envoi.minute=local->tm_min;

(*elt)->heure_envoi.seconde=local->tm_sec;
}



//}}//}}

}


void elementAfficher_MSG(ELEMENT_MSG elt){
printf("\nrecepteur: %s \n prix : %f \n date envoi: %d-%d-%d \n heure d'envoi:%02d:%02d:%02d   ",elt->recepteur,elt->prix,elt->date_envoi.jour,elt->date_envoi.mois,elt->date_envoi.annee,elt->heure_envoi.heure,elt->heure_envoi.minute,elt->heure_envoi.seconde);

printf("\n votre message:est ");
listeAfficher_SMS(elt->msg);
}

void elementAffecter_MSG(ELEMENT_MSG* e1,ELEMENT_MSG e2){
*e1=e2;
}

void elementCopier_MSG(ELEMENT_MSG * e1,ELEMENT_MSG e2){
    LISTE_SMS laux=listeCreer_SMS();
   (*e1)->msg= listeCopier_SMS(e2->msg);
    /*
strcpy((*e1)->texte,e2->texte);
(*e1)->taille = e2->taille;
*/
}

int elementComparer_MSG(ELEMENT_MSG e1, ELEMENT_MSG e2){
return 1; //((e1->taille)-(e2->taille));
}





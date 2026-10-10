#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ELTSMSSDD.h"
#include "LSTSMSSDD.h"
#include "LSTMSGSDD.h"
#include "ELTMSGSDD.h"
#include"ELTCONSDD.h"
#include "LSTCONSDD.h"
#include "LSTMSGPRIM.h"
#include "PILEPRIM.h"
#include "ELTSDD.h"
char chrglob[8000];


Pile unigrammes(LISTE_MSG LMH,int m)
{
    int i=0,j,pos=0,taillech,n=0;
char ch[8000],temp[300],ta[30][3000],tab[30][3000];
 int t1[1000];
   char t[30][1000];
   int k=0,nt,x,fois,max,posmax,occ=1;

strcpy(ch,chrglob);
taillech=strlen(ch);

while((pos<taillech))
{
    k=0;
    while(ch[pos]!=' ' )
    {
       temp[k]=ch[pos];
        pos++;
        k++;
    }
    temp[k]='\0';
   // printf("\n pos %i \n",pos);
   // printf("\n tch %i \n",taillech);
    //printf("%s ",temp);
    strcpy(t[i],temp);
    pos++;
    i++;
    n++;//n --> taille du tableau des unigrammes
}
/*printf("\n");
printf("tous les unigrammes");
printf("\n");
for(j=0;j<n;j++)
{
    printf("%s|",t[j]);
}
*/
//au dessus division d'une chaine en un tableau des unigrammes









   i=0;nt=n;occ=1;
   while(i<nt)
   {if(strcmp(t[i],"!")!=0){
       for(j=i+1;j<nt;j++)
       {
           if((strcmp(t[i],t[j])==0)&&(strcmp (t[i],"!")!=0))
           {
               strcpy(t[j],"!\0");

               occ++;
               //t1[j]=0;
           }

           t1[i]=occ;
       }

   }
       occ=1;
       i++;
   }

//supprimer les doublons de la chaine
for(i=0;i<nt;i++){
for(j=i+1;j<nt;j++)
{
    if (strcmp(t[j],"!")==0){
        for(x=j;x<nt;x++){
            strcpy(t[x],t[x+1]);
        }
            nt--;
    }else j++;
}
}
/*for(j=0;j<nt;j++)
{
    printf("%s|",t[j]);
}
 /*printf("\npos4\n");
   for (i=0;i<n;i++)
  {
      printf("%i|",t1[i]);
  }*/

//supprimer les doublons du tab d'occurences
for(i=0;i<n;i++){
for(j=i+1;j<n;j++)
{
    if (t1[j]==0){
        for(x=j;x<n;x++){


            t1[x]=t1[x+1];
        }
            n--;

    }else j++;
}
}

 /*printf("\npos3\n");
   for (i=0;i<n;i++)
  {
      printf("%i|",t1[i]);
  }*/

//test
i=0;
j=0;
posmax=0;
fois=0;
while(fois<m)
{
max=t1[0];
   for(i=0;i<n;i++)
   {
       if(t1[i]>=max)
       {
           max=t1[i];
   posmax=i;
 strcpy(tab[j],t[posmax]);
       }




   }

t1[posmax]=0;

    fois++;
    j++;
}


/*  printf("\npos2\n");
   for (i=0;i<n;i++)
  {
      printf("%i|",t1[i]);
  }



   printf("\npos\n");
   for (i=0;i<n;i++)
  {
      printf("%i|",t1[i]);
  }
   printf("\ntestfail\n");
  for (i=0;i<fois;i++)
  {
      printf("%s|",tab[i]);
  }*/
  Pile p;
  p=PileCreer();
  for (i=m;i>=0;i--){
ELEMENT e=elementCreer();
strcpy(e,tab[i]);
//elementAfficher(e);

Empiler(p,e);
//strcpy(e,tab[1]);
}
return p;
}
//////////////////////////////////////////////////

int verifemail(char *ch)
{
   int posat=0,occat=0,i=0,j;
   int pospo=0,occpo=0,k;
   char aux[4];
   while(i<=strlen(ch))
   {
       if (ch[i]=='@')
       {
           occat++;
           posat=i;
       }else if(ch[i]=='.')
       {
           occpo++;
           pospo=i;//pos de la derniere point
       }
       i++;
   }
   if (occat!=1 ||occpo==0){
    return 0;
   }else
   {
       aux[0]="\0";k=0;
   //for(j=pospo+1;j<=strlen(ch);j++)
   //{  aux[k]=ch[j];
   // k++;
   ///}
   aux[0]=ch[pospo+1];
    aux[1]=ch[pospo+2];
     aux[2]=ch[pospo+3];
     aux[3]='\0';
     printf("%s",aux);
   if( (strcmp(aux,"com")==0)||(strcmp(aux,"tn")==0)||(strcmp(aux,"fr")==0))
    return 1;
   else return 0;

   }

}


int num(char *ch)
{int i;
    i=0;
    while((ch[i]>='0')&&(ch[i]<='9'))
    {
        i++;
    }
    if(i<strlen(ch))
        return 0;
    else return 1;
}


int numer(char * ch)
{
    if (((strlen(ch)!=8) || ((ch[0]!='2')&&(ch[0]!='5')&&(ch[0]!='9')))||(!num(ch)))
    return 0;
    else return 1;

}




int alpha(char *ch)
{int i;
    i=0;
    while(((ch[i]>='A')&&(ch[i]<='Z'))||((ch[i]>='a')&&(ch[i]<='z')))
    {
        i++;
    }
    if(i<strlen(ch))
        return 0;
    else return 1;
}



ELEMENT_MSG messageLePlusLong(LISTE_MSG LMH)
{
    int taille=0,taillemax=0,i;
    NOEUD_MSG q;
    ELEMENT_MSG res=elementCreer_MSG();
     for (q=LMH->tete_MSG;q!=NULL;q=q->suivant_MSG)
     {

    ELEMENT_MSG e=elementCreer_MSG();
    e=q->info_MSG;

    for (i=1;i<=e->msg->lg;i++)
    {
       taille=taille+ e->msg->elements[i]->taille;

    }
if(taille>taillemax)
{
   taillemax=taille;
   res=e;
}
taille=0;
     }

    return res;
}

LISTE_MSG message_D1_D2(LISTE_MSG LMH,DATE D1,DATE D2)
{int i=1,k;
    LISTE_MSG res=listeCreer_MSG();

    // n=noeudCreer_MSG (e);
     NOEUD_MSG q,n,p;
     for (q=LMH->tete_MSG;q!=NULL;q=q->suivant_MSG)
     {



     if ((q->info_MSG->date_envoi.annee>=D1.annee)&&(q->info_MSG->date_envoi.annee<=D2.annee))
{
 LMH->lg_MSG=1;

       ELEMENT_MSG e=elementCreer_MSG();
       //recuperationnn
       e= q->info_MSG;
       printf("\n-----1-------------\n");
       elementAfficher_MSG(q->info_MSG);
       printf("\n ----------1-----------------\n");
i++;
       inserer_MSG(res,q->info_MSG,LMH->lg_MSG);
       printf("hjjjjjjjjjjjjjjjjjjjjjjjjjj");

    }

     }
     printf(" \n++++++++++++++++++++++\n");
     listeAfficher_MSG(res);
     printf(" \n+++++++++++++++++++\n");
    return res;
}

ELEMENT_CONT lePlusContacte(LISTE_MSG L1,LISTE_CONT L2)
{ELEMENT_CONT max=elementCreer_CONT();
    int occmax=0,occ,i,j;
    for(i=1;i<=L2->lg;i++)
    {
        ELEMENT_CONT e=elementCreer_CONT();
        e=recuperer_CONT(L2,i);
        occ=0;
        for(j=1;j<=L1->lg_MSG;j++)
        {
            ELEMENT_MSG e2=elementCreer_MSG();
            e2=recuperer_MSG(L1,j);
            if (strcmp((e->numero),e2->recepteur)==0)
            {
                occ++;
                if (occ>occmax)
                {
                    occmax=occ;

                    max=e;

                }
            }
        }
    }
    return max;
}
//liste contact jamais contactes

LISTE_CONT jamaisContactes(LISTE_MSG L1,LISTE_CONT L2)
{ELEMENT_CONT jam=elementCreer_CONT();
LISTE_CONT LJ=listeCreer_CONT();
    int occmax=0,occ,i,j,k=0;
    for(i=1;i<=L2->lg;i++)
    {
        ELEMENT_CONT e=elementCreer_CONT();
        e=recuperer_CONT(L2,i);
        occ=0;
        for(j=1;j<=L1->lg_MSG;j++)
        {
            ELEMENT_MSG e2=elementCreer_MSG();
            e2=recuperer_MSG(L1,j);
           // elementAfficher_CONT(e2);
            if (strcmp((e->numero),e2->recepteur)==0)
            {
                occ++;
            }

        }
        if (occ==0)
        {
            k++;
            inserer_CONT(LJ,e,k);
        }

    }
    return LJ;
}


int carspeciaux(char* ch)//retourne 1 si il existe un car special dans la chaine
{
    int i=0;
    int test=0;
    while ((i< strlen(ch))&&(test==0))
    {
     if  ((ch[i]!=' ')&&(ch[i]!='£')&&(ch[i]!='$')&&(ch[i]!='¥')
        &&(ch[i]!='è')&&(ch[i]!='é')&&(ch[i]!='ù')&&(ch[i]!='ì')
        &&(ch[i]!='ò')&&(ch[i]!='Ç')&&(ch[i]!='Ø')&&(ch[i]!='ø')
        &&(ch[i]!='Å')&&(ch[i]!='å')&&(ch[i]!='Δ')&&(ch[i]!='_')
        &&(ch[i]!='Φ')&&(ch[i]!='Γ')&&(ch[i]!='Λ')&&(ch[i]!='Ω')
        &&(ch[i]!='Π')&&(ch[i]!='Ψ')&&(ch[i]!='Σ')&&(ch[i]!='Θ')
        &&(ch[i]!='Ξ')&&(ch[i]!='^')&&(ch[i]!='{')&&(ch[i]!='}')
        &&(ch[i]!='[')&&(ch[i]!='~')&&(ch[i]!=']')&&(ch[i]!='|')
        &&(ch[i]!='€')&&(ch[i]!='Æ')&&(ch[i]!='æ')&&(ch[i]!='ß')
        &&(ch[i]!='É')&&(ch[i]!='!')&&(ch[i]!='"')&&(ch[i]!='#')
        &&(ch[i]!='¤')&&(ch[i]!='%')&&(ch[i]!='&')
        &&(ch[i]!='(')&&(ch[i]!=')')&&(ch[i]!='*')&&(ch[i]!='+')
        &&(ch[i]!=',')&&(ch[i]!='.')&&(ch[i]!='/')&&(ch[i]!='0')
        &&(ch[i]!='1')&&(ch[i]!='2')&&(ch[i]!='3')&&(ch[i]!='4')
        &&(ch[i]!='5')&&(ch[i]!='6')&&(ch[i]!='7')&&(ch[i]!='8')
        &&(ch[i]!='9')&&(ch[i]!=':')&&(ch[i]!=';')&&(ch[i]!='<')
        &&(ch[i]!='>')&&(ch[i]!='=')&&(ch[i]!='?')&&(ch[i]!='¡')
        &&(ch[i]!='A')&&(ch[i]!='B')&&(ch[i]!='C')&&(ch[i]!='D')
        &&(ch[i]!='E')&&(ch[i]!='F')&&(ch[i]!='G')&&(ch[i]!='H')
        &&(ch[i]!='I')&&(ch[i]!='J')&&(ch[i]!='K')&&(ch[i]!='L')
        &&(ch[i]!='M')&&(ch[i]!='N')&&(ch[i]!='O')&&(ch[i]!='P')
        &&(ch[i]!='Q')&&(ch[i]!='R')&&(ch[i]!='S')&&(ch[i]!='T')
        &&(ch[i]!='U')&&(ch[i]!='V')&&(ch[i]!='W')&&(ch[i]!='X')
        &&(ch[i]!='Y')&&(ch[i]!='Z')&&(ch[i]!='Ä')&&(ch[i]!='Ö')
        &&(ch[i]!='Ñ')&&(ch[i]!='Ü')&&(ch[i]!='§')&&(ch[i]!='¿')
        &&(ch[i]!='a')&&(ch[i]!='b')&&(ch[i]!='c')&&(ch[i]!='d')
        &&(ch[i]!='e')&&(ch[i]!='f')&&(ch[i]!='g')&&(ch[i]!='h')
        &&(ch[i]!='i')&&(ch[i]!='j')&&(ch[i]!='k')&&(ch[i]!='l')
        &&(ch[i]!='m')&&(ch[i]!='n')&&(ch[i]!='o')&&(ch[i]!='p')
        &&(ch[i]!='q')&&(ch[i]!='r')&&(ch[i]!='s')&&(ch[i]!='t')
        &&(ch[i]!='u')&&(ch[i]!='v')&&(ch[i]!='w')&&(ch[i]!='x')
        &&(ch[i]!='y')&&(ch[i]!='z')&&(ch[i]!='ä')&&(ch[i]!='ö')
        &&(ch[i]!='ñ')&&(ch[i]!='ü')&&(ch[i]!='à'))
        {
        test=1;
        printf("\n c spec existe\n");
        }
                i++;

    }

    return test;
}
/*
void LMA(LISTE_SMS L)
{
    //L=listeCreer_SMS();
    strcpy(L->elements[1]->texte,"bonjouuuuuuuuuuuuuuuuuur");
    L->elements[1]->taille=7;
}
*/

int taillechspeciale(char* ch)//retourne 1 si il existe un car special dans la chaine
{
    int i=0;
    int res=0;
    int cspes=0;
    while (i< strlen(ch))
    {
     if  ((ch[i]!=' ')&&(ch[i]!='£')&&(ch[i]!='$')&&(ch[i]!='¥')
        &&(ch[i]!='è')&&(ch[i]!='é')&&(ch[i]!='ù')&&(ch[i]!='ì')
        &&(ch[i]!='ò')&&(ch[i]!='Ç')&&(ch[i]!='Ø')&&(ch[i]!='ø')
        &&(ch[i]!='Å')&&(ch[i]!='å')&&(ch[i]!='Δ')&&(ch[i]!='_')
        &&(ch[i]!='Φ')&&(ch[i]!='Γ')&&(ch[i]!='Λ')&&(ch[i]!='Ω')
        &&(ch[i]!='Π')&&(ch[i]!='Ψ')&&(ch[i]!='Σ')&&(ch[i]!='Θ')
        &&(ch[i]!='Ξ')&&(ch[i]!='^')&&(ch[i]!='{')&&(ch[i]!='}')
        &&(ch[i]!='[')&&(ch[i]!='~')&&(ch[i]!=']')&&(ch[i]!='|')
        &&(ch[i]!='€')&&(ch[i]!='Æ')&&(ch[i]!='æ')&&(ch[i]!='ß')
        &&(ch[i]!='É')&&(ch[i]!='!')&&(ch[i]!='"')&&(ch[i]!='#')
        &&(ch[i]!='¤')&&(ch[i]!='%')&&(ch[i]!='&')
        &&(ch[i]!='(')&&(ch[i]!=')')&&(ch[i]!='*')&&(ch[i]!='+')
        &&(ch[i]!=',')&&(ch[i]!='.')&&(ch[i]!='/')&&(ch[i]!='0')
        &&(ch[i]!='1')&&(ch[i]!='2')&&(ch[i]!='3')&&(ch[i]!='4')
        &&(ch[i]!='5')&&(ch[i]!='6')&&(ch[i]!='7')&&(ch[i]!='8')
        &&(ch[i]!='9')&&(ch[i]!=':')&&(ch[i]!=';')&&(ch[i]!='<')
        &&(ch[i]!='>')&&(ch[i]!='=')&&(ch[i]!='?')&&(ch[i]!='¡')
        &&(ch[i]!='A')&&(ch[i]!='B')&&(ch[i]!='C')&&(ch[i]!='D')
        &&(ch[i]!='E')&&(ch[i]!='F')&&(ch[i]!='G')&&(ch[i]!='H')
        &&(ch[i]!='I')&&(ch[i]!='J')&&(ch[i]!='K')&&(ch[i]!='L')
        &&(ch[i]!='M')&&(ch[i]!='N')&&(ch[i]!='O')&&(ch[i]!='P')
        &&(ch[i]!='Q')&&(ch[i]!='R')&&(ch[i]!='S')&&(ch[i]!='T')
        &&(ch[i]!='U')&&(ch[i]!='V')&&(ch[i]!='W')&&(ch[i]!='X')
        &&(ch[i]!='Y')&&(ch[i]!='Z')&&(ch[i]!='Ä')&&(ch[i]!='Ö')
        &&(ch[i]!='Ñ')&&(ch[i]!='Ü')&&(ch[i]!='§')&&(ch[i]!='¿')
        &&(ch[i]!='a')&&(ch[i]!='b')&&(ch[i]!='c')&&(ch[i]!='d')
        &&(ch[i]!='e')&&(ch[i]!='f')&&(ch[i]!='g')&&(ch[i]!='h')
        &&(ch[i]!='i')&&(ch[i]!='j')&&(ch[i]!='k')&&(ch[i]!='l')
        &&(ch[i]!='m')&&(ch[i]!='n')&&(ch[i]!='o')&&(ch[i]!='p')
        &&(ch[i]!='q')&&(ch[i]!='r')&&(ch[i]!='s')&&(ch[i]!='t')
        &&(ch[i]!='u')&&(ch[i]!='v')&&(ch[i]!='w')&&(ch[i]!='x')
        &&(ch[i]!='y')&&(ch[i]!='z')&&(ch[i]!='ä')&&(ch[i]!='ö')
        &&(ch[i]!='ñ')&&(ch[i]!='ü')&&(ch[i]!='à'))
        {

        cspes=cspes+2;
        }
        else
        {res++;}
        i++;

    }

    return res+cspes;
}

int main()
{
int i,j;
   char  res[1000];
   NOEUD_MSG p;
int j1,j2,m1,m2,a1,a2,m,op;

char chr[3000];



printf("**BIENVENU**");
printf("\n 1:Repertoire\n");
printf("\n 2:Historique messages\n");
printf("\n 3:Ajout contact\n");
printf("\n 4:Envoyer une message\n");
printf("\n   ***FONCTIONS***\n");
printf("\n 5:Test unigramme\n");
printf("\n 6:Test contact le plus contacte\n");
printf("\n 7:Test contact jamais contacte\n");
printf("\n 8:Test affichage selon deux dates\n");
printf("\n 9:Test le plus long message\n");



do{
printf("choisissez une operation svp: \n");
scanf("%i",&op);
}while((op<1)||(op>9));

;

    LISTE_SMS liste=listeCreer_SMS();
   // elementAfficher_SMS(e);
   // listeAfficher_SMS(historique_SMS());

    LISTE_CONT LC=listeCreer_CONT();
    LC=repertoire_CONT();
    if(op==1){
    listeAfficher_CONT(LC);
    }

    LISTE_MSG LMH=listeCreer_MSG();
    LMH=historique_msg();
    if(op==2){
   listeAfficher_MSG(LMH);
    }
    //ajout d'un message
LISTE_SMS msg=listeCreer_SMS();

  ELEMENT_MSG e=  elementCreer_MSG();
  if (op==4){
  elementLire_MSG(&e);
 // elementAfficher_MSG(e);
  inserer_MSG(LMH,e,listeTaille_MSG(LMH));

  listeAfficher_MSG(LMH);
  }
  if(op==3){
     //ajout d'un contact

ELEMENT_CONT ec=elementCreer_CONT();
elementLire_CONT(&ec);
inserer_CONT(LC,ec,(LC->lg)+1);
listeAfficher_CONT(LC);

  }
  if (op==5){
//concatenation de tous les messages de la liste d'historique///////////////////////////////
     chr[0]='\0';
     res[0]='\0';
   p=LMH->tete_MSG;
   ELEMENT_MSG em=elementCreer_MSG();
   for(j=1;j<=LMH->lg_MSG;j++){
        //em=recuperer_MSG(LMH,i);


liste=recuperer_MSG(LMH,j)->msg;

    if((liste->lg)==1){
   strcpy(res,liste->elements[1]->texte);
    }
    else{
    for(i=1;i<=liste->lg;i++)
    strcpy(res,(strcat(res,liste->elements[i]->texte)));

     //printf("\n res= %s",res);
}
strcat(res," ");
 strcat(chr, res);
 p= p->suivant_MSG;

   }

  // printf("\n chr= %s",chr);
   strcpy(chrglob,chr);
  // printf("\n chrglob= %s",chrglob);

   printf("tapez le nombre de unigramme: ");
   scanf("%i",&m);
   Pile pi=PileCreer();
   pi=unigrammes(LMH,m);
   PileAfficher(pi);
//////////////////////////////////////////////
  }

if (op==6){
  printf("\n\n\nle contact le plus contacte est: ");

  elementAfficher_CONT(lePlusContacte(LMH,LC));
}
if (op==7){
  printf("\n\n\nles contacts jamais contactes: \n\n");
  LISTE_CONT cont_jam=listeCreer_CONT();
  cont_jam=jamaisContactes(LMH,LC);
  listeAfficher_CONT(cont_jam);
}
//printf("%i messages dans l'historique\n ",listeTaille_MSG(LMH));
if(op==8){
  //saisie de la 1ere date

  do{
  printf("taper le jour de la 1ere date : \n");
  scanf("%i",&j1);
  }while((j1<0)||(j1>31));

  do{
        printf("taper le mois de la 1ere date : \n");
        scanf("%i",&m1);
  }while((m1<1)||(m1>12));

  do{
 printf("taper l'annee de la 1ere date : \n");
  scanf("%i",&a1);
   }while((a1<1995)||(a1>2022));
  //saisie de la 1ere date
  do{
  printf("taper le jour de la 2eme date : \n");
  scanf("%i",&j2);  }while((j2<0)||(j2>31));
   do{
  printf("taper le mois de la 2eme date : \n");
  scanf("%i",&m2);
  }while((m2<1)||(m2>12));
   do{
  printf("taper l'annee de la 2eme date : \n");
  scanf("%i",&a2);
   }while((a2<1995)||(a2>2022));
  DATE D1,D2;
  //1ere date
  D1.jour=j1;
  D1.mois=m1;
  D1.annee=a1;
  //2eme date
  D2.jour=j2;
  D2.mois=m2;
  D2.annee=a2;


/* printf("\n\nla 1ere date est :\n");
 printf("%d-%d-%d ",D1.jour,D1.mois,D1.annee);
*/



//affichage de tous les messages entre d1 et d2
 printf("\nles messages dans cette date \n");
 LISTE_MSG LMD=listeCreer_MSG();
 LMD=message_D1_D2(LMH,D1,D2);
 listeAfficher_MSG(LMD);
}
if(op==9){
 //affichage le message le plus long
 printf("\n\nle message le plus long \n");
 ELEMENT_MSG t=elementCreer_MSG();
 t=messageLePlusLong(LMH);
 elementAfficher_MSG(t);
}


///unigramme




    return 0;
    }

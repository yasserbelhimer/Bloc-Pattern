#include<stdio.h>
#include<stdlib.h>
#include"piles.h"

pileCh initPileCh()
{
    pileCh p;
    p=NULL;
    return p;
}

void empilerCh(pileCh *p,int x)
{
    pileCh temp;
    temp = malloc(sizeof(pileCh));
    temp->val = x;
    temp->svt = *p;
    *p = temp;
}
void enfiler(pileCh *tete,pileCh *Queue ,int x)
{
    pileCh temp;
    temp = malloc(sizeof(pileCh));
    temp->val = x;temp->svt = NULL;
    if(*tete == NULL)
    {
        *tete = temp;
        *Queue = temp;
    }
    else
    {
        (*Queue)->svt = temp;
        *Queue = temp;
    }
}
void depilerCh(pileCh *p,int *x)
{
    pileCh temp;
    *x = (*p)->val;
    temp = *p;
    *p=(*p)->svt;
    free(temp);

}
int sommetPileCh(pileCh p)
{
    return(p->val);
}
int pileVideCh(pileCh p)
{
    if(p==NULL)
        return 1;
    else
        return 0;
}

int veriffier(pileCh pile1,pileCh pile2,pileCh listeI,pileCh listeJ)
{
    int booll = 0;
    while((listeI !=NULL) && (booll == 0))
    {
        pileCh P = pile1,Q= pile2;
        while((P !=NULL) && (booll == 0))
        {
            if((P->val == listeI->val)&&(Q->val == listeJ->val))
            {
                booll = 1;
            }
            P = P->svt;
            Q = Q->svt;
        }
        listeI = listeI->svt;listeJ = listeJ->svt;
    }
    return booll;
}
int veriffierPlace(pileCh pile1,pileCh pile2,pileCh listeI,pileCh listeJ)
{
    int trouv1 = 1, trouv2 =0;
    pileCh P = pile1,Q= pile2;
    while((P!=NULL)&&trouv1)
    {
        if((P->val>=10)||(Q->val>=10)||(P->val<0)||(Q->val<0))
        {
            trouv1 = 0;

        }
        else
        {
            pileCh R = listeI,S=listeJ;
            while((R!=NULL)&&(trouv2==0))
            {
                if((P->val == R->val)&&(Q->val == S->val))
                    trouv2 = 1;
                R = R->svt;S = S->svt;

            }
            if(trouv2)
            {
                P = P->svt;Q = Q->svt;trouv2 = 0;
            }
            else
                trouv1 = 0;
        }


    }
    return trouv1;
}

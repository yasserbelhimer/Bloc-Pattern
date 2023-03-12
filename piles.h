#ifndef piles
#define piles

    typedef struct cellule *pileCh;
    typedef struct cellule
    {
        int val;
        pileCh svt;
    }cellule;
    #define max 100
    typedef struct  pileCn
    {
        int T[max];
        int sommet;
    }pileCn;
    pileCh initPileCh();
    void empilerCh(pileCh *p,int x);
    void enfiler(pileCh *tete,pileCh *Queue ,int x);
    void depilerCh(pileCh *p,int *x);
    int sommetPileCh(pileCh p);
    int pileVideCh(pileCh p);
    int veriffier(pileCh pile1,pileCh pile2,pileCh listeI,pileCh listeJ);
    int veriffierPlace(pileCh pile1,pileCh pile2,pileCh listeI,pileCh listeJ);
#endif

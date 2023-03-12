#ifndef  DEF_play
#define  DEF_play
    typedef struct cellule *pileCh;
    typedef struct cellule
    {
        int val;
        pileCh svt;
    }cellule;
    void minBloc(int t,int *x,int *y);
    int remplire(int carte[10][10],int pi,int pj,int in);
    int place(int carte[10][10],int in);
    int placeRobot(int carte[10][10],int in,pileCh *xx,pileCh *yy);
    void remplireRebot(int carte[10][10],int *indice1,int *indice2,int *indice3,int *score);
    void playSolo(SDL_Surface* screen);
    void playRebot(SDL_Surface* screen);
    void playVsRebot(SDL_Surface* screen);
    void introduction(SDL_Surface* screen);
#endif

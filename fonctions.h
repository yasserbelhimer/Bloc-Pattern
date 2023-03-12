
#ifndef  DEF_FONCTIONS
#define  DEF_FONCTIONS
    void initialiser(int carte[10][10],int *i1,int *i2,int *i3);
    int indiceI(SDL_Event event);
    int indiceJ(SDL_Event event);
    int indiceVsRobotJ(SDL_Event event);
    void eleminer(int carte[10][10],int *score);
    int convert(char ch[100]);
    void sauvegarder(int carte[10][10],int indiceP1,int indiceP2,int indiceP3,int score,char name[15]);
    int load(int niveau[][10],int *indiceP1,int *indiceP2,int *indiceP3,int *score);
    void copierMatrice(int m[10][10],int t[10][10]);
    int readTop5(Player t[5]);
    void savTop(Player t[5],int n);
    void trierTop(Player t[5],int n);
    Date getDate();
    int carteEstVide(int carte[10][10]);
    void saveVsRobot(int carte[10][10],int cartRobot[10][10],int indiceP1,int indiceP2,int indiceP3,int score,int scoreRobot,char name[15]);
    int loadVsRobot(int niveau[][10],int carteRobot[10][10],int *indiceP1,int *indiceP2,int *indiceP3,int *score,int *scoreRobot);

#endif

#ifndef  DEF_constantes
#define  DEF_constantes
    #define TAILLE_BLOC_GRAND 30
    #define NB_BLOCS_CARTE  10
    #define TAILLE_BLOC_PETIT 17
    #define NB_BLOCS_PIECE  5
    typedef struct
    {
        int day;
        int month;
        int year;
    }Date;
    typedef struct
    {
        int score;
        char name[15];
        Date date;
    }Player;

    enum { ZERO , MOUVE, JAUNE , BLUE, ROUGE , VERT ,BLUE_C};
#endif


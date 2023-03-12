#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "constantes.h"
#include "fonctions.h"
#include "piles.h"
    const int piece[28][5][5] ={
    //--------------------- la piece 0 blue ciel --------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,0,0},
                                            {0,0,0,BLUE_C,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 1 mouve -------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,0,0},
                                            {0,0,MOUVE,MOUVE,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 2 mouve -------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,ROUGE,ROUGE,0},
                                            {0,0,0,ROUGE,0},
                                            {0,0,ROUGE,ROUGE,0},
                                            {0,0,0,0,0}
                                        },
    // -------------------- la piece 3 vert -----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,JAUNE,0},
                                            {0,0,0,JAUNE,0},
                                            {0,0,0,JAUNE,0},
                                            {0,0,0,JAUNE,0}
                                        },
    // -------------------- la piece 4 vert -----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,VERT,0},
                                            {0,0,0,VERT,0},
                                            {0,0,0,VERT,0},
                                            {0,0,0,0,0}
                                        },
    // -------------------- la piece 5 vert -----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,ROUGE,ROUGE,ROUGE,0},
                                            {0,ROUGE,0,0,0},
                                            {0,ROUGE,0,0,0},
                                            {0,0,0,0,0}
                                        },
    // -------------------- la piece 6 vert -----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,VERT,0},
                                            {0,0,VERT,VERT,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    // -------------------- la piece 7 vert -----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,VERT,0,0},
                                            {0,0,VERT,VERT,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    // -------------------- la piece 8 vert -----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,VERT,VERT,0},
                                            {0,0,VERT,0,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    // -------------------- la piece 9 jaune -----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,ROUGE,0,ROUGE,0},
                                            {0,ROUGE,ROUGE,ROUGE,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 10 jaune ---------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,JAUNE,0,0},
                                            {0,0,JAUNE,JAUNE,0},
                                            {0,0,JAUNE,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 11 jaune ---------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,JAUNE,JAUNE,JAUNE,0},
                                            {0,0,JAUNE,0,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 12 jaune ---------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,ROUGE,ROUGE,ROUGE,0},
                                            {0,ROUGE,0,ROUGE,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 13 jaune ---------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,JAUNE,0,0},
                                            {0,JAUNE,JAUNE,JAUNE,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 14 jaune ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,0,0},
                                            {0,VERT,VERT,VERT,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 15 jaune ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,0,0},
                                            {JAUNE,JAUNE,JAUNE,JAUNE,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 16 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,0,0},
                                            {0,0,0,BLUE_C,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 17 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,0,0},
                                            {ROUGE,ROUGE,ROUGE,ROUGE,ROUGE},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 18 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,ROUGE,ROUGE,ROUGE,0},
                                            {0,0,0,ROUGE,0},
                                            {0,0,0,ROUGE,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 19 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,BLUE,BLUE,BLUE,0},
                                            {0,BLUE,BLUE,BLUE,0},
                                            {0,BLUE,BLUE,BLUE,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 20 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,ROUGE,0,0,0},
                                            {0,ROUGE,0,0,0},
                                            {0,ROUGE,ROUGE,ROUGE,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 21 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,VERT,VERT,0},
                                            {0,0,0,VERT,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 22 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,JAUNE,JAUNE,0},
                                            {0,0,JAUNE,JAUNE,0},
                                            {0,0,0,0,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 23 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,ROUGE,ROUGE,0},
                                            {0,0,ROUGE,0,0},
                                            {0,0,ROUGE,ROUGE,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 24 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,JAUNE,0},
                                            {0,0,JAUNE,JAUNE,0},
                                            {0,0,0,JAUNE,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 25 rouge ----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,0,0},
                                            {0,0,0,MOUVE,0},
                                            {0,0,0,MOUVE,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 26 blue -----------------------------
                                        {
                                            {0,0,0,0,0},
                                            {0,0,0,ROUGE,0},
                                            {0,0,0,ROUGE,0},
                                            {0,ROUGE,ROUGE,ROUGE,0},
                                            {0,0,0,0,0}
                                        },
    //--------------------- la piece 27 blue -----------------------------
                                        {
                                            {0,0,0,ROUGE,0},
                                            {0,0,0,ROUGE,0},
                                            {0,0,0,ROUGE,0},
                                            {0,0,0,ROUGE,0},
                                            {0,0,0,ROUGE,0}
                                        }
                                };
void minBloc(int t,int *x,int *y)
{
    int bol = 1,i=0,j;
    while((i<5)&&bol)
    {
        j=0;
        while((j<5)&&bol)
        {
            if(piece[t][i][j]!=0)
            {
                *x = i;*y=j;bol=0;
            }
            j++;
        }
        i++;
    }
}
int remplire(int carte[10][10],int pi,int pj,int in)
{
    int val,i = 0,j = 0,x,y,nBlock = 0;
    pileCh pileI = NULL,pileJ = NULL,listeI = NULL,listeJ = NULL, P = NULL,Q = NULL;
    int booleen = 1;

    minBloc(in,&x,&y);
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(piece[in][i][j]!=0)
            {
                    empilerCh(&pileI,i);empilerCh(&pileJ,j);
                    if(((i+pi-x)>9)||((j+pj-y)>9)||((i+pi-x)<0)||((j+pj-y)<0))
                        booleen = 0;
                    empilerCh(&P,i+pi-x);empilerCh(&Q,j+pj-y);
            }
        }
    }
    if(booleen)
    {
        val = piece[in][x][y];
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(carte[i][j]!=0)
                {
                    empilerCh(&listeI,i);empilerCh(&listeJ,j);
                }
            }
        }
        if(veriffier(P,Q,listeI,listeJ))
        booleen = 0;
    }
    while(listeI!= NULL)
    {
        depilerCh(&listeI,&i);depilerCh(&listeJ,&j);
    }
    while(P!= NULL)
    {
        depilerCh(&P,&i);depilerCh(&Q,&j);
    }
    if(booleen)
    {
        while(pileI!= NULL)
        {
            depilerCh(&pileI,&i);depilerCh(&pileJ,&j);
            nBlock++;
            carte[i+pi-x][j+pj-y] = val;
        }
        return nBlock;
    }
    else
    {
        while(P!= NULL)
        {
            depilerCh(&pileI,&i);depilerCh(&pileJ,&j);
        }
        return 0;
    }

}
int place(int carte[10][10],int in)
{
    int i,j,pi,pj,x,y;
    int booleen = 1 ;
    pileCh pileI = NULL,pileJ = NULL,listeI = NULL,listeJ = NULL, P = NULL,Q = NULL;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(carte[i][j]==0)
            {
                empilerCh(&listeI,i);empilerCh(&listeJ,j);
            }

        }
    }
    P = listeI;Q=listeJ;
    minBloc(in,&x,&y);
    while((P!=NULL)&&(booleen))
    {
        pi = P->val;pj = Q->val;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(piece[in][i][j]!=0)
                {
                    empilerCh(&pileI,i+pi-x);empilerCh(&pileJ,j+pj-y);
                }
            }
        }

        if(veriffierPlace(pileI,pileJ,listeI,listeJ))
        {
           booleen =  0;
        }
        while(pileI!=NULL)
        {
            depilerCh(&pileI,&pi);depilerCh(&pileJ,&pj);
        }
        pileI = NULL;pileJ  =NULL;
        P = P->svt;Q=Q->svt;
    }
    while(listeI!=NULL)
    {
        depilerCh(&listeI,&pi);depilerCh(&listeJ,&pj);
    }
    return booleen;

}
int nb_Blocs(int in)
{
    int i,j,nb=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(piece[in][i][j]!=0)
            {
                nb++;
            }
        }
    }
    return nb;
}
int placeRobot(int carte[10][10],int in,pileCh *xx,pileCh *yy)
{
    int i,j,pi,pj,x,y;
    int boool =0;
    pileCh pileI = NULL,pileJ = NULL,listeI = NULL,listeJ = NULL, P = NULL,Q = NULL,listeII = NULL,listeJJ = NULL;
    pileCh possibleI = NULL,possibleJ = NULL,possibleII = NULL,possibleJJ = NULL;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(carte[i][j]==0)
            {
                enfiler(&listeI,&listeII,i);enfiler(&listeJ,&listeJJ,j);
            }

        }
    }
    P = listeI;Q=listeJ;

    minBloc(in,&x,&y);
    while(P!=NULL)
    {
        listeII = NULL;listeJJ=NULL;
        pi = P->val;pj = Q->val;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(piece[in][i][j]!=0)
                {
                    enfiler(&pileI,&listeII,i+pi-x);enfiler(&pileJ,&listeJJ,j+pj-y);
                }
            }
        }
        if(veriffierPlace(pileI,pileJ,listeI,listeJ))
        {
            enfiler(&possibleI,&possibleII,pileI->val);enfiler(&possibleJ,&possibleJJ,pileJ->val);
            boool= 1;
        }
        while(pileI!=NULL)
        {
            depilerCh(&pileI,&pi);depilerCh(&pileJ,&pj);
        }
        pileI = NULL;pileJ  =NULL;
        P = P->svt;Q=Q->svt;
    }
    while(listeI!=NULL)
    {
        depilerCh(&listeI,&pi);depilerCh(&listeJ,&pj);
    }
    if(boool)
    {
        *xx = possibleJ;*yy= possibleI;
    }
    return boool;

}
void remplireRebot(int carte[][NB_BLOCS_CARTE],int *indice1,int *indice2,int *indice3,int *score)
{
    int x,y,nb_bolc = 0,scoreTemps1=0,scoreTemps2=0,scoreTemps3=0,pi,pj;
    int carteTemps[10][10];
    int i1Temps,j1Temps,i2Temps,j2Temps,i3Temps,j3Temps,scoreMax;
    pileCh possibleI=NULL,possibleJ=NULL;
    if(placeRobot(carte,*indice1,&possibleJ,&possibleI))
    {
        scoreMax = 0;
        while(possibleI!=NULL)
        {
            scoreTemps1 = 0;
            copierMatrice(carte,carteTemps);
            x=possibleI->val;y=possibleJ->val;
            nb_bolc=remplire(carteTemps,x,y,*indice1);
            scoreTemps1+=nb_bolc*10;
            eleminer(carteTemps,&scoreTemps1);
            if(scoreTemps1>scoreMax)
            {
                scoreMax = scoreTemps1;
                i1Temps = x;
                j1Temps = y;
            }
            possibleI=possibleI->svt;possibleJ=possibleJ->svt;
        }
        scoreTemps1 = scoreMax;
    }
    while(possibleI!=NULL)
    {
        depilerCh(&possibleI,&pi);depilerCh(&possibleJ,&pj);
    }
    if(placeRobot(carte,*indice2,&possibleJ,&possibleI))
    {
        scoreMax = 0;
        while(possibleI!=NULL)
        {
            scoreTemps2 = 0;
            copierMatrice(carte,carteTemps);
            x=possibleI->val;y=possibleJ->val;
            nb_bolc=remplire(carteTemps,x,y,*indice2);
            scoreTemps2+=nb_bolc*10;
            eleminer(carteTemps,&scoreTemps2);
            if(scoreTemps2>scoreMax)
            {
                scoreMax = scoreTemps2;
                i2Temps = x;
                j2Temps = y;
            }
            possibleI=possibleI->svt;possibleJ=possibleJ->svt;
        }
        scoreTemps2 = scoreMax;
    }
    while(possibleI!=NULL)
    {
        depilerCh(&possibleI,&pi);depilerCh(&possibleJ,&pj);
    }
    if(placeRobot(carte,*indice3,&possibleJ,&possibleI))
    {
        scoreMax = 0;
        while(possibleI!=NULL)
        {
            scoreTemps3 = 0;
            copierMatrice(carte,carteTemps);
            x=possibleI->val;y=possibleJ->val;
            nb_bolc=remplire(carteTemps,x,y,*indice3);
            scoreTemps3+=nb_bolc*10;
            eleminer(carteTemps,&scoreTemps3);
            if(scoreTemps3>scoreMax)
            {
                scoreMax = scoreTemps3;
                i3Temps = x;
                j3Temps = y;
            }
            possibleI=possibleI->svt;possibleJ=possibleJ->svt;
        }
        scoreTemps3 = scoreMax;
    }
    while(possibleI!=NULL)
    {
        depilerCh(&possibleI,&pi);depilerCh(&possibleJ,&pj);
    }
    nb_bolc= 0;srand(time(NULL));
        if((*indice1 ==3)||(*indice1 ==15 )||(*indice1 == 17)||(*indice1 ==19 )||(*indice1 == 17))
    {
        nb_bolc=remplire(carte,i1Temps,j1Temps,*indice1);
        do
        {
            *indice1=(rand()%28);
        }while(*indice1==0);
    }
    if(!nb_bolc)
    {
        if((*indice2 ==3)||(*indice2 ==15 )||(*indice2 == 17)||(*indice2 ==19 )||(*indice2 == 17))
        {
            nb_bolc=remplire(carte,i2Temps,j2Temps,*indice2);
            do
            {
                *indice2=(rand()%28);
            }while(*indice2==0);
        }
    }
    if(!nb_bolc)
    {
        if((*indice3 ==3)||(*indice3 ==15 )||(*indice3 == 17)||(*indice3 ==19 )||(*indice3 == 17))
        {
            nb_bolc=remplire(carte,i3Temps,j3Temps,*indice3);
            do
            {
                *indice3=(rand()%28);
            }while(*indice3==0);
        }
    }
    if(!nb_bolc)
    {
        if((*indice1 == 1)||(*indice1 == 4) ||(*indice1==14)||(*indice1==16)||(*indice1==22)||(*indice1==25))
        {
            nb_bolc=remplire(carte,i1Temps,j1Temps,*indice1);
            do
            {
                *indice1=(rand()%28);
            }while(*indice1==0);
        }
    }
    if(!nb_bolc)
    {
        if((*indice2 == 1)||(*indice2 == 4) ||(*indice2==14)||(*indice2==16)||(*indice2==22)||(*indice2==25))
        {
            nb_bolc=remplire(carte,i2Temps,j2Temps,*indice2);
            do
            {
                *indice2=(rand()%28);
            }while(*indice2==0);
        }
    }
    if(!nb_bolc)
    {
        if((*indice3 == 1)||(*indice3 == 4) ||(*indice3==14)||(*indice3==16)||(*indice3==22)||(*indice3==25))
        {
            nb_bolc=remplire(carte,i3Temps,j3Temps,*indice3);
            do
            {
                *indice3=(rand()%28);
            }while(*indice3==0);
        }
    }
    if(!nb_bolc)
    {
        if(scoreTemps1>scoreTemps2)
        {
            if(scoreTemps3>scoreTemps1)
            {
                nb_bolc=remplire(carte,i3Temps,j3Temps,*indice3);
                do
                {
                    *indice3=(rand()%28);
                }while(*indice3==0);
            }
            else
            {
                nb_bolc=remplire(carte,i1Temps,j1Temps,*indice1);
                do
                {
                    *indice1=(rand()%28);
                }while(*indice1==0);
            }
        }
        else
        {
            if(scoreTemps3>scoreTemps2)
            {
                nb_bolc=remplire(carte,i3Temps,j3Temps,*indice3);
                do
                {
                    *indice3=(rand()%28);
                }while(*indice3==0);
            }
            else
            {
                nb_bolc=remplire(carte,i2Temps,j2Temps,*indice2);
                do
                {
                    *indice2=(rand()%28);
                }while(*indice2==0);
            }
        }
    }
    if(nb_bolc)
    {
        *score+=nb_bolc*10;
    }
}
void playSolo(SDL_Surface* screen)
{
    int carte[NB_BLOCS_CARTE][NB_BLOCS_CARTE];
    int indice1,indice2,indice3,i,j,p1,pi,pj,nb_bolc,bestScore = 0,creat = 0;
    char temps[20] = "",temps2[20] = "",temp[1]="",tempsTop[500]="";
    Player tabTop[5],tempsPlayer;
    tempsPlayer.score = 0;
    strcpy(tempsPlayer.name,"player");
    TTF_Init();
    SDL_Surface* top5 = NULL;
    SDL_Surface *scoreA = NULL,*scoreB = NULL,*nPlayer = NULL;
    SDL_Surface* play = SDL_LoadBMP("images/play.bmp");
    SDL_Surface* mouve = SDL_LoadBMP("images/mouve.bmp");
    SDL_Surface* mouve17 = SDL_LoadBMP("images/mouve17.bmp");
    SDL_Surface* pause = SDL_LoadBMP("images/pause.bmp");
    SDL_Surface* jaune = SDL_LoadBMP("images/jaune.bmp");
    SDL_Surface* jaune17 = SDL_LoadBMP("images/jaune17.bmp");
    SDL_Surface* rouge = SDL_LoadBMP("images/rouge.bmp");
    SDL_Surface* rouge17 = SDL_LoadBMP("images/rouge17.bmp");
    SDL_Surface* blue = SDL_LoadBMP("images/blue.bmp");
    SDL_Surface* blue17 = SDL_LoadBMP("images/blue17.bmp");
    SDL_Surface* blue_c = SDL_LoadBMP("images/blue_c.bmp");
    SDL_Surface* blue_c17 = SDL_LoadBMP("images/blue_c17.bmp");
    SDL_Surface* vert = SDL_LoadBMP("images/vert.bmp");
    SDL_Surface* vert17 = SDL_LoadBMP("images/vert17.bmp");
    SDL_Surface* trans = SDL_LoadBMP("images/trans.bmp");
    SDL_Surface* gameOver = SDL_LoadBMP("images/over.bmp");
    SDL_Surface* edition = SDL_LoadBMP("images/edition.bmp");
    TTF_Font *police = TTF_OpenFont("arial.ttf",20);
    TTF_Font *police2 = TTF_OpenFont("arial.ttf",30);
    TTF_Font *police3 = TTF_OpenFont("Frozito.ttf",28);
    SDL_Rect dstrect,position1,position2,position3,positions,positionScore,positionBestScore,positionPlayer,positionTop5;
    dstrect.x = 0;dstrect.y = 0;
    SDL_Color couleurNoire = {207, 181, 59},noire = {255,255,255},blanc = {0,0,0};
    if(!load(carte,&indice1,&indice2,&indice3,&tempsPlayer.score))
    {
        initialiser(carte,&indice1,&indice2,&indice3);tempsPlayer.score  =0;
    }
    if(carteEstVide(carte))
    {
        int edit = 1,n=0;i=0;char playerName[25] ="";SDL_Event event;
        while(edit)
        {
            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT : edit = 0; break;
                    case SDL_MOUSEBUTTONUP:
                        if((event.motion.x>=300)&&(event.motion.x<=400)&&(event.motion.y<=340)&&(event.motion.y>=315))
                        {
                            edit = 0;
                        }
                        break;
                    case SDL_KEYUP:
                        i = 1;
                        if((event.key.keysym.sym==SDLK_KP_ENTER)||(event.key.keysym.sym==SDLK_RETURN))
                        {
                            edit = 0;
                            i = 0;
                        }
                        if(event.key.keysym.sym==109)
                            event.key.keysym.sym = 59;
                        else if(event.key.keysym.sym==59)
                            event.key.keysym.sym = 109;
                        else if(event.key.keysym.sym==97)
                            event.key.keysym.sym = 113;
                        else if(event.key.keysym.sym==113)
                            event.key.keysym.sym = 97;
                        if((n<8)&&(event.key.keysym.sym!=SDLK_BACKSPACE)&&(((event.key.keysym.sym>= 97) && (event.key.keysym.sym <= 122))||(event.key.keysym.sym==32)))
                        {
                            sprintf(temp,"%c",event.key.keysym.sym);
                            strcat(playerName,temp);n++;playerName[n] = '\0';
                        }
                        if((event.key.keysym.sym==SDLK_BACKSPACE)&&(n>0))
                        {
                            n--;
                            playerName[n] = '\0';
                        }
                        break;
                }
                if(i)
                    strcpy(tempsPlayer.name,playerName);
                }
                SDL_BlitSurface(play, 0, screen, &dstrect);
                positionPlayer.x =  screen->w/2 -(strlen(tempsPlayer.name)*15/2);positionPlayer.y = 260;
                positions.x=187;positions.y=178;
                scoreB = TTF_RenderText_Blended(police3,tempsPlayer.name,blanc);
                SDL_BlitSurface(edition,NULL,screen,&positions);
                SDL_BlitSurface(scoreB,NULL,screen,&positionPlayer);
                SDL_Flip(screen);
                SDL_FreeSurface(scoreB);
        }
    }
    else
    {
        FILE* fileS = NULL;
        fileS = fopen("files/name.ys","r");
        if(fileS!=NULL)
        {
            fgets(tempsPlayer.name,15,fileS);
            fclose(fileS);
        }
        creat = 1;
    }
    int done = 1,NB_plaeyr;
    NB_plaeyr = readTop5(tabTop);
    if(NB_plaeyr!=-1)
        bestScore = tabTop[0].score;
    srand(time(NULL));
    int x = 0,y = 0,val=0;SDL_Event event;
    while (done)
    {
        if(bestScore<tempsPlayer.score)
            bestScore = tempsPlayer.score;
        x = 0;y = 0;val=0;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = 0;
                break;
            case SDL_MOUSEBUTTONDOWN :
            {
                if((event.motion.x>=221)&&(event.motion.x<=306)&&(event.motion.y<=545)&&(event.motion.y>=460))
                {
                    p1 =1;
                }
                else if((event.motion.x>=318)&&(event.motion.x<=403)&&(event.motion.y<=545)&&(event.motion.y>=460))
                {
                    p1=2;
                }
                else if ((event.motion.x>=415)&&(event.motion.x<=500)&&(event.motion.y<=545)&&(event.motion.y>=460))
                {
                    p1=3;
                }
                else if((event.motion.x>=430)&&(event.motion.x<=500)&&(event.motion.y<=105)&&(event.motion.y>=20))
                {
                    int continuep = 1;
                    if(!creat)
                    {
                        if(NB_plaeyr==5)
                        {
                            if(tabTop[4].score<=tempsPlayer.score)
                            {
                                tabTop[4].score = tempsPlayer.score;
                                tabTop[4].date = getDate();
                                strcpy(tabTop[4].name,tempsPlayer.name);
                            }
                        }
                        else if(NB_plaeyr<5)
                        {
                            if(NB_plaeyr==-1)
                            NB_plaeyr = 0;
                            tabTop[NB_plaeyr].score = tempsPlayer.score;
                            tabTop[NB_plaeyr].date = getDate();
                            strcpy(tabTop[NB_plaeyr].name,tempsPlayer.name);
                            NB_plaeyr++;
                        }
                        trierTop(tabTop,NB_plaeyr);
                        savTop(tabTop,NB_plaeyr);
                        creat = 1;
                    }
                    else
                    {
                        for(i=0;i<NB_plaeyr;i++)
                        {
                            if(!strcmp(tabTop[i].name,tempsPlayer.name)&&(tabTop[i].score<=tempsPlayer.score))
                            {
                                tabTop[i].score = tempsPlayer.score;
                                break;
                            }
                        }
                    }
                    trierTop(tabTop,NB_plaeyr);
                    while((continuep)&&(done))
                    {
                        while (SDL_PollEvent(&event))
                        {
                            switch(event.type)
                            {
                                case SDL_QUIT : done = 0;break;
                                case SDL_MOUSEBUTTONUP :
                                {
                                    if((event.motion.x>=300)&&(event.motion.x<=400)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        continuep = 0;
                                    }
                                    else if((event.motion.x>=415)&&(event.motion.x<=500)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        initialiser(carte,&indice1,&indice2,&indice3);tempsPlayer.score = 0;continuep = 0;
                                    }
                                    else if((event.motion.x>=218)&&(event.motion.x<=278)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        sauvegarder(carte,indice1,indice2,indice3,tempsPlayer.score,tempsPlayer.name);continuep = 0;
                                    }
                                    break;
                                }
                            }
                            SDL_BlitSurface(pause,NULL,screen,&dstrect);
                            positionScore.x = 355;positionScore.y = 40;
                            positionBestScore.x = 330;positionBestScore.y = 130;
                            sprintf(temps, "%d", tempsPlayer.score);
                            sprintf(temps2,"%d",bestScore);
                            scoreB = TTF_RenderText_Blended(police2,temps2,couleurNoire);
                            scoreA = TTF_RenderText_Blended(police2, temps , noire);
                            SDL_BlitSurface(scoreA,NULL,screen,&positionScore);
                            SDL_BlitSurface(scoreB,NULL,screen,&positionBestScore);
                            SDL_FreeSurface(scoreA);SDL_FreeSurface(scoreB);
                            positionTop5.x= 215;
                            for(i=0;i<NB_plaeyr;i++)
                            {
                                positionTop5.y = i* 40 + 310 ;
                                sprintf(tempsTop,"%s",tabTop[i].name);
                                top5 = TTF_RenderText_Blended(police3,tempsTop,couleurNoire);
                                SDL_BlitSurface(top5,NULL,screen,&positionTop5);
                                SDL_FreeSurface(top5);
                            }
                            positionTop5.x= 345;
                            for(i=0;i<NB_plaeyr;i++)
                            {
                                positionTop5.y = i* 40 + 310 ;
                                sprintf(tempsTop,"%d",tabTop[i].score);
                                top5 = TTF_RenderText_Blended(police,tempsTop,couleurNoire);
                                SDL_BlitSurface(top5,NULL,screen,&positionTop5);
                                SDL_FreeSurface(top5);
                            }
                            positionTop5.x= 410;
                            for(i=0;i<NB_plaeyr;i++)
                            {
                                positionTop5.y = i* 40 + 310 ;
                                sprintf(tempsTop,"%d/%d/%d",tabTop[i].date.day,tabTop[i].date.month,tabTop[i].date.year);
                                top5 = TTF_RenderText_Blended(police,tempsTop,couleurNoire);
                                SDL_BlitSurface(top5,NULL,screen,&positionTop5);
                                SDL_FreeSurface(top5);
                            }

                            SDL_Flip(screen);
                        }
                    }
                }
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                switch(p1)
                {
                    case 1:
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            if((event.motion.x>=211)&&(event.motion.x<=511)&&(event.motion.y<=429)&&(event.motion.y>=129))
                            {
                                pi = indiceI(event);pj = indiceJ(event);
                                nb_bolc = remplire(carte,pj,pi,indice1);
                                if (nb_bolc)
                                {
                                    do
                                    {
                                        indice1=(rand()%28);
                                    }while(indice1==0);
                                    tempsPlayer.score+=nb_bolc*10;
                                }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            if((event.motion.x>=211)&&(event.motion.x<=511)&&(event.motion.y<=429)&&(event.motion.y>=129))
                            {
                                pi = indiceI(event);pj = indiceJ(event);
                                nb_bolc = remplire(carte,pj,pi,indice2);
                                if(nb_bolc)
                                {
                                    do
                                    {
                                        indice2=(rand()%28);
                                    }while(indice2==0);

                                    tempsPlayer.score+=nb_bolc*10;
                                }
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            if((event.motion.x>=211)&&(event.motion.x<=511)&&(event.motion.y<=429)&&(event.motion.y>=129))
                            {
                                pi = indiceI(event);pj = indiceJ(event);
                                nb_bolc = remplire(carte,pj,pi,indice3);
                                if(nb_bolc!=0)
                                {
                                    do
                                    {
                                        indice3=(rand()%28);
                                    }while(indice3==0);
                                    tempsPlayer.score+=nb_bolc*10;
                                }
                            }
                        }
                        break;
                    }
                }
                p1 = 0;
                break;
            }
            case SDL_MOUSEMOTION:
                {
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        if(p1==1)
                        {
                            val = indice1;
                            if(val==0)
                            {
                                val=16;
                            }
                        }
                        else if(p1==2) val = indice2;
                        else if(p1==3) val = indice3;
                        minBloc(val,&x,&y);
                    }
                    break;
                }

            } // end switch
            SDL_BlitSurface(play, 0, screen, &dstrect);
            positionScore.x = 228;positionScore.y = 73;
            positionBestScore.x = 225;positionBestScore.y = 30;
            positionPlayer.x = 320;positionPlayer.y = 550;
            sprintf(temps, "%d", tempsPlayer.score);
            sprintf(temps2,"%d",bestScore);
            scoreB = TTF_RenderText_Blended(police,temps2,couleurNoire);
            scoreA = TTF_RenderText_Blended(police, temps , noire);
            nPlayer= TTF_RenderText_Blended(police3,tempsPlayer.name,couleurNoire);
            SDL_BlitSurface(nPlayer,NULL,screen,&positionPlayer);
            SDL_BlitSurface(scoreA,NULL,screen,&positionScore);
            SDL_BlitSurface(scoreB,NULL,screen,&positionBestScore);
            SDL_FreeSurface(scoreA);SDL_FreeSurface(scoreB);SDL_FreeSurface(nPlayer);
            for(i=0;i<NB_BLOCS_CARTE;i++)
            {
                for(j=0;j<NB_BLOCS_CARTE;j++)
                {
                    positions.x = i*30 + 211;
                    positions.y = j*30+129;
                    switch(carte[i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve ,NULL,screen,&positions);break;
                        case JAUNE :SDL_BlitSurface(jaune ,NULL,screen,&positions);break;
                        case BLUE  :SDL_BlitSurface(blue  ,NULL,screen,&positions);break;
                        case ROUGE :SDL_BlitSurface(rouge ,NULL,screen,&positions);break;
                        case VERT  :SDL_BlitSurface(vert  ,NULL,screen,&positions);break;
                        case BLUE_C:SDL_BlitSurface(blue_c,NULL,screen,&positions);break;
                    }
                }
            }
            for(i=0;i<NB_BLOCS_PIECE;i++)
            {
                for(j=0;j<NB_BLOCS_PIECE;j++)
                {
                    position1.x = i*TAILLE_BLOC_PETIT+221;position1.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice1][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position1);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position1);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position1);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position1);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position1);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position1);break;
                    }
                    if(place(carte,indice1))
                    {
                        if(piece[indice1][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position1);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                    position2.x = i*TAILLE_BLOC_PETIT+318;position2.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice2][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position2);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position2);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position2);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position2);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position2);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position2);break;
                    }
                    if(place(carte,indice2))
                    {
                        if(piece[indice2][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position2);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                    position3.x = i*TAILLE_BLOC_PETIT+415;position3.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice3][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position3);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position3);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position3);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position3);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position3);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position3);break;
                    }
                    if(place(carte,indice3))
                    {
                        if(piece[indice3][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position3);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                }
            }
            if((val)&&!place(carte,val))
            {
                for(i=0;i<5;i++)
                {
                    for(j=0;j<5;j++)
                    {
                        positions.x = i*30 + event.motion.x - x*30 -10;
                        positions.y =j*30 + event.motion.y - y*30 -10;
                        switch(piece[val][i][j])
                        {
                            case MOUVE :SDL_BlitSurface(mouve,NULL,screen,&positions);break;
                            case JAUNE :SDL_BlitSurface(jaune,NULL,screen,&positions);break;
                            case BLUE :SDL_BlitSurface(blue,NULL,screen,&positions);break;
                            case ROUGE :SDL_BlitSurface(rouge,NULL,screen,&positions);break;
                            case VERT :SDL_BlitSurface(vert,NULL,screen,&positions);break;
                            case BLUE_C :SDL_BlitSurface(blue_c,NULL,screen,&positions);break;
                        }
                    }
                }
            }
        }
        eleminer(carte,&tempsPlayer.score);
        SDL_Flip(screen);
        if((place(carte,indice1))&&(place(carte,indice2))&&(place(carte,indice3)))
        {
            if(!creat)
            {
                if(NB_plaeyr==5)
                {
                    if(tabTop[4].score<=tempsPlayer.score)
                    {
                        tabTop[4].score = tempsPlayer.score;
                        tabTop[4].date = getDate();
                        strcpy(tabTop[4].name,tempsPlayer.name);
                    }
                }
                else if(NB_plaeyr<5)
                {
                    if(NB_plaeyr==-1)
                        NB_plaeyr = 0;
                    tabTop[NB_plaeyr].score = tempsPlayer.score;
                    tabTop[NB_plaeyr].date = getDate();
                    strcpy(tabTop[NB_plaeyr].name,tempsPlayer.name);
                    NB_plaeyr++;
                }

            }
            else
            {
                for(i=NB_plaeyr;i>0;i--)
                {
                    if(!strcmp(tabTop[i].name,tempsPlayer.name)&&(tabTop[i].score<=tempsPlayer.score))
                    {
                        tabTop[i].score = tempsPlayer.score;
                        break;
                    }
                }
            }
            trierTop(tabTop,NB_plaeyr);
            savTop(tabTop,NB_plaeyr);
            initialiser(carte,&indice1,&indice2,&indice3);tempsPlayer.score =0;
            sauvegarder(carte,indice1,indice2,indice3,tempsPlayer.score,tempsPlayer.name);
            int gOver = 1;
            positions.x=211;positions.y=189;
            while(gOver)
            {
                while (SDL_PollEvent(&event))
                {
                    switch(event.type)
                    {
                        case SDL_QUIT :gOver=0;done = 0;
                        case SDL_MOUSEBUTTONUP:
                            if(event.button.button == SDL_BUTTON_LEFT)
                            {
                                if((event.motion.x>=320)&&(event.motion.x<=390)&&(event.motion.y<=350)&&(event.motion.y>=260))
                                {
                                    goto fin ;
                                }
                            }
                            break;
                    }
                    SDL_BlitSurface(gameOver,NULL,screen,&positions);
                    SDL_Flip(screen);
                }
            }
        }
        // finally, update the screen :)
        SDL_Flip(screen);
    }

    sauvegarder(carte,indice1,indice2,indice3,tempsPlayer.score,tempsPlayer.name);
    if(!creat)
    {
        if(NB_plaeyr==5)
        {
            if(tabTop[4].score<=tempsPlayer.score)
            {
                tabTop[4].score = tempsPlayer.score;
                tabTop[4].date = getDate();
                strcpy(tabTop[4].name,tempsPlayer.name);
            }
        }
        else if(NB_plaeyr<5)
        {
            if(NB_plaeyr==-1)
                NB_plaeyr = 0;
            tabTop[NB_plaeyr].score = tempsPlayer.score;
            tabTop[NB_plaeyr].date = getDate();
            strcpy(tabTop[NB_plaeyr].name,tempsPlayer.name);
            NB_plaeyr++;
        }
    }
    else
    {
        for(i=NB_plaeyr;i>0;i--)
        {
            if(!strcmp(tabTop[i].name,tempsPlayer.name)&&(tabTop[i].score<=tempsPlayer.score))
            {
                tabTop[i].score = tempsPlayer.score;
                break;
            }
        }
    }
    trierTop(tabTop,NB_plaeyr);
    savTop(tabTop,NB_plaeyr);
    fin:
    SDL_FreeSurface(pause);
    SDL_FreeSurface(mouve17);SDL_FreeSurface(jaune17);SDL_FreeSurface(rouge17);
    SDL_FreeSurface(blue17);SDL_FreeSurface(blue_c17);SDL_FreeSurface(vert17);
    SDL_FreeSurface(mouve);SDL_FreeSurface(jaune);SDL_FreeSurface(rouge);
    SDL_FreeSurface(blue);SDL_FreeSurface(blue_c);SDL_FreeSurface(vert);
    SDL_FreeSurface(play);SDL_FreeSurface(gameOver);SDL_FreeSurface(edition);
    TTF_CloseFont(police);
    TTF_CloseFont(police2);
    TTF_CloseFont(police3);
    TTF_Quit();
    return ;
}
void playRebot(SDL_Surface* screen)
{
    int carte[NB_BLOCS_CARTE][NB_BLOCS_CARTE];
    int indice1,indice2,indice3,i,j,score = 0;
    char temps[20] = "";
    TTF_Init();
    SDL_Surface *scoreA = NULL,*scoreB = NULL;
    SDL_Surface* play = SDL_LoadBMP("images/playRobot.bmp");
    SDL_Surface* mouve = SDL_LoadBMP("images/mouve.bmp");
    SDL_Surface* mouve17 = SDL_LoadBMP("images/mouve17.bmp");
    SDL_Surface* pause = SDL_LoadBMP("images/pauseVS.bmp");
    SDL_Surface* jaune = SDL_LoadBMP("images/jaune.bmp");
    SDL_Surface* jaune17 = SDL_LoadBMP("images/jaune17.bmp");
    SDL_Surface* rouge = SDL_LoadBMP("images/rouge.bmp");
    SDL_Surface* rouge17 = SDL_LoadBMP("images/rouge17.bmp");
    SDL_Surface* blue = SDL_LoadBMP("images/blue.bmp");
    SDL_Surface* blue17 = SDL_LoadBMP("images/blue17.bmp");
    SDL_Surface* blue_c = SDL_LoadBMP("images/blue_c.bmp");
    SDL_Surface* blue_c17 = SDL_LoadBMP("images/blue_c17.bmp");
    SDL_Surface* vert = SDL_LoadBMP("images/vert.bmp");
    SDL_Surface* vert17 = SDL_LoadBMP("images/vert17.bmp");
    SDL_Surface* trans = SDL_LoadBMP("images/trans.bmp");
    SDL_Surface* gameOver = SDL_LoadBMP("images/over.bmp");
    SDL_Surface* edition = SDL_LoadBMP("images/edition.bmp");
    TTF_Font *police = TTF_OpenFont("arial.ttf",20);
    TTF_Font *police2 = TTF_OpenFont("arial.ttf",30);
    TTF_Font *police3 = TTF_OpenFont("Frozito.ttf",30);
    SDL_Rect dstrect,position1,position2,position3,positions,positionScore,positionBestScore;
    dstrect.x = 0;dstrect.y = 0;
    SDL_Color couleurNoire = {207, 181, 59},noire = {255,255,255};

    initialiser(carte,&indice1,&indice2,&indice3);score  =0;
    int done = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    srand(time(NULL));
    while (done)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:done = 0;break;
            case SDL_MOUSEBUTTONDOWN :
            {
                if((event.motion.x>=430)&&(event.motion.x<=500)&&(event.motion.y<=105)&&(event.motion.y>=20))
                {
                    int continuep = 1;
                    while((continuep)&&(done))
                    {
                        while (SDL_PollEvent(&event))
                        {
                            switch(event.type)
                            {
                                case SDL_QUIT : done = 0;break;
                                case SDL_MOUSEBUTTONUP :
                                {
                                    if((event.motion.x>=300)&&(event.motion.x<=400)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        continuep = 0;
                                    }
                                    else if((event.motion.x>=415)&&(event.motion.x<=500)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        initialiser(carte,&indice1,&indice2,&indice3);score = 0;continuep = 0;
                                    }
                                    else if((event.motion.x>=218)&&(event.motion.x<=278)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        continuep = 0;
                                    }
                                    break;
                                }
                            }
                            SDL_BlitSurface(pause,NULL,screen,&dstrect);
                            positionScore.x = 355;positionScore.y = 40;
                            positionBestScore.x = 240;positionBestScore.y = 40;
                            sprintf(temps, "%d", score);
                            SDL_FreeSurface(scoreA);SDL_FreeSurface(scoreB);
                            scoreB = TTF_RenderText_Blended(police3,"Score ",noire);
                            scoreA = TTF_RenderText_Blended(police2, temps , noire);
                            SDL_BlitSurface(scoreA,NULL,screen,&positionScore);
                            SDL_BlitSurface(scoreB,NULL,screen,&positionBestScore);
                            SDL_Flip(screen);
                        }
                    }
                }
                break;
            }

        } // end switch
        tempsActuel = SDL_GetTicks();
        if ((tempsActuel - tempsPrecedent > 1000)) /* Si 30 ms se sont écoulées */
        {
            remplireRebot(carte,&indice1,&indice2,&indice3,&score);
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(1000 - (tempsActuel - tempsPrecedent));
        }
        SDL_BlitSurface(play, 0, screen, &dstrect);
        positionScore.x = 228;positionScore.y = 53;
        positionBestScore.x = 320;positionBestScore.y = 545;
        sprintf(temps, "%d", score);
        SDL_FreeSurface(scoreA);SDL_FreeSurface(scoreB);
        scoreB = TTF_RenderText_Blended(police3,"Robot",couleurNoire);
        scoreA = TTF_RenderText_Blended(police, temps , noire);
        SDL_BlitSurface(scoreA,NULL,screen,&positionScore);
        SDL_BlitSurface(scoreB,NULL,screen,&positionBestScore);
        for(i=0;i<NB_BLOCS_CARTE;i++)
        {
            for(j=0;j<NB_BLOCS_CARTE;j++)
            {
                positions.x = i*30 + 211;
                positions.y = j*30+129;
                switch(carte[i][j])
                {
                    case MOUVE :SDL_BlitSurface(mouve ,NULL,screen,&positions);break;
                    case JAUNE :SDL_BlitSurface(jaune ,NULL,screen,&positions);break;
                    case BLUE  :SDL_BlitSurface(blue  ,NULL,screen,&positions);break;
                    case ROUGE :SDL_BlitSurface(rouge ,NULL,screen,&positions);break;
                    case VERT  :SDL_BlitSurface(vert  ,NULL,screen,&positions);break;
                    case BLUE_C:SDL_BlitSurface(blue_c,NULL,screen,&positions);break;
                }
            }
        }
        for(i=0;i<NB_BLOCS_PIECE;i++)
        {
            for(j=0;j<NB_BLOCS_PIECE;j++)
            {
                position1.x = i*TAILLE_BLOC_PETIT+221;position1.y = j*TAILLE_BLOC_PETIT+460;
                switch(piece[indice1][i][j])
                {
                    case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position1);break;
                    case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position1);break;
                    case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position1);break;
                    case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position1);break;
                    case VERT :SDL_BlitSurface(vert17,NULL,screen,&position1);break;
                    case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position1);break;
                }
                if(place(carte,indice1))
                {
                    if(piece[indice1][i][j]!=0)
                    {
                        SDL_BlitSurface(trans,NULL,screen,&position1);
                    }
                    SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                }
                position2.x = i*TAILLE_BLOC_PETIT+318;position2.y = j*TAILLE_BLOC_PETIT+460;
                switch(piece[indice2][i][j])
                {
                    case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position2);break;
                    case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position2);break;
                    case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position2);break;
                    case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position2);break;
                    case VERT :SDL_BlitSurface(vert17,NULL,screen,&position2);break;
                    case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position2);break;
                }
                if(place(carte,indice2))
                {
                    if(piece[indice2][i][j]!=0)
                    {
                        SDL_BlitSurface(trans,NULL,screen,&position2);
                    }
                    SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                }
                position3.x = i*TAILLE_BLOC_PETIT+415;position3.y = j*TAILLE_BLOC_PETIT+460;
                switch(piece[indice3][i][j])
                {
                    case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position3);break;
                    case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position3);break;
                    case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position3);break;
                    case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position3);break;
                    case VERT :SDL_BlitSurface(vert17,NULL,screen,&position3);break;
                    case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position3);break;
                }
                if(place(carte,indice3))
                {
                    if(piece[indice3][i][j]!=0)
                    {
                        SDL_BlitSurface(trans,NULL,screen,&position3);
                    }
                    SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                }
            }
        }
        eleminer(carte,&score);
        if((place(carte,indice1))&&(place(carte,indice2))&&(place(carte,indice3)))
        {
            int gOver = 1;
            positions.x=211;positions.y=189;
            while(gOver)
            {
                SDL_PollEvent(&event);
                    switch(event.type)
                    {
                        case SDL_QUIT :gOver=0;done = 0;
                        case SDL_MOUSEBUTTONUP:
                            if(event.button.button == SDL_BUTTON_LEFT)
                            {
                                if((event.motion.x>=320)&&(event.motion.x<=390)&&(event.motion.y<=350)&&(event.motion.y>=260))
                                {
                                    return ;
                                }
                            }
                            break;
                    }
                    SDL_BlitSurface(gameOver,NULL,screen,&positions);
                    SDL_Flip(screen);
            }
        }
        // finally, update the screen :)
        SDL_Flip(screen);
    }
    SDL_FreeSurface(pause);
    SDL_FreeSurface(mouve17);SDL_FreeSurface(jaune17);SDL_FreeSurface(rouge17);
    SDL_FreeSurface(blue17);SDL_FreeSurface(blue_c17);SDL_FreeSurface(vert17);
    SDL_FreeSurface(mouve);SDL_FreeSurface(jaune);SDL_FreeSurface(rouge);
    SDL_FreeSurface(blue);SDL_FreeSurface(blue_c);SDL_FreeSurface(vert);
    SDL_FreeSurface(play);SDL_FreeSurface(gameOver);SDL_FreeSurface(edition);
    SDL_FreeSurface(scoreA);SDL_FreeSurface(scoreB);
    TTF_CloseFont(police);
    TTF_CloseFont(police2);
    TTF_CloseFont(police3);
    TTF_Quit();

    return ;
}
void playVsRebot(SDL_Surface* screen)
{
    int carte[NB_BLOCS_CARTE][NB_BLOCS_CARTE],carteRobot[NB_BLOCS_CARTE][NB_BLOCS_CARTE];
    int indice1,indice2,indice3,i,j,scoreRobot = 0,p1,pi,pj,nb_bolc,score = 0;
    int A,B,C,E,F,G;
    char temps[20] = "",temps2[20] = "",player[25] = "player",temp[1]="";
    TTF_Init();
    SDL_Surface *scoreA = NULL,*scoreB = NULL,*robot = NULL,*nPlayer = NULL;
    SDL_Surface* play = SDL_LoadBMP("images/vsRobot.bmp");
    SDL_Surface* win = SDL_LoadBMP("images/win.bmp");
    SDL_Surface* draw = SDL_LoadBMP("images/draw.bmp");
    SDL_Surface* mouve = SDL_LoadBMP("images/mouve.bmp");
    SDL_Surface* mouve17 = SDL_LoadBMP("images/mouve17.bmp");
    SDL_Surface* pause = SDL_LoadBMP("images/pauseVS.bmp");
    SDL_Surface* jaune = SDL_LoadBMP("images/jaune.bmp");
    SDL_Surface* jaune17 = SDL_LoadBMP("images/jaune17.bmp");
    SDL_Surface* rouge = SDL_LoadBMP("images/rouge.bmp");
    SDL_Surface* rouge17 = SDL_LoadBMP("images/rouge17.bmp");
    SDL_Surface* blue = SDL_LoadBMP("images/blue.bmp");
    SDL_Surface* blue17 = SDL_LoadBMP("images/blue17.bmp");
    SDL_Surface* blue_c = SDL_LoadBMP("images/blue_c.bmp");
    SDL_Surface* blue_c17 = SDL_LoadBMP("images/blue_c17.bmp");
    SDL_Surface* vert = SDL_LoadBMP("images/vert.bmp");
    SDL_Surface* vert17 = SDL_LoadBMP("images/vert17.bmp");
    SDL_Surface* trans = SDL_LoadBMP("images/trans.bmp");
    SDL_Surface* gameOver = SDL_LoadBMP("images/lose.bmp");
    SDL_Surface* edition = SDL_LoadBMP("images/edition.bmp");
    TTF_Font *police = TTF_OpenFont("arial.ttf",20);
    TTF_Font *police2 = TTF_OpenFont("arial.ttf",30);
    TTF_Font *police3 = TTF_OpenFont("Frozito.ttf",30);
    SDL_Rect dstrect,position1,position2,position3,positions,positionScore,positionBestScore,positionPlayer,positionRobot;
    dstrect.x = 0;dstrect.y = 0;
    SDL_Color couleurNoire = {207, 181, 59},noire = {255,255,255},blanc = {0,0,0};

    if(!loadVsRobot(carte,carteRobot,&indice1,&indice2,&indice3,&score,&scoreRobot))
    {
        initialiser(carte,&indice1,&indice2,&indice3);score  =0;
        initialiser(carteRobot,&indice1,&indice2,&indice3);scoreRobot = 0;
    }
    if(carteEstVide(carte)&&carteEstVide(carteRobot))
    {
        int edit = 1,n=0;i=0;char playerName[25] ="";
        while(edit)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT : edit = 0; break;
                    case SDL_MOUSEBUTTONUP:
                        if((event.motion.x>=300)&&(event.motion.x<=400)&&(event.motion.y<=340)&&(event.motion.y>=315))
                        {
                            edit = 0;
                        }
                        break;
                    case SDL_KEYUP:
                        i = 1;
                        if(event.key.keysym.sym==109)
                            event.key.keysym.sym = 59;
                        else if(event.key.keysym.sym==59)
                            event.key.keysym.sym = 109;
                        else if(event.key.keysym.sym==97)
                            event.key.keysym.sym = 113;
                        else if(event.key.keysym.sym==113)
                            event.key.keysym.sym = 97;
                        if((n<15)&&(event.key.keysym.sym!=SDLK_BACKSPACE)&&(((event.key.keysym.sym>= 97) && (event.key.keysym.sym <= 122))||(event.key.keysym.sym==32)))
                        {
                            sprintf(temp,"%c",event.key.keysym.sym);
                            strcat(playerName,temp);n++;playerName[n] = '\0';
                        }
                        if((event.key.keysym.sym==SDLK_BACKSPACE)&&(n>0))
                        {
                            n--;
                            playerName[n] = '\0';
                        }
                        break;
                }
                if(i)
                    strcpy(player,playerName);
                SDL_BlitSurface(play, 0, screen, &dstrect);
                positionPlayer.x =  screen->w/2 -(strlen(player)*15/2);positionPlayer.y = 260;
                positions.x=187;positions.y=178;
                scoreB = TTF_RenderText_Blended(police3,player,blanc);
                SDL_BlitSurface(edition,NULL,screen,&positions);
                SDL_BlitSurface(scoreB,NULL,screen,&positionPlayer);
                SDL_Flip(screen);
                SDL_FreeSurface(scoreB);
            }
        }
    }
    else
    {
        FILE* fileS = NULL;
        fileS = fopen("files/nameP.ys","r");
        if(fileS!=NULL)
        {
            fgets(player,15,fileS);
            fclose(fileS);
        }
    }
    int conRobot = 0,done = 1;
    srand(time(NULL));
    int x = 0,y = 0,val=0,continuep;int gOver = 1;
    SDL_Event event;
    while (done)
    {
        x = 0,y = 0,val=0;
        A=indice1;B=indice2;C=indice3;
        E=indice1;F=indice2;G=indice3;
        while(SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            case SDL_QUIT:
                done = 0;
                break;
            case SDL_MOUSEBUTTONDOWN :
            {
                if((event.motion.x>=410)&&(event.motion.x<=495)&&(event.motion.y<=545)&&(event.motion.y>=460))
                {
                    p1 =1;
                }
                else if((event.motion.x>=507)&&(event.motion.x<=592)&&(event.motion.y<=545)&&(event.motion.y>=460))
                {
                    p1=2;
                }
                else if ((event.motion.x>=604)&&(event.motion.x<=689)&&(event.motion.y<=545)&&(event.motion.y>=460))
                {
                    p1=3;
                }
                else if(((event.motion.x>=619)&&(event.motion.x<=689)&&(event.motion.y<=105)&&(event.motion.y>=20))||((event.motion.x>=250)&&(event.motion.x<=305)&&(event.motion.y<=105)&&(event.motion.y>=20)))
                {
                    continuep = 1;
                    while((continuep)&&(done))
                    {
                        while (SDL_PollEvent(&event))
                        {
                            switch(event.type)
                            {
                                case SDL_QUIT : done = 0;break;
                                case SDL_MOUSEBUTTONUP :
                                {
                                    if((event.motion.x>=300)&&(event.motion.x<=400)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        continuep = 0;
                                    }
                                    else if((event.motion.x>=415)&&(event.motion.x<=500)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        initialiser(carte,&indice1,&indice2,&indice3);score = 0;
                                        initialiser(carteRobot,&indice1,&indice2,&indice3);scoreRobot = 0;
                                        continuep = 0;
                                    }
                                    else if((event.motion.x>=218)&&(event.motion.x<=278)&&(event.motion.y<=266)&&(event.motion.y>=170))
                                    {
                                        saveVsRobot(carte,carteRobot,indice1,indice2,indice3,score,scoreRobot,player);
                                        continuep = 0;
                                    }
                                    break;
                                }
                            }
                            SDL_BlitSurface(pause,NULL,screen,&dstrect);
                            positionScore.x = 355;positionScore.y = 40;
                            positionBestScore.x = 330;positionBestScore.y = 130;
                            sprintf(temps, "%d", scoreRobot);
                            sprintf(temps2,"%d",score);
                            scoreB = TTF_RenderText_Blended(police2,temps2,couleurNoire);
                            scoreA = TTF_RenderText_Blended(police2, temps , noire);
                            SDL_BlitSurface(scoreB,NULL,screen,&positionScore);
                            SDL_BlitSurface(scoreA,NULL,screen,&positionBestScore);
                            positionPlayer.x =230 ;positionPlayer.y =40 ;
                            positionRobot.x = 230; positionRobot.y = 130;
                            nPlayer = TTF_RenderText_Blended(police3,player,noire);
                            robot = TTF_RenderText_Blended(police3,"robot",couleurNoire);
                            SDL_BlitSurface(robot,NULL,screen,&positionRobot);
                            SDL_BlitSurface(nPlayer,NULL,screen,&positionPlayer);
                            SDL_Flip(screen);
                            SDL_FreeSurface(scoreA);SDL_FreeSurface(scoreB);SDL_FreeSurface(nPlayer);SDL_FreeSurface(robot);
                        }
                    }
                }
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                switch(p1)
                {
                    case 1:
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            if((event.motion.x>=395)&&(event.motion.x<=695)&&(event.motion.y<=429)&&(event.motion.y>=129))
                            {
                                pi = indiceI(event);pj = indiceVsRobotJ(event);
                                nb_bolc = remplire(carte,pj,pi,A);
                                if (nb_bolc)
                                {
                                    do
                                    {
                                        A=(rand()%28);
                                    }while(A==0);
                                    score+=nb_bolc*10;
                                    conRobot = 1;
                                }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            if((event.motion.x>=395)&&(event.motion.x<=695)&&(event.motion.y<=429)&&(event.motion.y>=129))
                            {
                                pi = indiceI(event);pj = indiceVsRobotJ(event);
                                nb_bolc = remplire(carte,pj,pi,B);
                                if(nb_bolc)
                                {
                                    do
                                    {
                                        B=(rand()%28);
                                    }while(B==0);

                                    score+=nb_bolc*10;
                                    conRobot = 1;
                                }
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            if((event.motion.x>=395)&&(event.motion.x<=695)&&(event.motion.y<=429)&&(event.motion.y>=129))
                            {
                                pi = indiceI(event);pj = indiceVsRobotJ(event);
                                nb_bolc = remplire(carte,pj,pi,C);
                                if(nb_bolc!=0)
                                {
                                    do
                                    {
                                        C=(rand()%28);
                                    }while(C==0);
                                    score+=nb_bolc*10;
                                    conRobot = 1;
                                }
                            }
                        }
                        break;
                    }
                }
                p1 = 0;
                break;
            }
            case SDL_MOUSEMOTION:
                {
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        if(p1==1)
                        {
                            val = indice1;
                            if(val==0)
                            {
                                val=16;
                            }
                        }
                        else if(p1==2) val = indice2;
                        else if(p1==3) val = indice3;
                        minBloc(val,&x,&y);
                    }
                    break;
                }

            } // end switch
            SDL_BlitSurface(play, 0, screen, &dstrect);
            positionScore.x = 43;positionScore.y = 49;
            positionBestScore.x = 410;positionBestScore.y = 49;
            sprintf(temps, "%d", scoreRobot);
            sprintf(temps2,"%d",score);
            scoreB = TTF_RenderText_Blended(police,temps2,noire);
            scoreA = TTF_RenderText_Blended(police, temps , noire);
            SDL_BlitSurface(scoreA,NULL,screen,&positionScore);
            SDL_BlitSurface(scoreB,NULL,screen,&positionBestScore);
            positionPlayer.x =505 ;positionPlayer.y =540 ;
            positionRobot.x = 140; positionRobot.y = 540;
            nPlayer = TTF_RenderText_Blended(police3,player,couleurNoire);
            robot = TTF_RenderText_Blended(police3,"robot",couleurNoire);
            SDL_BlitSurface(robot,NULL,screen,&positionRobot);
            SDL_BlitSurface(nPlayer,NULL,screen,&positionPlayer);
            SDL_FreeSurface(scoreA);SDL_FreeSurface(scoreB);SDL_FreeSurface(nPlayer);SDL_FreeSurface(robot);
            for(i=0;i<NB_BLOCS_CARTE;i++)
            {
                for(j=0;j<NB_BLOCS_CARTE;j++)
                {
                    positions.x = i*30 + 396;
                    positions.y = j*30+128;
                    switch(carte[i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve ,NULL,screen,&positions);break;
                        case JAUNE :SDL_BlitSurface(jaune ,NULL,screen,&positions);break;
                        case BLUE  :SDL_BlitSurface(blue  ,NULL,screen,&positions);break;
                        case ROUGE :SDL_BlitSurface(rouge ,NULL,screen,&positions);break;
                        case VERT  :SDL_BlitSurface(vert  ,NULL,screen,&positions);break;
                        case BLUE_C:SDL_BlitSurface(blue_c,NULL,screen,&positions);break;
                    }
                    positions.x = i*30 + 22;
                    positions.y = j*30+128;
                    switch(carteRobot[i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve ,NULL,screen,&positions);break;
                        case JAUNE :SDL_BlitSurface(jaune ,NULL,screen,&positions);break;
                        case BLUE  :SDL_BlitSurface(blue  ,NULL,screen,&positions);break;
                        case ROUGE :SDL_BlitSurface(rouge ,NULL,screen,&positions);break;
                        case VERT  :SDL_BlitSurface(vert  ,NULL,screen,&positions);break;
                        case BLUE_C:SDL_BlitSurface(blue_c,NULL,screen,&positions);break;
                    }
                }
            }
            eleminer(carte,&score);
            eleminer(carteRobot,&scoreRobot);
            for(i=0;i<NB_BLOCS_PIECE;i++)
            {
                for(j=0;j<NB_BLOCS_PIECE;j++)
                {
                    position1.x = i*TAILLE_BLOC_PETIT+410;position1.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice1][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position1);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position1);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position1);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position1);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position1);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position1);break;
                    }
                    if(place(carte,indice1))
                    {
                        if(piece[indice1][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position1);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                    position2.x = i*TAILLE_BLOC_PETIT+507;position2.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice2][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position2);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position2);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position2);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position2);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position2);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position2);break;
                    }
                    if(place(carte,indice2))
                    {
                        if(piece[indice2][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position2);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                    position3.x = i*TAILLE_BLOC_PETIT+604;position3.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice3][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position3);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position3);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position3);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position3);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position3);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position3);break;
                    }
                    if(place(carte,indice3))
                    {
                        if(piece[indice3][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position3);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                    position1.x = i*TAILLE_BLOC_PETIT+30;position1.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice1][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position1);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position1);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position1);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position1);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position1);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position1);break;
                    }
                    if(place(carteRobot,indice1))
                    {
                        if(piece[indice1][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position1);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                    position2.x = i*TAILLE_BLOC_PETIT+127;position2.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice2][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position2);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position2);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position2);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position2);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position2);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position2);break;
                    }
                    if(place(carteRobot,indice2))
                    {
                        if(piece[indice2][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position2);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                    position3.x = i*TAILLE_BLOC_PETIT+224;position3.y = j*TAILLE_BLOC_PETIT+460;
                    switch(piece[indice3][i][j])
                    {
                        case MOUVE :SDL_BlitSurface(mouve17,NULL,screen,&position3);break;
                        case JAUNE :SDL_BlitSurface(jaune17,NULL,screen,&position3);break;
                        case BLUE :SDL_BlitSurface(blue17,NULL,screen,&position3);break;
                        case ROUGE :SDL_BlitSurface(rouge17,NULL,screen,&position3);break;
                        case VERT :SDL_BlitSurface(vert17,NULL,screen,&position3);break;
                        case BLUE_C :SDL_BlitSurface(blue_c17,NULL,screen,&position3);break;
                    }
                    if(place(carteRobot,indice3))
                    {
                        if(piece[indice3][i][j]!=0)
                        {
                            SDL_BlitSurface(trans,NULL,screen,&position3);
                        }
                        SDL_SetAlpha(trans,SDL_SRCALPHA,190);
                    }
                }
            }
            if((val)&&!place(carte,val))
            {
                for(i=0;i<5;i++)
                {
                    for(j=0;j<5;j++)
                    {
                        positions.x = i*30 + event.motion.x - x*30 -10;
                        positions.y =j*30 + event.motion.y - y*30 -10;
                        switch(piece[val][i][j])
                        {
                            case MOUVE :SDL_BlitSurface(mouve,NULL,screen,&positions);break;
                            case JAUNE :SDL_BlitSurface(jaune,NULL,screen,&positions);break;
                            case BLUE :SDL_BlitSurface(blue,NULL,screen,&positions);break;
                            case ROUGE :SDL_BlitSurface(rouge,NULL,screen,&positions);break;
                            case VERT :SDL_BlitSurface(vert,NULL,screen,&positions);break;
                            case BLUE_C :SDL_BlitSurface(blue_c,NULL,screen,&positions);break;
                        }
                    }
                }
            }
        }
        SDL_Flip(screen);
        if(((place(carteRobot,indice1))&&(place(carteRobot,indice2))&&(place(carteRobot,indice3)))||((place(carte,indice1))&&(place(carte,indice2))&&(place(carte,indice3))))
        {
            gOver = 1;
            positions.x=211;positions.y=189;
            while(gOver)
            {
                SDL_PollEvent(&event);
                    switch(event.type)
                    {
                        case SDL_QUIT :gOver=0;done = 0;
                        case SDL_MOUSEBUTTONUP:
                            if(event.button.button == SDL_BUTTON_LEFT)
                            {
                                if((event.motion.x>=320)&&(event.motion.x<=390)&&(event.motion.y<=350)&&(event.motion.y>=260))
                                {
                                    gOver =0 ;done =0;
                                }
                            }
                            break;
                    }
                    if(scoreRobot>score)
                        SDL_BlitSurface(gameOver,NULL,screen,&positions);
                    else if(score==scoreRobot)
                        SDL_BlitSurface(draw,NULL,screen,&positions);
                    else
                        SDL_BlitSurface(win,NULL,screen,&positions);
                    SDL_Flip(screen);
            }
        }
        if(conRobot)
        {
                    SDL_Delay(500);
                    remplireRebot(carteRobot,&indice1,&indice2,&indice3,&scoreRobot);
                    if(E!=A)
                        indice1 = A;
                    if(F!=B )
                        indice2 = B;
                    if(G!=C)
                        indice3 = C;
                    conRobot = 0;
        }
        // finally, update the screen :)
        SDL_Flip(screen);
    }
    if(!gOver)
    {
        initialiser(carte,&indice1,&indice2,&indice3);score  =0;
        initialiser(carteRobot,&indice1,&indice2,&indice3);scoreRobot = 0;
    }
    saveVsRobot(carte,carteRobot,indice1,indice2,indice3,score,scoreRobot,player);
    SDL_FreeSurface(pause);
    SDL_FreeSurface(mouve17);SDL_FreeSurface(jaune17);SDL_FreeSurface(rouge17);
    SDL_FreeSurface(blue17);SDL_FreeSurface(blue_c17);SDL_FreeSurface(vert17);
    SDL_FreeSurface(mouve);SDL_FreeSurface(jaune);SDL_FreeSurface(rouge);
    SDL_FreeSurface(blue);SDL_FreeSurface(blue_c);SDL_FreeSurface(vert);
    SDL_FreeSurface(play);SDL_FreeSurface(gameOver);SDL_FreeSurface(edition);
    SDL_FreeSurface(win);SDL_FreeSurface(draw);
    TTF_CloseFont(police);
    TTF_CloseFont(police2);
    TTF_CloseFont(police3);
    TTF_Quit();

    return ;
}
void introduction(SDL_Surface* screen)
{
    SDL_Surface *intro = SDL_LoadBMP("images/introduction.bmp");
    SDL_Rect dstrect; // centre the bitmap on screen
    dstrect.x = 0;dstrect.y = 0;
    int done = 1;
    SDL_Event event;
    while(done)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:done = 0;break;
            case SDL_MOUSEBUTTONUP:
            {
                if((event.motion.x>=600)&&(event.motion.x<=670)&&(event.motion.y<=570)&&(event.motion.y>=505))
                    goto fin ;
                break;
            }
        }
        SDL_BlitSurface(intro, 0, screen, &dstrect);
        SDL_Flip(screen);
    }
    fin:
    SDL_FreeSurface(intro);
    return;
}

#include <SDL/SDL.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include"piles.h"
#include"constantes.h"
void initialiser(int carte[10][10],int *i1,int *i2,int *i3)
{
    int i,j;
    //-------------------- l'intialisation de la carte------------------
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            carte[i][j]=0;
        }
    }
    srand(time(NULL));
    do
    {
        *i1=(rand()%28);
    }while(*i1==0);
    do
    {
        *i2=(rand()%28);
    }while(*i2==0);
    do
    {
        *i3=(rand()%28);
    }while(*i3==0);
}
int indiceI(SDL_Event event)
{
    if((event.motion.y>=130)&&(event.motion.y<160))
        return 0;
    else if((event.motion.y>=160)&&(event.motion.y<190))
        return 1;
    else if((event.motion.y>=190)&&(event.motion.y<220))
        return 2;
    else if((event.motion.y>=220)&&(event.motion.y<250))
        return 3;
    else if((event.motion.y>=250)&&(event.motion.y<280))
        return 4;
    else if((event.motion.y>=280)&&(event.motion.y<310))
        return 5;
    else if((event.motion.y>=310)&&(event.motion.y<340))
        return 6;
    else if((event.motion.y>=340)&&(event.motion.y<370))
        return 7;
    else if((event.motion.y>=370)&&(event.motion.y<400))
        return 8;
    else if((event.motion.y>=400)&&(event.motion.y<430))
        return 9;
    else
        return -1;
}
int indiceJ(SDL_Event event)
{
    if((event.motion.x>=210)&&(event.motion.x<240))
        return 0;
    else if((event.motion.x>=240)&&(event.motion.x<270))
        return 1;
    else if((event.motion.x>=270)&&(event.motion.x<300))
        return 2;
    else if((event.motion.x>=300)&&(event.motion.x<330))
        return 3;
    else if((event.motion.x>=330)&&(event.motion.x<360))
        return 4;
    else if((event.motion.x>=360)&&(event.motion.x<390))
        return 5;
    else if((event.motion.x>=390)&&(event.motion.x<420))
        return 6;
    else if((event.motion.x>=420)&&(event.motion.x<450))
        return 7;
    else if((event.motion.x>=450)&&(event.motion.x<480))
        return 8;
    else if((event.motion.x>=480)&&(event.motion.x<510))
        return 9;
    else
        return -1;
}
int indiceVsRobotJ(SDL_Event event)
{
    if((event.motion.x>=396)&&(event.motion.x<426))
        return 0;
    else if((event.motion.x>=426)&&(event.motion.x<456))
        return 1;
    else if((event.motion.x>=456)&&(event.motion.x<486))
        return 2;
    else if((event.motion.x>=486)&&(event.motion.x<516))
        return 3;
    else if((event.motion.x>=516)&&(event.motion.x<546))
        return 4;
    else if((event.motion.x>=546)&&(event.motion.x<576))
        return 5;
    else if((event.motion.x>=576)&&(event.motion.x<606))
        return 6;
    else if((event.motion.x>=606)&&(event.motion.x<636))
        return 7;
    else if((event.motion.x>=636)&&(event.motion.x<666))
        return 8;
    else if((event.motion.x>=666)&&(event.motion.x<696))
        return 9;
    else
        return -1;
}
void eleminer(int carte[10][10],int *score)
{
    int i,j,charger,charger2,nb = 0;
    pileCh pileI = NULL,pileJ = NULL;

    for(i=0;i<10;i++)
    {
        charger = 1;j=0;
        while((j<10)&&(charger))
        {
            if(carte[i][j]==0)
                charger = 0;
            j++;
        }
        charger2=1;j=0;
        while((j<10)&&(charger2))
        {
            if(carte[j][i]==0)
                charger2 = 0;
            j++;
        }

        if(charger)
        {
                empilerCh(&pileI,i);
            nb++;
        }
        if(charger2)
        {
            empilerCh(&pileJ,i);
            nb++;
        }
    }
    while(pileI!=NULL)
    {
        depilerCh(&pileI,&i);
        for(j=0;j<10;j++)
            carte[i][j]=0;
    }
    while(pileJ!=NULL)
    {
        depilerCh(&pileJ,&i);
        for(j=0;j<10;j++)
            carte[j][i]=0;
    }
    switch(nb)
    {
        case 1: *score+=100;break;
        case 2: *score+=300;break;
        case 3: *score+=600;break;
        case 4: *score+=1000;break;
        case 5: *score+=1500;break;
        case 6: *score+=2100;break;
    }
}
int convert(char ch[100])
{
    int x = 0,i;
    for(i=0;i<strlen(ch);i++)
    {
        switch(ch[i])
        {
            case '0': x = x*10 + 0 ;break;
            case '1': x = x*10 + 1 ;break;
            case '2': x = x*10 + 2 ;break;
            case '3': x = x*10 + 3 ;break;
            case '4': x = x*10 + 4 ;break;
            case '5': x = x*10 + 5 ;break;
            case '6': x = x*10 + 6 ;break;
            case '7': x = x*10 + 7 ;break;
            case '8': x = x*10 + 8 ;break;
            case '9': x = x*10 + 9 ;break;
        }
    }
    return x;
}
void sauvegarder(int carte[10][10],int indiceP1,int indiceP2,int indiceP3,int score,char name[15])
{
    FILE *fichier = NULL,*I1 =NULL,*I2 =NULL,*I3 =NULL,*scoreF =NULL,*fileS = NULL;
    int i = 0, j = 0;
    fichier = fopen("files/niveaux.ys", "w+");
    if (fichier != NULL)
    {
        for (i = 0 ; i < 10 ; i++)
        {
            for (j = 0 ; j < 10 ; j++)
            {
                fprintf(fichier, "%d", carte[j][i]);
            }
        }
        fclose(fichier);
    }
    I1 =fopen("files/indiceP1.ys","w+");
    if (I1 != NULL)
    {
        fprintf(I1, "%d", indiceP1);
        fclose(I1);
    }
    I2 =fopen("files/indiceP2.ys","w+");
    if (I2 != NULL)
    {
        fprintf(I2, "%d", indiceP2);
        fclose(I2);
    }
    I3 =fopen("files/indiceP3.ys","w+");
    if (I3 != NULL)
    {
        fprintf(I3, "%d", indiceP3);
        fclose(I3);
    }
    scoreF = fopen("files/score.ys","w+");
    if(scoreF!=NULL)
    {
        fprintf(scoreF,"%d",score);
        fclose(scoreF);
    }
    fileS = fopen("files/name.ys","w+");
    if(fileS!=NULL)
    {
        fprintf(fileS,"%s",name);
        fclose(fileS);
    }
}
int load(int niveau[][10],int *indiceP1,int *indiceP2,int *indiceP3,int *score)
{
    FILE* fichier = NULL,*I1 =NULL,*I2 =NULL,*I3 =NULL,*scoreF =NULL;
    char ligneFichier[101]="";
    int i = 0, j = 0;
    fichier = fopen("files/niveaux.ys", "r");
    if(fichier!=NULL)
    {
        fgets(ligneFichier,101,fichier);
        for (i = 0 ; i <10 ; i++)
        {
            for (j = 0 ; j < 10 ; j++)
            {
                switch (ligneFichier[(i * 10) + j])
                {
                    case '0':niveau[j][i] = 0;break;
                    case '1':niveau[j][i] = 1;break;
                    case '2':niveau[j][i] = 2;break;
                    case '3':niveau[j][i] = 3;break;
                    case '4':niveau[j][i] = 4;break;
                    case '5':niveau[j][i] = 5;break;
                    case '6':niveau[j][i] = 6;break;
                }
            }
        }
        fclose(fichier);
    }
    else return 0;
    I1 =fopen("files/indiceP1.ys","r");
    if (I1 != NULL)
    {
        fgets(ligneFichier,101,I1);
        *indiceP1 = convert(ligneFichier);
        fclose(I1);
    }
    else return 0;
    I2 =fopen("files/indiceP2.ys","r");
    if (I2 != NULL)
    {
        fgets(ligneFichier,101,I2);
        *indiceP2 = convert(ligneFichier);
        fclose(I2);
    }
    else return 0;
    I3 =fopen("files/indiceP3.ys","r");
    if (I3 != NULL)
    {
        fgets(ligneFichier,101,I3);
        *indiceP3 = convert(ligneFichier);
        fclose(I3);
    }
    else return 0;
    scoreF = fopen("files/score.ys","r");
    if(scoreF!=NULL)
    {
        fgets(ligneFichier,101,scoreF);
        *score = convert(ligneFichier);
        fclose(scoreF);
    }
    else return 0;
    return 1;
}
void copierMatrice(int m[10][10],int t[10][10])
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            t[i][j]=m[i][j];
        }
    }
}
int readTop5(Player t[5])
{
    int i,n;
    char ligneFichier[15];
    FILE *fichier = NULL;
    fichier = fopen("files/Top5.ys","r");
    if (fichier != NULL)
    {
        i=0;
        while(fgets(ligneFichier,15,fichier)!=NULL)
        {
            n = strlen(ligneFichier);
            ligneFichier[n-1] = '\0';
            strcpy(t[i].name,ligneFichier);
            fscanf(fichier,"%d\n",&t[i].score);
            fscanf(fichier,"%d %d %d\n",&t[i].date.day,&t[i].date.month,&t[i].date.year);
            i++;
        }
        fclose(fichier);
    }
    else
        return -1;
    return i;
}
void savTop(Player t[5],int n)
{
    int i;
    FILE *fichier = NULL;
    fichier = fopen("files/Top5.ys","w+");
    if (fichier != NULL)
    {
        for(i=0;i<n;i++)
        {
            fprintf(fichier,"%s\n%d\n%d %d %d\n",t[i].name,t[i].score,t[i].date.day,t[i].date.month,t[i].date.year);
        }
        fclose(fichier);
    }
}
void trierTop(Player t[5],int n)
{
    int i,j;
    Player temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(t[i].score<t[j].score)
            {
                temp.score = t[i].score;temp.date.day = t[i].date.day;temp.date.month = t[i].date.month;temp.date.year = t[i].date.year;
                strcpy(temp.name,t[i].name);
                t[i].score = t[j].score;t[i].date.day = t[j].date.day;t[i].date.month = t[j].date.month;t[i].date.year = t[j].date.year;
                strcpy(t[i].name,t[j].name);
                t[j].score =temp.score ; t[j].date.day = temp.date.day;t[j].date.month= temp.date.month; t[j].date.year=temp.date.year ;
                strcpy(t[j].name,temp.name);
            }
        }
    }
}
Date getDate()
{
    Date d;
    int i;
    time_t rawtime;
    struct tm *info;

    time( &rawtime );

    info = localtime( &rawtime );
    d.day = (*info).tm_mday;
    d.month = (*info).tm_mon+1;
    d.year = (*info).tm_year;
    i = d.year%10;
    d.year=d.year/10;
    d.year = 200+ d.year%10;
    d.year = d.year*10+i;
    return d;
}
int carteEstVide(int carte[10][10])
{
    int i=0,j=0,vid =1;
    while((i<10)&&(vid))
    {
        j = 0;
        while((j<10)&&(vid))
        {
            if(carte[i][j]!=0)
                vid = 0;
            j++;
        }
        i++;
    }
    return vid;
}
void saveVsRobot(int carte[10][10],int cartRobot[10][10],int indiceP1,int indiceP2,int indiceP3,int score,int scoreRobot,char name[15])
{
    FILE *fichier = NULL,*I1 =NULL,*I2 =NULL,*I3 =NULL,*scoreF =NULL,*fileS = NULL,*fichierRobot=NULL,*scoreR= NULL;
    int i = 0, j = 0;
    fichier = fopen("files/niveauxP.ys", "w+");
    if (fichier != NULL)
    {
        for (i = 0 ; i < 10 ; i++)
        {
            for (j = 0 ; j < 10 ; j++)
            {
                fprintf(fichier, "%d", carte[j][i]);
            }
        }
        fclose(fichier);
    }
    fichierRobot = fopen("files/niveauxR.ys", "w+");
    if (fichierRobot != NULL)
    {
        for (i = 0 ; i < 10 ; i++)
        {
            for (j = 0 ; j < 10 ; j++)
            {
                fprintf(fichierRobot, "%d", carte[j][i]);
            }
        }
        fclose(fichierRobot);
    }
    I1 =fopen("files/indiceP1R.ys","w+");
    if (I1 != NULL)
    {
        fprintf(I1, "%d", indiceP1);
        fclose(I1);
    }
    I2 =fopen("files/indiceP2R.ys","w+");
    if (I2 != NULL)
    {
        fprintf(I2, "%d", indiceP2);
        fclose(I2);
    }
    I3 =fopen("files/indiceP3R.ys","w+");
    if (I3 != NULL)
    {
        fprintf(I3, "%d", indiceP3);
        fclose(I3);
    }
    scoreF = fopen("files/scoreP.ys","w+");
    if(scoreF!=NULL)
    {
        fprintf(scoreF,"%d",score);
        fclose(scoreF);
    }
    scoreR = fopen("files/scoreR.ys","w+");
    if(scoreR!=NULL)
    {
        fprintf(scoreR,"%d",score);
        fclose(scoreR);
    }
    fileS = fopen("files/nameP.ys","w+");
    if(fileS!=NULL)
    {
        fprintf(fileS,"%s",name);
        fclose(fileS);
    }
}
int loadVsRobot(int niveau[][10],int carteRobot[10][10],int *indiceP1,int *indiceP2,int *indiceP3,int *score,int *scoreRobot)
{
    FILE* fichier = NULL,*I1 =NULL,*I2 =NULL,*I3 =NULL,*scoreF =NULL,*fichierRobot=NULL,*scoreR= NULL;
    char ligneFichier[101]="";
    int i = 0, j = 0;
    fichier = fopen("files/niveauxP.ys", "r");
    if(fichier!=NULL)
    {
        fgets(ligneFichier,101,fichier);
        for (i = 0 ; i <10 ; i++)
        {
            for (j = 0 ; j < 10 ; j++)
            {
                switch (ligneFichier[(i * 10) + j])
                {
                    case '0':niveau[j][i] = 0;break;
                    case '1':niveau[j][i] = 1;break;
                    case '2':niveau[j][i] = 2;break;
                    case '3':niveau[j][i] = 3;break;
                    case '4':niveau[j][i] = 4;break;
                    case '5':niveau[j][i] = 5;break;
                    case '6':niveau[j][i] = 6;break;
                }
            }
        }
        fclose(fichier);
    }
    else return 0;
    fichierRobot = fopen("files/niveauxP.ys", "r");
    if(fichierRobot!=NULL)
    {
        fgets(ligneFichier,101,fichierRobot);
        for (i = 0 ; i <10 ; i++)
        {
            for (j = 0 ; j < 10 ; j++)
            {
                switch (ligneFichier[(i * 10) + j])
                {
                    case '0':carteRobot[j][i] = 0;break;
                    case '1':carteRobot[j][i] = 1;break;
                    case '2':carteRobot[j][i] = 2;break;
                    case '3':carteRobot[j][i] = 3;break;
                    case '4':carteRobot[j][i] = 4;break;
                    case '5':carteRobot[j][i] = 5;break;
                    case '6':carteRobot[j][i] = 6;break;
                }
            }
        }
        fclose(fichierRobot);
    }
    else return 0;
    I1 =fopen("files/indiceP1R.ys","r");
    if (I1 != NULL)
    {
        fgets(ligneFichier,101,I1);
        *indiceP1 = convert(ligneFichier);
        fclose(I1);
    }
    else return 0;
    I2 =fopen("files/indiceP2R.ys","r");
    if (I2 != NULL)
    {
        fgets(ligneFichier,101,I2);
        *indiceP2 = convert(ligneFichier);
        fclose(I2);
    }
    else return 0;
    I3 =fopen("files/indiceP3R.ys","r");
    if (I3 != NULL)
    {
        fgets(ligneFichier,101,I3);
        *indiceP3 = convert(ligneFichier);
        fclose(I3);
    }
    else return 0;
    scoreF = fopen("files/scoreP.ys","r");
    if(scoreF!=NULL)
    {
        fgets(ligneFichier,101,scoreF);
        *score = convert(ligneFichier);
        fclose(scoreF);
    }
    else return 0;
    scoreR = fopen("files/scoreR.ys","r");
    if(scoreR!=NULL)
    {
        fgets(ligneFichier,101,scoreR);
        *scoreRobot = convert(ligneFichier);
        fclose(scoreR);
    }
    else return 0;
    return 1;
}

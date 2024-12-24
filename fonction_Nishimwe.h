#ifndef  FONCTION_NISHIMWE
#define FONCTION_NISHIMWE
#define MAX 20
#define Long 70
#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<SDL2/SDL.h>
#define Gras "\033[1m"
#define Italic "\033[3m"
#define Blinklw "\033[5m"
#define  Blinkfs "\033[6m" //boucle pour le scintillement
#define Grey "\033[02m"
#define white "\033[01m"
#define rouge "\033[31m"
#define green "\033[32m"
#define jaune "\033[33m"
#define purple "\033[35m"
#define bleu "\033[34m"
#define end "\033[0m"
#define whitebg "\033[47m" //les backgrounds ne s'appliquent pas sur les tabulations
#define blackbg "\033[40m"
#define easytime 900000
#define mediumtime 300000
#define hardtime 150000
typedef struct point{
    int x,y;
}point;
static point p={10,15};//fruit
static point t={10,4};
// Definition de la cellule
struct CelluleNi{
    point valeur;
     struct CelluleNi *suivant;
};
typedef struct CelluleNi CelluleNi;
//Alliage pour obtenir une liste plus facilement manipulable
typedef struct CelluleNi *ListeNi;
static int score=0;
static ListeNi SerpentNi;//corps du serpent
ListeNi Creer();
ListeNi insertTeteNi(ListeNi l,point q);
void afficherNi(char TabNi[][Long]);
void Quadrillage(char TabNi[MAX][Long]);
void  deplacer_droit(char TabNi[][Long],int timeNi);
void echanger(char *c1,char *c2);
void generer(char TabNi[][Long]);
void deplacer_gauche(char TabNi[][Long],int timeNi);
void deplacer_haut(char TabNi[][Long],int  timeNi);
void deplacer_bas(char TabNi[][Long],int timeNi);
void FacileNi(char TabNi[][Long]);
void MoyenNi(char TabNi[][Long]);
void DifficileNi(char TabNi[][Long]);
void initNi();
void LogoNi();
void barre_chargementNi();


#endif
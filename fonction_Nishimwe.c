#include"fonction_Nishimwe.h"

ListeNi Creer(){
    return NULL;
}
void initNi(){

    initscr();
    cbreak();
    noecho();
    curs_set(0);         
    keypad(stdscr, TRUE); 
    nodelay(stdscr, TRUE);  
}
//Les fonctions d'insertion classiques
ListeNi insertTeteNi(ListeNi l,point q){
  //creation de la cellule
    ListeNi cel=malloc(sizeof(CelluleNi));
    cel->valeur.x=q.x;
    cel->valeur.y=q.y;//affection de la valeur a la liste
    cel->suivant=l;
    l=cel;
    return l;
}

void generer(char TabNi[][Long]){
    srand(time(NULL));
    int x1=rand()%MAX;
    int y1=rand()%Long;
    while(TabNi[x1][y1]!=' '){
     x1=rand()%MAX;
     y1=rand()%Long;        
    }
    p.x=x1;
    p.y=y1;
    TabNi[p.x][p.y]='*';
}
void Quadrillage(char TabNi[MAX][Long]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<Long;j++){
            if((i==0 && j<Long)||j==0||(i==MAX-1 && j<Long)||j==Long-1){
                TabNi[i][j]='#';
            }else
            TabNi[i][j]=' ';
        }
    }
    point h ;h.x=t.x; h.y=t.y;
   SerpentNi= insertTeteNi(SerpentNi,h);
   h.y++;
   SerpentNi=insertTeteNi(SerpentNi,h);
   h.y++;
   SerpentNi=insertTeteNi(SerpentNi,h);
   h.y++;
   SerpentNi=insertTeteNi(SerpentNi,h);
    h.y++;
    SerpentNi=insertTeteNi(SerpentNi,h);

    TabNi[p.x][p.y]='*';
    TabNi[t.x][t.y]='*';
    TabNi[t.x][t.y+1]='*';
    TabNi[t.x][t.y+2]='*';
    TabNi[t.x][t.y+3]='*';
    TabNi[t.x][t.y+4]='*';

}

void afficherNi(char TabNi[][Long]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<Long;j++){
            printw("%c",TabNi[i][j]);
        }
        printw("\n");
    }
    refresh();
}
void echanger(char *c1,char *c2){
    char  a;
     a=*c1;
     *c1=*c2;
     *c2=a;
}


void deplacer_droit(char TabNi[][Long],int  timeNi){
    if(TabNi[SerpentNi->valeur.x][SerpentNi->valeur.y+1]=='*'){
        SerpentNi=insertTeteNi(SerpentNi,p);
        score++;
        generer(TabNi);
    }
 
    point k=SerpentNi->valeur,inter;
    ListeNi interNi=SerpentNi->suivant;
    SerpentNi->valeur.y++;
    echanger(&TabNi[k.x][k.y],&TabNi[SerpentNi->valeur.x][SerpentNi->valeur.y]);
    while(interNi->suivant!=NULL){

        echanger(&TabNi[k.x][k.y],&TabNi[interNi->valeur.x][interNi->valeur.y]);
        inter=k;
        k=interNi->valeur;
        interNi->valeur=inter;
        interNi=interNi->suivant; 
         if((interNi->valeur.x==k.x)&& (interNi->valeur.y==k.y)){
            printf(Gras Blinkfs rouge"GAME  OVER !!!!\n");
            printf(Gras bleu "SCORE : %d\n",score);
            exit(0) ;
            }
    }
    echanger(&TabNi[k.x][k.y],&TabNi[interNi->valeur.x][interNi->valeur.y]);
    interNi->valeur=k;
    usleep(timeNi);
    clear();
    afficherNi(TabNi);
    if(SerpentNi->valeur.y==Long-1|| SerpentNi->valeur.y==0){
        printf(Gras Blinkfs rouge"GAME  OVER !!!!\n");
        printf(Gras bleu "SCORE : %d\n",score);
            exit(0) ;
    }
      
    
}

void deplacer_gauche(char TabNi[][Long],int  timeNi){
    if(TabNi[SerpentNi->valeur.x][SerpentNi->valeur.y-1]=='*'){
        SerpentNi=insertTeteNi(SerpentNi,p);
        score++;
        generer(TabNi);
    }
 
    point k=SerpentNi->valeur,inter;
    ListeNi interNi=SerpentNi->suivant;
    SerpentNi->valeur.y--;
    echanger(&TabNi[k.x][k.y],&TabNi[SerpentNi->valeur.x][SerpentNi->valeur.y]);
    while(interNi->suivant!=NULL){

        echanger(&TabNi[k.x][k.y],&TabNi[interNi->valeur.x][interNi->valeur.y]);
        inter=k;
        k=interNi->valeur;
        interNi->valeur=inter;
        interNi=interNi->suivant;
         if((interNi->valeur.x==k.x)&& (interNi->valeur.y==k.y)){
        printf(Gras Blinkfs rouge"GAME  OVER !!!!\n");
        printf(Gras bleu "SCORE : %d\n",score);
            exit(0) ;
         }
    }
    echanger(&TabNi[k.x][k.y],&TabNi[interNi->valeur.x][interNi->valeur.y]);
    interNi->valeur=k;
    usleep(timeNi);
    clear();
    afficherNi(TabNi);
    if(SerpentNi->valeur.y==Long-1|| SerpentNi->valeur.y==0){
        printf(Gras Blinkfs rouge"GAME  OVER !!!!\n");
        printf(Gras bleu "SCORE : %d\n",score);
        exit(0) ;
          
    }    

}


void deplacer_haut(char TabNi[][Long],int  timeNi){
     if(TabNi[SerpentNi->valeur.x-1][SerpentNi->valeur.y]=='*'){
        SerpentNi=insertTeteNi(SerpentNi,p);
        score++;
        generer(TabNi);
    }

    point k=SerpentNi->valeur,inter;
    ListeNi interNi=SerpentNi->suivant;
    SerpentNi->valeur.x--;
    echanger(&TabNi[k.x][k.y],&TabNi[SerpentNi->valeur.x][SerpentNi->valeur.y]);
    while(interNi->suivant!=NULL){

        echanger(&TabNi[k.x][k.y],&TabNi[interNi->valeur.x][interNi->valeur.y]);
        inter=k;
        k=interNi->valeur;
        interNi->valeur=inter;
        interNi=interNi->suivant; 
          if((interNi->valeur.x==k.x)&& (interNi->valeur.y==k.y)){
        printf(Gras Blinkfs rouge"GAME  OVER !!!!\n");
        printf(Gras bleu "SCORE : %d\n",score);
            exit(0) ;
         }  
    }
    echanger(&TabNi[k.x][k.y],&TabNi[interNi->valeur.x][interNi->valeur.y]);
    interNi->valeur=k;
    usleep(timeNi);
    clear();
    afficherNi(TabNi);
    if(SerpentNi->valeur.x==MAX-1|| SerpentNi->valeur.x==0){
        printf(Gras Blinkfs rouge"GAME  OVER !!!!\n");
        printf(Gras bleu "SCORE : %d\n",score);
        exit(0);
          
    }     
}
void deplacer_bas(char TabNi[][Long],int timeNi){
        if(TabNi[SerpentNi->valeur.x+1][SerpentNi->valeur.y]=='*'){
        SerpentNi=insertTeteNi(SerpentNi,p);
        score++;
        generer(TabNi);
    }

    point k=SerpentNi->valeur,inter;
    ListeNi interNi=SerpentNi->suivant;
    SerpentNi->valeur.x++;
    echanger(&TabNi[k.x][k.y],&TabNi[SerpentNi->valeur.x][SerpentNi->valeur.y]);
    while(interNi->suivant!=NULL){

        echanger(&TabNi[k.x][k.y],&TabNi[interNi->valeur.x][interNi->valeur.y]);
        inter=k;
        k=interNi->valeur;
        interNi->valeur=inter;
        interNi=interNi->suivant; 
          if((interNi->valeur.x==k.x)&& (interNi->valeur.y==k.y)){
        printf(Gras Blinkfs rouge"GAME  OVER !!!!\n");
        printf(Gras bleu "SCORE : %d\n",score);
            exit(0) ;
         }  
    }
    echanger(&TabNi[k.x][k.y],&TabNi[interNi->valeur.x][interNi->valeur.y]);
    interNi->valeur=k;
    usleep(timeNi);
    clear();
    afficherNi(TabNi);
    if(SerpentNi->valeur.x==MAX-1|| SerpentNi->valeur.x==0){
        printf(Gras Blinkfs rouge"GAME  OVER !!!!\n");
        printf(Gras bleu "SCORE : %d\n",score);
        exit(0) ;
          
    }  
}
void FacileNi(char TabNi[][Long]){
initNi();
 Quadrillage(TabNi);
 afficherNi(TabNi);
 int ch;         
    int direction = KEY_RIGHT; // Direction initiale (vers la droite)

    while (1) {
 
        printw("SCORE : %d",score);
        ch = getch(); // Récupère la touche pressée
        if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT || ch == KEY_RIGHT) {
            direction = ch;
        }

        // Appelle la fonction de déplacement selon la direction
        switch (direction) {
            case KEY_UP:
                deplacer_haut(TabNi,easytime);
                break;
            case KEY_DOWN:
                deplacer_bas(TabNi,easytime);
                break;
            case KEY_LEFT:
                deplacer_gauche(TabNi,easytime);
                break;
            case KEY_RIGHT:
                
                deplacer_droit(TabNi,easytime);
                break;
        }

    }

}
void MoyenNi(char TabNi[][Long]){

initNi();
Quadrillage(TabNi);
afficherNi(TabNi);
 int ch;         
 int direction = KEY_RIGHT; // Direction initiale (vers la droite)

    while (1) {

         printw("SCORE : %d",score);
        ch = getch(); // Récupère la touche pressée
        if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT || ch == KEY_RIGHT) {
            direction = ch;
        }

        // Appelle la fonction de déplacement selon la direction
        switch (direction) {
            case KEY_UP:
                deplacer_haut(TabNi,mediumtime);
                break;
            case KEY_DOWN:
                deplacer_bas(TabNi,mediumtime);
                break;
            case KEY_LEFT:
                deplacer_gauche(TabNi,mediumtime);
                break;
            case KEY_RIGHT:
                deplacer_droit(TabNi,mediumtime);
                break;
        }

    }

}
void DifficileNi(char TabNi[][Long]){
initNi();
Quadrillage(TabNi);
afficherNi(TabNi);
 int ch;         
    int direction = KEY_RIGHT; // Direction initiale (vers la droite)

    while (1) {
        printw("SCORE : %d",score);
        ch = getch(); // Récupère la touche pressée
        if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT || ch == KEY_RIGHT) {
            direction = ch;
        }

        // Appelle la fonction de déplacement selon la direction
        switch (direction) {
            case KEY_UP:
                deplacer_haut(TabNi,hardtime);
                break;
            case KEY_DOWN:
                deplacer_bas(TabNi,hardtime);
                break;
            case KEY_LEFT:
                deplacer_gauche(TabNi,hardtime);
                break;
            case KEY_RIGHT:
                deplacer_droit(TabNi,hardtime);
                break;
        }

    }
}
//Fonctions d'affichage et d'embellisement
void barre_chargementNi(){
  char chaineNi[400]= Gras bleu "Chargement en cours["end;
     for(int i=0;i<6;i++){
        if(i==5){
            strcat(chaineNi,Gras bleu"]"end );
        }else{
            strcat(chaineNi,whitebg"  "end" ");
        }

       printf(Gras rouge "\t\t\t"Blinklw" BIENVENUE "end"\n\n\n");
       printf("\n");
       printf("%s",chaineNi);
       printf("\n");
       sleep(1);
       system("clear");
        fflush(stdout);//Vider le tampon(permet l'affichage sur le terminale)
     }
     printf("\n");

}
void LogoNi(){
    printf(Gras whitebg"\t\t\t                                "end"\n");
    printf("\t\t\t\t"Gras purple"  SNAKE   GAME  "end"\n");
    printf(Gras whitebg"\t\t\t                                "end"\n");
}
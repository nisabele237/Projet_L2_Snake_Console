#include"fonction_Nishimwe.h"
int main(){
    // Initialisation du plateau
    char TabNi[MAX][Long];

system("clear");
barre_chargementNi();
system("clear");
 int choix;
do{
LAHAUT:
LogoNi(); 
printf("\n\n\n");
printf("\t\t\t\t"Italic bleu"    MENU"end"\n");
printf("\n\n\n");
printf(Gras white "\t\t1. JOUER\n\t\t2. REGLE DU JEU ET DESCRIPTION\n\t\t3. QUITTER\n\n");
printf("\t\t CHOIX :  ");
scanf("%d",&choix);
system("clear");
switch(choix){
    case 1:
    LogoNi();
    printf( Gras bleu "\n NB:Servez vous des touches directionnelles!"end"\n");
    printf(Gras white"\n\n\t\t1. NIVEAU  FACILE\n\t\t2. NIVEAU MOYEN\n\t\t3. NIVEAU DIFFICILE\n\t\t4.MENU\n");
    printf("\t\t CHOIX :  "end);
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        system("clear");

        FacileNi(TabNi);      
        break;
    case 2:
        system("clear");
        MoyenNi(TabNi);
        break;
    case 3:
        system("clear");
        DifficileNi(TabNi);
        break;    
    case 4:
     printf(whitebg jaune"\n\t\tRedirection"end"\n");
     sleep(1);
     system("clear");
     goto LAHAUT;
    default:
        printf(Gras"Choix indisponible""\n"end);
        break;
    }

        break;

    case 2:
        system("clear");
        LogoNi();
         FILE *fichier=fopen("readme.txt","r");
        if(fichier==NULL){
            printf("ERREUR,le fichier est introuvable\n");
            return 0;
        }else{
        char carac[100];
       while(fgets(carac,sizeof(carac),fichier)!=NULL){
        printf("%s",carac);
           }  
        }       
        printf(green"\n\t\tBonne Chance!"end"\n");
        printf("Appuyez sur la touche Entrée pour retourner au Menu\n");
            getchar();
            while(getchar()!='\n');

            system("clear");
        break;
    case 3:
        system("clear");
        printf("À BIENTOT!!\n\n");
        break;
    default:
    system("clear");
    printf("Veuillez reeffectuer votre choix");
   
}
}while(choix!=3);
  
    // Fin de ncurses
    endwin();
    return 0;
}
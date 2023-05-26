#include "header.h"

const char *symbole_cache[TAILLE_ROWS][TAILLE_COLS];
const char *symbole_case[TAILLE_ROWS][TAILLE_COLS];

enum Type_Case plateau_cache[TAILLE_ROWS][TAILLE_COLS]; // remplacer 18 par la taille de Symnole_case
enum Type_Case plateau_ouvert[TAILLE_ROWS][TAILLE_COLS];
                         



void set_init(void)
{
  for (int r = 0; r < TAILLE_PLATEAU; r++)
  {
    for (int c = 0; c < TAILLE_PLATEAU; c++)
    {
      symbole_cache[r][c] = Symbole_case_init[VIDE_MAP];
      symbole_case[r][c] = Symbole_case_init[VIDE_MAP];
      plateau_cache[r][c] = VIDE_MAP;
      plateau_ouvert[r][c] = VIDE_MAP;
      
    }
  }
  return; 
}


void initialize_set_cache(Joueur *joueur)
{
  system("clear");
  // Top rows
  for (int c = 0; c < TAILLE_COLS; c++)
  {
    if (c == TAILLE_COLS - 3)
    {
     printf(" %ls ",Guerrier);//joueur[1].symbole_affecte); // Joueur 2
    } 
    else
    {
      if (c < TAILLE_COLS)
      {
        printf(" - ");
        printf(" ");
      }
    }
  }
  printf("\n");
 
  
  
  // Central matrix 5x5 + les joueurs 1 et 3 dans la 1ere et derniere colonne

  
  for (int r=1; r < TAILLE_ROWS - 1; r++)
  {
    for (int c=0; c < TAILLE_COLS ; c++)
    {
        symbole_cache[r][c] = Symbole_case_init[CASE_CACHE];
        
        if ( c == 0 || c == 6 )
        {
          if ( (c == 0 && r == 2) || (c == 6 && r == 4) )
          {
            if (c == 0)
            {
              printf(" %ls ",joueur[0].symbole_affecte); //Joueur 1
            } 
            else
            {
              printf(" %ls ",joueur[2].symbole_affecte); //Joueur 3 
            }
          } 
          else
          {
            printf(" - "); 
          }
        } 
        else
        {
      	   printf(" %s ", symbole_cache[r][c]); 
        }
        if (c < TAILLE_COLS - 1)
        {
          printf("|");  
        }       
    }
    printf("\n");
  }
  // Bottom row
  for (int c = 0; c < TAILLE_COLS ; c++)
  {
    if (c == 2)
    {
      printf(" %ls ",joueur[3].symbole_affecte); // Joueur 4
    } 
    else
    {
      if (c < TAILLE_COLS)
      {
        printf(" - ");
        printf(" ");
      }
    }
  }
  printf("\n");
}

void print_set_cache(void)
{
  system("clear");
  initialize_set_cache(joueur);
}



int my_rand(void){
  int n = (rand() % 11) + 3;  
  return n;
}


void set_board()
{
  int numero_case;
  enum Type_Case tab[SIZE];
  for (int r=0; r < TAILLE_PLATEAU ; r++)
  {
    for (int c = 0; c < TAILLE_PLATEAU ; c++)
    {

      // COMPTEUR NOMBRE MONSTRE (16)/ ARME ANTI (1 de chaque)etc... 
      numero_case = my_rand();
      symbole_case[r][c] = Symbole_case_init[numero_case];
      plateau_cache[r][c] = CASE_CACHE;
      
      plateau_ouvert[r][c] = tab[numero_case];
      
    	//printf(" %s |", symbole_case[r][c]);
      // printf(" %d |", plateau_cache[r][c]);
      // printf(" %d |", plateau_ouvert[r][c] = tab[numero_case]);
      
    }
  }
}







void detruire_Plateau(Plateau* Plateau) {
    // Libérer la mémoire allouée pour le tableau 2D
    free(Plateau);
}





// PSEUDO ET CLASSE JOUEURS
void debut_partie(Joueur * joueurs, int nbJoueurs) {
    char aventuriersNoms[4][10] = {"Guerrier", "Ranger", "Magicien", "Voleur"};
    bool aventuriersDisponibles[4] = {true, true, true, true};

    for (int i = 0; i < nbJoueurs; i++) {
        printf("\nJoueur %d\n", i + 1);

        // Demander le pseudo du joueur
        printf("Choisissez un Pseudo : ");
        scanf("%s", joueur[i].pseudo);

        // Demander le choix de l'aventurier
        printf("\nChoisissez maintenant un aventurier :\n");
        for (int j = 0; j < 4; j++) {
            if (aventuriersDisponibles[j]) {
                printf("%d. %s\n", j + 1, aventuriersNoms[j]);
            }
        }

        int choix,chx;
        scanf("%d", &choix);

        while (choix < 1 || choix > 4 || !aventuriersDisponibles[choix - 1]) {
            printf("\nChoix invalide. Veuillez choisir à nouveau :\n");
            scanf("%d", &choix);
        }
        chx = choix - 1;
        joueurs[i].aventurier = (enum Type_Aventurier) (chx);
        switch(chx)
        {
          case 0 :
          joueurs[i].symbole_affecte = Guerrier;
          break;
          
          case 1 :
          joueurs[i].symbole_affecte = Ranger;
          break;
          case 2 :
          joueurs[i].symbole_affecte = Magicien;
          break;
          case 3 :
          joueurs[i].symbole_affecte = Voleur;
          break;
          
        }        
        // printf("%ls\n",Guerrier);
        // printf("%ls\n",Ranger);
        // printf("%ls\n",Magicien);
        // printf("%ls\n",Voleur);
        //printf(" %d = valeur aventurier = %ls", joueurs[i].aventurier, joueurs[i].symbole_affecte);
        aventuriersDisponibles[choix - 1] = false;

        printf("\n");
    }
}


// Tour du joueur

// CHOIX DE L'ARME
void ChoixArme (Joueur joueur) {
    
    printf("\nChoisissez une arme : \n");
    printf("1. Torche\n");
    printf("2. Bouclier\n");
    printf("3. Hache\n");
    printf("4. Arc\n");
    
    int choixArme;
    scanf("%d", &choixArme);
    
    switch (choixArme) {
        case 1:
            joueur.Arme_Tour = Arme_Tour_TORCHE;
            break;
        case 2:
            joueur.Arme_Tour = Arme_Tour_BOUCLIER;
            break;
        case 3:
            joueur.Arme_Tour =  Arme_Tour_HACHE;
            break;
        case 4:
            joueur.Arme_Tour = Arme_Tour_ARC;
            break;
        default:
            printf("Choix invalide.\n");
            
    }
  return;
}




// INSTRUCTION DEPLACEMENT UTILISATEUR
 void demander_deplacement(Joueur* joueur) {
   //J'ai modif para (Joueur joueur[]) -----> (Joueur* joueur)

  int x_actuel, case_haut_x, case_droite_x, case_gauche_x, case_bas_x;
  int y_actuel, case_haut_y, case_droite_y, case_gauche_y, case_bas_y;
  
  x_actuel = joueur->x;
  y_actuel = joueur->y;

  case_haut_x = x_actuel - 1;
  case_haut_y = y_actuel ;
  case_droite_x = x_actuel ;
  case_droite_y = y_actuel + 1;
  case_gauche_x = x_actuel;
  case_gauche_y = y_actuel - 1 ;
  case_bas_x = x_actuel + 1;
  case_bas_y = y_actuel;


  // if ((symbole_id[case_haut_x][case_haut_y] != CASE_CACHE ) && (symbole_id[case_droite_x][case_droite_y] != CASE_CACHE ) 
  //   && (symbole_id[case_gauche_x][case_gauche_y] != CASE_CACHE ) && (symbole_id[case_bas_x][case_bas_y] != CASE_CACHE ) )
  // {
  //   printf("Le joueur est bloqué, son tour est donc fini. \n" );
  //   joueur->joueur_mort = 1;
  //   // changer de tour joueur
  // }


   
  char input; 
  int valid_input = 0;
  
  while (!valid_input) {

    printf(" Choisissez un déplacement : \n");
    printf("z = haut \nq = gauche \ns = bas \nd = droite \n ");
    scanf(" %c", &input);
    
  switch (input) {
    case 'z':
      
      if (plateau_cache[case_haut_x][case_haut_y] != CASE_CACHE) // SI JOUEUR APPUIE SUR Z MAIS NOUVELLE CASE = DEJA RETOURNER)
      {
        printf ("mouvement illicite\n\n");
        printf("Veuilez saisir une nouvelle direction\n");
        valid_input = 1;
        demander_deplacement(joueur);
      }
      else
      {
        joueur->x--;
        print_set_cache();
        
        valid_input = 0;
      }
    break;
    
    case 'q':
      
      if (plateau_cache[case_gauche_x][case_gauche_y] != CASE_CACHE)// ADD SI JOUEUR APPUIE SUR Q MAIS NOUVELLE CASE = DEJA RETOURNER)
      {
        printf ("mouvement illicite\n\n");
        printf("Veuilez saisir une nouvelle direction\n");
        valid_input = 1;
        demander_deplacement(joueur);
      }
      else
      {
        joueur->y--;
        print_set_cache();
        
        valid_input = 0;
      }
    
    break;
    
    case 's':
      
      if ((plateau_cache[case_bas_x][case_bas_y] != CASE_CACHE))// ADD SI JOUEUR APPUIE SUR S MAIS NOUVELLE CASE = DEJA RETOURNER)
      {
        printf ("mouvement illicite\n\n");
        printf("Veuilez saisir une nouvelle direction\n");
        valid_input = 1;
        demander_deplacement(joueur);
      }
      else
      {
        joueur->x++;
        print_set_cache();
        
        valid_input = 0;
      }
    break;
    
    case 'd' :

      if ((plateau_cache[case_droite_x][case_droite_y] != CASE_CACHE))// ADD SI JOUEUR APPUIE SUR D MAIS NOUVELLE CASE = DEJA RETOURNER)
      {
        printf ("mouvement illicite\n\n");
        printf("Veuilez saisir une nouvelle direction\n");
        valid_input = 1;
        demander_deplacement(joueur);
      }
      else
      {
        joueur->y++;
        print_set_cache();
        
        valid_input = 0;
      }  
    break;
    
    default :
      printf("commande invalide\n\n");
      valid_input=1;
        }
      }

 }








//FONCTION DE DUEL
  

  
  void rencontre_ZOMBIE(Joueur* joueur){
        if ((joueur->Arme_Tour == Arme_Tour_TORCHE)  &&  symbole_case[joueur->x][joueur->y] == Symbole_case_init[ZOMBIE]){
        printf("Bien joué aventurier , tu as vaincu ce zombie, tu peux avancer");
        }
      else{
        joueur->joueur_mort=1;
        printf("Malheuresement pour toi aventurier, ce zombie aura eu raison de toi. Venges toi au prochain tour \n\n");
            }
  }

  void rencontre_TROLLS(Joueur* joueur){
      if (( joueur->Arme_Tour == Arme_Tour_BOUCLIER   &&  symbole_case[joueur->x][joueur->y] == Symbole_case_init[TROLLS])){
       printf("Bien joué aventurier , tu as vaincu ce troll, tu peux avancer");
      }
      else{
        joueur->joueur_mort=1;
         printf("Malheuresement pour toi aventurier, ce troll aura eu raison de toi. Venges toi au prochain tour \n\n");
         }
  }
    

  void  rencontre_HARPIE(Joueur* joueur){
      if ((joueur->Arme_Tour ==  Arme_Tour_HACHE)   &&  symbole_case[joueur->x][joueur->y] == Symbole_case_init[HARPIE] ){
       printf("Bien joué aventurier , tu as vaincu cette harpie, tu peux avancer");
  }
        else{
        joueur->joueur_mort=1;
         printf("Malheuresement pour toi aventurier, cette harpie aura eu raison de toi. Venges toi au prochain tour \n\n");
      }
  }
        
    

  void rencontre_BASILIC(Joueur* joueur)
      {
          
        if ((joueur->Arme_Tour == Arme_Tour_ARC)  &&  symbole_case[joueur->x][joueur->y] == Symbole_case_init[BASILIC]){
          printf("Bien joué aventurier , tu as vaincu ce basilique, tu peux avancer");
        }
        else{
          joueur->joueur_mort=1;
          printf("Malheuresement pour toi aventurier, ce basilique aura eu raison de toi. Venges toi au prochain tour \n\n");
        }
      }




//rencontre_TOTEM ____________________TO DO___________________ 

        



void rencontre_TOTEM (int nbJoueurs, Joueur* joueur ){
  printf(" Tu as trouvé un Totem de transmutation \n change le totem de place avec l'une des case face cachée:\n");
        		printf("Coordonné en x de la case: \n");
        		int quick_x;
        		scanf("%d", &quick_x);
        		quick_x--;
        		printf("Coordonné en y de la case: \n");  
        		int quick_y;
        		scanf("%d", &quick_y );
        		quick_y--;
            
            switch(nbJoueurs){
  	           case 2:
  		            while((quick_x == 3 && quick_y == 0) || (quick_x == 0 && quick_y == 1) || (quick_x<1 || quick_x>5) || (quick_y<1 || quick_y>5)){
  			             printf("C'est le spawn d'un joueur ! \n Soit sympa et change les coordonnée de la transmutation . \n\n");
  			             printf("Coordonné en x de la case: \n");
        		         scanf("%d", &quick_x);
        		         quick_x--;
        		         printf("Coordonné en y de la case: \n");
        		         scanf("%d", &quick_y);
        		         quick_y--;
        	         }
  		            
                 break;
  	           case 3:
  		            while((quick_x == 3 && quick_y == 0) || (quick_x == 0 && quick_y == 1) || (quick_x == 4 && quick_y == 3) || (quick_x<1 || quick_x>5) || (quick_y<1 || quick_y>5)){
  			              printf("C'est le spawn d'un joueur ! \n Soit sympa et change les coordonnée de la transmutation . \n\n");
  			              printf("Coordonné en x de la case: \n");
        		          scanf("%d", &quick_x);
        		          quick_x--;
        		          printf("Coordonné en y de la case: \n");
        		          scanf("%d", &quick_y);
        		          quick_y--;
        	        }
  		            break;
  	           case 4:
  		            while((quick_x == 3 && quick_y == 0) || (quick_x == 0 && quick_y == 1) || (quick_x == 4 && quick_y == 3) || (quick_x == 1 && quick_y == 4) || (quick_x<1 || quick_x>5) || (quick_y<1 || quick_y>5)){
  			              printf("C'est le spawn d'un joueur ! \n Soit sympa et change les coordonnée de la transmutation . \n\n");
  			              printf("Coordonné en x de la case: \n");
        		          scanf("%d", &quick_x);
        		          quick_x--;
        		          printf("Coordonné en y de la case: \n");
        		          scanf("%d", &quick_y);
        		          quick_y--;
        	         }
  		            break;
  	           default:
  		            break;
  	            }

}


          

//rencontre_COFFRE _______________________________________ 

void rencontre_COFFRE(Joueur* joueur){
  if ((joueur->a_trouve_coffre == 0 )  &&  (joueur->a_trouve_antique == 0)){
    printf("Félicitation aventurier!! vous avez trouver un coffre au tresor.\n");
    printf("Il vous reste désormais à trouver votre arme antique, courage !\n\n");
    joueur->a_trouve_coffre++;
  }
  else if ((joueur->a_trouve_coffre == 1)  &&  (joueur->a_trouve_antique == 0)){
    printf("Malheuresement pour toi aventurier, tu as déja trouvé un coffre...\n");
    printf("Ne perds pas espoir et trouve ton arme antique, la victoire est proche !\n");
  }
  else if ((joueur->a_trouve_coffre == 0)  &&  (joueur->a_trouve_antique == 1)){
    printf("tu as trouvé ton coffre manquant !\n");
    joueur->a_trouve_coffre++;
    joueur->joueur_win++;
  }
}




//rencontre_ANTIQUE_EPEE _______________________________________ 

void rencontre_ANTIQUE_EPEE(Joueur* joueur){
    if ((joueur->a_trouve_coffre == 0 )   &&  (joueur->aventurier == GUERRIER)){
    printf("Bravo guerrier, vous avez trouvé votre épée de feu !\n");
    printf("Il vous reste maintenant à trouver un coffre aux trésors!!\n\n");
    joueur->a_trouve_antique++;
  }
  else if (((joueur->a_trouve_coffre == 0)||(joueur->a_trouve_coffre == 1))   &&  (joueur->aventurier != GUERRIER)){
    printf("Malheuresement pour vous aventurier, mais ce n'est pas votre arme antique (EPEE)...\n\n");
  }
  else if ((joueur->a_trouve_coffre == 1 )   &&  (joueur->aventurier == GUERRIER)){
    printf("Bravo, vous avez trouvé votre épée de feu guerrier\n\n");
    joueur->a_trouve_antique++;
    joueur->joueur_win++;
  }
}




//rencontre_ANTIQUE_BATON _______________________________________



void rencontre_ANTIQUE_BATON(Joueur* joueur){
    if ((joueur->a_trouve_coffre == 0 )   &&  (joueur->aventurier == RANGER)){
    printf("Bravo ranger, vous avez trouvé votre baton de contrôle !\n");
    printf("Il vous reste maintenant à trouver un coffre aux trésors!!\n\n");
    joueur->a_trouve_antique++;
  }
  else if (((joueur->a_trouve_coffre == 0)||(joueur->a_trouve_coffre == 1))   &&  (joueur->aventurier != RANGER)){
    printf("Malheuresement pour vous aventurier, mais ce n'est pas votre arme antique (BATON)...\n\n");
  }
  else if ((joueur->a_trouve_coffre == 1 )   &&  (joueur->aventurier == RANGER)){
    printf("Bravo, vous avez trouvé votre baton de contrôle ranger\n\n");
    joueur->a_trouve_antique++;
    joueur->joueur_win++;
  }
}


//rencontre_ ANTIQUE_GRIMOIRE _______________________________________


void rencontre_ANTIQUE_GRIMOIRE(Joueur* joueur){
      if ((joueur->a_trouve_coffre == 0 )   &&  (joueur->aventurier == MAGICIEN)){
    printf("Bravo magicien, vous avez trouvé votre grimoir interdit !\n");
    printf("Il vous reste maintenant à trouver un coffre aux trésors!!\n\n");
    joueur->a_trouve_antique++;
  }
  else if (((joueur->a_trouve_coffre == 0)||(joueur->a_trouve_coffre == 1))   &&  (joueur->aventurier != MAGICIEN)){
    printf("Malheuresement pour vous aventurier, mais ce n'est pas votre arme antique (GRIM)...\n\n");
  }
  else if ((joueur->a_trouve_coffre == 1 )   &&  (joueur->aventurier == MAGICIEN)){
    printf("Bravo, vous avez trouvé votre grimoir interdit magicien\n\n");
    joueur->a_trouve_antique++;
    joueur->joueur_win++;
  }
}



//rencontre_ANTIQUE_DAGUE-------------------------------------

void rencontre_ANTIQUE_DAGUE(Joueur* joueur){
        if ((joueur->a_trouve_coffre == 0 )   &&  (joueur->aventurier == VOLEUR)){
    printf("Bravo voleur, vous avez trouvé votre dague de sommeil !\n");
    printf("Il vous reste maintenant à trouver un coffre aux trésors!!\n\n");
    joueur->a_trouve_antique++;
  }
  else if (((joueur->a_trouve_coffre == 0)||(joueur->a_trouve_coffre == 1))   &&  (joueur->aventurier != VOLEUR)){
    printf("Malheuresement pour vous aventurier, mais ce n'est pas votre arme antique (DAGUE)...\n\n");
  }
  else if ((joueur->a_trouve_coffre == 1 )   &&  (joueur->aventurier == VOLEUR)){
    printf("Bravo, vous avez trouvé votre dague de sommeil voleur\n\n");
    joueur->a_trouve_antique++;
    joueur->joueur_win++;
  }
}




//RENCONTRE TELEPORTEUR  _______________________________________  


void rencontre_TELEPORTEUR(Joueur* joueur){
  int ligne, colonne;
    while ((joueur->x<1)|| (joueur->x>5) || (joueur->y<1) || (joueur->y>5) ){
        printf("Choisissez la ligne de destination du téléporteur (1-%d) : ", TAILLE_PLATEAU-1);
        scanf("%d", &ligne);
        printf("Choisissez la colonne de destination du téléporteur (1-%d) : ", TAILLE_PLATEAU-1);
        scanf("%d", &colonne);

    joueur->x = ligne;
    joueur->y = colonne;
      
    }
    
        //Attention, il reste a verifier si la case de teleportation est bien face cache, 
        //et qu'il rempli bien des nombres entre 0 et 4
}
        








// REGROUPEMENT DES EVENTUALITE

void rencontre_case(Joueur *joueur, int nbJoueurs, enum Type_Case plateau_ouvert[TAILLE_ROWS][TAILLE_COLS], enum Type_Case plateau_hidden[TAILLE_ROWS][TAILLE_COLS], const char *tab_elem_ouvert[TAILLE_ROWS][TAILLE_COLS], const char *tab_elem_hidden[TAILLE_ROWS][TAILLE_COLS])
{
  switch(plateau_cache[joueur->x][joueur->y])// paramètre à definir plateau 2D d'element
    {
      case HARPIE :
      rencontre_HARPIE(joueur);
      break;

      case BASILIC :
      rencontre_BASILIC(joueur);
      break;

      case TROLLS :
      rencontre_TROLLS(joueur);
      break;

      case ZOMBIE :
      rencontre_ZOMBIE(joueur);
      break;

      case TELEPORTEUR :
      rencontre_TELEPORTEUR(joueur);
      break;

      case TOTEM :
      rencontre_TOTEM(nbJoueurs, joueur);
      break;

      case COFFRE :
      rencontre_COFFRE(joueur);
      break;
      
      case ANTIQUE_EPEE :
      rencontre_ANTIQUE_EPEE(joueur);
      break;
      
      case ANTIQUE_BATON :
      rencontre_ANTIQUE_BATON(joueur);
      break;
      
      case ANTIQUE_GRIMOIRE :
      rencontre_ANTIQUE_GRIMOIRE(joueur);
      break;
      
      case ANTIQUE_DAGUE :
      rencontre_ANTIQUE_DAGUE(joueur);
      break;

      default:
        break;
        
    }
}


void victoire(char a[])
{
  printf("----------------FELICITATION, %s  a gagné la partie !----------------------",a);
  
  
}
    





// Boucle principale du jeu:  

    // Creer boucle while pas de gagnant
    
    // Appeler Joueur x

    // Créer boucle while 

          // Demander Arme

          // Print plateau cache

          // demander deplacement

          // Logique du jeu

                // Deplacer image joueur si WIN, sinon joueur suivant

// Joueur *joueur, int nbJoueurs, enum Type_Case plateau_ouvert[TAILLE_ROWS][TAILLE_COLS], enum Type_Case plateau_hidden[TAILLE_ROWS][TAILLE_COLS], const char *tab_elem_ouvert[TAILLE_ROWS][TAILLE_COLS], const char *tab_elem_hidden[TAILLE_ROWS][TAILLE_COLS]
void Tour_joueur( )
    {
      for (int i = 0; i < NB_JOUEURS_MAX; i++) 
      {
      printf("\n-----------Tour du joueur %d------------\n\n\n", i + 1);

      printf("C'est à %s de jouer\n", joueur[i].pseudo);

        while ((joueur[i].joueur_mort == 0) || (joueur[i].joueur_win == 0))
        {
    
          // Demander quelle arme à utiliser
          ChoixArme (joueur[i]);
          
          print_set_cache(); //Affichage tableau
    
          // point de départ pour tous

          
          switch(i)
          {
            case 0 :
              joueur[i].x = 2;
              joueur[i].y = 0;
              break;
           case 1 :
              joueur[i].x = 0;
              joueur[i].y = 4;
              break;
           case 2 :
              joueur[i].x = 4;
              joueur[i].y = 6;
              break;
           case 3 :
              joueur[i].x = 6;
              joueur[i].y = 2;
              break;
           
          }
            
          demander_deplacement(&joueur[i]);

// print Map mise à jour
          
          // rencontre_case(&joueur[i]);

          if(joueur[i].joueur_win == 1)
          {
            victoire(joueur->pseudo); // A faire
          }
          else 
          {
          continue;
          }
          
          
          
        }
       
      } 
    }


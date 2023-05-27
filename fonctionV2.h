#include "header.h"

const char *symbol_cache = "▩"; // Affectation du tableau caché
const char *symbol_case[SIZE_ROWS][SIZE_COLS];

enum Type_Case board_hidden[SIZE_ROWS][SIZE_COLS]; // remplacer 18 par la taille de Symbole_case
enum Type_Case board_revealed[SIZE_ROWS][SIZE_COLS];

int tab[SIZE_ROWS][SIZE_COLS] = //Affectation d'un tableau 5x5 initialisé à 0 et et son contour à 1  
{ 
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };
                         



void set_init(void) 
{
  for (int r = 0; r < SIZE_BOARD; r++)
  {
    for (int c = 0; c < SIZE_BOARD; c++)
    {
      
      symbol_case[r][c] = Symbol_case_init[VOID_MAP]; //Initialisation du tableau symbol_case à VIDE_MAP
      board_hidden[r][c] = VOID_MAP; //Initialisation du tableau board_hidden à VIDE_MAP
      board_revealed[r][c] = VOID_MAP; //Initialisation du tableau board_hidden à VIDE_MAP
      
    }
  }
  return; 
}


void initialize_set_cache(Player *player, int nb_player) //Initialisation du tableau de jeu
{
  system("clear");
  
  // Top rows
  bool a;
  a = true;
  
  for (int r = 0; r < SIZE_BOARD; r++)
  {
    
    for (int c = 0; c < SIZE_BOARD; c++)
    {  
      for (int i = 0; i <  nb_player; i++) 
      {
        if ((player[i].x == r) && (player[i].y == c))
        {
          
          printf("%ls", icon_adventurer[i]); //Affiche l'aventurier
          a = false;
        }
      }
    
    if((a) && (tab[r][c] == 2))
    {
     
      printf("%s | ", symbol_case[r][c]); // affiche les symboles de chaque case 
    }
    else if ((r == 0) || (r == 6) || (c == 0) || ( c == 6))
      {   
        if((c == 6) && (a))
          {
            printf("- ");
            
          }
          else if(a)
          {  
            printf("- | "); 
          }
          else if (c != 6)
          {
            printf(" | ");
          }
          else
          {
            printf("");
          }
      }
        // else if (tab[r][c] != 0) // Le tableau 5x5 et déjà découvert
        // {
        //   printf("%s | ", symbole_case[r - 1][c - 1]);
        // }
    else if(a)
        {
          printf("%s | ", symbol_cache); // affiche les symboles cachés
        } 
        // else if (tab[r][c] == 2)
        // {
        //   printf("%s",symbole_case[r - 1][c - 1]);
        // }
        
        
    else 
        {
          printf(" | ");
        }
      a = true;
  }
  printf("\n");
}
}


void print_set_cache(int nb_player) // Affichage du tableau de jeu
{
  system("clear");
  initialize_set_cache(player, nb_player);
}

  

 int my_rand(char symbol[SIZE_ROWS][SIZE_COLS]) 
{
    int counts[NB_MONSTER] = {4, 4, 4, 4}; // Nombre d'occurrences pour chaque monstre
    int counts_other[SIZE - NB_MONSTER] = {2, 1, 2, 1, 1, 1, 1}; // Nombre d'occurrences pour les autres éléments
    int i, j;

    // Remplir le tableau avec les monstres
    for (i = 0; i < SIZE_ROWS; i++) 
    {
        for (j = 0; j < SIZE_COLS; j++) 
        {
            if (counts[ZOMBIE] > 0) 
            {
                symbol[i][j] = *Symbol_case_init[ZOMBIE];
                counts[ZOMBIE]--;
            } 
            else if (counts[TROLLS] > 0) 
            {
                symbol[i][j] = *Symbol_case_init[TROLLS];
                counts[TROLLS]--;
            } 
            else if (counts[HARPY] > 0) 
            {
                symbol[i][j] = *Symbol_case_init[HARPY];
                counts[HARPY]--;
            } 
            else if (counts[BASILISK] > 0) 
            {
                symbol[i][j] = *Symbol_case_init[BASILISK];
                counts[BASILISK]--;
            } 
            else 
            {
                // Remplir le reste du tableau avec les autres éléments
                int index = rand() % (SIZE - NB_MONSTER);
                int count = counts_other[index];
                symbol[i][j] = *Symbol_case_init[NB_MONSTER + index];
                counts_other[index]--;
                
            }
        }
    }
}



void destruct_Board(Board* Board) {
    // Libérer la mémoire allouée pour le tableau 2D
    free(Board);
}

int menu_choice()          
{
    int choice;
    int input_check;

    do {
         printf("---------------Bienvenue dans Memory RPG ------------------\n\n");
         printf("                 1.     Jouez\n");
         printf("                 2. Voir les scores.\n");
        input_check = scanf("%d", &choice);

        if (input_check != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre.\n");
            // Vider le tampon d'entrée en cas de saisie invalide
            while (getchar() != '\n') {}
        } else if (choice != 1 && choice != 2) {
            printf("Choix invalide. Veuillez choisir à nouveau.\n");
        }
    } while (input_check != 1 || (choice != 1 && choice != 2));

    return choice;
}

int getNumberOfPlayers() { //Demande le nombre de joueur qui va jouer 
    int nmb_players;
    char input[100];
    
    do {
        printf("\nVeuillez saisir le nombre de joueurs (entre 2 et 4) : ");
        
        if (scanf("%d", &nmb_players) != 1) {
            printf("\nEntrée invalide. Veuillez saisir un nombre entier.\n");
            scanf("%*[^\n]");  // Vide le tampon d'entrée
            continue;
        }
        
        if (nmb_players < 2 || nmb_players > 4) {
            printf("\nNombre de joueurs invalide. Veuillez saisir un nombre entre 2 et 4.\n");
        }
    } while (nmb_players < 2 || nmb_players > 4);
    
    return nmb_players;
}


// PSEUDO ET CLASSE JOUEURS
void START_game(Player * player, int nb_player) {
    char adventurerName[4][10] = {"Guerrier", "Ranger", "Magicien", "Voleur"};
    bool adventurer_available[4] = {true, true, true, true};

    for (int i = 0; i < nb_player; i++) {
        printf("\n\nJoueur %d\n", i + 1);

        // Demander le pseudo du joueur
        printf("Choisissez un Pseudo : ");
        scanf("%s", player[i].pseudo);

        // Demander le choix de l'aventurier
        printf("\nChoisissez maintenant un aventurier :\n");
        for (int j = 0; j < 4; j++) {
            if (adventurer_available[j]) {
                printf("%d. %s\n", j + 1, adventurerName[j]);
            }
        }
        int choice,chx;
        scanf("%d", &choice);

        while (choice < 1 || choice > 4 || !adventurer_available[choice - 1]) {
            printf("\nChoix invalide. Veuillez choisir à nouveau :\n");
            scanf("%d", &choice);
        }
        chx = choice - 1;
        player[i].adventurer = (enum Type_adventurer) (chx); // Aventurier enlever de la prochaine demande car il est déjà utilisé
        switch(chx) // Affectation du symbole de l'aventurier au joueur
        {
          case 0 :
          player[i].symbol_affecte = Warrior;
          icon_adventurer[i] = Warrior;
          printf("Vous êtes un Guerrier = %ls", icon_adventurer[i]);
          break;
          
          case 1 :
          player[i].symbol_affecte = Ranger;
          icon_adventurer[i] = Ranger;
          printf("Vous êtes un Guerrier = %ls", icon_adventurer[i]);
          break;
          
          case 2 :
          player[i].symbol_affecte = Wizard;
          icon_adventurer[i] = Wizard;
          printf("Vous êtes un Guerrier = %ls", icon_adventurer[i]);
          break;
          
          case 3 :
          player[i].symbol_affecte = Thief;
          icon_adventurer[i] = Thief;
          printf("Vous êtes un Guerrier = %ls", icon_adventurer[i]);
          break;
          
        }        
        adventurer_available[choice - 1] = false;

        printf("");
    }
}




void fill_alea( const char *board[SIZE_ROWS - 2][SIZE_COLS - 2]) {
    
    int indices_disponibles[SIZE];  // Indices disponibles pour chaque symbole
    int symboles_restants = SIZE ; 
  
  // Initialiser les indices disponibles pour chaque symbole
   
     srand(time(NULL));
    // Remplir le tableau aléatoirement
    
for (int r = 1; r < SIZE_ROWS - 1; r++) {
        for (int c = 1; c < SIZE_COLS - 1; c++) {
            int symbol_index = (rand() % 11) + 3; // Génère un symbole_index aléatoire dans la plage [0, SIZE-1]

            // Vérifier si l'indice est disponible
            while (indices_disponibles[symbol_index] == 0) {
                symbol_index = (rand() % 11) + 3 ;
            }

            // Placer le symbole dans le tableau et décrémenter l'indice disponible correspondant
            board[r][c] = Symbol_case_init[symbol_index];
            indices_disponibles[symbol_index]--;
        }
    }

  //afficherBoard (board);
  // Afficher le tableau
 
}


// Tour du joueur
const char* name_weapon[] = { "Torche", "Bouclier", "Hache", "Arc" };

void ChoiceWeapon (Player player) { // Choix de l'arme à chaque toue
    
    printf("\nChoisissez une arme : \n");
    printf("1. Torche\n");
    printf("2. Bouclier\n");
    printf("3. Hache\n");
    printf("4. Arc\n");
    
    int choiceWeapon;
    scanf("%d", &choiceWeapon);
    
    switch (choiceWeapon) { //Affectation de l'arme au joueur
        case 1:
            player.Weapon_Tour = Weapon_Turn_TORCH;
            break;
        case 2:
            player.Weapon_Tour = Weapon_Turn_SHIELD;
            break;
        case 3:
            player.Weapon_Tour =  Weapon_Turn_AXE;
            break;
        case 4:
            player.Weapon_Tour = Weapon_Turn_BOW;
            break;
        default:
            printf("Choix invalide.\n");
            
    }

    printf("Vous avez choisi %s, excellent choix !\n\n", name_weapon[choiceWeapon - 1]);
    sleep(3);
}


void encounter_TOTEM (Player* player,int nb_player, const char *symbol_case[SIZE_ROWS - 2][SIZE_COLS - 2]) // Utilisation du Totem
{
        printf(" \nTu as trouvé un Totem de transmutation \n change le totem de place avec l'une des case face cachée:\n");
        int old_x = player->x--;
        int old_y = player->y--;
        		printf("Coordonné en x de la case: \n");
        		int new_x;
        		scanf("%d", &new_x);
        		new_x--;
        		printf("Coordonné en y de la case: \n");  
        		int new_y;
        		scanf("%d", &new_y );
        		new_y--;

            int temp_x, temp_y;
            symbol_case [temp_x][temp_y] = symbol_case [new_x][new_y];
            symbol_case[new_x][new_y]=  symbol_case [old_x][old_y];
            symbol_case[old_x][old_y] = symbol_case [temp_x][temp_y];
        
            
            switch(nb_player)
            {
    	           case 2:
    		            while((new_x == 3 && new_y == 0) || (new_x == 0 && new_y == 1) || (new_x<1 || new_x>5) ||                               (new_y<1 || new_y>5)) //Eviter de choisir les coordonnes des spawns
                    {
    			             printf("\nC'est le spawn d'un joueur ! \n Ce n'est pas possible d'aller ici il faut changer les coordonnées de la transmutation : \n\n");
    			             printf("Coordonné en x de la case: \n");
          		         scanf("%d", &new_x);
          		         new_x--;
          		         printf("Coordonné en y de la case: \n");
          		         scanf("%d", &new_y);
          		         new_y--;
          	         }
  		            
                 break;
  	           case 3:
  		            while((new_x == 3 && new_y == 0) || (new_x == 0 && new_y == 1) || (new_x == 4 && new_y == 3) ||   (new_x<1 || new_x>5) || (new_y<1 || new_y>5))
                  {
  			              printf("\nC'est le spawn d'un joueur ! \n Ce n'est pas possible d'aller ici il faut changer les coordonnée de la transmutation : \n\n");
  			              printf("Coordonné en x de la case: \n");
        		          scanf("%d", &new_x);
        		          new_x--;
        		          printf("Coordonné en y de la case: \n");
        		          scanf("%d", &new_y);
        		          new_y--;
        	        }
  		            break;
  	           case 4:
  		            while((new_x == 3 && new_y == 0) || (new_x == 0 && new_y == 1) || (new_x == 4 && new_y == 3) ||                          (new_x == 1 && new_y == 4) || (new_x<1 || new_x>5) || (new_y<1 || new_y>5))
                  {
  			              printf("\nC'est le spawn d'un joueur ! \n Ce n'est pas possible d'aller ici il faut changer les coordonnée de la transmutation : \n\n");
  			              printf("Coordonné en x de la case: \n");
        		          scanf("%d", &new_x);
        		          new_x--;
        		          printf("Coordonné en y de la case: \n");
        		          scanf("%d", &new_y);
        		          new_y--;
        	        }
  		            break;
  	           default:
  		            break;
  	        }
    player->player_dead++;
}


void encounter_TELEPORTEUR(Player* player) //Utilisation du téléporteur
{
  int row, col;
    while ((player->x<1)|| (player->x>5) || (player->y<1) || (player->y>5) )
    {
        printf("\nChoisissez la ligne de destination du téléporteur (1-%d) : ", SIZE_BOARD-1);
        scanf("%d", &row);
        printf("Choisissez la colonne de destination du téléporteur (1-%d) : ", SIZE_BOARD-1);
        scanf("%d", &col);

        player->x = row;
        player->y = col;
      
    }
    
        //Attention, il reste a verifier si la case de teleportation est bien face cache, 
        //et qu'il rempli bien des nombres entre 0 et 4
}     


// REGROUPEMENT DES EVENTUALITE

void encounter_case(Player *player, int nb_player, const char *symbol_case[SIZE_ROWS - 2][SIZE_COLS - 2])
{ // Fonction lorsque un joueur va sur une case du plateau
  switch(*symbol_case[player->x][player->y])
  {
      case 'H' : // Harpie
        
        if ((player->Weapon_Tour ==  Weapon_Turn_AXE)   &&  symbol_case[player->x][player->y] == Symbol_case_init[HARPY] )
          {
            printf("\nBien joué aventurier , tu as vaincu cette harpie, tu peux avancer");
          }
        else
          {
            player->player_dead=1;
            printf("\nMalheuresement pour toi aventurier, cette harpie aura eu raison de toi. Venges toi au prochain tour \n\n");
          }
        break;

      case 'B' : // Basilique
        
      if ((player->Weapon_Tour == Weapon_Turn_BOW)  &&  symbol_case[player->x][player->y] == Symbol_case_init[BASILISK])
      {
          printf("\nBien joué aventurier , tu as vaincu ce basilique, tu peux avancer");
      }
      else
        {
          player->player_dead=1;
          printf("\nMalheuresement pour toi aventurier, ce basilique aura eu raison de toi. Venges toi au prochain tour \n\n");
        }
      break;

      case 'T': // Troll
        
      if (( player->Weapon_Tour == Weapon_Turn_SHIELD   &&  symbol_case[player->x][player->y] == Symbol_case_init[TROLLS]))
      {
       printf("\nBien joué aventurier , tu as vaincu ce troll, tu peux avancer");
      }
        else
        {
          player->player_dead=1;
          printf("\nMalheuresement pour toi aventurier, ce troll aura eu raison de toi. Venges toi au prochain tour \n\n");
        }
          break;

      case 'Z': // Zombie
      if ((player->Weapon_Tour == Weapon_Turn_TORCH)  &&  symbol_case[player->x][player->y] == Symbol_case_init[ZOMBIE])
      {
        printf("\nBien joué aventurier , tu as vaincu ce zombie, tu peux avancer");
      }
      else
        {
          player->player_dead++;
          printf("\nMalheuresement pour toi aventurier, ce zombie aura eu raison de toi. Venges toi au prochain tour \n\n");
        }
        
        break;

      case '0' :
        encounter_TELEPORTEUR(player); // Teleporteur
        break;

      case 't':
        encounter_TOTEM (player, nb_player,symbol_case); // Totem
        break;

      case 'C' : // Coffre
        
      if ((player->has_found_chest == 0 )  &&  (player->has_found_antique == 0))
      {
        printf("Félicitation aventurier!! vous avez trouver un coffre au tresor.\n");
        printf("Il vous reste désormais à trouver votre arme antique, courage !\n\n");
        player->has_found_chest++;
      }
  
      else if ((player->has_found_chest == 1)  &&  (player->has_found_antique == 0))
      {
        printf("Malheuresement pour toi aventurier, tu as déja trouvé un coffre...\n");
        printf("Ne perds pas espoir et trouve ton arme antique, la victoire est proche !\n");
      }
      
      else if ((player->has_found_chest == 0)  &&  (player->has_found_antique == 1))
      {
        printf("tu as trouvé ton coffre manquant !\n");
        player->has_found_chest++;
        player->player_win++;
      }
        break;
      
      case 'e' : // Epée de feu
        
      if ((player->has_found_chest == 0 )   &&  (player->adventurer == WARRIOR))
      {
        printf("Bravo guerrier, vous avez trouvé votre épée de feu !\n");
        printf("Il vous reste maintenant à trouver un coffre aux trésors!!\n\n");
        player->has_found_antique++;
      }
      
      else if (((player->has_found_chest == 0)||(player->has_found_chest == 1))   &&  (player->adventurer != WARRIOR))
      {
        printf("Malheuresement pour vous aventurier, mais ce n'est pas votre arme antique (EPEE)...\n\n");
      }
  
      else if ((player->has_found_chest == 1 )   &&  (player->adventurer == WARRIOR))
      {
        printf("Bravo, vous avez trouvé votre épée de feu guerrier\n\n");
        player->has_found_antique++;
        player->player_win++;
      }
        break;
      
      case 'b' :
        
      if ((player->has_found_chest == 0 )   &&  (player->adventurer == RANGER))
      {
          printf("Bravo ranger, vous avez trouvé votre baton de contrôle !\n");
          printf("Il vous reste maintenant à trouver un coffre aux trésors!!\n\n");
          player->has_found_antique++;
      }
  
      else if (((player->has_found_chest == 0)||(player->has_found_chest == 1))   &&  (player->adventurer != RANGER))
      {
        printf("Malheuresement pour vous aventurier, mais ce n'est pas votre arme antique (BATON)...\n\n");
      }
      else if ((player->has_found_chest == 1 )   &&  (player->adventurer == RANGER))
      {
        printf("Bravo, vous avez trouvé votre baton de contrôle ranger\n\n");
        player->has_found_antique++;
        player->player_win++;
      }
        break;
      
      case 'g' :
      if ((player->has_found_chest == 0 )   &&  (player->adventurer == WIZARD))
      {
        printf("Bravo magicien, vous avez trouvé votre grimoir interdit !\n");
        printf("Il vous reste maintenant à trouver un coffre aux trésors!!\n\n");
        player->has_found_antique++;
      }
      
      else if (((player->has_found_chest == 0)||(player->has_found_chest == 1))   &&  (player->adventurer != WIZARD))
      {
        printf("Malheuresement pour vous aventurier, mais ce n'est pas votre arme antique (GRIM)...\n\n");
      }
  
      else if ((player->has_found_chest == 1 )   &&  (player->adventurer == WIZARD))
      {
        printf("Bravo, vous avez trouvé votre grimoir interdit magicien\n\n");
        player->has_found_antique++;
        player->player_win++;
      }
        break;
      
      case 'd' :
        
      if ((player->has_found_chest == 0 )   &&  (player->adventurer == THIEF))
      {
        printf("Bravo voleur, vous avez trouvé votre dague de sommeil !\n");
        printf("Il vous reste maintenant à trouver un coffre aux trésors!!\n\n");
        player->has_found_antique++;
      }
      else if (((player->has_found_chest == 0)||(player->has_found_chest == 1))   &&  (player->adventurer != THIEF))
      {
        printf("Malheuresement pour vous aventurier, mais ce n'est pas votre arme antique (DAGUE)...\n\n");
      }
  
      else if ((player->has_found_chest == 1 )   &&  (player->adventurer == THIEF))
      {
        printf("Bravo, vous avez trouvé votre dague de sommeil voleur\n\n");
        player->has_found_antique++;
        player->player_win++;
      }
        break;

      default:
          break;
        
  }
}

// INSTRUCTION DEPLACEMENT UTILISATEUR
 void ask_shift(Player *player, int nb_player, const char *symbol_case[SIZE_ROWS - 2][SIZE_COLS - 2]) 
{
  
  char verif;  
  char input; 
  int valid_input = 0;
  
  while (!valid_input) 
  {
    

    if(((tab[player->x - 1][player->y] == 2) || (tab[player->x - 1][player->y] == 1)) 
      && ((tab[player->x][player->y - 1] == 2) || (tab[player->x][player->y - 1] == 1)) 
      && ((tab[player->x + 1][player->y] == 2) || (tab[player->x + 1][player->y] == 1))
      && ((tab[player->x][player->y + 1] == 2) || (tab[player->x][player->y + 1] == 1)))
    {
      printf("Toutes les cartes autour de vous sont déjà retournés, c'est la fin de votre tour");
      player->player_dead = 1; 
      // sorti de la boucle
    }
    else
    { 
      
    
    
    printf(" \n\n %s, choisissez un déplacement : \n", player->pseudo); 
    printf("z = haut \nq = gauche \ns = bas \nd = droite \n ");
    scanf(" %c", &input);
    
    
      switch (input) 
      {
        case 'z':
    
          if ((player->x == 0) || (tab[player->x - 1][player->y] == 1) || (tab[player->x - 1][player->y] == 2))                                         // SI JOUEUR APPUIE SUR Z MAIS NOUVELLE CASE = DEJA RETOURNER)
          {
            printf ("mouvement illicite\n\n");
            printf("Veuilez saisir une nouvelle direction\n");
            valid_input = 1;
            ask_shift(player,nb_player, symbol_case );
           }
          else
          {
            player->x--;
            print_set_cache(nb_player);
            tab[player->x][player->y] = 2;
        
            valid_input = 0;
          }
            break;
    
        case 'q':
      
          if ((player->y == 0) || (tab[player->x][player->y - 1] == 1) || (tab[player->x][player->y - 1] == 2))                                                // ADD SI JOUEUR APPUIE SUR Q MAIS NOUVELLE CASE = DEJA RETOURNER)
          {
            printf ("mouvement illicite\n\n");
            printf("Veuilez saisir une nouvelle direction\n");
            valid_input = 1;
            ask_shift(player,nb_player,symbol_case);
          }
          else
          {
            player->y--;
            print_set_cache(nb_player);
            tab[player->x][player->y] = 2;
            
            valid_input = 0;
          }
    
          break;
    
        case 's':
          
           if ((player->x == 6) || (tab[player->x + 1][player->y] == 1) || (tab[player->x + 1][player->y] == 2))                          // ADD SI JOUEUR APPUIE SUR S MAIS NOUVELLE CASE = DEJA RETOURNER)
           {
            printf ("mouvement illicite\n\n");
            printf("Veuilez saisir une nouvelle direction\n");
            valid_input = 1;
            ask_shift(player, nb_player, symbol_case);
           }
           else
           {
          // {printf("test");
            player->x++;
            tab[player->x][player->y] = 2;
            // printf("test3");
            print_set_cache(nb_player);
            
            valid_input = 0;
            // printf("test2");
            } 
            break;
    
        case 'd' :

         if ((player->y == 6) || (tab[player->x][player->y + 1] == 1) || (tab[player->x][player->y + 1] == 2))                          // ADD SI JOUEUR APPUIE SUR D MAIS NOUVELLE CASE = DEJA RETOURNER)
         {
          printf ("mouvement illicite\n\n");
          printf("Veuilez saisir une nouvelle direction\n");
          valid_input = 1;
          ask_shift(player, nb_player, symbol_case);
         } 
        else
        {
          player->y++;
          print_set_cache(nb_player);
          tab[player->x][player->y] = 2;
          
          valid_input = 0;
         }  
          break;
    
        default :
          printf("commande invalide\n\n");
          valid_input=1;
      }
           encounter_case(player, nb_player, symbol_case);
           sleep(2);
    }
  }
}
   



void victory (Player player)
{
  printf("----------------FELICITATION, %s  a gagné la partie !----------------------",player.pseudo);
  player.Number_of_win++;
  
}

    

void spawn_player()
{
  for (int i = 0; i < NB_PLAYER_MAX; i++)
  {
    switch(i)
          {
            case 0 :
              player[i].x = 2;
              player[i].y = 0;
              break;
           case 1 :
              player[i].x = 0;
              player[i].y = 4;
              break;
           case 2 :
              player[i].x = 4;
              player[i].y = 6;
              break;
           case 3 :
              player[i].x = 6;
              player[i].y = 2;
              break;
           
          }
     }
}



void init_player_turn (Player player, int nb)
{
  player.has_found_chest   = 0;
  player.has_found_antique = 0;
  player.player_dead       = 0;
  player.player_win        = 0;
  print_set_cache (nb);
}



void Turn_player(int nb_player)
    {
      for (int i = 0; i <  nb_player; i++) 
      {
        printf("\n-----------Tour du joueur %d------------\n\n\n", i + 1);

        printf("C'est à %s de jouer\n", player[i].pseudo);

        //   FONCTION INIT_PLAYER

        while ((player[i].player_dead == 0) && (player[i].player_win == 0))
        {
          init_player_turn(*player, nb_player);
          // Demander quelle arme à utiliser
          ChoiceWeapon (player[i]);
          //Affichage tableau
          print_set_cache(nb_player); 
          // DéPLACE DéJA LE JOUEUR + condition de la case 
          ask_shift(&player[i], nb_player, symbol_case);

          if(player[i].player_win == 1)
          {
            victory(*player); 
          }
          else 
          {
          break;
          }
          
          
          
        }
       
      } 
    
   }




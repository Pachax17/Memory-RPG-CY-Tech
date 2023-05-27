#include "fonctionV2.h"


// Fonction principale

int main() 
{
  setlocale(LC_ALL, "");
  const wchar_t *Warrior = L"\u2663";
  const wchar_t *Ranger = L"\u2666";
  const wchar_t *Wizard = L"\u2665";
  const wchar_t *Thief = L"\u2660";
  
  srand(time(NULL));


  //Affichage du menu avec 2 possibilités : les scores, jouer         


  int choice = menu_choice();
  if (choice == 1)
  {
    int nbPlayers;
    nbPlayers = getNumberOfPlayers();
    
    Player Info_player[NB_PLAYER_MAX]; 
    START_game(player, nbPlayers);// PRISES DES INFO JOUEURS

    printf("\n------------------Informations des joueurs :   -----------------\n"); // RECAP DE TOUTES LES INFO DES JOUEURS
    
    for (int i = 0; i < nbPlayers; i++) 
    {
      printf("\nJoueur %d\n", i + 1);
      printf("\nPseudo : %s\n", player[i].pseudo);
      printf("Aventurier : ");
      
      switch (Info_player[i].adventurer) 
      {
        case 0:
          printf("Guerrier\n");
          printf("\nTon objectif est de récupérer l'épée de feu ainsi qu'un coffre lors d'une aventure\n\n");
          break;
        case 1:
          printf("Ranger\n");
          printf("\nTon objectif est de récupérer le baton ainsi qu'un coffre lors d'une aventure\n\n");
          break;
        case 2:
          printf("Magicien\n");
          printf("\nTon objectif est de récupérer le grimoire interdit ainsi qu'un coffre lors d'une aventure\n\n");
          break;
        case 3:
          printf("Voleur\n");
          printf("\nTon objectif est de récupérer la dague de someil ainsi qu'un coffre lors d'une aventure\n\n");
          break;      
      }
      printf("\n");
    }

    printf("\n\n Chargement...");
    sleep(3); // pause de 3 secondes pour lire son objectif
  
    // Initialisation du plateau de jeu, les joueurs et leur placement
  
    srand(time(0));  
  
    int board[SIZE_BOARD][SIZE_BOARD];   
    for (int r = 0; r < SIZE_BOARD; r++)
    {
      for (int c = 0; c < SIZE_BOARD; c++)
      {
        board[r][c] = CASE_EMPTY  ;
      }
      const char *converted_Board[7][5];
      set_init();
      // set_board();
      fill_alea(converted_Board); // Check
      spawn_player();
      initialize_set_cache(player, nbPlayers);
    }
    
    // Tour de tous les joueurs
    while(player->player_win == 0)
    {
     
      Turn_player(nbPlayers);
    }
    
    if (player->player_win == 1) 
    {
      victory(*player); // A faire
    }
    else
    {
      printf("BUG, on recommence le jeu");

      // NEVER DO THAT !
      // main(); 
    }
    return 0;
  
    
  }
}



// Temps chronometre debut de partie : NOUS SOMMES PAS PARVENU A INCLURE NOTRE CHRONOMETRE CONVENABLEMENT

// #include <stdio.h>
// #include <time.h>

//int main() {
    //time_t start_time, current_time;
    //double elapsed_time;

    //printf("Appuyez sur Entrée pour démarrer le chronomètre.\n");
    //getchar();

    // Enregistre le temps de démarrage
    //start_time = time(NULL);

    //printf("Le jeu a commencé !\n");

    // Boucle principale du jeu
    //while (1) {
        // Obtient le temps actuel
        //current_time = time(NULL);

        // Calcule le temps écoulé depuis le démarrage
        //elapsed_time = difftime(current_time, start_time);

        // Affiche le temps écoulé en secondes
        //printf("Temps écoulé : %.2f secondes\n", elapsed_time);

        // Vérifie si le jeu est terminé (par exemple, une condition de victoire ou de défaite)
        //if (joueur->joueur_win++;)
            //break

        // Si le jeu est terminé, vous pouvez arrêter le chronomètre en utilisant "break"

        // Attend une courte période (par exemple, 1 seconde) avant de mettre à jour le temps
        //sleep(1);
    //}

    //return 0;
//}


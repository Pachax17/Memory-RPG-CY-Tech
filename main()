#include "fonctionV2.h"
#include <locale.h>




// Fonction principale
int main() 
{
   setlocale(LC_ALL, ""); 

        wchar_t *clubs = L"\u2663  \u2667"; 
        wchar_t *diamonds = L"\u2666  \u2662"; 
        wchar_t *hearts = L"\u2665  \u2661"; 
        wchar_t *spades = L"\u2660  \u2664"; 

        printf("%ls\n", clubs); 
        printf("%ls\n", diamonds); 
        printf("%ls\n", hearts); 
        printf("%ls\n", spades); 
  
  srand(time(NULL));

  // Affichage du menu avec 2 possibilités : les scores, jouer
  int choix = 0;
  
  printf("1. Jouer une nouvelle partie ! \n");
  printf("2. Voir les scores. \n");
  scanf("%d", &choix);


  // Demander le nb, le nom et l'aventurier nom de chaque joueur

  if (choix == 1)
  {
    int nbJoueurs;
    printf("\nCombien de joueurs participent à la partie (entre 2 et 4) ? ");
    scanf("%d", &nbJoueurs);

    while (nbJoueurs < 2 || nbJoueurs > 4) {
        printf("\nNombre de joueurs invalide. Veuillez choisir à nouveau : ");
        scanf("%d", &nbJoueurs);
    }
    

    Joueur Info_joueurs[NB_JOUEURS_MAX];
    debut_partie(Info_joueurs, nbJoueurs); // PRISES DES INFO JOUEURS

    printf("\nInformations des joueurs :\n"); // RECAP DE TOUTES LES INFO DES JOUEURS
    for (int i = 0; i < nbJoueurs; i++) {
        printf("Joueur %d\n", i + 1);
        printf("\nPseudo : %s\n", joueur[i].pseudo);
        printf("Aventurier : ");
        switch (Info_joueurs[i].aventurier) {
            case 0:
                printf("Guerrier\n");
                printf("\nTon objectif est de récupérer l'épée de feu ainsi un coffre lors d'une aventure\n");
                break;
            case 1:
                printf("Ranger\n");
                printf("\nTon objectif est de récupérer le baton ainsi qu'un coffre lors d'une aventure\n");
                break;
            case 2:
                printf("Magicien\n");
                printf("\nTon objectif est de récupérer le grimoire interdit ainsi qu'un coffre lors d'une aventure\n");
                break;
            case 3:
                printf("Voleur\n");
                printf("\nTon objectif est de récupérer la dague de someil ainsi qu'un coffre lors d'une aventure\n");
                break;
        }
        printf("\n");
    }


   sleep(10); // pause de 15 secondes pour lire son objectif

    
    // Initialisation du plateau de jeu, les joueurs et leur placement
	  srand(time(0));  
    int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];   
    for (int r = 0; r < TAILLE_PLATEAU; r++)
    {
      for (int c = 0; c < TAILLE_PLATEAU; c++)
      {
        plateau[r][c] = CASE_VIDE;
      }
      set_init();
      set_board();

      
      initialize_set_cache(joueur);
    }






    
  // Affichage du plateau de jeu

  // Temps chronometre debut de partie : TODO



{
//time_t start_time, current_time;
    //int game_duration;

    //printf("Appuyez sur une touche pour commencer le jeu...\n");
    //getchar(); // Attendre l'appui d'une touche

    //start_time = time(NULL); // Enregistrer l'heure de début du jeu

    //printf("Le jeu a commencé!\n");

    // Boucle principale du jeu
    //while (/* Condition de fin du jeu */) {
        // Mettez ici le code de votre jeu

        //current_time = time(NULL); // Obtenir l'heure actuelle 

        // Calculer la durée passée en secondes
        //game_duration = (int)(current_time - start_time);

        // Afficher la durée du jeu en temps réel en secondes
        //printf("Durée du jeu : %d secondes\n", game_duration);

        // Mettez ici la condition de fin du jeu
        //  joueur->joueur_win == 1

        //printf("Le jeu est terminé!\n");

    //return 0;
}


    
    





  // Tour de tous les joueurs
    while(joueur->joueur_win == 0)
    {
      Tour_joueur();
    }
    if (joueur->joueur_win == 1) 
    {
      victoire(joueur->pseudo); // A faire
    }
    else
    {
      printf("BUG, on recommence le jeu");
      main();
    }
    
    
    
   
       // COMPRIT DANS TOUR JOUEUR ;     
          // Demander au joueur où il veut aller
          // Vérifier si le joueur peut avancer sur la case spécifiée sinon lui redemander une autre direction
    
            // SI toutes les cartes autour de lui sont retournés = fin du tour
      
                    // Révélation de la carte
                    
                   
    
          // Duel, Totem, Téléportation, Arme Antique et Coffre
          
        
          
          
              // SI Monstre pas vaincu ou Totem, retour à la case départ et fin du tour
              
              // Effectuer le déplacement
          
          
          // Vérifier si le joueur a trouvé un coffre et son arme antique spécifique
          // Victoire, Sinon prochain tour
        
  // else if (choix == 2){
  //   // fonction voir score 
  // }
  //     }
  //   }
  //     //FIN de Partie:
  //         //Annoncer vainqueur
  //               // garder en mémoire que Vainqueur = ce Pseudo
  //         //Annoncer temps de la partie ( Tour ou Temps )
  //         // AFFICHER TOUT LE Plateau

  //     //CHOIX PROCHAINE PARTIE:
  //     // recommencer avc les memes joueurs 
  //         //retour L17
  //     // recommencer avc d'autre joueurs 
  //         // retour L 15
  //     // sinon retour menu
  // } 
  return 0;
  }

}


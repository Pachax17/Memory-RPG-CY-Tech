#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <wchar.h>
#define SIZE 25



// Définition des constantes du jeu
#define NB_JOUEURS_MAX 4
#define TAILLE_PLATEAU 7
#define TAILLE_COLS 7
#define TAILLE_ROWS 7
#define NB_MONSTRES 16
#define NB_TYPES_ARMES 4
#define NB_ARMES_ANTIQUES 4

// Définition des types énumérés


//Type d'aventurier
enum Type_Aventurier { VOLEUR, GUERRIER, MAGICIEN, RANGER};



enum Type_Case { 

//Autre
VIDE_MAP, CASE_VIDE, CASE_CACHE,
//monstres
ZOMBIE, TROLLS, HARPIE, BASILIC, 

// Case spe
COFFRE, TELEPORTEUR, TOTEM,

// Arme Antique
ANTIQUE_EPEE, ANTIQUE_BATON, ANTIQUE_GRIMOIRE, ANTIQUE_DAGUE,

//Spawn
SPAWN_BLEU, SPAWN_JAUNE, SPAWN_ROUGE, SPAWN_VERT,

//AVATAR JOUEURS
J1, J2, J3, J4 ,
};

// SYMBOLE DES CASES

const char* Symbole_case_init[] = { // dans le meme ordre que 'enum Type_Case'
 " ",      // Vide
  "▢",      // case vide
  "▩",      // case cache
  "☢",      // Zombie
  "⚉",      // Troll
  "⚘",      // Harpie
  "⧜",      // Basilic
  "⚿",      // coffre
  "⦕",      // TP
  "◭",      // Totem
  "⚔",      // epee
  "∫",      // Baton
  "🕮",      // Grimoire
  "𐃉",      // Dague
  "▣",      // carre bleu      COULEUR A MODIF CF CAHIER DES CHARGES
  "▣",      // carre jaune
  "▣",      // carre rouge
  "▣",      // carre vert

};

const wchar_t *Symbole_aventurier[] = {
  L"\u2663",    // guerrier ⛨
  L"\u2666",     //  VOLEUR 🗝
  L"\u2665",  // Magicien "✫"
  L"\u2660"  // ranger "↣"
};

// // symbole aventurier
// #define VOLEUR 🗝
// #define GUERRIER ⛨, // guerrier
// #define MAGICIEN ✫, // Magicien
// #define RANGER ↣, // ranger

//Couleur du Joueur 
enum Joueur_Couleur { JOUEUR_ROUGE, JOUEUR_VERT, JOUEUR_BLEU, JOUEUR_JAUNE };


//Arme utilisée par tour
enum Type_Armes { Arme_Tour_TORCHE, Arme_Tour_BOUCLIER, Arme_Tour_HACHE, Arme_Tour_ARC };


typedef struct {
  int cell[TAILLE_ROWS][TAILLE_COLS];
  char symbole[TAILLE_COLS*TAILLE_ROWS];
  bool Case_Cache, Case_Vide;
} Plateau; // Définition de la structure Carte (qui représente une case du plateau)

typedef struct{
  int x; // ligne
  int y; // colonne
  int a_trouve_coffre;
  int a_trouve_antique;
  enum Type_Armes Arme_Tour;
  int joueur_mort;
  int Nb_Victoire;
  char pseudo[SIZE];
  int joueur_win;
  enum Type_Aventurier aventurier; 
  const wchar_t *symbole_affecte;
} Joueur; // Définition de la structure Joueur


// ****

// definition info joueur
// typedef struct {
//     char pseudo[SIZE];
//     //Type_Aventurier
//     int aventurier;
// } Info_Joueur;

// ****

// typedef struct{
//   char nom_joueur[SIZE];
//   int partie_gagne;
// }score_joueur;

Plateau* Initialiser_Plateau(); // création d'un plateau 2D formant notre plateau 

void Reinitialiser_Plateau (Plateau (*plateau)[TAILLE_PLATEAU][TAILLE_PLATEAU]); 

void detruire_plateau(Plateau* plateau);

void Remplir_Plateau(Plateau (*plateau)[TAILLE_PLATEAU][TAILLE_PLATEAU]);

void show_board(void);
void set_board(void);
int my_rand(void);
void show_board(void);

Joueur Info_joueurs[NB_JOUEURS_MAX];
Joueur joueur[NB_JOUEURS_MAX];
    int case_cible;
    Joueur joueur1;
    Joueur joueur2;
    Joueur joueur3;
    Joueur joueur4;

const wchar_t *Guerrier = L"\u2663";
const wchar_t *Ranger = L"\u2666";
const wchar_t *Magicien = L"\u2665";
const wchar_t *Voleur = L"\u2660";

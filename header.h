#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>

// Définition des constantes du jeu

#define SIZE 25
#define NB_PLAYER_MAX 4
#define SIZE_BOARD 7
#define SIZE_COLS 7
#define SIZE_ROWS 7
#define NB_MONSTER 16
#define NB_WEAPON_TYPE 4
#define NB_ANTIQUES_WEAPON 4

// Définition des types énumérés

//Type d'aventurier
enum Type_adventurer { THIEF, WARRIOR, WIZARD, RANGER};

enum Type_Case 
{ 

//Autre
VOID_MAP, CASE_EMPTY, CASE_HIDDEN,
//monstres
ZOMBIE, TROLLS, HARPY, BASILISK, 

// Case spe
CHEST, TELEPORTER, TOTEM,

// Arme Antique
ANTIQUE_SWORD, ANTIQUE_STICK, ANTIQUE_GRIMOIRE, ANTIQUE_DAGER,

//Spawn
SPAWN_BLUE, SPAWN_YELLOW, SPAWN_RED, SPAWN_GREEN,

//AVATAR JOUEURS
J1, J2, J3, J4 ,
};

// SYMBOLE DES CASES

const char* Symbol_case_init[] = 
{ // dans le meme ordre que 'enum Type_Case'
  "Z", // "☢",      // Zombie
  "T", // "⚉",      // Troll
  "H", // "⚘",      // Harpie
  "B", // "⧜",      // Basilic
  "C", // "⚿",      // coffre
  "0", // "⦕",      // TP
  "t", // "◭",      // Totem
  "e", // "⚔",      // epee
  "b", // "∫",      // Baton
  "g", // "🕮",      // Grimoire
  "d"  // "𐃉"      // Dague
};

int init_available[SIZE] = 
{
    4,
    4,
    4,
    4,
    2,
    1,
    2,
    1,
    1,
    1,
    1
};

const wchar_t *Symbol_adventurer[] = 
{
  L"\u2663",   // guerrier ⛨
  L"\u2666",   //  VOLEUR 🗝
  L"\u2665",   // Magicien "✫"
  L"\u2660"    // ranger "↣"
};

// // symbole aventurier

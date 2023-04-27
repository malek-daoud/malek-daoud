#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


typedef struct animation
{
  SDL_Surface *sprite ;
  SDL_Rect possprite,pos;  	
}animation; 
typedef struct enigme
{
    animation a;
    SDL_Surface *background;
    char question[60],rep1[20],rep2[20],rep3[20];
    int solution;
}enigme;   





enigme genererEnigme(char *nomfichier);
void afficherEnigme(enigme *e, SDL_Surface * screen);
void rotozoom(enigme * e,int rep);

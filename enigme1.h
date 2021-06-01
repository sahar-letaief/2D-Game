#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h> 

typedef struct 
{
 SDL_Surface * img; /*!< Surface. */ 
 SDL_Rect 	p; /*!< rectangle. */ 
 int result;
}enigme;

void init_enigme(enigme * e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;
 int solution_e2 (char image []);
int resolution1 (int * running,int *run );
int resolution2 (int * running,int *run );
void solution_e1 (SDL_Surface * screen,char image [],int *x1,int *x2) ;
void afficher_reponse( SDL_Surface *screen, int r2, int r1);
int afficher_resultat (SDL_Surface * screen,int r2,int r1,enigme *en,int x1,int x2);

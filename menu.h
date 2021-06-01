
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>




void credit_surface();



void setrects(SDL_Rect* clip);

void menu1(SDL_Rect* clip);
void credit_surface(SDL_Surface *ecran ,SDL_Surface *instrc ,SDL_Surface *yassine ,SDL_Surface *sahar ,SDL_Surface *nardine ,SDL_Surface *nahed ,SDL_Surface *semah,SDL_Surface *back ,SDL_Surface *enjoy,SDL_Surface *yasmine ,  SDL_Event event, TTF_Font *police , SDL_Color couleurNoire,SDL_Rect ttf[]);

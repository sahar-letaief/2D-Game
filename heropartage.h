/**
* @file heropartage.h
* @brief  fichier header
* @author NOT YET Yassine Ben Salha + Semah Bader  1A3
* @version 1.2
* @date June 2020
*/
#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED


/**
* @struct hero
* @brief structure hero
*/
struct hero
{
	int mouselocation,frame,direction;
	SDL_Surface *heroright;
	SDL_Surface *heroleft;
	SDL_Rect heroposition;
	SDL_Rect rectsright[5],rectsleft[5];
	SDL_Rect herorelativeposition;
	int speedup,speeddown,directionjump,ground,gravity;
	int herospeed;
	int heroisjumping;
	
	
};
typedef struct hero hero; 

/**
* @struct background
* @brief structure background
*/
struct background
{
	SDL_Surface* bg;
	SDL_Rect bgposition;
	SDL_Rect camera;
};
typedef struct background background;



void initbackgroundtop(background* bgtop);
void inittophero(hero* herotop);

void initbackgroundbot(background* bgbot);
void initbothero(hero* herobot);


void setrectsleftp(hero* hero);
void setrectsrightp(hero* hero);
void deplacerhero(hero* hero ,int choixdeplacement);
void blit(SDL_Surface *screen,int choix,hero* hero,background* bg);
void scrollingright(background* bg);
void scrollingleft(background* bg);






#endif // HERO_H_INCLUDED

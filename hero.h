#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

struct heros
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
typedef struct heros heros; 


struct minihero
{
	SDL_Surface *minihero;
	SDL_Surface *minimap;
	SDL_Surface *minimapfocus;
	SDL_Rect miniheroposition;
	SDL_Rect positionminimap;
	SDL_Rect positionfocus;

	int directiondep;
	
};
typedef struct minihero minihero;

struct camera
{
	SDL_Rect camera;
};
typedef struct camera camera;


void jouer(SDL_Surface* screen);
void initialisation(heros* hero);
void setrectsright(heros* hero);
void setrectsleft(heros* hero);
void deplacerjoueur(heros* hero ,int choixdeplacement);
void blitfenetre(SDL_Rect positionMenu1,SDL_Surface *screen,int choix,SDL_Surface *menu1,heros* hero,camera* c);
void speed(heros* hero);

void resetafterjump ( heros* hero,camera* c);
void jump (heros* hero);
void restart_jump ( heros* hero ) ;

void initcamera ( camera* c);
void scrolling (camera* c,heros* hero);
void scrollingb (camera* c,heros* hero);

void initialiserminihero(minihero* mh);
void blitminihero(SDL_Surface *screen,minihero* mh);
void deplacer ( minihero* mh,heros* hero);

#endif // HERO_H_INCLUDED

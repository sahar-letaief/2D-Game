/**
* @file heropartage.c
* @brief  fichier source
* @author NOT YET Yassine Ben Salha+Semah Bader 1A3
* @version 0.1
* @date June 2020
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "heropartage.h"

/** 
* @brief initialisation deu background bot
* @param struct bg
* @return nothing
*/
void initbackgroundbot(background* bg)
{
	bg->bg = NULL;
	bg->camera.x = 0;
	bg->camera.y=0;
	bg->camera.w = 1200;
	bg->camera.h = 400;
	bg->bgposition.x =0 ;
	bg->bgposition.y = 400;
	bg->bg = IMG_Load("bgpartage.png");
}

/** 
* @brief initialisation de l'hero bot
* @param struct hero
* @return nothing
*/
void initbothero(hero* hero)
{
	hero->heroright = NULL;
	hero->heroleft = NULL;
	hero->mouselocation = 0;
	hero->frame = 0;
	hero->direction = 0;
	hero->heroright = IMG_Load("rightpartage.png");
	hero->heroleft = IMG_Load("leftpartage.png");
	hero->heroposition.x = 100;
	hero->heroposition.y = 700;
	hero->speedup = 1 ;
	hero->speeddown = 20 ;
	hero->directionjump = 0;
	hero->ground = 550 ;
	hero->gravity = 0;
	hero->herospeed=1;
	hero->heroisjumping = 0;


}


/** 
* @brief initialisation deu background top
* @param struct bg
* @return nothing
*/
void initbackgroundtop(background* bg)
{
	bg->bg = NULL;
	bg->camera.x = 0;
	bg->camera.y=0;
	bg->camera.w = 1200;
	bg->camera.h = 400;
	bg->bgposition.x = 0;
	bg->bgposition.y = 0;
	bg->bg = IMG_Load("bgpartage.png");
}

/** 
* @brief initialisation de l'hero top
* @param struct hero
* @return nothing
*/
void inittophero(hero* hero)
{
	hero->heroright = NULL;
	hero->heroleft = NULL;
	hero->mouselocation = 0;
	hero->frame = 0;
	hero->direction = 0;
	hero->heroright = IMG_Load("rightpartage.png");
	hero->heroleft = IMG_Load("leftpartage.png");
	hero->heroposition.x = 100;
	hero->heroposition.y = 300;
	hero->speedup = 1 ;
	hero->speeddown = 20 ;
	hero->directionjump = 0;
	hero->ground = 550 ;
	hero->gravity = 0;
	hero->herospeed=1;
	hero->heroisjumping = 0;


}

/** 
* @brief setrects du spritesheet de l'hero left
* @param struct hero
* @return nothing
*/
void setrectsleftp(hero* hero)
{
    for(int i = 0; i < 6; i ++ )
    {
        hero->rectsleft[i].x = 250 - i*50;
        hero->rectsleft[i].y = 0;
        hero->rectsleft[i].w = 50;
        hero->rectsleft[i].h = 150;
    }
}

/** 
* @brief setrects du spritesheet de l'hero right
* @param struct hero
* @return nothing
*/
void setrectsrightp(hero* hero)
{
    for(int i = 0; i < 5 ; i ++ )
    {
        hero->rectsright[i].x = i*50.5;
        hero->rectsright[i].y = 0;
        hero->rectsright[i].w = 50;
        hero->rectsright[i].h = 100;
    }
    hero->rectsright[5].x = 260 ;
    hero->rectsright[5].y = 0;
    hero->rectsright[5].w = 50;
    hero->rectsright[5].h = 100;
}



/** 
* @brief sdeplacer l'hero
* @param struct hero,choixdeplacement
* @return nothing
*/
void deplacerhero(hero* hero ,int choixdeplacement)
{

if ( hero->frame <= 5 )
	{
	hero->frame = hero->frame + 1 ;
	}
	if ( hero->frame > 5 )
	{
	hero->frame = 0 ;
	}

switch(choixdeplacement)
{
	case 1 :
	{

		hero->heroposition.x+=0;
	
 
	}break;
	
	case 2 :
	{

		hero->heroposition.x-=0;
	
	}break;

}
SDL_Delay(50);
}



/** 
* @brief bits du spritesheets de l'hero 
* @param struct screen,choix,hero,bg
* @return nothing
*/
void blit(SDL_Surface *screen,int choix,hero* hero,background* bg)
{
switch(choix)
{
	case 1 : 
	{

		SDL_BlitSurface(hero->heroright,&(hero->rectsright[hero->frame]), screen, &(hero->heroposition));


	}break;
	
	case 2 :
	{

		SDL_BlitSurface(hero->heroleft, &(hero->rectsleft[hero->frame]), screen, &(hero->heroposition));


	}break;
}

}

/** 
* @brief scrollinh à droite
* @param struct bg
* @return nothing
*/
void scrollingright(background* bg)
{
if ( bg->camera.x >= 8800 )
{
	bg->camera.x = 8800;
}
else 
	bg->camera.x += 10;

}

/**
* @brief scrolling à gauche
* @param struct bg
* @return nothing
*/

void scrollingleft(background* bg)
{
if ( bg->camera.x ==0 )
{
	bg->camera.x = 0;
}
else 
	bg->camera.x -= 10;

}





/////////////////////////////////////////////////////////////

/****************************************************************/

/////////////////////////////////////////////////////////////


































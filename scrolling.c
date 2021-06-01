/***************************************************************************************/
                               //****scrolling.c****//
#include<stdio.h>

#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#include "s.h"

int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg = SDL_LoadBMP("../images/background.bmp");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}

	Backg->backgroundCollide = SDL_LoadBMP("../images/background.bmp");
	if (Backg->backgroundCollide == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}
	return (0);
}


void initBackground(Background *Backg)
{       
        int SCREEN_W , SCREEN_H;
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=SCREEN_W;
	Backg->backgroundPos.h=SCREEN_H;
}

void blitBackground(Background*Backg,SDL_Surface *screen)
{
	//Blit the bachground to the backbuffer

        int SCREEN_W;

	if(Backg->backgroundPos.x>Backg->backgroundImg->w-SCREEN_W)
		Backg->backgroundPos.x=0;
	if(Backg->backgroundPos.x<0)
		Backg->backgroundPos.x=Backg->backgroundImg->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); //scrolling horizontal

}

void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}
//******************************************************************//
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>


struct Background
{
	SDL_Surface *backgroundImg;
	SDL_Surface *backgroundCollide;
	SDL_Rect backgroundPos;
};
typedef struct Background Background;

int loadBackground(Background *Backg);
void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitBackground(Background*Backg,SDL_Surface *screen);

#endif

/*******************************************************************//
#include<stdio.h>

#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"s.h"

 

void scrolling (SDL_Rect* camera)
{
    camera->x+=10;
    if (camera->x>=16000-1200)//si arriver a la fin(c'est tas dire la largeur final du background ki est 3837 ici )on remet la camera au debut a la position x = 0
    {
        camera->x=14800;
    }
}

void scrollingb (SDL_Rect* camera)
{
    camera->x-=10;
    if (camera->x == 0)//si arriver a la fin(c'est tas dire la largeur final du background ki est 3837 ici )on remet la camera au debut a la position x = 0
    {
        camera->x <= 10;
    }
}


int main(int argc, char *argv[])
{
 
SDL_Surface *ecran = NULL, *fond = NULL , *perso= NULL , *obstacle = NULL ;
SDL_Rect camera;

camera.h = 600 ;
camera.w = 800 ; 
 SDL_Rect positionf,posp, pos;
pos.x =50;
pos.y =50;
positionf.x = 10;
positionf.y = 0;
posp.x =10 ;
posp.y=150;
SDL_Init(SDL_INIT_VIDEO);
 
 ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   fond = IMG_Load("fond.jpg");
   SDL_BlitSurface(fond, NULL, ecran, &positionf);
    perso = IMG_Load("personnage.png");
   SDL_BlitSurface(perso, NULL, ecran, &posp); 
   obstacle = IMG_Load("obstacle.jpg");
    SDL_BlitSurface(obstacle, NULL, ecran, &pos); 
   
 SDL_Flip(ecran); 
  
 int continuer = 1;
  SDL_Event event;
  SDL_EnableKeyRepeat(10,10);
   while (continuer)
{    
     SDL_WaitEvent(&event);
    switch(event.type)
    { 
         case SDL_QUIT:
            continuer = 0;
          break ;
      break ;
         /*case SDL_MOUSEMOTION:
   if((event.motion.x != posp.x) || (event.motion.y != posp.y))
   {

      
       posp.x = event.motion.x ;
             scrollingb (&camera);
          SDL_BlitSurface(perso, NULL, ecran, &posp);
         SDL_BlitSurface(obstacle, NULL, ecran, &pos);
        SDL_BlitSurface(fond, &camera, ecran, &positionf);  
       SDL_Flip(ecran);
       
    }*/
            break; 
         case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
   {
        case SDL_QUIT:
            continuer = 0;
            break;
           case SDLK_UP:
            posp.y--;
            scrollingb (&camera);
            SDL_BlitSurface(fond, NULL, ecran, &positionf);
            SDL_BlitSurface(perso, NULL, ecran, &posp);
             SDL_BlitSurface(obstacle, NULL, ecran, &pos); 
            SDL_Flip(ecran);
            
            break;
           case SDLK_DOWN:
            posp.y++;
            scrolling (&camera);
            SDL_BlitSurface(fond, NULL, ecran, &positionf);
            SDL_BlitSurface(perso, NULL, ecran, &posp);
               SDL_BlitSurface(obstacle, NULL, ecran, &pos); 
            SDL_Flip(ecran);
             break;
             case SDLK_RIGHT:
              posp.x++;
              scrolling (&camera);
              SDL_BlitSurface(fond, &camera, ecran, &positionf);
              SDL_BlitSurface(perso, NULL, ecran, &posp);
              SDL_BlitSurface(obstacle, NULL, ecran, &pos); 
              SDL_Flip(ecran);
               break;
           case SDLK_LEFT:
                  posp.x--;
                  scrollingb (&camera);
                  SDL_BlitSurface(fond, &camera, ecran, &positionf);
                  SDL_BlitSurface(perso, NULL, ecran, &posp);
                  SDL_BlitSurface(obstacle, NULL, ecran, &pos); 
                  SDL_Flip(ecran);
             break;
 
          }
    }
}
SDL_Flip(ecran);
Mix_CloseAudio();

SDL_FreeSurface(fond);
SDL_FreeSurface(perso);
 
SDL_Quit();
return EXIT_SUCCESS;

   
}

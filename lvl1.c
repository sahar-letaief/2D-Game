#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "hero.h"




void jouer(SDL_Surface* screen)
{

    

    heros hero;



    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1200,800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    camera c;
    initcamera (&c);
    

    SDL_Surface   *menu1=NULL ;
    int continuer = 1;
    SDL_Rect positionMenu1;
    menu1 = IMG_Load("lvl1.png");
    positionMenu1.x=0;
    positionMenu1.y=0;
    
    minihero mh;
    initialiserminihero(&mh);


    initialisation(&hero);
    setrectsright(&hero);
    setrectsleft(&hero);
    


  blitfenetre(positionMenu1,screen,1,menu1,&hero,&c);
blitminihero(screen,&mh);
SDL_Flip(screen);
      SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
    while(continuer!=0)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {

            case SDL_QUIT:
                continuer=0;
                break;



            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                case SDLK_ESCAPE:
                    continuer=0;
                    break;

                case SDLK_RIGHT:

	hero.directionjump = 1;
			deplacerjoueur(&hero,1);
			scrolling (&c,&hero);
			blitfenetre(positionMenu1,screen,1,menu1,&hero,&c);	
blitminihero(screen,&mh);
deplacer (&mh,&hero);
mh.directiondep = 1;

			
                    break;

                case SDLK_LEFT :
	hero.directionjump = 2;
			deplacerjoueur(&hero,2);
			scrollingb (&c,&hero);	
			blitfenetre(positionMenu1,screen,2,menu1,&hero,&c);
blitminihero(screen,&mh);
deplacer (&mh,&hero);
mh.directiondep = 2;

                    break;

                

		case SDLK_LCTRL : 


hero.heroisjumping = 1;


		break;
	 
		case SDLK_LSHIFT :
		speed(&hero);
		break;
		}
                break;
		case SDL_KEYUP:
		{
 switch(event.key.keysym.sym)
{
		 
		}
}	
                break;
            }



jump (&hero);

blitminihero(screen,&mh);

        }//taskiret pollevent

resetafterjump (&hero,&c);
blitminihero(screen,&mh);
if ( hero.directionjump == 1 )
{
blitfenetre(positionMenu1,screen,1,menu1,&hero,&c);
	     SDL_Flip(screen);
}
if ( hero.directionjump == 2 ) 
{
blitfenetre(positionMenu1,screen,2,menu1,&hero,&c);
	     SDL_Flip(screen);
}
			

              
           
    }
    SDL_FreeSurface(menu1);
    SDL_FreeSurface(hero.heroright);
    SDL_FreeSurface(hero.heroleft);
    SDL_FreeSurface(screen);
}



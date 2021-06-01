#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "hero.h"

void initialisation(heros* hero)
{
	hero->heroright = NULL;
	hero->heroleft = NULL;
	hero->mouselocation = 0;
	hero->frame = 0;
	hero->direction = 0;
	hero->heroright = IMG_Load("right.png");
	hero->heroleft = IMG_Load("left.png");
	hero->heroposition.x = 100;
	hero->heroposition.y = 650;
	hero->herorelativeposition.x = -100 ;
	hero->herorelativeposition.y = 0;
	hero->speedup = 1 ;
	hero->speeddown = 20 ;
	hero->directionjump = 0;
	hero->ground = 650 ;
	hero->gravity = 0;
	hero->herospeed=1;
	hero->heroisjumping = 0;



}



void setrectsleft(heros* hero)
{
    for(int i = 0; i < 5; i ++ )
    {
        hero->rectsleft[i].x = 250 - i*50;
        hero->rectsleft[i].y = 0;
        hero->rectsleft[i].w = 50;
        hero->rectsleft[i].h = 100;
    }
}


void setrectsright(heros* hero)
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





void deplacerjoueur(heros* hero ,int choixdeplacement)
{

if ( hero->frame < 5 )
	{
	hero->frame = hero->frame + 1 ;
	}
	if ( hero->frame >= 5 )
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

void resetafterjump ( heros* hero,camera* c)
{
	int speeddown ;
	speeddown = hero->speeddown;
	if ( speeddown >= 1 )
	{
		speeddown -= 1;
	}
	if ( hero->heroposition.y < hero->ground ) 
	{
		hero->heroposition.y += (hero->heroposition.y/30)+2;
		SDL_Delay(speeddown);
	}
	if ( hero->heroposition.y >= hero->ground )
	{
		hero->heroposition.y = hero->ground;
		hero->heroisjumping = 0;
	}
	if ( (hero->directionjump == 1) &&(hero->heroisjumping == 1) )
	{
		scrolling (c,hero);
	}
	if ( (hero->directionjump == 2)&&(hero->heroisjumping == 1) )
	{
		scrollingb (c,hero);
	}
SDL_Delay(20);
}



void jump (heros* hero)
{

		if ( hero->heroisjumping == 1 )
		{
			if ( hero->gravity == 0 )
			{
				hero->heroposition.y -= (hero->heroposition.y/30);
				SDL_Delay(hero->speedup);
			}
			if( hero->speedup <= 10)
			{
				hero->speedup +=1;
			}

			if ( hero->heroposition.y <= 450 )
			{
				hero->gravity = 1;
			}
			if ( hero->gravity == 1 )
			{
				SDL_Delay(hero->speeddown);
				if ( hero->speeddown >=1 )
				{
					hero->speeddown -= 1;
				}
				if ( hero->heroposition.y >= hero->ground )
				{
					hero->heroposition.y = hero->ground;
					restart_jump(hero); 
					hero->heroisjumping = 0;
				}
				if ( hero->heroposition.y != hero->ground )
				{
					hero->heroposition.y += (hero->heroposition.y/30)+2;
				}			
			} 
			

		}//taskiret heroisjumping
		
	


}


void restart_jump ( heros* hero ) 
{
	hero->speedup = 0;
	hero->gravity = 0;
	hero->speeddown = 20;
}




void blitfenetre(SDL_Rect positionMenu1,SDL_Surface *screen,int choix,SDL_Surface *menu1,heros* hero,camera* c)
{
switch(choix)
{
	case 1 : 
	{
		SDL_BlitSurface(menu1,&c->camera,screen,&positionMenu1);
		if ( hero->heroisjumping == 1 )
		{
	                SDL_BlitSurface(hero->heroright,&(hero->rectsright[0]), screen, &(hero->heroposition));
		}
		else
                	SDL_BlitSurface(hero->heroright,&(hero->rectsright[hero->frame]), screen, &(hero->heroposition));
	}break;
	
	case 2 :
	{
		SDL_BlitSurface(menu1,&c->camera,screen,&positionMenu1);
		if ( hero->heroisjumping == 1 )
		{
                	SDL_BlitSurface(hero->heroleft, &(hero->rectsleft[0]), screen, &(hero->heroposition));
		}
		else 
	                SDL_BlitSurface(hero->heroleft, &(hero->rectsleft[hero->frame]), screen, &(hero->heroposition));
	}break;
}

}

void speed(heros* hero)
{
	if ( hero->herospeed <= 1 )
	{
		hero->herospeed+=1;
	}
	if ( hero->herospeed > 1 )
	{
		hero->herospeed = 0;
	}
}



////////////////////////////////////////////////////////////////////////////////////

void initcamera ( camera* c)
{
	c->camera.x=0;
	c->camera.y=0;
	c->camera.h=800;
	c->camera.w=1200;
}

void scrolling (camera* c,heros* hero)
{
	
	
	if ( hero->herospeed == 0 )
	{
		c->camera.x+=10;
	}
	if ( hero->herospeed == 1 )
	{
		c->camera.x+=15;
	}

    if (c->camera.x >=16000-1200)
    {
        c->camera.x=14800;
    }

}



void scrollingb (camera* c,heros* hero)
{
	
	if ( hero->herospeed == 0 )
	{
		c->camera.x-=10;
	}
	if ( hero->herospeed == 1 )
	{
		c->camera.x-=15;
	}
	

    if (c->camera.x == 0)
    {
        c->camera.x = 0;
    }
}





//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////MINI HERO////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////

void initialiserminihero(minihero* mh)
{
	mh->minihero = NULL;
	mh->minimap = NULL;
	mh->minimapfocus = NULL;

	


	mh->miniheroposition.x = 770;
	mh->miniheroposition.y = 175; 

	mh->positionminimap.x = 750;
	mh->positionminimap.y = 100;

	mh->positionfocus.x = 750;
	mh->positionfocus.y = 100;

	mh->directiondep = 0;

	mh->minihero = IMG_Load("minihero.png");
	mh->minimap = IMG_Load("minimap.png");
	mh->minimapfocus = IMG_Load("focusminimap.png");
}


void deplacer ( minihero* mh,heros* hero)
{
switch (mh->directiondep )
{
	case 1 : 
	{	

if ( hero->herospeed == 1) 
	{
		if( ( mh->positionfocus.x < 1150 ) && ( mh->miniheroposition.x <= 1100 ) )
		{
			mh->positionfocus.x+=1;
			mh->miniheroposition.x+=1;
		}
}
if ( hero->herospeed == 2) 
	{
		if( ( mh->positionfocus.x < 1150 ) && ( mh->miniheroposition.x <= 1100 ) )
		{
			mh->positionfocus.x+=1.5;
			mh->miniheroposition.x+=1.5;
		}
}
	}break;
	case 2 : 
	{

if ( hero->herospeed == 1) 
	{
		if( ( mh->positionfocus.x > 750 ) && ( mh->miniheroposition.x > 770 ) )
		{
			mh->positionfocus.x-=1;
			mh->miniheroposition.x-=1;
		}
}
if ( hero->herospeed == 2) 
	{
		if( ( mh->positionfocus.x > 750 ) && ( mh->miniheroposition.x > 770 ) )
		{
			mh->positionfocus.x-=1.5;
			mh->miniheroposition.x-=1.5;
		}
}
	
	}break;
}

}


void blitminihero(SDL_Surface *screen,minihero* mh)
{

   SDL_BlitSurface(mh->minimap,NULL,screen,&(mh->positionminimap) );

   SDL_BlitSurface(mh->minimapfocus,NULL,screen,&(mh->positionfocus));

   SDL_BlitSurface(mh->minihero,NULL,screen,&(mh->miniheroposition));

	      SDL_Flip(screen);
}




















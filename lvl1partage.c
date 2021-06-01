/**
* @file lvl1partage.c
* @brief  jouer avec un partage d'ecran
* @author NOT YET Yassine Ben Salha+ Semah Bader 1A3
* @version 0.1
* @date June 2020
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enemiepartage.h"
#include "heropartage.h"





void jouerpartage(SDL_Surface* screen)
{

    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    Mix_Chunk *coin_sound=NULL;

    SDL_Rect anim_enemie2top[6], cointop[21],anim_enemie2bot[6], coinbot[21];
    int frame_enemie2bot,frame_enemie2top;

    entite_second_artif enemie1top,enemie1bot;

    entite_second_fix coinstop[3],enemie2top,coinsbot[3],enemie2bot;


    SDL_Rect positionMenu1;
    int test=0,i;

    inti_enemietop(anim_enemie2top, &enemie1top, coinstop, cointop,&coin_sound,&enemie2top,positionMenu1);
    inti_enemiebot(anim_enemie2bot, &enemie1bot, coinsbot, coinbot,&coin_sound,&enemie2bot,positionMenu1);

////////////////////////////////////////////////
	int righttop = 0,lefttop = 0, rightbot = 0 , leftbot = 0  ;
    hero herotop,herobot;
    background bgtop,bgbot;


    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1200,800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    int continuer = 1;
    
    initbackgroundtop(&bgtop);
    initbackgroundbot(&bgbot);

    inittophero(&herotop);
    initbothero(&herobot);

    setrectsleftp(&herobot);
    setrectsrightp(&herobot);

    setrectsleftp(&herotop);
    setrectsrightp(&herotop);
    

		SDL_BlitSurface(bgbot.bg,&bgbot.camera,screen,&(bgbot.bgposition));
    		SDL_BlitSurface(bgtop.bg,&bgtop.camera,screen,&(bgtop.bgposition));

blit(screen,1,&herobot,&bgbot);
blit(screen,1,&herotop,&bgtop);

Afficher_Etitespartage(screen,anim_enemie2top,&enemie1top,coinstop,cointop,&test,&enemie2top,herotop.heroposition);
Afficher_Etitespartage(screen,anim_enemie2bot,&enemie1bot,coinsbot,coinbot,&test,&enemie2bot,herobot.heroposition);


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

righttop = 1 ;
herotop.direction = 1 ;

                    break;

                case SDLK_LEFT :

lefttop = 1;
herotop.direction = 2 ;
                    break;
		
		case SDLK_q:

leftbot = 1 ;
herobot.direction = 2 ;
		break;

		case SDLK_d:

rightbot = 1 ;
herobot.direction = 1 ;
		break;
	
		}
                break;
		case SDL_KEYUP:
		{
 switch(event.key.keysym.sym)
{
		case SDLK_RIGHT : 
		righttop = 0 ;
		break;

		case SDLK_LEFT : 
		lefttop = 0 ;
		break;

		case SDLK_q : 
		leftbot = 0 ;
		break;

		case SDLK_d : 
		rightbot = 0 ;
		break;
		 
}
}	
                break;
            }
////////////////////////////////////


		
    		
if ( righttop == 1 )
{
deplacerhero(&herotop ,1);
SDL_BlitSurface(bgtop.bg,&bgtop.camera,screen,&(bgtop.bgposition));
blit(screen,1,&herotop,&bgtop);
if(Bounding_Boxpartage(&herotop.heroposition,&enemie2top.tpos) == 1 )
                    {}
                    else
                    {
                        scrollingright(&bgtop);
                        enemie2top.tpos.x-=10;
                        enemie1top.tpos.x-=10;
                        coinstop[0].tpos.x-=10;
                        coinstop[1].tpos.x-=10;
                        coinstop[2].tpos.x-=10;
                    }
}

if ( lefttop == 1 ) 
{
deplacerhero(&herotop ,2);
SDL_BlitSurface(bgtop.bg,&bgtop.camera,screen,&(bgtop.bgposition));
blit(screen,2,&herotop,&bgtop);
scrollingleft(&bgtop);


}

if ( rightbot == 1 )
{
deplacerhero(&herobot ,1);
SDL_BlitSurface(bgbot.bg,&bgbot.camera,screen,&(bgbot.bgposition));
blit(screen,1,&herobot,&bgbot);
if(Bounding_Boxpartage(&herobot.heroposition,&enemie2bot.tpos) == 1 )
                    {}
                    else
                    {
                        scrollingright(&bgbot);
                        enemie2bot.tpos.x-=10;
                        enemie1bot.tpos.x-=10;
                        coinsbot[0].tpos.x-=10;
                        coinsbot[1].tpos.x-=10;
                        coinsbot[2].tpos.x-=10;
                    }

}


if ( leftbot == 1 ) 
{
deplacerhero(&herobot ,2);
SDL_BlitSurface(bgbot.bg,&bgbot.camera,screen,&(bgbot.bgposition));
blit(screen,2,&herobot,&bgbot);
scrollingleft(&bgbot);

}
















 for(i=0; i<3; i++)
            {
                if(Colllision_Trigopartage ( herotop.heroposition,coinstop[i].tpos)==1)
                {
                    Mix_PlayChannel(1,coin_sound,0);
                    SDL_Delay(10);
                    coinstop[i].image=NULL;
                    coinstop[i].tpos.x=-200;
                    coinstop[i].tpos.y=-200;




                }

            }

 for(i=0; i<3; i++)
            {
                if(Colllision_Trigopartage ( herobot.heroposition,coinsbot[i].tpos)==1)
                {
                    Mix_PlayChannel(1,coin_sound,0);
                    SDL_Delay(10);
                    coinsbot[i].image=NULL;
                    coinsbot[i].tpos.x=-200;
                    coinsbot[i].tpos.y=-200;




                }

            }


Afficher_Etitespartage(screen,anim_enemie2top,&enemie1top,coinstop,cointop,&test,&enemie2top,herotop.heroposition);
Afficher_Etitespartage(screen,anim_enemie2bot,&enemie1bot,coinsbot,coinbot,&test,&enemie2bot,herobot.heroposition);
SDL_Flip(screen);


        }//taskiret pollevent




SDL_BlitSurface(bgtop.bg,&bgtop.camera,screen,&(bgtop.bgposition));
SDL_BlitSurface(bgbot.bg,&bgbot.camera,screen,&(bgbot.bgposition));

if ( herotop.direction == 1 )
{
blit(screen,1,&herotop,&bgtop);
}

if (herotop.direction == 2 )
{
blit(screen,2,&herotop,&bgtop);
}

if ( herobot.direction == 1 )
{
blit(screen,1,&herobot,&bgbot);
}
if ( herobot.direction == 2 )
{
blit(screen,2,&herobot,&bgbot);
}

Afficher_Etitespartage(screen,anim_enemie2top,&enemie1top,coinstop,cointop,&test,&enemie2top,herotop.heroposition);
Afficher_Etitespartage(screen,anim_enemie2bot,&enemie1bot,coinsbot,coinbot,&test,&enemie2bot,herobot.heroposition);
SDL_Flip(screen);
           SDL_Delay(24);
    }
    SDL_FreeSurface(bgtop.bg);
    SDL_FreeSurface(bgbot.bg);
    SDL_FreeSurface(herotop.heroright);
    SDL_FreeSurface(herotop.heroleft);
    SDL_FreeSurface(herobot.heroright);
    SDL_FreeSurface(herobot.heroleft);



}


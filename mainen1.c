
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigme1.h"
#include<time.h>


int main()
{

    SDL_Surface *screen=NULL, *texte=NULL;
    enigme  e;
    int r2,r1=10,run =1,running=1,alea,cond1=0,cond2=0;
    int x1,x2 ;
    char image[30]="";
    SDL_Event event;
    srand(time(NULL));
    SDL_Init ( SDL_INIT_VIDEO ) ;
    Mix_Music *chrono;
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    SDL_EnableUNICODE( SDL_ENABLE ); //obtain the character codes corresponding to received keyboard events
    screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
    init_enigme(&e);
    chrono=Mix_LoadMUS("chrono.mp3");
    Mix_PlayMusic(chrono, 1);
    srand(time(NULL));
    while (run)
    {  running=1;
       if (Mix_PlayingMusic()==0)
              
                 { 
                   running=0;
                   run=0;
                   }
        SDL_PollEvent(&event);
        if( event.type == SDL_QUIT)
        {   
            run = 0;
        }

        generate_afficher ( screen, image,&e,&alea) ;

        solution_e1 (screen,image,&x1,&x2) ;

        printf("%d      %d\n",x1,x2);

        if(cond2!=1)
        {
            cond2=1 ;
            do
            {
                r2=resolution1 (&running,&run ) ;
            }
            while(r2<0 || r2>9) ;
        }
        if(cond1!=1)
        {
            cond1=1 ;
            do
            {
                r1=resolution1 (&running,&run ) ;
            }
            while(r1<0 || r1>9) ;
        }
//printf("%d    %d\n",r1,r2);

        afficher_reponse(screen,r1,r2);
        e.result=afficher_resultat (screen,r1,r2,&e,x1,x2) ;
        printf("%d \n",e.result);
        while(running)
        {  if (e.result==1)
            
                 { 
                   running=0;
                   run=0;
                   }
          if (Mix_PlayingMusic()==0)
              
                 { 
                   running=0;
                   run=0;
                   }
            SDL_WaitEvent(&event);
            switch(event.type)
            {
            case SDL_QUIT :
               //running =0;
                run=0 ;
                break ;
            case SDL_KEYDOWN :
               {
                   switch( event.key.keysym.sym )
                {
                case  SDLK_ESCAPE:
                   {running= 0 ;
                    generate_afficher ( screen, image,&e,&alea) ;
                    cond1=0 ;
                    cond2=0 ;
                   } break ;
                }
            }break ;
            }
        }

    
}


SDL_FreeSurface(screen);
Mix_FreeMusic(chrono);
Mix_CloseAudio();
SDL_Quit();

return e.result;

}


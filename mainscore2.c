#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "score2.h"



int main()
{

    SDL_Surface *screen=NULL, *texte=NULL;
    int continuer=1;
    char image[30]="";
    SDL_Event event;
    SDL_Init ( SDL_INIT_VIDEO ) ;
    SDL_EnableUNICODE( SDL_ENABLE ); //obtain the character codes corresponding to received keyboard events
    screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
    score s;
    init_score(&s);
    s.imgback=IMG_Load("1.jpg");
    s.img1=IMG_Load("0.png");
    s.img2=IMG_Load("0.png");
    
    while (continuer)
    {
        SDL_PollEvent(&event);
        
        if(event.type==SDL_QUIT)/* Si c'est un événement de type "Quitter" */
            continuer = 0;
            generate_afficher (screen, image,&s) ;

    }
    SDL_FreeSurface(screen);
    SDL_Quit();

}

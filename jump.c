#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void setrects1(SDL_Rect* clip)
{
    for(int i=0; i<6; i++)
    {
        clip[i].x +=50;
        clip[i].y =0;
        clip[i].w =50;
        clip[i].h =100;
    }
}

int main ( int argc, char** argv )
{

    SDL_Init( SDL_INIT_VIDEO );
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);


    SDL_Surface* menu = IMG_Load("menu.jpg");
    SDL_Rect positionMenu;
    positionMenu.x=0;
    positionMenu.y=0;

    //On charge du joueur
    SDL_Surface* sprite1 = IMG_Load("hejer1.png");

    SDL_Rect posSpriteAbsolue;
    posSpriteAbsolue.x = 200;
    posSpriteAbsolue.y = 300-(sprite1->h);
    SDL_Rect rects1[6];
    setrects1(rects1);

    SDL_Rect posSpriteRelative;
    posSpriteRelative.x = -50;
    posSpriteRelative.y = 0;


    int running = 1,test=0;
    SDL_Event event;
    const int FPS = 30;
    Uint32 start;
    int frame = 0;
    SDL_SetColorKey(screen,SDL_SRCCOLORKEY, SDL_MapRGB(screen->format,255,255,255));

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = 0;
                break;

            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running=0;
                if (event.key.keysym.sym == SDLK_j)
                    test=5;

            }
            break;

            case SDL_KEYUP:
                test=0;
                break;

            }//fermeture de switch
        }//fermeture du SDL_Poll

        if(test==5)
        {
            //notre joeur avance de 1:
            posSpriteRelative.x++;
            //si notre sprite quite l'ecran lors du saut
            if(posSpriteRelative.x>=50)
            {
                posSpriteRelative.x=-50;
            }

            //remise à 0:
            posSpriteAbsolue.x = 200;
            posSpriteAbsolue.y = 300-(sprite1->h);

            //calcul
            posSpriteRelative.y=(-0.04*(posSpriteRelative.x*posSpriteRelative.x)+100);

            //le joueur tombe et remonte.
            posSpriteAbsolue.x = posSpriteAbsolue.x + posSpriteRelative.x+50;
            posSpriteAbsolue.y = posSpriteAbsolue.y - posSpriteRelative.y;

            if(frame == 5)
            {
                frame = 0;
            }

            //delay

            if(3000/FPS > SDL_GetTicks()-start)
            {
                SDL_Delay(3000/FPS-(SDL_GetTicks()-start));
            }


            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
            SDL_BlitSurface(sprite1, &rects1[frame], screen, &posSpriteAbsolue);
            SDL_Flip(screen);
            SDL_BlitSurface(menu,NULL,screen,&positionMenu);
            frame ++;
            SDL_Flip(screen);
        }
    }//Fermeture du while(running)

    SDL_FreeSurface(menu);
    SDL_FreeSurface(sprite1);
    SDL_Quit();

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>


void setrects1(SDL_Rect* clip)
{
    clip[0].x =0;
    clip[0].y =0;
    clip[0].w =50;
    clip[0].h =100;

    clip[1].x =50;
    clip[1].y =0;
    clip[1].w =50;
    clip[1].h =100;

    clip[2].x =100;
    clip[2].y =0;
    clip[2].w =50;
    clip[2].h =100;

    clip[3].x =150;
    clip[3].y = 0;
    clip[3].w = 50;
    clip[3].h = 100;

    clip[4].x = 200;
    clip[4].y = 0;
    clip[4].w = 50;
    clip[4].h = 100;

    clip[5].x = 250;
    clip[5].y = 0;
    clip[5].w = 50;
    clip[5].h = 100;
}

void setrects2(SDL_Rect* clip)
{
    clip[0].x =250;
    clip[0].y =0;
    clip[0].w =50;
    clip[0].h =100;

    clip[1].x =200;
    clip[1].y =0;
    clip[1].w =50;
    clip[1].h =100;

    clip[2].x =150;
    clip[2].y =0;
    clip[2].w =50;
    clip[2].h =100;

    clip[3].x =100;
    clip[3].y = 0;
    clip[3].w = 50;
    clip[3].h = 100;

    clip[4].x = 50;
    clip[4].y = 0;
    clip[4].w = 50;
    clip[4].h = 100;

    clip[5].x = 0;
    clip[5].y = 0;
    clip[5].w = 84;
    clip[5].h = 68;
}


int main(int argc, char** argv[ ])
{
    int x,y;
    int test;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Rect rect;
    int h=720,w=1280;
    SDL_Surface *screen, *sprite1=NULL, *menu=NULL, *sprite2=NULL;
    screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Game", NULL);
    int running = 1;
    SDL_Event event;
    const int FPS = 30;
    Uint32 start;

    SDL_Rect positionMenu;
    int frame = 0;
    SDL_SetColorKey(screen,SDL_SRCCOLORKEY, SDL_MapRGB(screen->format,255,255,255));



    menu = IMG_Load("menu.jpg");
    positionMenu.x=0;
    positionMenu.y=0;

    sprite1 = IMG_Load("hejer1.png");
    rect.x = 0 ;
    rect.y = 0 ;
    SDL_Rect rects1[6];
    setrects1(rects1);


    sprite2 = IMG_Load("hejer2.png");
    SDL_Rect rects2[6];
    setrects2(rects2);

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

    while(running)
    {
        start = SDL_GetTicks();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {

            case SDL_QUIT:
                running = 0;
                break;

            case SDL_MOUSEBUTTONDOWN :
            {
                switch(event.button.button)
                {
                case SDL_BUTTON_RIGHT:

                {
                    test = 3 ;
                    x = event.button.x;
                    y = event.button.y;
                }
                break;

                case SDL_BUTTON_LEFT:

                {
                    test = 4 ;
                    x = event.button.x;
                    y = event.button.y;
                }
                break;
                }
            }
            break;

            case SDL_KEYDOWN:
            {

                if (event.key.keysym.sym == SDLK_RIGHT)
                    test = 1;

                if (event.key.keysym.sym == SDLK_LEFT)
                    test = 2;

            }
            break;
            case SDL_KEYUP:
                test=0;
                break;
            }
        }

        switch (test)
        {

        case 1:
        {
            rect.x += 5 ;
            if(frame == 5)
            {
                frame = 0;
            }

            if(5000/FPS > SDL_GetTicks()-start)
            {
                SDL_Delay(5000/FPS-(SDL_GetTicks()-start));
            }
            SDL_BlitSurface(sprite1, &rects1[frame], screen, &rect);
            SDL_Flip(screen);
            SDL_BlitSurface(menu,NULL,screen,&positionMenu);
            frame ++;
        }
        break;

        case 2:
        {

            rect.x -= 5 ;
            if(frame == 5)
            {
                frame = 0;
            }
            if(5000/FPS > SDL_GetTicks()-start)
            {
                SDL_Delay(5000/FPS-(SDL_GetTicks()-start));
            }
            SDL_BlitSurface(sprite2, &rects2[frame], screen, &rect);
            SDL_Flip(screen);
            SDL_BlitSurface(menu,NULL,screen,&positionMenu);
            frame ++;
        }
        break;
        case 3:
        {
            if   (x > rect.x+50)
            {
                rect.x += 5 ;
                if(frame == 5)
                {
                    frame = 0;
                }

                if(5000/FPS > SDL_GetTicks()-start)
                {
                    SDL_Delay(5000/FPS-(SDL_GetTicks()-start));
                }
                SDL_BlitSurface(sprite1, &rects1[frame], screen, &rect);
                SDL_Flip(screen);
                SDL_BlitSurface(menu,NULL,screen,&positionMenu);
                frame ++;
            }
        }
        break;

        case 4:
        {

            if   (x < rect.x+50)
            {
                rect.x -= 5 ;
                if(frame == 5)
                {
                    frame = 0;
                    rect.x -= 5 ;
                }

                if(5000/FPS > SDL_GetTicks()-start)
                {
                    SDL_Delay(5000/FPS-(SDL_GetTicks()-start));
                }
                SDL_BlitSurface(sprite2, &rects2[frame], screen, &rect);
                SDL_Flip(screen);
                SDL_BlitSurface(menu,NULL,screen,&positionMenu);
                frame ++;
            }
        }
        break;
        }
    }


    SDL_FreeSurface(sprite2);
    SDL_FreeSurface(menu);
    SDL_FreeSurface(sprite1);
    SDL_Quit();
    return 0 ;
}





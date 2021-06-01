#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme1.h"
#include <math.h>
#include <time.h> 


void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;
        e->result=0;


}


/*void affichage_chrono(SDL_Surface * screen,SDL_Surface *texte, SDL_Color couleurNoire)
{  int tempsPrecedent = 0, tempsActuel = 0;
   int temps;
     TTF_Font *police;
     SDL_Rect position;
        position.x = 60;
        position.y = 370;
 police = TTF_OpenFont("angelina.ttf", 65);
 tempsActuel = SDL_GetTicks();
 temps= (tempsActuel/1000) - (tempsPrecedent/1000);
 sprintf((char*)temps,"%d", tempsActuel);
 texte = TTF_RenderText_Blended(police, "hello", couleurNoire);
   
 SDL_BlitSurface(texte, NULL, screen, &position);

}
/*int gestion_temps()
{   int tempsPrecedent = 0, tempsActuel = 0;
    int test=1;
   tempsActuel = SDL_GetTicks();
    if (tempsActuel - tempsPrecedent < 6000)
      return(test);
    else {
       test=0;
       return (test);
       
         }
  
}*/

 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 

 *alea =  rand()%5 +1;
 sprintf(image ,"%d.jpg",*alea);
 e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
 SDL_Flip(screen) ;
}


void solution_e1 (SDL_Surface * screen ,char image [],int *x1,int *x2)
 {   SDL_Surface *img,*img1,*img2;
     SDL_Rect p,p1,p2;   
     float delta ;
     int a,b,c,d,i,j;
 	
 	
   do
{
       a=1;
       d=rand()%10;
       b=-d;
       c=rand()%10;
p.x=230;
p.y=320;
p1.x=410;
p1.y=320;
p2.x=570;
p2.y=320;
img=IMG_Load("c1.png");
SDL_BlitSurface(img,NULL,screen,&p);
SDL_Flip(screen);
 
//printf(" %d    %d    %d  %d\n",a,b,c,d);
       delta= pow(b,2) -4*a*c;

      *x1= (int) (-b- sqrt(delta))/(2*a) ;
      *x2= (int)(-b+(sqrt(delta)))/(2*a);
} while ((delta<0)&&((*x1<0)||(*x2<0)));
if(d==1)
{
img1=IMG_Load("c1.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==2)
{
img1=IMG_Load("c2.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==3)
{
img1=IMG_Load("c3.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==4)
{
img1=IMG_Load("c4.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==5)
{
img1=IMG_Load("c5.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==6)
{
img1=IMG_Load("c6.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==7)
{
img1=IMG_Load("c7.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==8)
{
img1=IMG_Load("c8.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==9)
{
img1=IMG_Load("c9.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==0)
{
img1=IMG_Load("c0.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}



if(c==1)
{
img2=IMG_Load("c1.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==2)
{
img2=IMG_Load("c2.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==3)
{
img2=IMG_Load("c3.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==4)
{
img2=IMG_Load("c4.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==5)
{
img2=IMG_Load("c5.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==6)
{
img2=IMG_Load("c6.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==7)
{
img2=IMG_Load("c7.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==8)
{
img2=IMG_Load("c8.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==9)
{
img2=IMG_Load("c9.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==0)
{
img2=IMG_Load("c0.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}


  }
 	





int resolution1 (int * running,int *run )
{
	SDL_Event event ;
 int r=-1;
               SDL_WaitEvent(&event);
		 if( event.type == SDL_QUIT)
                 {
                     *running= 0 ;
                     *run = 0;
		 }
	    if( event.type == SDL_KEYDOWN )
                 {

            if( ( event.key.keysym.unicode >= ((Uint16)48) ) && ( event.key.keysym.unicode <= ((Uint16)57)	 ) )
            { r=event.key.keysym.unicode-48;
	} 
		 }	
return r;

                 
	}

void afficher_reponse( SDL_Surface *screen, int r2, int r1)
{
   SDL_Surface *img3,*img4;
     SDL_Rect p3,p4;   
p3.x=600;
p3.y=460;
p4.x=650;
p4.y=460;

if(r1==1)
{
img3=IMG_Load("c1.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==2)
{
img3=IMG_Load("c2.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==3)
{
img3=IMG_Load("c3.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==4)
{
img3=IMG_Load("c4.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==5)
{
img3=IMG_Load("c5.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==6)
{
img3=IMG_Load("c6.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==7)
{
img3=IMG_Load("c7.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==8)
{
img3=IMG_Load("c8.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==9)
{
img3=IMG_Load("c9.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}
else if(r1==0)
{
img3=IMG_Load("c0.png");
SDL_BlitSurface(img3,NULL,screen,&p3);
SDL_Flip(screen);
}


if(r2==1)
{
img4=IMG_Load("c1.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==2)
{
img4=IMG_Load("c2.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==3)
{
img4=IMG_Load("c3.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==4)
{
img4=IMG_Load("c4.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==5)
{
img4=IMG_Load("c5.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==6)
{
img4=IMG_Load("c6.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==7)
{
img4=IMG_Load("c7.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==8)
{
img4=IMG_Load("c8.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==9)
{
img4=IMG_Load("c9.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}
else if(r2==0)
{
img4=IMG_Load("c0.png");
SDL_BlitSurface(img4,NULL,screen,&p4);
SDL_Flip(screen);
}

    }

int afficher_resultat (SDL_Surface * screen,int r2,int r1,enigme *en,int x1,int x2)
 { 	Mix_Chunk *wrong;
        Mix_Chunk *correct;
        wrong = Mix_LoadWAV("wrong.wav");
        correct = Mix_LoadWAV("correct.wav");

 	 if (((r1==x1)&&(r2==x2))||((r2==x1)&&(r1==x2)))
 	{       Mix_PlayChannel(1,correct,0);
                SDL_Delay(900);
 		en->img=IMG_Load("10.png");			 
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
                SDL_Flip(screen);
                Mix_FreeChunk(correct);
                return 1;
 	}
        
 	else
 	{       Mix_PlayChannel(1,wrong,0);
                SDL_Delay(900);
 		en->img=IMG_Load("01.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
                SDL_Flip(screen);
                Mix_FreeChunk(wrong);
                
                return -1;
 	}
 }
 


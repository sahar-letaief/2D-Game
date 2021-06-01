#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "score2.h"


void init_score(score *s)
{       s->pback.x=0;
	s->pback.y=0;
	s->p.x=800;
	s->p.y=50;
        s->p1.x=830;
        s->p1.y=50;
        s->p2.x=860;
        s->p2.y=50;
        s->imgback=NULL;	
	s->img=NULL;
        s->img1=NULL;
        s->img2=NULL;
        s->result=4;
}

void generate_afficher (SDL_Surface * screen  , char image [],score *s)
{ 
 SDL_BlitSurface(s->imgback,NULL,screen,&(s->pback)) ;
 
 sprintf(image ,"%d.png",s->result);
 s->img = IMG_Load(image);
 SDL_BlitSurface(s->img,NULL,screen,&(s->p)) ;

 SDL_BlitSurface(s->img1,NULL,screen,&(s->p1));

 SDL_BlitSurface(s->img2,NULL,screen,&(s->p2));
 SDL_Flip(screen);

}

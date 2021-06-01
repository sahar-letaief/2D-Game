#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enemiepartage.h"




//boundingbox colliision

int Bounding_Boxpartage(SDL_Rect* perso,SDL_Rect* obstacl )
{
   if((*perso).y >= (*obstacl).y + (*obstacl).h)
     return 0 ;
    if((*perso).x >= (*obstacl).x + (*obstacl).w)
     return 0 ;
    if((*perso).y + (*perso).h <= (*obstacl).y)
     return 0 ;
    if((*perso).x + (*perso).w <= (*obstacl).x)
     return 0 ;
   
    return 1 ;
}
////


//trigo collision 


float Distance_Cerclepartage(int X1,int Y1,int X2,int Y2)
{
   double x_distance=X2-X1;
   double y_distance=Y2-Y1;


 return (sqrt( ( pow(x_distance,2) ) +( pow(y_distance,2) ) ) ) ;

}


float Rayonpartage(SDL_Rect perso)
{ 
   float X1,Y1;

    X1 = perso.x +  perso.w/2    ;      
    Y1 = perso.y + perso.h/2    ;  
    
  if (perso.w < perso.h)   
       return perso.w/2  ; 

   else 
      return perso.h/2 ;
 
 
}


int Colllision_Trigopartage (SDL_Rect hero ,SDL_Rect position_enemie)
{
   float Distance1,Distance2;
   float R1,R2;

  Distance1 = Distance_Cerclepartage(hero.x,hero.y,position_enemie.x,position_enemie.y);
  R1= Rayonpartage(hero);
  R2= Rayonpartage(position_enemie);

  Distance2=R1+R2;


if ( Distance1  <=  Distance2)
  return 1;


else 
  return 0 ;


}

///////

// mvmt intellig artif (enemie 1)

void caractere_artifpartage(entite_second_artif *perso,SDL_Rect position_enemie2)
{

	

        if((*perso).sens==1)
     {
             (*perso).tpos.x+=5;
	     (*perso).compteur += 1;

           if(Bounding_Boxpartage(&(*perso).tpos,&position_enemie2)==1)
             {
                      (*perso).tpos.x-=10;
             } 

               if((*perso).compteur== 200 )
                {    
                   (*perso).sens=-1;
                 }
     }
       if((*perso).sens==-1)
     {
             (*perso).tpos.x-=5;   
		  (*perso).compteur -= 1;
           if(Bounding_Boxpartage(&(*perso).tpos,&position_enemie2)==1)
             {
                      (*perso).tpos.x+=10;
             } 

               if((*perso).compteur== 0 )
                {
                   (*perso).sens=1;
                 }
    }
  



}

///////


/// mvmt enemie2 
void Enemiepartage (SDL_Rect *perso,SDL_Rect *position_enemie)
{
 
             (*perso).x-=7;
            // if( Colllision_Trigo ( perso ,(*position_enemie))==1)

              if(Bounding_Boxpartage(perso,position_enemie)==1)
             {
                      (*perso).x+=7;
             } 



}

//////





//// animation enemie1
void setrects1partage(SDL_Rect* clip)
{
// sens 1

        clip[0].x = 0;
        clip[0].y = 2;
        clip[0].w = 75;
        clip[0].h = 104;

        clip[1].x = 128;
        clip[1].y = 2;
        clip[1].w = 75;
        clip[1].h = 104;

        clip[2].x = 200;
        clip[2].y = 2;
        clip[2].w = 75;
        clip[2].h = 104;

        clip[3].x = 277;
        clip[3].y = 2;
        clip[3].w = 75;
        clip[3].h = 104;

        clip[4].x = 353;
        clip[4].y = 2;
        clip[4].w = 75;
        clip[4].h = 104;

        clip[5].x = 427;
        clip[5].y = 2;
        clip[5].w = 75;
        clip[5].h = 104;

//sens -1

        clip[6].x = 790;
        clip[6].y = 2;
        clip[6].w = 65;
        clip[6].h = 104;

        clip[7].x = 726;
        clip[7].y = 2;
        clip[7].w = 65;
        clip[7].h = 104;

        clip[8].x = 654;
        clip[8].y = 2;
        clip[8].w = 65;
        clip[8].h = 104;

        clip[9].x = 577;
        clip[9].y = 2;
        clip[9].w = 65;
        clip[9].h = 104;

        clip[10].x = 501;
        clip[10].y = 2;
        clip[10].w = 65;
        clip[10].h = 104;

        clip[11].x = 427;
        clip[11].y = 2;
        clip[11].w = 65;
        clip[11].h = 104;


}

//// done !!!


///animation enemie2
void setrects2partage(SDL_Rect* clip)
{

        clip[0].x  =0;
        clip[0].y = 2;
        clip[0].w = 74;
        clip[0].h = 300;

        clip[1].x = 75;
        clip[1].y = 2;
        clip[1].w = 74;
        clip[1].h = 300;

        clip[2].x = 153;
        clip[2].y = 2;
        clip[2].w = 74;
        clip[2].h = 300;

        clip[3].x = 230;
        clip[3].y = 2;
        clip[3].w = 74;
        clip[3].h = 300;

        clip[4].x = 309;
        clip[4].y = 2;
        clip[4].w = 74;
        clip[4].h = 300;

        clip[5].x = 387;
        clip[5].y = 2;
        clip[5].w = 74;
        clip[5].h = 300;

}

//done !! 


/// animation coin


void setrects3partage(SDL_Rect* clip)
{

 //bronze coin 0--6

        clip[0].x  = 258;
        clip[0].y = 0;
        clip[0].w = 41;
        clip[0].h = 41;

        clip[1].x  =308;
        clip[1].y = 0;
        clip[1].w = 29;
        clip[1].h = 41;

        clip[2].x = 346;
        clip[2].y = 0;
        clip[2].w = 24;
        clip[2].h = 41;

        clip[3].x = 380;
        clip[3].y = 0;
        clip[3].w = 9;
        clip[3].h = 41;

        clip[4].x = 401;
        clip[4].y = 0;
        clip[4].w = 23;
        clip[4].h = 41;

        clip[5].x = 431;
        clip[5].y = 0;
        clip[5].w = 30;
        clip[5].h = 41;

        clip[6].x = 470;
        clip[6].y = 0;
        clip[6].w = 41;
        clip[6].h = 41;

// silver coin 7--13

        clip[7].x  = 514;
        clip[7].y = 0;
        clip[7].w = 41;
        clip[7].h = 41;

        clip[8].x  =563;
        clip[8].y = 0;
        clip[8].w = 29;
        clip[8].h = 41;

        clip[9].x = 601;
        clip[9].y = 0;
        clip[9].w = 24;
        clip[9].h = 41;

        clip[10].x = 634;
        clip[10].y = 0;
        clip[10].w = 9;
        clip[10].h = 41;

        clip[11].x = 655;
        clip[11].y = 0;
        clip[11].w = 23;
        clip[11].h = 41;

        clip[12].x = 686;
        clip[12].y = 0;
        clip[12].w = 30;
        clip[12].h = 41;

        clip[13].x = 724;
        clip[13].y = 0;
        clip[13].w = 41;
        clip[13].h = 41;

//gold coin 14--20

        clip[14].x  = 5;
        clip[14].y = 0;
        clip[14].w = 41;
        clip[14].h = 41;

        clip[15].x  =54;
        clip[15].y = 0;
        clip[15].w = 29;
        clip[15].h = 41;

        clip[16].x = 92;
        clip[16].y = 0;
        clip[16].w = 24;
        clip[16].h = 41;

        clip[17].x = 126;
        clip[17].y = 0;
        clip[17].w = 9;
        clip[17].h = 41;

        clip[18].x = 147;
        clip[18].y = 0;
        clip[18].w = 23;
        clip[18].h = 41;

        clip[19].x = 177;
        clip[19].y = 0;
        clip[19].w = 30;
        clip[19].h = 41;

        clip[20].x = 216;
        clip[20].y = 0;
        clip[20].w = 41;
        clip[20].h = 41;

}





void inti_enemiebot(SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[],SDL_Rect coin[],Mix_Chunk **coin_sound,entite_second_fix *enemie2,SDL_Rect positionMenu1 )
{

     enemie1->image=NULL;
     enemie1->image=IMG_Load("spreetsheet enemie01.png");
     enemie1->tpos.x=2500;
     enemie1->tpos.y=700;
     enemie1->compteur=0;
     enemie1->sens=1;
     enemie1->frame_enemie1=0;




    enemie2->image =IMG_Load("spreetsheet enemie02.png");
    enemie2->tpos.x=1800;
    enemie2->tpos.y=700; 
    enemie2->frame_brnz_silv_gold_coin=5; 


    coins[0].image =IMG_Load("spreetsheet coins01.png");
    coins[0].tpos.x=1000;
    coins[0].tpos.y=700; 
    coins[0].frame_brnz_silv_gold_coin=0; 

    coins[1].image =IMG_Load("spreetsheet coins01.png");
    coins[1].tpos.x=1200;
    coins[1].tpos.y=700;
    coins[1].frame_brnz_silv_gold_coin=7; 
 
    coins[2].image =IMG_Load("spreetsheet coins01.png");
    coins[2].tpos.x=1400;
    coins[2].tpos.y=700; 
    coins[2].frame_brnz_silv_gold_coin=14; 




       setrects1partage(enemie1->anim_enemie1);
       setrects2partage(anim_enemie2);
        setrects3partage(coin);
    (*coin_sound)= Mix_LoadWAV("coin.wav"); //Chargement de la musique
 

}


void inti_enemietop(SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[],SDL_Rect coin[],Mix_Chunk **coin_sound,entite_second_fix *enemie2,SDL_Rect positionMenu1 )
{

     enemie1->image=NULL;
     enemie1->image=IMG_Load("spreetsheet enemie01.png");
     enemie1->tpos.x=2500;
     enemie1->tpos.y=300;
     enemie1->compteur=0;
     enemie1->sens=1;
     enemie1->frame_enemie1=0;





    enemie2->image =IMG_Load("spreetsheet enemie02.png");
    enemie2->tpos.x=1800;
    enemie2->tpos.y=295; 
    enemie2->frame_brnz_silv_gold_coin=5; 


    coins[0].image =IMG_Load("spreetsheet coins01.png");
    coins[0].tpos.x=1000;
    coins[0].tpos.y=310; 
    coins[0].frame_brnz_silv_gold_coin=0; 

    coins[1].image =IMG_Load("spreetsheet coins01.png");
    coins[1].tpos.x=1200;
    coins[1].tpos.y=310;
    coins[1].frame_brnz_silv_gold_coin=7; 
 
    coins[2].image =IMG_Load("spreetsheet coins01.png");
    coins[2].tpos.x=1400;
    coins[2].tpos.y=310; 
    coins[2].frame_brnz_silv_gold_coin=14; 




       setrects1partage(enemie1->anim_enemie1);
       setrects2partage(anim_enemie2);
      // printf("******%d",*frame_enemie2);

        setrects3partage(coin);
    (*coin_sound)= Mix_LoadWAV("coin.wav"); //Chargement de la musique
 

}


void Afficher_Etitespartage(SDL_Surface *ecran,SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[], SDL_Rect coin[],int *test,entite_second_fix *enemie2,SDL_Rect heroposition)
{

             if(enemie2->tpos.x-heroposition.x<200)
                     (*test)=1;

             if(enemie1->compteur== 200 )
                 enemie1->frame_enemie1=7;

             if(enemie1->compteur== 0 )
                enemie1->frame_enemie1=1;

       // SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

            if(enemie1->sens==1)
                          {

                             SDL_BlitSurface(enemie1->image,&enemie1->anim_enemie1[enemie1->frame_enemie1] ,ecran,&enemie1->tpos);
                                 enemie1->frame_enemie1++;

                                if(enemie1->frame_enemie1==5)
                                  enemie1->frame_enemie1=1;

                          }
                        if(enemie1->sens==-1)
                          {
                             SDL_BlitSurface(enemie1->image,&enemie1->anim_enemie1[enemie1->frame_enemie1] ,ecran,&enemie1->tpos); 
                                 enemie1->frame_enemie1++;

                                if(enemie1->frame_enemie1==11)
                                  enemie1->frame_enemie1=7;

                          }


                         SDL_BlitSurface(enemie2->image,&anim_enemie2[enemie2->frame_brnz_silv_gold_coin],ecran,&enemie2->tpos); 


                        SDL_BlitSurface(coins[0].image,&coin[coins[0].frame_brnz_silv_gold_coin] ,ecran,& coins[0].tpos); 
                          coins[0].frame_brnz_silv_gold_coin++;

                               if(coins[0].frame_brnz_silv_gold_coin==6)
                                 coins[0].frame_brnz_silv_gold_coin=0;
                                 

                       SDL_BlitSurface(coins[1].image,&coin[coins[1].frame_brnz_silv_gold_coin] ,ecran,& coins[1].tpos);   
                          coins[1].frame_brnz_silv_gold_coin++;

                               if(coins[1].frame_brnz_silv_gold_coin==13)
                                 coins[1].frame_brnz_silv_gold_coin=7;
               
                        SDL_BlitSurface(coins[2].image,&coin[coins[2].frame_brnz_silv_gold_coin] ,ecran,& coins[2].tpos);     
                          coins[2].frame_brnz_silv_gold_coin++;

                               if(coins[2].frame_brnz_silv_gold_coin==20)
                                  coins[2].frame_brnz_silv_gold_coin=14;
                                 




                          caractere_artifpartage(enemie1,heroposition);


                                if((*test)==1)
                           { 
                              Enemiepartage (&(enemie2->tpos),&heroposition);
                              enemie2->frame_brnz_silv_gold_coin--;

                               if((enemie2->frame_brnz_silv_gold_coin)==0)
                                 enemie2->frame_brnz_silv_gold_coin=4;

                           }

}



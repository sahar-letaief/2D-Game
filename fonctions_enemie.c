/**  
     * @file fonctions_enemie.c  
     * @brief documentation de tache enemie 
     * @author  BADER SEMAH	
     * @version 0.6
*       
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enemie.h"
#include "hero.h"




//boundingbox colliision

/**  
* @brief  POUR DETECTER LA COLLISION ENTRE 2 ENTITES .  
* @param perso l'entite en mouvement  
* @param  obstacl l'entite fix   
* @return 1 si il y a collision , 0 si n'y a pas  
*/
int Bounding_Box(SDL_Rect* perso,SDL_Rect* obstacl )
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


/**  
* @brief  CALCULER LA DISTANCE ENTRE DEUX ENTITES CIRCULAIRE  .  
* @param X1 L'ABSICISSE DE 1ere ENTITE 
* @param Y1 L'ORDRE DE 1ere ENTITE 
* @param X2 L'ABSICISSE DE 2eme L'ENTITE 
* @param Y2 L'ORDRE DE 2eme L'ENTITE 
* @return DISTANCE ENTRE DEUX ENTITES   
*/
float Distance_Cercle(int X1,int Y1,int X2,int Y2)
{
   double x_distance=X2-X1;
   double y_distance=Y2-Y1;


 return (sqrt( ( pow(x_distance,2) ) +( pow(y_distance,2) ) ) ) ;

}


/**  
* @brief  CALCULER LE RAYON D'UN ENTITE CIRCULAIRE .  
* @param perso LES DEMENSION   
* @return LE RAYON 
*/
float Rayon(SDL_Rect perso)
{ 
   float X1,Y1;

    X1 = perso.x +  perso.w/2    ;      
    Y1 = perso.y + perso.h/2    ;  
    
  if (perso.w < perso.h)   
       return perso.w/2  ; 

   else 
      return perso.h/2 ;
 
 
}


/**  
* @brief  DETECTER SI IL YA UNE COLLISION ENTRE DEUX ENTITES CIRCULAIRE .  
* @param  hero LES DEMENSIONS 1ere entite  
* @param  position_enemie  LES DEMENSIONS DE 2eme ENTITE   
* @return (1) SI IL Y A UNE COLLISION , SI NON (0)  
*/
int Colllision_Trigo (SDL_Rect hero ,SDL_Rect position_enemie)
{
   float Distance1,Distance2;
   float R1,R2;

  Distance1 = Distance_Cercle(hero.x,hero.y,position_enemie.x,position_enemie.y);
  R1= Rayon(hero);
  R2= Rayon(position_enemie);

  Distance2=R1+R2;


if ( Distance1  <=  Distance2)
  return 1;


else 
  return 0 ;


}

///////

// mvmt intellig artif (enemie 1)

/**  
* @brief  LA MOUBEMENT DE L'ENEMIE 1 (INTELLIGENCE ARTIFICIEL)  .  
* @param  perso L'ENEMIE  
* @param  position_enemie2 POSITION DE L'HERO 
* @return Nothing  
*/
void caractere_artif(entite_second_artif *perso,SDL_Rect position_enemie2)
{

	

        if((*perso).sens==1)
     {
             (*perso).tpos.x+=5;
	     (*perso).compteur += 1;

           if(Bounding_Box(&(*perso).tpos,&position_enemie2)==1)
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
           if(Bounding_Box(&(*perso).tpos,&position_enemie2)==1)
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

/**  
* @brief  MOUVEMENT DE L'ENMIE FINAL .  
* @param  perso POSITION DE LENEMIE   
* @param  position_enemie POSITION DE L'HERO   
* @return Nothing  
*/
void Enemie (SDL_Rect *perso,SDL_Rect *position_enemie)
{
 
             (*perso).x-=1;
            // if( Colllision_Trigo ( perso ,(*position_enemie))==1)

              if(Bounding_Box(perso,position_enemie)==1)
             {
       			printf("***********************************");
                      (*perso).x+=1;
             } 



}

//////


//// animation enemie1

/**  
* @brief  INITIALISER LE TABLEAU D'ANIMATION DE L'ENEMIE 1  .  
* @param  clip RECTANGLE  
* @return Nothing  
*/
void setrects1(SDL_Rect* clip)
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

/**  
* @brief  INITIALISER LE TABLEAU D'ANIMATION DE L'ENEMIE 2  .  
* @param  clip RECTANGLE  
* @return Nothing  
*/
void setrects2(SDL_Rect* clip)
{

        clip[0].x  =0;
        clip[0].y = 2;
        clip[0].w = 74;
        clip[0].h = 200;

        clip[1].x = 75;
        clip[1].y = 2;
        clip[1].w = 74;
        clip[1].h = 200;

        clip[2].x = 153;
        clip[2].y = 2;
        clip[2].w = 74;
        clip[2].h = 200;

        clip[3].x = 230;
        clip[3].y = 2;
        clip[3].w = 74;
        clip[3].h = 200;

        clip[4].x = 309;
        clip[4].y = 2;
        clip[4].w = 74;
        clip[4].h = 200;

        clip[5].x = 387;
        clip[5].y = 2;
        clip[5].w = 74;
        clip[5].h = 200;

//shot  && dieng position animation

        clip[6].x = 463;
        clip[6].y = 2;
        clip[6].w = 97;
        clip[6].h = 104;

        clip[7].x = 577;
        clip[7].y = 2;
        clip[7].w = 91;
        clip[7].h = 104;

        clip[8].x = 689;
        clip[8].y = 2;
        clip[8].w = 95;
        clip[8].h = 104;

        clip[9].x = 808;
        clip[9].y = 2;
        clip[9].w = 83;
        clip[9].h = 104;

        clip[10].x = 922;
        clip[10].y = 2;
        clip[10].w = 77;
        clip[10].h = 104;

//shot animation

        clip[11].x =17 ;
        clip[11].y = 0;
        clip[11].w = 377;
        clip[11].h =109 ;

        clip[12].x =11 ;
        clip[12].y =118 ;
        clip[12].w = 383;
        clip[12].h = 87;

        clip[13].x =6 ;
        clip[13].y =210 ;
        clip[13].w =388 ;
        clip[13].h = 69;

        clip[14].x = 6;
        clip[14].y =286 ;
        clip[14].w =389;
        clip[14].h = 49;

        clip[15].x = 5;
        clip[15].y = 353;
        clip[15].w = 390;
        clip[15].h = 31;

        clip[16].x =3 ;
        clip[16].y = 405;
        clip[16].w = 391;
        clip[16].h =22 ;

        clip[17].x = 4;
        clip[17].y = 441;
        clip[17].w = 391;
        clip[17].h = 10;

// jump warning

        clip[18].x =0 ;
        clip[18].y = 0;
        clip[18].w = 220;
        clip[18].h =220 ;

        clip[19].x = 221;
        clip[19].y = 0;
        clip[19].w = 220;
        clip[19].h = 220;
}

//done !! 


/// animation coin


/**  
* @brief  INITIALISER LE TABLEAU D'ANIMATION DES COINS	  .  
* @param  clip RECTANGLE  
* @return Nothing  
*/
void setrects3(SDL_Rect* clip)
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


///

// initialiser 


/**  
* @brief  INITIALISER TOUS LES ENTITES SECONDAIRE DE JEU .  
* @param  anim_enemie2 TABLEAU D'ANIMATION DE L'ENEMIE 2  
* @param  enemie1 STRUCT ENEMIE 1 
* @param  coins TABLEAU DE 3 COINS  
* @param  coins TABLEAU D'ANIMATION DES COINS 
* @param  coin_sound SON BREF DE RECUPERAGE DE COIN  
* @param  enemie2 STRUCT ENEMIE 2 
* @param  positionMenu1 LA POSITION DE LA BACKGROUND  
* @param  shot STRUCT DE SHOT DE L'ENEMIE 2  
* @return Nothing  
*/
void inti_enemie(SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[],SDL_Rect coin[],Mix_Chunk **coin_sound,entite_second_fix *enemie2,SDL_Rect positionMenu1 ,enemie_shot* shot )
{

     enemie1->image=NULL;
     enemie1->image=IMG_Load("spreetsheet enemie01.png");
     enemie1->tpos.x=2500;
     enemie1->tpos.y=650;
     enemie1->compteur=0;
     enemie1->sens=1;
     enemie1->frame_enemie1=0;





    enemie2->image =IMG_Load("spreetsheet enemie02.png");
    enemie2->tpos.x=1800;
    enemie2->tpos.y=650; 
    enemie2->frame_brnz_silv_gold_coin=5; 

    shot->shot_image=IMG_Load("shot.png");
    shot->jump_image=IMG_Load("/home/esprit/Desktop/lastupdategame/yassine deplacement (5th copy)/enemie imges/warning.png");
    shot->frame_shot=11;
    shot->frame_jump_warning=18;  
    shot->compteur=0;
   // (shot->shot_sound)= Mix_LoadWAV("shot sound.wav");
   // (shot->reload_sound)= Mix_LoadWAV("reload sound.wav");



    coins[0].image =IMG_Load("spreetsheet coins01.png");
    coins[0].tpos.x=1000;
    coins[0].tpos.y=600; 
    coins[0].frame_brnz_silv_gold_coin=0; 

    coins[1].image =IMG_Load("spreetsheet coins01.png");
    coins[1].tpos.x=1200;
    coins[1].tpos.y=600;
    coins[1].frame_brnz_silv_gold_coin=7; 
 
    coins[2].image =IMG_Load("spreetsheet coins01.png");
    coins[2].tpos.x=1400;
    coins[2].tpos.y=600; 
    coins[2].frame_brnz_silv_gold_coin=14; 




       setrects1(enemie1->anim_enemie1);
       setrects2(anim_enemie2);
      // printf("******%d",*frame_enemie2);

        setrects3(coin);
    (*coin_sound)= Mix_LoadWAV("coin.wav"); //Chargement de la musique
 





 

}


/**  
* @brief  AFFICHER TOUS LES ENTITES SECONDAIRE DE JEU .  
* @param  ecran POITEUR DE FENETRE  
* @param  anim_enemie2 TABLEAU D'ANIMATION DE L'ENEMIE 2  
* @param  enemie1  ENEMIE 1 
* @param  coins TABLEAU DE 3 COINS  
* @param  coins TABLEAU D'ANIMATION DES COINS 
* @param  test TEST D'AFFICHAGE SELON LE SCENARIO DE JEU  
* @param  enemie2  ENEMIE 2 
* @param  heroposition LA POSITION DE L'HERO  
* @param  shot SHOT DE L'ENEMIE 2  
* @return Nothing  
*/
void Afficher_Etites(SDL_Surface *ecran,SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[], SDL_Rect coin[],int *test,entite_second_fix *enemie2,SDL_Rect heroposition,enemie_shot *shot)
{

           if(enemie2->tpos.x-heroposition.x>700)
                {     (*test)=1;
                     (shot->frame_shot)=11;
		}             
	     if(enemie2->tpos.x-heroposition.x<=700)
              {
                     (*test)=2;
                     enemie2->frame_brnz_silv_gold_coin=6;

              }

             if(enemie1->compteur== 200 )
                 enemie1->frame_enemie1=7;

             if(enemie1->compteur== 0 )
                enemie1->frame_enemie1=1;



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
                                 




                          caractere_artif(enemie1,heroposition);


                                if((*test)==1)
                           { 
                              Enemie (&(enemie2->tpos),&heroposition);
                              enemie2->frame_brnz_silv_gold_coin--;

                               if((enemie2->frame_brnz_silv_gold_coin)==0)
                                 enemie2->frame_brnz_silv_gold_coin=4;

                           }

}




//////enemie shot 


/**  
* @brief  L'ATTACK DE LENEMIE .  
* @param  test TEST D'AFFICHAGE SELON LE SCENARIO DE JEU  
* @param  enemie2  ENEMIE 2 
* @param  anim_enemie2 TABLEAU D'ANIMATION DE L'ENEMIE 2  
* @param  positionMenu1 LA POSITION DE LA BACKGROUND  
* @param  ecran POITEUR DE FENETRE  
* @param  CAMERA SCROLLING DE BACKGROUND 
* @param  menu1  IMAGE DE BACKGROUND
* @param  hero   HERO   
* @param  shot   LES VARIABLES D'ATTACK DE ENEMIE 2    
* @param  blitperso   SENS DE MOUVEMENT DE L'HERO    
* @param  event EVENEMENT DE L'INPUT            
* @return Nothing  
*/
void Shoting(int test ,entite_second_fix *enemie2,SDL_Rect anim_enemie2[],SDL_Rect positionMenu1,SDL_Surface *screen1,camera* c,SDL_Surface *menu1,heros* hero,enemie_shot *shot,int blitperso,  SDL_Event *event, vie* v,entite_second_artif *enemie1,entite_second_fix coins[], SDL_Rect coin[],minihero* mh)
{
     //	SDL_Event event;
       if(test==2)
                           {                         

                              enemie2->frame_brnz_silv_gold_coin=10;


                         //    while(enemie2->frame_brnz_silv_gold_coin!=6)
                             {

                           SDL_BlitSurface(enemie2->image,&anim_enemie2[6],screen1,&enemie2->tpos); 

    				if(blitperso == 1)
				{			
         //   blitfenetre(positionMenu1,screen1,1,menu1,hero,c);


				 }                       

				if ( blitperso == 2)
				{			
                                   // blitfenetre(positionMenu1,screen1,2,menu1,hero,c);
				}
           /* blitvie(v,screen1);
            Afficher_Etites(screen1, anim_enemie2, enemie1, coins,  coin,&test,enemie2,hero->heroposition,shot);
           // SDL_BlitSurface(s.text, NULL, screen, &(s.positionscore));
            blitminihero(screen1,mh);*/


                            //  enemie2->frame_brnz_silv_gold_coin--;		

			     }
			

			switch(shot->frame_shot)
			{
				case 11 :
                                 shot->shot_posit.x=enemie2->tpos.x-shot->shot_posit.w+10;
   		                 shot->shot_posit.y=enemie2->tpos.y-20; 
				break;

				case 12 :
                                 shot->shot_posit.x=enemie2->tpos.x-shot->shot_posit.w+10 ;
   		                 shot->shot_posit.y=enemie2->tpos.y+5; 
				break;

				case 13 :
                                 shot->shot_posit.x=enemie2->tpos.x-shot->shot_posit.w+5 ;
   		                 shot->shot_posit.y=enemie2->tpos.y+16; 
				break;

				case 14 :
                                 shot->shot_posit.x=enemie2->tpos.x-shot->shot_posit.w+8 ;
   		                 shot->shot_posit.y=enemie2->tpos.y+37; 
				break;

				case 15 :
                                 shot->shot_posit.x=enemie2->tpos.x-shot->shot_posit.w+50 ;
   		                 shot->shot_posit.y=enemie2->tpos.y+60; 
				break;

				case 16 :
                                 shot->shot_posit.x=enemie2->tpos.x-shot->shot_posit.w+5 ;
   		                 shot->shot_posit.y=enemie2->tpos.y+65; 
				break;

				case 17 :
                                 shot->shot_posit.x=enemie2->tpos.x-shot->shot_posit.w+5 ;
   		                 shot->shot_posit.y=enemie2->tpos.y+75; 
				break;

			}


			SDL_BlitSurface(shot->shot_image,&anim_enemie2[shot->frame_shot],screen1,&shot->shot_posit);
                       // SDL_Delay(1000); 
                  	 (shot->frame_shot)++;
			if((shot->frame_shot)>=17)
			{
			 (shot->frame_shot)=17;
			}


		/*	if(shot->compteur==1)
    		      {
			Mix_PlayChannel(2,shot->reload_sound,0);
		      // SDL_Delay(50);
		      }
*/
                 if((shot->frame_shot==17)&&(hero->heroposition.x>=shot->shot_posit.x))
                {         

                         if(shot->compteur>=30)
 		        { 
			    shot->jump_warning_posit.x=enemie2->tpos.x+10; 
                            shot->jump_warning_posit.y=enemie2->tpos.y; 
			SDL_BlitSurface(shot->jump_image,NULL,screen1,&shot->jump_warning_posit);
			// shot.frame_jump_warning++;

				if(shot->frame_jump_warning==19)
                                 shot->frame_jump_warning=18;
 			}
                         if(shot->compteur>=100)
 		        { 
				      shot->compteur=0;
 			}
                       (shot->compteur)++;

		}


                           }




}
////



/**  
* @brief  To initialize the background b .  
* @param b the background  
* @param url  the url of the image   
* @return Nothing  
*/
/*void Free_Entites (SDL_Surface *ecran,entite_second_artif enemie1,entite_second_fix coins[3],entite_second_fix enemie2,Mix_Chunk *coin_sound)
{
   SDL_FreeSurface(enemie2);
   SDL_FreeSurface(enemie2);
   SDL_FreeSurface(enemie2);
 
   Mix_FreeChunk()


}*/

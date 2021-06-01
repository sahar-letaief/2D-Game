/**  
        * @file enemie.h 
	* @brief entites secondaires structs && headers  
	* @author  semah bader  
	* @version 0.6  
*  
*  
*/
#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED


#include "hero.h"

/**  
* @struct entite_second_fix  
* @brief struct for enemie final && coins 
*/
typedef struct
{ 
  SDL_Surface *image;  /*!<SURFACE*/
  int frame_brnz_silv_gold_coin; /*!< Rectangle*/
  SDL_Rect tpos; /*!< POSITION*/
  SDL_Rect savetpos; /*!< LOAD-POSITION*/

}entite_second_fix;


/**  
* @struct enemie_shot  
* @brief  final boss attacking  
*/
typedef struct
{
   SDL_Surface *jump_image;/*!<JUMP WARNING IMG */
   SDL_Surface *shot_image;/*!<SNIPER AIMING IMG*/
   SDL_Rect shot_posit,jump_warning_posit;/*!< POSITIONS*/
   int frame_shot,frame_jump_warning,compteur;/*!<ANIMATION FRAMES*/
   //Mix_Chunk *shot_sound;
  // Mix_Chunk *reload_sound;

}enemie_shot;



/**  
* @struct entite_second_artif  
* @brief  ENEMIE INTELLIGENCE ARTIF  
*/
typedef struct
{ 
  SDL_Surface *image;/*!<ENEMIE IMG*/
  SDL_Rect anim_enemie1[12];/*!<ANIMATION TAB*/
  int frame_enemie1;/*!<ANIMATION FRAME*/
  SDL_Rect tpos;/*!<ENEMIE POSITION*/
  SDL_Rect savetpos;/*!<ENEMIE LOADPOSITION*/
  int compteur;/*!<COMPTEUR DE MOUVEMENT*/
  int sens;/*!<SENS DE MOUVEMENT*/
}entite_second_artif;


int Bounding_Box(SDL_Rect* obstacl,SDL_Rect* perso );

void caractere_artif(entite_second_artif *batt,SDL_Rect position_enemie);
void Enemie (SDL_Rect *perso,SDL_Rect *position_enemie);

float Distance_Cercle(int X1,int Y1,int X2,int Y2);
float Rayon(SDL_Rect perso);
int Colllision_Trigo (SDL_Rect hero ,SDL_Rect position_enemie);

void setrects1(SDL_Rect* clip);
void setrects2(SDL_Rect* clip);
void setrects3(SDL_Rect* clip);

void inti_enemie(SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[],SDL_Rect coin[],Mix_Chunk **coin_sound,entite_second_fix *enemie2,SDL_Rect positionMenu1 ,enemie_shot* shot );

void Afficher_Etites(SDL_Surface *ecran,SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[], SDL_Rect coin[],int *test,entite_second_fix *enemie2,SDL_Rect heroposition,enemie_shot *shot);

void Shoting(int test ,entite_second_fix *enemie2,SDL_Rect anim_enemie2[],SDL_Rect positionMenu1,SDL_Surface *screen1,camera* c,SDL_Surface *menu1,heros* hero,enemie_shot *shot,int blitperso,  SDL_Event *event, vie* v,entite_second_artif *enemie1,entite_second_fix coins[], SDL_Rect coin[],minihero* mh);






#endif // ENEMIE_H_INCLUDED

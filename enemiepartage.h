#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED

/**
* @struct entite_second_fix;
* @brief structure entite_second_fix pour l'ennemie partage;
*/

typedef struct
{ 
  SDL_Surface *image;
  int frame_brnz_silv_gold_coin;

  SDL_Rect tpos;
  SDL_Rect savetpos;


}entite_second_fix;




/**
* @struct entite_second_artif;
* @brief structure entite_second_artif pour l'ennemie partage;
*/
typedef struct
{ 
  SDL_Surface *image;
  SDL_Rect anim_enemie1[12];
  int frame_enemie1;
  SDL_Rect tpos;
  SDL_Rect savetpos;
  int compteur;
  int sens;
}entite_second_artif;


int Bounding_Boxpartage(SDL_Rect* obstacl,SDL_Rect* perso );
void caractere_artifpartage(entite_second_artif *batt,SDL_Rect position_enemie);
void Enemiepartage (SDL_Rect *perso,SDL_Rect *position_enemie);
float Distance_Cerclepartage(int X1,int Y1,int X2,int Y2);
float Rayonpartage(SDL_Rect perso);
int Colllision_Trigopartage (SDL_Rect hero ,SDL_Rect position_enemie);
void setrects1partage(SDL_Rect* clip);
void setrects2partage(SDL_Rect* clip);
void setrects3partage(SDL_Rect* clip);
void inti_enemiebot(SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[],SDL_Rect coin[],Mix_Chunk **coin_sound,entite_second_fix *enemie2,SDL_Rect positionMenu1  );
void inti_enemietop(SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[],SDL_Rect coin[],Mix_Chunk **coin_sound,entite_second_fix *enemie2,SDL_Rect positionMenu1 );
void Afficher_Etitespartage(SDL_Surface *ecran,SDL_Rect anim_enemie2[],entite_second_artif *enemie1,entite_second_fix coins[], SDL_Rect coin[],int *test,entite_second_fix *enemie2,SDL_Rect heroposition);

void update_enemie1partage (entite_second_artif *enemie1);


#endif // ENEMIE_H_INCLUDED

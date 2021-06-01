#ifndef SCORE2_H_INCLUDED
#define SCORE2_H_INCLUDED

struct score
{
 SDL_Surface * img;
 SDL_Surface * img1; 
 SDL_Surface * img2; 
 SDL_Surface * imgback; 
 SDL_Rect 	p; 
 SDL_Rect 	pback; 
 SDL_Rect 	p1; 
 SDL_Rect 	p2; 
 int result;
};
typedef struct score score;

void init_score(score *s);
void generate_afficher (SDL_Surface * screen, char image [],score *s);

#endif // SCORE2_H_INCLUDED

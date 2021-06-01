//dans le main.c
char score_char[4]="";
int score_int=0;
recuperation_score(sprite,coin,&score_int);
conversion_int_char(score_int,score_char);

//**************score.c********************

void recuperation_score(SDL_Rect *sprite, SDL_Rect *coin,int *score_int)
{

    //Les côtés des rectangles
    float spriteLeft, coinLeft;
    float spriteRight, coinRight;
    float spriteTop, coinTop;
    float spriteBottom, coinBottom;

    //Calcul des côtés du rectangle

    spriteTop = sprite->y + sprite->h;
    spriteBottom = sprite->y - sprite->h;
    spriteRight = sprite->x + sprite->w;
    spriteLeft = sprite->x - sprite->w;

    coinTop = coin->y + coin->h;
    coinBottom = coin->y -coin->h;
    coinLeft = coin->x -coin->w;
    coinRight = coin->x + coin->w;

    //verification de l'intersection de notre sprite avec le golden coin
    if ((coinBottom > spriteTop) ||(coinTop < spriteBottom) ||(coinLeft > spriteRight) ||(coinRight < spriteLeft))
    {
        collision=0;
    }
    else
    {
        collision=1;
    }

    if(collision==1)
    {
        (*score_int)++;
    }
}

void conversion_int_char(int score_int,char score_char[])
{
    itoa(score_int,score_char);
}

void afficherscore(char score_char[])
{
    SDL_Surface *screen;
    SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position_texte;
    position_texte.x = 20;
    position_texte.y = 20;
    TTF_Font *font = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    char chaine_affiche[50]="";
    font = TTF_OpenFont("berlin.ttf", 20);
    sprintf(chaine_affiche,"Meilleur score : %s",score_char);
    texte = TTF_RenderText_Blended(font, chaine_affiche,couleurNoire);
    TTF_CloseFont(fonts);
    TTF_Quit();
}





//dans le main:
char vie_char[4]="";
int vie_int=3; //vie initialiser a 3
gestion_vie(&sprite,&enemy,&vie_int);
conversion_int_char(vie_int,vie_char); //conversion de vie(entier) en vie (char) pour l'affichage

//********************vie.c***************************

void gestion_vie(SDL_Rect *sprite, SDL_Rect *enemy,int *vie_int)
{

    //Les côtés des rectangles
    float spriteLeft, enemyLeft;
    float spriteRight, enemyRight;
    float spriteTop, enemyTop;
    float spriteBottom, enemyBottom;

    //Calcul des côtés du rectangle

    spriteTop = sprite->y + sprite->h;
    spriteBottom = sprite->y - sprite->h;
    spriteRight = sprite->x + sprite->w;
    spriteLeft = sprite->x - sprite->w;

    enemyTop = enemy->y + enemy->h;
    enemyBottom = enemy->y -enemy->h;
    enemyLeft = enemy->x -enemy->w;
    enemyRight = enemy->x + enemy->w;

    //verification de l'intersection de notre sprite avec l'enemy
    if ((enemyBottom > spriteTop) ||(enemyTop < spriteBottom) ||(enemyLeft > spriteRight) ||(enemyRight < spriteLeft))
    {
        collision=0;
    }
    else
    {
        collision=1;
    }

    if((collision==1)&&(vie_int>0))
    {
        (*vie_int)--;
    }
}

void conversion_int_char(int vie_int,char vie_char[])
{
    itoa(vie_int,vie_char);
}

void affichervie(char vie_char[])
{
    SDL_Surface *screen;
    SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position_texte;
    position_texte.x = 20;
    position_texte.y = 30;
    TTF_Font *font = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    char chaine_affiche[50]="";
    font = TTF_OpenFont("berlin.ttf", 20);
    sprintf(chaine_affiche,"Vie: %s",vie_char);
    texte = TTF_RenderText_Blended(font, chaine_affiche,couleurNoire);
    TTF_CloseFont(fonts);
    TTF_Quit();
}

#include <stdlib.h>
 #include <stdio.h>
 #include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "menu.h"


/* doen :: 
      background animation / menu bttms / mouse keyboard selection & click / music sound 
*/








void setrects(SDL_Rect* clip)
{
      clip[0].x=0;
      clip[0].y=0;
      clip[0].w=640;
      clip[0].h=480;

      clip[1].x=641;
      clip[1].y=0;
      clip[1].w=640;
      clip[1].h=480;

      clip[2].x=1282;
      clip[2].y=0;
      clip[2].w=640;
      clip[2].h=480;

      clip[3].x=1923;
      clip[3].y=0;
      clip[3].w=640;
      clip[3].h=480;

      clip[4].x=2564;
      clip[4].y=0;
      clip[4].w=640;
      clip[4].h=480;

      clip[5].x=3205;
      clip[5].y=0;
      clip[5].w=640;
      clip[5].h=480;

      clip[6].x=3846;
      clip[6].y=0;
      clip[6].w=640;
      clip[6].h=480;

      clip[7].x=4487;
      clip[7].y=0;
      clip[7].w=640;
      clip[7].h=480;

      clip[8].x=5128;
      clip[8].y=0;
      clip[8].w=640;
      clip[8].h=480;

      clip[9].x=5767;
      clip[9].y=0;
      clip[9].w=640;
      clip[9].h=480;

      clip[10].x=6404;
      clip[10].y=0;
      clip[10].w=640;
      clip[10].h=480;

      clip[11].x=7044;
      clip[11].y=0;
      clip[11].w=640;
      clip[11].h=480;

      clip[12].x=7683;
      clip[12].y=0;
      clip[12].w=640;
      clip[12].h=480;

      clip[13].x=8324;
      clip[13].y=0;
      clip[13].w=640;
      clip[13].h=480;

      clip[14].x=8965;
      clip[14].y=0;
      clip[14].w=640;
      clip[14].h=480;







}

void menu1(SDL_Rect* clip)
{
      clip[0].x=0;
      clip[0].y=0;
      clip[0].w=195;
      clip[0].h=268;

      clip[1].x=197;
      clip[1].y=0;
      clip[1].w=195;
      clip[1].h=268;

      clip[2].x=394;
      clip[2].y=0;
      clip[2].w=195;
      clip[2].h=268;

      clip[3].x=592;
      clip[3].y=0;
      clip[3].w=195;
      clip[3].h=268;

      clip[4].x=789;
      clip[4].y=0;
      clip[4].w=195;
      clip[4].h=268;



}
void ttf_posit(SDL_Rect* clip)
{
      clip[0].x=10;
      clip[0].y=0;


      clip[1].x=0;
      clip[1].y=50;


      clip[2].x=0;
      clip[2].y=100;


      clip[3].x=0;
      clip[3].y=150;


      clip[4].x=0;
      clip[4].y=200;

      clip[5].x=0;
      clip[5].y=250;

      clip[6].x=0;
      clip[6].y=300;

      clip[7].x=500;
      clip[7].y=400;

      clip[8].x=0;
      clip[8].y=400;

     




}

void options(SDL_Rect* clip)
{
      clip[0].x=14;
      clip[0].y=14;
      clip[0].w=190;
      clip[0].h=106;

      clip[1].x=215;
      clip[1].y=0;
      clip[1].w=190;
      clip[1].h=106;

      clip[2].x=420;
      clip[2].y=0;
      clip[2].w=190;
      clip[2].h=106;

      clip[3].x=625;
      clip[3].y=0;
      clip[3].w=190;
      clip[3].h=106;

      


}

void option_surface(SDL_Rect opti[],SDL_Surface *option,SDL_Surface *ecran ,SDL_Rect position_option,int *volume,int *w,int *h,int *frameoption,SDL_Event event)
{

      int X,Y;
      int continuer=1;


         
              
        
     

   SDL_Init(SDL_INIT_VIDEO);


          option=IMG_Load("options.png");
   


      while(continuer)
         { 
                  

               SDL_PollEvent(&event);
                  switch(event.type)
                     {
                        case SDL_QUIT: 
                              continuer = 0 ;
                        break;
/*
                        case SDL_KEYDOWN :
                          switch (event.key.keysym.sym)
                            {

                             case SDLK_BACKSPACE :
                                continuer = 0;
                             break;
                             /*case SDLK_RETURN:
                                 //if(opt==2)
                                      // test_music=Mix_PausedMusic();
                              //if(test_music!=1)
                                 //  {   
                                         
                                        //Mix_CloseAudio();
                                          ;
                                   //  break;
                              
                                 //  }
                            // else if (test_music==1)
                             //{
                                 //Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
                                 // rain = Mix_LoadMUS("rain-01.mp3");
                                 //Mix_PlayMusic(rain, -1);
                                 //Mix_Volume(-1,MIX_MAX_VOLUME/2);
                                // test_music=0;
                                
                                 
                           //  }
                             break;
                             case SDLK_UP : 
                               //if(opt!=1)
                                 // opt--; 
                                  //  if(framemenu==0)
                                    //  framemenu==4;
                             
                             break;
                             case SDLK_DOWN :
                                // if(opt!=4)
                                 //opt++; 
                              // if(framemenu==5)
                                //      framemenu=1;
                         
                             break;
                             
                          } //fin switch clavier
                        break;*/
                         case SDL_MOUSEMOTION :
                             X=event.motion.x;
                             Y=event.motion.y;
                             if((X>0) && (X<100) && (Y>0) && (Y<108))    
                               {  
                                   
                                         SDL_WaitEvent(&event);
                                         switch(event.type)
                                           {
                                                 case SDL_MOUSEBUTTONDOWN:
                                                        if (event.button.button == SDL_BUTTON_LEFT)
                                                           {
                                                                  //son breff
                                                                  *frameoption=1;
                                                                  //*h=1000;
                                                                  //*w=1000;
                                                                   SDL_Delay(1000);
                                            ecran = SDL_SetVideoMode(*w,*h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                                                                  
                                                                  // ttf soon
                                                                                                                                                                                
                                                            }
                                                 break;
                                            


                                           }
                             
                                } //fullscreen click & motion
                              else if((X>28) && (X<222) && (Y>219) && (Y<276))    
                               {  
                                   
                                         SDL_WaitEvent(&event);
                                         switch(event.type)
                                           {
                                                 case SDL_MOUSEBUTTONDOWN:
                                                        if (event.button.button == SDL_BUTTON_LEFT)
                                                           {
                                                                  //son breff
                                                                 
                                                                  SDL_Delay(1000);
                                                                  // ttf soon
                                                                                                                                                                                
                                                            }
                                                 break;
                                            


                                           }
                             
                                }//mute click & motion
                             else if((X>28) && (X<222) && (Y>286) && (Y<343))    
                               {  
                                   
                                         SDL_WaitEvent(&event);
                                         switch(event.type)
                                           {
                                                 case SDL_MOUSEBUTTONDOWN:
                                                        if (event.button.button == SDL_BUTTON_LEFT)
                                                           {
                                                                  //son breff
                                                                  
                                                               
                                                                                                                                                                                
                                                            }
                                                 break;
                                            


                                           }
                             
                                }//volume click & motion
                             
                            
                                           


                                     
                                 
                        break;
            
                
                      
                      
                          
            
             
                  
        

                     

     


     
     
      
            

      }//fni switch event
               SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
               SDL_BlitSurface(option,&opti[*frameoption],ecran,&position_option);
                 SDL_Flip(ecran);
               SDL_Delay(30);
            }//fin while
   
                


    

}




void credit_surface(SDL_Surface *ecran ,SDL_Surface *instrc ,SDL_Surface *yassine ,SDL_Surface *sahar ,SDL_Surface *nardine ,SDL_Surface *nahed ,SDL_Surface *semah,SDL_Surface *back ,SDL_Surface *enjoy,SDL_Surface *yasmine ,  SDL_Event event, TTF_Font *police , SDL_Color couleurNoire,SDL_Rect ttf[])
{
      
      int continuer =1,X,Y;
      
    

   while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
             case SDL_KEYDOWN :
                switch (event.key.keysym.sym)
                    {
                     case SDLK_BACKSPACE :
                      continuer = 0;
                     break;
                  
            break;
            case SDL_MOUSEBUTTONDOWN:
             
              if(event.button.button == SDL_BUTTON_LEFT)
                {
                  if(event.button.x>0 && event.button.x<200 && event.button.y>400 && event.button.y<300)
                     continuer = 0;
                    
                }
           break;

                     }

                                            


       }
       // SDL_BlitSurface(background,&rects[0],ecran,&position_background);
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

        SDL_BlitSurface(instrc,NULL, ecran, &ttf[0]); //Blit du texte 
        SDL_BlitSurface(yassine,NULL, ecran, &ttf[1]); 
        SDL_BlitSurface(nardine,NULL, ecran, &ttf[2]); 
        SDL_BlitSurface(sahar,NULL, ecran, &ttf[3]); 
        SDL_BlitSurface(nahed,NULL, ecran, &ttf[4]); 
        SDL_BlitSurface(yasmine,NULL, ecran, &ttf[5]); 
        SDL_BlitSurface(semah,NULL, ecran, &ttf[6]); 
        SDL_BlitSurface(enjoy,NULL, ecran, &ttf[7]); 
        SDL_BlitSurface(back,NULL, ecran, &ttf[8]); 
        SDL_Flip(ecran);
    
           





}

}






int main(int argc, char *argv[])
{  
    // declarations :::::::::::::


    SDL_Surface *ecran = NULL , *background = NULL,*menu=NULL, *option=NULL,*soon=NULL;
 SDL_Surface *instrc = NULL,*yassine = NULL,*sahar = NULL,*nardine = NULL,*nahed = NULL,*semah = NULL,*enjoy = NULL,*yasmine = NULL,*back = NULL;
    SDL_Rect position_background,position_menu,position_option,soon_posit;
    SDL_Rect rects[15],bttom[5],ttf[8];
    menu1(bttom);
    setrects(rects);
    SDL_Rect opti[4];
    options(opti);
    ttf_posit(ttf);
    SDL_Event event; /* La variable contenant l'événement */
    Mix_Music *rain;
    Mix_Music *music;
    Mix_Chunk *thunder; //Création du pointeur de type Mix_Music
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
      TTF_Font *police = NULL;
      SDL_Color couleurNoire = {255, 255, 255};
      SDL_Rect position_ttf;
 


   

    int continuer = 1,opt=0; /* Notre booléen pour la boucle */
    int frame=0,framemenu,frameoption;
    int running=1,test_music=0;
    int w=641,h=480;
    int X,Y;
   int volume=64;
   char inst[40]="GAME DEVELOPPED BY :",yassi[40]= "YASSINE BEN SALHA" ,sah[40]="SAHAR LTAIEF",nardi[40]="NARDINE HANFI" ,nah[40]="NAHED BELKACEM"  ,sem[40]="BADER SEMAH ",enj[40]="ENJOY !!!",yasmi[40]="YASMINE SEMITI",bac[10]="back"; 
     


   /* credit[0][50]="GAME DEVELOPPED BY :";
    credit[0][50]="YASSINE BEN SALHA";
    credit[0][50]="SAHAR LTAIEF";
    credit[0][50]="NARDINE HANFI";
    credit[0][50]="NAHED BELKACEM";
    credit[0][50]="BADER SEMAH";
    credit[0][50]="ENJOY !!!";*/

  

//positions :::::::
    soon_posit.x=320;
    soon_posit.y=220;
        

    position_background.x=h*0+w*0;
    position_background.y=h*0+w*0;

    position_menu.x=w/64+20;
    position_menu.y=h/4.8+50;



    thunder = Mix_LoadWAV("thunderrumble.wav"); //Chargement de la musique
        rain = Mix_LoadMUS("rain-01.mp3"); //Chargement de la musique
        music = Mix_LoadMUS("music.mp3");
        Mix_PlayMusic(rain, -1); //Jouer infiniment la musique
        Mix_PlayMusic(music, -1);

        


    // SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
    //Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,1024);
 
    
       
       
      



   SDL_Init(SDL_INIT_VIDEO);
   TTF_Init();
       if(TTF_Init() == -1)
                { 
         fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
                   exit(EXIT_FAILURE);
                }

    ecran = SDL_SetVideoMode(w,h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("menu !!!!!!!!!!!!", NULL);
   

    
        background =IMG_Load("background 2.png");
        menu=IMG_Load("menu bottms.png");
        soon=IMG_Load("coming-soon5.png");
        police = TTF_OpenFont("angelina.TTF", 65);
         

//ttf set :::: 


        instrc = TTF_RenderText_Blended(police,inst, couleurNoire);
        yassine = TTF_RenderText_Blended(police,yassi, couleurNoire);
        sahar = TTF_RenderText_Blended(police,sah, couleurNoire);
        nardine = TTF_RenderText_Blended(police,nardi, couleurNoire);
        nahed = TTF_RenderText_Blended(police,nah, couleurNoire);
        semah = TTF_RenderText_Blended(police,sem, couleurNoire);
        yasmine = TTF_RenderText_Blended(police,yasmi, couleurNoire);
        enjoy = TTF_RenderText_Blended(police,enj, couleurNoire);
        back = TTF_RenderText_Blended(police,bac, couleurNoire);
     
      
        
        //Mix_PlayMusic(rain,-1);
                  /*SDL_BlitSurface(background,&rects[0],ecran,&position_background);
                  SDL_BlitSurface(menu,&bttom[0],ecran,&position_menu);
                  SDL_Flip(ecran);*/

      while(continuer)
         { 
                  

               SDL_PollEvent(&event);
                  switch(event.type)
                     {
                        case SDL_QUIT: 
                              continuer = 0 ;
                        break;

                        case SDL_KEYDOWN :
                          switch (event.key.keysym.sym)
                            {

                             case SDLK_ESCAPE:
                                  continuer = 0;
                             break;

                             case SDLK_RETURN :
                               if(framemenu==4)
                                 continuer=0;
                               else if(framemenu==3)
                                  {
                                Mix_PlayChannel(1,thunder,0);
                                    SDL_Delay(1000);
    credit_surface( ecran ,instrc ,yassine ,sahar , nardine , nahed , semah,back , enjoy, yasmine ,event, police, couleurNoire, ttf);
                                            //SDL_FreeSurface(texte);
                                     framemenu==0;
                                break;
                                  }
                                
                               else if(framemenu==2)
                                  {
                                      Mix_PlayChannel(1,thunder,0);
                                           SDL_Delay(1000);
             option_surface( opti,option,ecran ,position_option,&volume,&w,&h,&frameoption, event);
                                break;
                                     }
                               else if(framemenu==1)
                                     {
                                      Mix_PlayChannel(1,thunder,0);
                                                                  SDL_Delay(1000);
                                  SDL_BlitSurface(soon,NULL,ecran,&soon_posit);
                                  SDL_Flip(ecran);
                                break;
                                     }

                             break;
                             case SDLK_m:
                                      // test_music=Mix_PausedMusic();
                              if(test_music!=1)
                                   {   
                                         Mix_FreeMusic(rain);
                                         Mix_FreeMusic(music);
                                        //Mix_CloseAudio();
                                        test_music=1   ;
                                    break;
                              
                                   }
                                 
                             else if (test_music==1)
                             {
                                 //Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
                                 rain = Mix_LoadMUS("rain-01.mp3");
                                 Mix_PlayMusic(rain, -1);
                                 music = Mix_LoadMUS("music.mp3");
                                 Mix_PlayMusic(music, -1);
                                 //Mix_Volume(-1,MIX_MAX_VOLUME/2);
                                 test_music=0;
                                
                                 
                             }
                             break;
                             case SDLK_UP : 
                               if(framemenu!=1)
                                  framemenu--; 
                                  //  if(framemenu==0)
                                    //  framemenu==4;
                             
                             break;
                             case SDLK_DOWN :
                                 if(framemenu!=4)
                                 framemenu++; 
                              // if(framemenu==5)
                                //      framemenu=1;
                         
                             break;
                             
                          } //fin switch clavier
                        break;
                         case SDL_MOUSEMOTION :
                             X=event.motion.x;
                             Y=event.motion.y;
                             if((X>28) && (X<222) && (Y>150) && (Y<208))    
                               {  
                                   framemenu=1;
                                         SDL_WaitEvent(&event);
                                         switch(event.type)
                                           {
                                                 case SDL_MOUSEBUTTONDOWN:
                                                        if (event.button.button == SDL_BUTTON_LEFT)
                                                           {
                                                                  //son breff
                                                                  Mix_PlayChannel(1,thunder,0);
                                                                  SDL_Delay(1000);
                           SDL_BlitSurface(soon,NULL,ecran,&soon_posit);
                                                                  // ttf soon
                                                                                                                                                                                
                                                            }
                                                 break;
                                            


                                           }
                             
                                } //play click & motion
                              else if((X>28) && (X<222) && (Y>219) && (Y<276))    
                               {  
                                   framemenu=2;
                                         SDL_WaitEvent(&event);
                                         switch(event.type)
                                           {
                                                 case SDL_MOUSEBUTTONDOWN:
                                                        if (event.button.button == SDL_BUTTON_LEFT)
                                                           {
                                                                  //son breff
                                                                  Mix_PlayChannel(1,thunder,0);
                                                                  SDL_Delay(1000);
             option_surface( opti,option,ecran ,position_option,&volume,&w,&h,&frameoption, event);
                                                                  // ttf soon
                                                                                                                                                                                
                                                            }
                                                 break;
                                            


                                           }
                             
                                }//option click & motion
                             else if((X>28) && (X<222) && (Y>286) && (Y<343))    
                               {  
                                     framemenu=3;
                                         SDL_WaitEvent(&event);
                                         switch(event.type)
                                           {
                                                 case SDL_MOUSEBUTTONDOWN:
                                                        if (event.button.button == SDL_BUTTON_LEFT)
                                                           {
                                                                  //son breff
                                                                  Mix_PlayChannel(1,thunder,0);
                                                                  SDL_Delay(1000);
                    
                                                                
    credit_surface( ecran ,instrc ,yassine ,sahar , nardine , nahed , semah,back , enjoy, yasmine ,event, police, couleurNoire, ttf);
                                                                  // ttf soon
                                                                                                                                                                                
                                                            }
                                                 break;
                                            


                                           }
                             
                                }//credits click & motion
                             else if((X>28) && (X<222) && (Y>360) && (Y<417))    
                               {  
                                  framemenu=4;
                                         SDL_WaitEvent(&event);
                                         switch(event.type)
                                           {
                                                 case SDL_MOUSEBUTTONDOWN:
                                                        if (event.button.button == SDL_BUTTON_LEFT)
                                                           {
                                                                  //son breff
                                                                 // Mix_PlayChannel(1,thunder,0);
                                                                  SDL_Delay(500);
                                                                 continuer=0;
                                                            }
                                                 break;
                                            


                                           }
                             
                                } //exit click & motion
                             else
                                 framemenu=0;
                                           


                                     
                                 
                        break;
            
                
                      
                      
                          
            
             
                  
        

                     

     


          
           /* if (framemenu>=4)
                   framemenu==1;
            if(framemenu<0)//&&(framemenu==0))
                   framemenu=4;*/
          
               
         
              
 

     
     
    // SDL_Delay(5);
            

      }//fni switch event


                        
              
                        SDL_BlitSurface(background,&rects[frame],ecran,&position_background);
                        SDL_BlitSurface(menu,&bttom[framemenu],ecran,&position_menu);
                        SDL_Flip(ecran);
                        SDL_Delay(100);
           
           frame++;
             if(frame==14)
               frame=0;
           //SDL_Flip(ecran);
  /* if((frame==12)||(frame==10))
    {
        Mix_PlayChannel(-1,thunder,0); //Jouer infiniment la musique
        Mix_PlayChannel(-1,thunder,0);
    }  */
                


            }//fin while
   
              



  //leberaton :::::
            
      Mix_FreeChunk(thunder);
      Mix_FreeMusic(rain); //Libération de la musique
      Mix_FreeMusic(music);
      Mix_CloseAudio();
     TTF_CloseFont(police); //Doit être avant 
     TTF_Quit() ;

       //FMOD_Sound_Release(rain);
       SDL_FreeSurface(background);
        //pause();
       
      SDL_Quit();

    return EXIT_SUCCESS;
}

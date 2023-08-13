#include"menu.h"
void init_background(background_menu *back)
{
back->background[0]=IMG_Load("1.png");
back->background[1]=IMG_Load("2.png");
back->background[2]=IMG_Load("3.png");
back->background[3]=IMG_Load("4.png");
back->background[4]=IMG_Load("5.png");
back->background[5]=IMG_Load("6.png");
back->background[6]=IMG_Load("7.png");
back->background[7]=IMG_Load("8.png");
back->background[8]=IMG_Load("9.png");
back->background[9]=IMG_Load("10.png");


back->compteur=0;

back->position_background.x=0;
back->position_background.y=0;
}



void animer_background(SDL_Surface *screen,background_menu *back)
{
SDL_BlitSurface(back->background[back->compteur],NULL,screen,&back->position_background);
back->compteur++;
SDL_Delay(110);
if (back->compteur==9) 
back->compteur=0;
}



void init_ttf(texte *ttf)
{
SDL_Color couleurNoire={255,255,255};
TTF_Init();
ttf->police=TTF_OpenFont("1.ttf",25);
ttf->texte =TTF_RenderText_Blended(ttf->police,"CREATED BY PERICULOS", couleurNoire);
ttf->position_texte.x=50;
ttf->position_texte.y=780;
}


void texte_ttf(SDL_Surface *screen,texte *ttf)
{
SDL_BlitSurface(ttf->texte, NULL, screen, &ttf->position_texte);
}


void init_bouton(bouton_menu *bm)
{
bm->continuer=NULL;
bm->play=NULL;
bm->setting=NULL;
bm->quit=NULL;


bm->poscontinuer.x=550;
bm->poscontinuer.y=330;

bm->posplay.x=550;
bm->posplay.y=450;

bm->possetting.x=550;
bm->possetting.y=570;

bm->posquit.x=550;
bm->posquit.y=690;
}


void afficher_bouton_normal(SDL_Surface *screen,bouton_menu *bm)
{
bm->continuer=IMG_Load("continue1.png");
SDL_BlitSurface(bm->continuer, NULL, screen, &bm->poscontinuer);
bm->play = IMG_Load("new game1.png");
SDL_BlitSurface(bm->play, NULL, screen, &bm->posplay);
bm->setting = IMG_Load("settings1.png");
SDL_BlitSurface(bm->setting, NULL, screen, &bm->possetting);
bm->quit = IMG_Load("quit1.png");
SDL_BlitSurface(bm->quit, NULL, screen, &bm->posquit);
}


void afficher_menu1(SDL_Surface *screen,bouton_menu *bm)
{
bm->continuer=IMG_Load("continue2.png");
SDL_BlitSurface(bm->continuer, NULL, screen, &bm->poscontinuer);
bm->play = IMG_Load("new game1.png");
SDL_BlitSurface(bm->play, NULL, screen, &bm->posplay);
bm->setting = IMG_Load("settings1.png");
SDL_BlitSurface(bm->setting, NULL, screen, &bm->possetting);
bm->quit = IMG_Load("quit1.png");
SDL_BlitSurface(bm->quit, NULL, screen, &bm->posquit);
}


void afficher_menu2(SDL_Surface *screen,bouton_menu *bm)
{
bm->continuer=IMG_Load("continue1.png");
SDL_BlitSurface(bm->continuer, NULL, screen, &bm->poscontinuer);
bm->play = IMG_Load("new game2.png");
SDL_BlitSurface(bm->play, NULL, screen, &bm->posplay);
bm->setting = IMG_Load("settings1.png");
SDL_BlitSurface(bm->setting, NULL, screen, &bm->possetting);
bm->quit = IMG_Load("quit1.png");
SDL_BlitSurface(bm->quit, NULL, screen, &bm->posquit);
}


void afficher_menu3(SDL_Surface *screen,bouton_menu *bm)
{
bm->continuer=IMG_Load("continue1.png");
SDL_BlitSurface(bm->continuer, NULL, screen, &bm->poscontinuer);
bm->play = IMG_Load("new game1.png");
SDL_BlitSurface(bm->play, NULL, screen, &bm->posplay);
bm->setting = IMG_Load("settings2.png");
SDL_BlitSurface(bm->setting, NULL, screen, &bm->possetting);
bm->quit = IMG_Load("quit1.png");
SDL_BlitSurface(bm->quit, NULL, screen, &bm->posquit);
}


void afficher_menu4(SDL_Surface *screen,bouton_menu *bm)
{
bm->continuer=IMG_Load("continue1.png");
SDL_BlitSurface(bm->continuer, NULL, screen, &bm->poscontinuer);
bm->play = IMG_Load("new game1.png");
SDL_BlitSurface(bm->play, NULL, screen, &bm->posplay);
bm->setting = IMG_Load("settings1.png");
SDL_BlitSurface(bm->setting, NULL, screen, &bm->possetting);
bm->quit = IMG_Load("quit2.png");
SDL_BlitSurface(bm->quit, NULL, screen, &bm->posquit);
}


void initialiser_bouton_setting(bouton_setting *bs)
{
bs->augmenter=IMG_Load("+.png"); 
bs->deminuer=IMG_Load("- .png");
bs->retour=IMG_Load("echap.png");
bs->posdeminuer.x=450;
bs->posdeminuer.y=450;
bs->posaugmenter.x=450;
bs->posaugmenter.y=250;
bs->posretour.x=100;
bs->posretour.y=100;
}

void liberer_bouton_setting(bouton_setting *bs)
{
SDL_FreeSurface(bs->deminuer);
SDL_FreeSurface(bs->augmenter);
SDL_FreeSurface(bs->retour);
}

void settings(SDL_Surface *screen,Mix_Chunk *son,Mix_Music *musique,bouton_setting *bs,int *doner)
{
SDL_Surface *image=NULL;
image=IMG_Load("sbackground.png"); 
SDL_Rect posimage;
posimage.x=0;
posimage.y=0;
int done=1;
while(done)
{
SDL_BlitSurface(image,NULL,screen,&posimage);
SDL_BlitSurface(bs->deminuer,NULL,screen,&bs->posdeminuer);
SDL_BlitSurface(bs->augmenter,NULL,screen,&bs->posaugmenter);
SDL_BlitSurface(bs->retour,NULL,screen,&bs->posretour);
SDL_Flip(screen);
SDL_Event event;
SDL_WaitEvent(&event);
		     switch(event.type)
                     {
                     case SDL_QUIT:
                          done=0;
			  *doner=0;
                     break;
	             case SDL_MOUSEBUTTONUP:
		          if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=bs->posdeminuer.x && event.motion.x<=bs->posdeminuer.x+80 && event.motion.y>=bs->posdeminuer.y && event.motion.y<=bs->posdeminuer.y+90))
                          {
                          Mix_VolumeChunk(son,MIX_MAX_VOLUME/4);
			  Mix_VolumeMusic(MIX_MAX_VOLUME/4);
			  Mix_VolumeChunk(son,MIX_MAX_VOLUME/16);
                          Mix_VolumeMusic(MIX_MAX_VOLUME/16);
		          }
		          else 
                          if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=bs->posaugmenter.x && event.motion.x<=bs->posaugmenter.x+80 && event.motion.y>=bs->posaugmenter.y &&event.motion.y<=bs->posaugmenter.y+90))
                          {
                          Mix_VolumeChunk(son,MIX_MAX_VOLUME*4);
                          Mix_VolumeChunk(son,MIX_MAX_VOLUME*16);
                          Mix_VolumeMusic(MIX_MAX_VOLUME*4);
                          Mix_VolumeMusic(MIX_MAX_VOLUME*16);
                          }
			  else 
                          if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=bs->posretour.x && event.motion.x<=bs->posretour.x+350 && event.motion.y>=0&&event.motion.y<=bs->posretour.y+250))
                          {
                          Mix_PlayChannel(-1, son, 0);
			  done=0;
                          }
		     break; 
		     }//fin switch
}
SDL_FreeSurface(image);
}

void liberer_ttf(texte *ttf)
{
TTF_CloseFont(ttf->police);
SDL_FreeSurface(ttf->texte);
}

void liberer_bouton(bouton_menu *bm)
{
SDL_FreeSurface(bm->continuer);
SDL_FreeSurface(bm->play);
SDL_FreeSurface(bm->setting);
SDL_FreeSurface(bm->quit);
}


void free_surface_background(background_menu *back)
{
SDL_FreeSurface(back->background[back->compteur]);
}



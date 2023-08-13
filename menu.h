#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
	SDL_Surface *background[10];
	int compteur;
	SDL_Rect position_background;
}background_menu;



typedef struct
{
	SDL_Surface *texte;
	SDL_Rect position_texte;
	TTF_Font *police;
}texte;


typedef struct
{
	SDL_Surface *play;
	SDL_Surface *continuer;
	SDL_Surface *setting;
	SDL_Surface *quit;
	SDL_Rect posplay;
	SDL_Rect poscontinuer;
	SDL_Rect possetting;
	SDL_Rect posquit;
}bouton_menu;

typedef struct
{
	SDL_Surface *retour;
	SDL_Surface *deminuer;
	SDL_Surface *augmenter;
	SDL_Rect posretour;
	SDL_Rect posdeminuer;
	SDL_Rect posaugmenter;
}bouton_setting;




void init_background(background_menu *back);
void animer_background(SDL_Surface *screen,background_menu *back);
void init_ttf(texte *ttf);
void texte_ttf(SDL_Surface *screen,texte *ttf);
void init_bouton(bouton_menu *bm);
void afficher_bouton_normal(SDL_Surface *screen,bouton_menu *bm);
void afficher_menu1(SDL_Surface *screen,bouton_menu *bm);
void afficher_menu2(SDL_Surface *screen,bouton_menu *bm);
void afficher_menu3(SDL_Surface *screen,bouton_menu *bm);
void afficher_menu4(SDL_Surface *screen,bouton_menu *bm);
void initialiser_bouton_setting(bouton_setting *bs);
void liberer_bouton_setting(bouton_setting *bs);
void settings(SDL_Surface *screen,Mix_Chunk *son,Mix_Music *musique,bouton_setting *bs,int *doner);
void liberer_ttf(texte *ttf);
void liberer_bouton(bouton_menu *bm);
void free_surface_background(background_menu *back);
#endif /* MENU_H_ */

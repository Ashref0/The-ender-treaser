#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
#include "perso.h"
#include "background.h"
#include "collisionparfaite.h"
#include "map.h"
#include "time.h"
#include "entity.h"
#include "ennemie.h"
#include "xo.h"


void sauvegarder(int score,char nomjoueur[],char nomfichier[])
{
	FILE *f;
   	int id;
char nom[255];
	f=fopen(nomfichier, "a");
	if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
       }
 	fprintf(f, "%s %d\n", nomjoueur,score);
	printf("%s %d\n", nomjoueur,score);
	fclose(f);}
void meilleur(SDL_Surface* screen)
{
	FILE *f;
    char nom[255];
    int age;
	int id;
 	char c;
	int t[50];//tab score
	int i=0,s=0;
	char* tnom[50];
    f = fopen("text.txt", "r");
    if(f==NULL)
	{
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
        // reading line by line, max 256 bytes
        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];

        while (fgets(buffer, MAX_LENGTH, f))
            buffer[strcspn(buffer, "\n")] = 0;
            char * token = buffer;
        // loop through the string to extract all other tokens
            printf( "%s\n", token ); //printing each token
		//affichage de token on screen
		//write texte ttf
fclose(f);
}



int level_one(SDL_Surface *screen)
{
	int hauteur_fenetre = 765,done=1,vi=1,sc=1,g=0,dt=0,sautt=0,
        	largeur_fenetre = 1360;
	SDL_Event event;
	background ba,bm;
	SDL_Surface *sorry ;
	SDL_Rect pos_sorry ; 
	sorry=IMG_Load("youlost.png");	
	pos_sorry.x=300;
	pos_sorry.y=300;
	initialisation_back(&ba);//initback
	initBackMasque(&bm);//pour la collision parfaite
	printf("donner le mode de jouer  : \n 1 ->  1 joueur || 2 -> 2 joueurs ");
	scanf("%d",&g); 
	map m;
	Time temps;
	Time tempsenig;
	SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER);
	inittemps(&temps);
	inittempsenig(&tempsenig);
//********** 
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 	screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
  
	SDL_WM_SetCaption("Jeu", NULL); 
//**********
 	SDL_Surface *backg;
	SDL_Rect backg_pos;
	backg = IMG_Load("Background.png");
	backg_pos.x = 0;
	backg_pos.y = 0;
	initialiser_map (&m,screen,ba.imgback);
 //**********
	Personne p;
	Personne p2;
	int a=1,an=1,an2=1,vie=0,vie2=0;
	initPerso(&p);
	initPerso2(&p2);
	p.position.y=500;
	p2.position.y=500;
	entity e;
	Ennemie en;
	initentity (&e) ;
	initEnnemi (&en) ;
	 while(done)
    {  
	perso_map(&m,&p.position);
	update_entity(&e);
	update_ennemie (&en,&p.position);
    	SDL_PollEvent(&event);

     switch(event.type)

     {  
     	case SDL_QUIT: 
		done=0;
		break;
	case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {  
		case SDLK_s: 
               	dt=0;
               	deplacerPerso(&p ,screen,dt);
		case SDLK_d: 
dt=1;
               	deplacerPerso(&p ,screen,dt);
               	sautt=1;
   
		break;       
		break;
			
		case SDLK_q:            	
dt=2;
               	deplacerPerso(&p ,screen,dt);
               	sautt=2;
               
		break;
		case SDLK_SPACE:		
dt=3;
               	deplacerPerso(&p ,screen,dt);
                    
		break;
		
		case SDLK_UP:
			vitesseUP(&p);
		break;
		
		case SDLK_DOWN:
			vitesseDOWN(&p);
		break;
               
		case SDLK_ESCAPE: 
              		done=0;
		break; 
		//***********
		case SDLK_l: 
               	dt=0;
               	deplacerPerso(&p2 ,screen,dt);
		break;
		
		case SDLK_m: 
               	dt=1;
               	deplacerPerso(&p2 ,screen,dt);
		break;
			
		case SDLK_k: 
               	dt=2;
               	deplacerPerso(&p2 ,screen,dt);
		break;
		case SDLK_o:
			dt=3;
               	deplacerPerso(&p2 ,screen,dt);
			
		break;
		
		case SDLK_u:
			vitesseUP(&p2);
		break;
		
		case SDLK_i:
			vitesseDOWN(&p2);
		break;
               

                
            }
      
     }   
if(bm.imgback==NULL)
printf("a\n");
SDL_BlitSurface(bm.imgback,NULL,screen,&bm.posback);
afficheBack(bm,screen);
afficheBack2(ba,screen);
displayFlower(bm,screen);
animerBackground(&bm);
affiche_map(&m ,screen,&p.position);
p.position.x+=bm.camera.x;
p2.position.x+=bm.camera.x;
collision(bm.imgback,&p.position);
collision(bm.imgback,&p2.position);
update_time(&temps);
displaytime(temps,screen);
	/*if(p.position.x<100)
{ scrolling (&bm,1);p.position.x=100;}
	if(p.position.x>600)
{ scrolling (&bm,0);p.position.x=800;}*/
	if (g>0){
if(detect_collision(&p.position,&e)) gestion(&e);

	if (en.show==1)afficherEnnemi(en ,screen);

	if (e.show==1)afficherentity(e ,screen);
	
	else if((vie==0)&&(vie2==0)) {vie=10;change_score(&p.score,1,vie);}
   	
   	if ((detect_collision_ennemie(&p.position,&en))&&(en.show==1))
	{if(vie>1){vie-=9;change_score(&p.score,1,vie);}
	else if(vie==0){vie-=10;change_score(&p.score,1,vie);}
	en.show=0;}
   	
		afficherPerso (p,screen);
		if (sautt==1){	 
		saut(&p);
		}
		if (sautt==2){
		sautgauche(&p);
		}
		
	}
	if(g==2){collision(bm.imgback,&p2.position);
if(detect_collision(&p2.position,&e)) gestion(&e);
if (e.show==1)afficherentity(e ,screen);
	else if((vie==0)&&(vie2==0)) {vie2=10;change_score(&p2.score,2,vie2);}
   	
   	if ((detect_collision_ennemie(&p2.position,&en))&&(en.show==1))
	{if(vie2>1){vie2-=9;change_score(&p2.score,2,vie2);}
	else if(vie2==0){vie2-=10;change_score(&p2.score,2,vie2);}
	en.show=0;}
   	if(vie2<-5)
{SDL_BlitSurface(sorry,NULL,screen,&pos_sorry);SDL_Flip(screen);SDL_Delay(2000);done=0;}

		afficherPerso (p2,screen);
		saut(&p2);

	}
	 if(vie<-5){if(game(screen)!=0)
{screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);SDL_BlitSurface(sorry,NULL,screen,&pos_sorry);SDL_Flip(screen);SDL_Delay(2000);done=0;}
else p.position.x=100;vie=0;screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);}
     	SDL_Flip(screen);
p.position.x-=bm.camera.x;
p2.position.x-=bm.camera.x;
    }
	
	SDL_FreeSurface(backg);
	SDL_Quit();

    return 0;
}










/**
 * @file ennemie.c 
 */
#include "ennemie.h"




int 
nb_frame1=12 ,
ennemie_h=100,
ennemie_w=100,
ennemie_y=100,
ennemie_x=100;


void init_tab_anim_ennemie(SDL_Rect *clip,Ennemie *e)
{	


for (int j=0;j<nb_frame1; j++)
	{
	clip[j].h=ennemie_h;
	clip[j].w=ennemie_w;
	clip[j].x = j*ennemie_w;
	clip[j].y = 0;
        }


}


/**
* @brief To initialize the ennemie en  .
* @param en the ennemie
* @return Nothing
*/

void initEnnemi(Ennemie *e)
{

    e->ennemie = IMG_Load("ENNEMIE.png");

    e->pos_ennemie.x = 400;
    e->pos_ennemie.y = 400;
    init_tab_anim_ennemie(e->anim_ennemie,e);
    e->frame_ennemie=0;
    e->direction=0;  
    e->col=0;
    e->show=1;
    
    
}
/**
* @brief To show the ennemie en .
* @param screen the screen
* @param en the ennemie
* @return Nothing
*/


void afficherEnnemi(Ennemie e, SDL_Surface *screen)
{
   
   SDL_BlitSurface(e.ennemie,&e.anim_ennemie[e.frame_ennemie], screen, &e.pos_ennemie);
  
  

}
/**
* @brief for the random movement of  the automation ennemi  .
* @param en the ennemie
* @param p the personnage  
* @return Nothing
*/

void deplacerIA(Ennemie *e,SDL_Rect *p)
{	srand (time(0));
	int diff;
	int maxi_down=300+rand()%300;
	int maxi_up=150+rand()%300;

  	//printf("maxup : %d\tmaxdown : %d\n",maxi_up,maxi_down );


if(e->pos_ennemie.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_ennemie.y<=maxi_up)
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_ennemie.y-=7;

}
if(e->direction==0)
{
	e->pos_ennemie.y+=7;
}

  diff=e->pos_ennemie.x-p->x;
  
  if (diff<350 && diff>50 ){

e->pos_ennemie.x-=3;
  }

if (diff >-350 && diff < 0){
  
  e->pos_ennemie.x+=3;
  }


}

/**
* @brief for the animation the ennemie .
* @param en the ennemie 
* @return Nothing
*/


/**
* @brief for the integration of two functions (anim,mouv) .
* @param en the ennemie 
* @param p the personnage 
* @return Nothing
*/


void update_ennemie(Ennemie *e,SDL_Rect *p)
{ 	deplacerIA(e,p);
	

}
/**
* @brief to change the maxi down and the maxi up randomly .
* @param en the ennemie 
* @return Nothing
*/


/*void rand_min_max(ennemie *en){
	srand (time(0));
  	e->maxi_up=50+rand()%100;
 	e->maxi_down=350+rand()%100;

  	printf("maxup : %d\tmaxdown : %d\n",e->maxi_up,e->maxi_down );

}*/


    
    


/**
* @brief for the detection of a collision bounding box  .
* @param en the ennemie 
* @param p the personnage 
* @return collision  
*/

int detect_collision_ennemie(SDL_Rect *p, Ennemie *e)
{
	

if ((p->x + p-> w< e->pos_ennemie. x) || (p->x> e->pos_ennemie. x + e->pos_ennemie. w) ||
(p->y + p->h< e->pos_ennemie. y) || (p->y> e->pos_ennemie. y + e->pos_ennemie. h ))
return 0;
else 
return 1;
 
}

int gerer(Ennemie *e) {
	
	e->show=0;
	
	return 0; 
}





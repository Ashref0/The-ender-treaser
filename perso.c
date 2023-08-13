#include "perso.h"

void initPerso(Personne *p){

int vi,sc;
vi=initTextvie(&p->vie);
sc=initTextscore(&p->score);

(*p).image=IMG_Load("perso.png");  

p->position.x=0;
p->position.y=700;
p->position.w=100;
p->position.h=100;
p->frame.w=100;
p->frame.h=100;
p->frame.x=0;
p->frame.y=0;

p->curframe=0;
p->running=1;
p->direction=0;
p->previousmvt=0;

p->v_x = 4;
p->v_grav = 0.3;
p->v_saut = -6.5;
p->v_y = p->v_saut;

p->acceleration=5;
p->vitesse=0;

}
void initPerso2(Personne *p){

int vi,sc;
vi=initTextvie1(&p->vie);
sc=initTextscore1(&p->score);

p->image=IMG_Load("perso.png");
 
p->position.x=100;
p->position.y=700;
p->position.w=100;
p->position.h=100;
p->frame.w=100;
p->frame.h=100;
p->frame.x=0;
p->frame.y=0;

p->curframe=0;
p->running=1;
p->direction=0;
p->previousmvt=0;

p->v_x = 4;
p->v_grav = 0.3;
p->v_saut = -6.5;
p->v_y = p->v_saut;

p->acceleration=5;
p->vitesse=0;

}

void afficherPerso (Personne p,SDL_Surface *screen){

	displayvie(p.vie,screen);
	displayscore(p.score,screen);
	SDL_BlitSurface(p.image,&(p.frame),screen,&(p.position));     
}


void deplacerPerso(Personne *p ,SDL_Surface *screen,int dt){ 


	if(dt!= p->previousmvt)
	{
		p->direction=0;
		p->previousmvt = p->direction;
	}
	
	if (dt==0){
		while(p->position.y<500) 
   		{ 
     			p->position.y+=3;
    		}
    		p->direction=dt;
    		animerPerso(p);	
	}
	
	if (dt==1){
		p->position.x+=p->vitesse; 
		p->direction=dt;
		animerPerso(p);
	}
   	
 	if (dt==2){
   		p->position.x-=p->vitesse;
   		p->direction=dt;
   		animerPerso(p);	
	}
	
	if (dt==3){		 
		p->position.y-=2;  
	}
	
}


void animerPerso(Personne *p){

	if(p->direction==1)
	{
		p->frame.y=0;
		p->curframe++;
	if(p->curframe>=4)
	{
		p->curframe=0;
	}
		p->frame.x=p->curframe * p->frame.w;  

	}	
	else
		if(p->direction==2)
		{ 
			p->frame.y=100;
			p->curframe++;
		if(p->curframe>=4)
		{
			p->curframe=0;
		}
		p->frame.x=p->curframe * p->frame.w;  
  
		}
	else 
		if(p->direction==0)
		{
			p->frame.x=0;

		}

}


void saut(Personne *p){
//kenet 700
	if(p->position.y<500){
   	p->position.x += p->v_x;
   	p->position.y+= p->v_y;
   	p->v_y += p->v_grav;
   }
  	if (p->position.y> 500)
    	p->v_y = p->v_saut;
    	
}
void sautgauche(Personne *p){
	if(p->position.y<500){
   	p->position.x -= p->v_x;
   	p->position.y+= p->v_y;
   	p->v_y += p->v_grav;
   }
  	if (p->position.y> 500)
    	p->v_y = p->v_saut;


}

void vitesseUP(Personne *p){
	 SDL_Delay(10);
       
         p->vitesse+=p->acceleration;
         p->position.x+=p->vitesse;
         p->direction=1;
         if(p->vitesse>=30)
         {
          p->vitesse=30;
         }
}
void vitesseDOWN(Personne *p){
 	 p->vitesse=0; 
         p->vitesse-=p->acceleration;
         p->position.x-=p->vitesse;
         p->direction=1;
         if(p->vitesse>=0)
         {
          p->vitesse=0;
         }

}



























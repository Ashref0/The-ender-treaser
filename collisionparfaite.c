#include"collisionparfaite.h"

SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
int  collisionparfaite(SDL_Surface *psurface,SDL_Rect p)
{	
	int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
	tabx[0]=p.x;
	tabx[1]=(p.x)+((p.w)/2);
	tabx[2]=(p.x+p.w);
	tabx[3]=p.x;
	tabx[4]=p.x;
	tabx[5]=(p.x)+((p.w)/2);
	tabx[6]=(p.x+p.w);
	tabx[7]=(p.x+p.w);
	taby[0]=p.y;
	taby[1]=p.y;
	taby[2]=p.y;
	taby[3]=(p.y)+((p.h)/2);
	taby[4]=(p.y+p.h);
	taby[5]=(p.y+p.h);
	taby[6]=(p.y+p.h);
	taby[7]=(p.y)+((p.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getpixel(psurface,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i;

	}
	}
	return 10;
	
}	


void collision(SDL_Surface *psurface,SDL_Rect *p)
{	int i;
	i=collisionparfaite(psurface,*p);
do{
i=collisionparfaite(psurface,*p);
	switch (i)
	{
		case 0 :p->y=p->y+10;
			break;
		case 1 :p->y=p->y+10;
			 break;
		//case 2 :p->y=p->y+10;
			break;
		case 3 :p->x=p->x+10;
			break;
		case 4 :p->y=p->y-10;
			break;
		case 5 :p->y=p->y-10; 
			break;
		case 6 :p->y=p->y-10; 
			break;
		case 7 :p->x=p->x-10;
			break;}
}while((i>-1)&&(i<8));

	
}




#include "header.h"

enigme genererEnigme(char *nomfichier){
    FILE* f;
    enigme e;
    srand( time( NULL ) );
    int alea = rand() % 1,p=0;
    e.background=IMG_Load("cap.jpg");
    f=fopen(nomfichier,"r");
    while (p<alea)
    {
        if (fgetc(f)=='\n')
        {
            p++;
        }
        
    }    
    fscanf(f,"%s %s %s %s %d\n",e.question,e.rep1,e.rep2,e.rep3,&e.solution);
    fclose(f);
    	e.a.sprite=IMG_Load("good.png");
	e.a.pos.x=200;
	e.a.pos.y=100;
	e.a.possprite.x=0;
	e.a.possprite.y=0;
	e.a.possprite.h=200;
	e.a.possprite.w=150;
    return e;
}

void afficherEnigme(enigme *e, SDL_Surface * screen){
    SDL_Surface  *quest = NULL ,*rep1 = NULL ,*rep2 = NULL , *rep3 = NULL;
    SDL_Rect posQ,pos1,pos2,pos3;
    TTF_Font *police = NULL;
    SDL_Color couleur = {255,0,0} ;    
    TTF_Init();
    police = TTF_OpenFont("MAGNETOB.TTF", 30);
    quest = TTF_RenderText_Blended(police, e->question, couleur);
    rep1 = TTF_RenderText_Blended(police, e->rep1, couleur);
    rep2 = TTF_RenderText_Blended(police, e->rep2, couleur);
    rep3 = TTF_RenderText_Blended(police, e->rep3, couleur);
    posQ.x=50;
    posQ.y=100;
    pos1.x=30;
    pos1.y=400;
    pos2.x=310;
    pos2.y=400;
    pos3.x=570;
    pos3.y=400;
    SDL_BlitSurface(e->background, NULL, screen, NULL); 
    SDL_BlitSurface(quest, NULL, screen, &posQ); 
    SDL_BlitSurface(rep1, NULL, screen, &pos1); 
    SDL_BlitSurface(rep2, NULL, screen, &pos2); 
    SDL_BlitSurface(rep3, NULL, screen, &pos3); 
    SDL_BlitSurface(e->a.sprite, &e->a.possprite , screen ,&e->a.pos);

}

void rotozoom(enigme * e,int rep){
if(rep==1)
{
	      if (e->a.possprite.x<750)
	      {
		e->a.possprite.x+=e->a.possprite.w;
		SDL_Delay(500);
	      }
	      else{
	      e->a.possprite.x=0;
	      }
}
if(rep==0)
{
if (e->a.possprite.x<1500)
	      {
		e->a.possprite.x+=e->a.possprite.w;
		SDL_Delay(500);
	      }
	      else{
	      e->a.possprite.x=750;
	      }
}
}


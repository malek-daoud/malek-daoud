#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "header.h"

int main()
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen=NULL;
SDL_Surface *back=NULL;
screen=SDL_SetVideoMode (800,564,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Event event;
SDL_Surface *background=NULL;
SDL_WM_SetCaption("Malek",NULL);
bool running=true;
int reponse=0,rep=2;
enigme e;
e=genererEnigme("que.txt");

while (running)
{
    rotozoom(&e,rep);
    afficherEnigme(&e,screen);
    SDL_Flip(screen);
    while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			running=false;
		break;
        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			
			case SDLK_a:
				if (e.solution==1)
                {
		    rep=1;
                    printf("vrai");
                }
                else {
		    rep=0;
                    printf("faux");
                }
                
      		break;
            case SDLK_z :
                if (e.solution==2)
                {
		    rep=1;
                    printf("vrai");
                }
                else {
		    rep=0;
                    printf("faux");
                }
            break;
            case SDLK_e:
                if (e.solution==3)
                {
		    rep=1;
                    printf("vrai");
                }
                else {
		    rep=0;
                    printf("faux");
                }
            break;
            }
        break;
        }
    }

}


}







 

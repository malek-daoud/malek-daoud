pro:source.o main.o
	gcc source.c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -o prog
source.o:source.c
	gcc -c source.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g	

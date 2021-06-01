prog : main_enigmef.o enigmefichier.o
	gcc main_enigmef.o enigmefichier.o -o prog -lSDL -lSDL_image -lSDL_mixer -g
main_enigmef.o :main_enigmef.c
	gcc -o main_enigmef.o -c main_enigmef.c -lSDL -lSDL_image -lSDL_mixer -g
enigmefichier.o :enigmefichier.c
	gcc -o enigmefichier.o -c enigmefichier.c -lSDL -lSDL_image -lSDL_mixer -g


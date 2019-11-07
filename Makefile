GOAL = star-wars-sb
CC = gcc
FLAGS = -lm
OGL = -lGL -lGLU -lglut

$(GOAL): main.o draw.o
	$(CC) -o $@ $^ $(FLAGS) $(OGL)

main.o: main.c draw.h draw.c
	$(CC) -o $@ $< -c

draw.o: draw.c draw.h
	$(CC) -o $@ $< -c

.PHONY:
	clean

clean:
	rm -rf $(GOAL) *.o

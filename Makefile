GOAL = star-wars-sb
CC = gcc
FLAGS = -lm
OGL = -lGL -lGLU -lglut

$(GOAL): main.o draw.o function.o image.o
	$(CC) -o $@ $^ $(FLAGS) $(OGL)

main.o: main.c draw.h draw.c function.h function.c image.h image.c
	$(CC) -o $@ $< -c

draw.o: draw.c draw.h
	$(CC) -o $@ $< -c

function.o: function.c function.h
	$(CC) -o $@ $< -c

image.o: image.c image.h
	$(CC) -o $@ $< -c

.PHONY:
	clean

clean:
	rm -rf $(GOAL) *.o

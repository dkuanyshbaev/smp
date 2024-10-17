NAME=./bin/smp
MAIN=./src/main.c
CC=cc
LIBS=-lcurses -lpthread -ldl -lm
FLAGS=-Wall

build:
	mkdir -p bin
	$(CC) -o $(NAME) $(MAIN) $(FLAGS) $(LIBS)

clean:
	rm -r bin/

run: build
	$(NAME) /home/denis/music/atmo/baba

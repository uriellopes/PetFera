#Nome do executavel
PROJ = exec

#arquivos dos .o .h e .cpp
FILE_OBJ = obj/
FILE_INC = includes/
FILE_CPP = cpp/

#verifica se a pasta obj existe
MKDIR = $(shell test ! -d obj && echo mkdir obj)

#compilador
CC = g++

#flags
FLAGS = -std=c++11 -Wall -pedantic -g -O0

#flags dos .o
OBJ_FLAG = -c $< -o $@

#.o para criar o executavel
OBJS = $(FILE_OBJ)main.o $(FILE_OBJ)funcionario.o $(FILE_OBJ)tratador.o $(FILE_OBJ)veterinario.o

all: create $(PROJ)

create:
	$(MKDIR)

$(PROJ): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

$(FILE_OBJ)main.o: $(FILE_CPP)main.cpp $(FILE_INC)animal.h $(FILE_INC)tratador.h $(FILE_INC)veterinario.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)funcionario.o: $(FILE_CPP)funcionario.cpp $(FILE_INC)funcionario.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)tratador.o: $(FILE_CPP)tratador.cpp $(FILE_INC)tratador.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)veterinario.o: $(FILE_CPP)veterinario.cpp $(FILE_INC)veterinario.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

run:
	./$(PROJ)

clean:
	rm -rf $(FILE_OBJ)*.o $(PROJ)
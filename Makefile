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


#flags de cada grupo de animal e funcionario
FUNC_FILES = $(FILE_OBJ)funcionario.o $(FILE_OBJ)tratador.o $(FILE_OBJ)veterinario.o
ANIM_FILES = $(FILE_OBJ)animal.o $(FILE_OBJ)animalsilvestre.o $(FILE_OBJ)animalnativo.o $(FILE_OBJ)animalexotico.o
ANF_FILES = $(FILE_OBJ)anfibio.o $(FILE_OBJ)anfibionativo.o $(FILE_OBJ)anfibioexotico.o
MAN_FILES = $(FILE_OBJ)mamifero.o $(FILE_OBJ)mamiferonativo.o $(FILE_OBJ)mamiferoexotico.o
REP_FILES = $(FILE_OBJ)reptil.o $(FILE_OBJ)reptilnativo.o $(FILE_OBJ)reptilexotico.o
AVE_FILES = $(FILE_OBJ)ave.o

#.o para criar o executavel
OBJS = $(FILE_OBJ)main.o $(FUNC_FILES) $(ANIM_FILES) $(ANF_FILES) $(MAN_FILES) $(REP_FILES) $(AVE_FILES)

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

$(FILE_OBJ)animal.o: $(FILE_CPP)animal.cpp $(FILE_INC)animal.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)animalsilvestre.o: $(FILE_CPP)animalsilvestre.cpp $(FILE_INC)animalsilvestre.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)animalnativo.o: $(FILE_CPP)animalnativo.cpp $(FILE_INC)animalnativo.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)animalexotico.o: $(FILE_CPP)animalexotico.cpp $(FILE_INC)animalexotico.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)anfibio.o: $(FILE_CPP)anfibio.cpp $(FILE_INC)anfibio.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)anfibionativo.o: $(FILE_CPP)anfibionativo.cpp $(FILE_INC)anfibionativo.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)anfibioexotico.o: $(FILE_CPP)anfibioexotico.cpp $(FILE_INC)anfibioexotico.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)mamifero.o: $(FILE_CPP)mamifero.cpp $(FILE_INC)mamifero.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)mamiferonativo.o: $(FILE_CPP)mamiferonativo.cpp $(FILE_INC)mamiferonativo.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)mamiferoexotico.o: $(FILE_CPP)mamiferoexotico.cpp $(FILE_INC)mamiferoexotico.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)reptil.o: $(FILE_CPP)reptil.cpp $(FILE_INC)reptil.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)reptilnativo.o: $(FILE_CPP)reptilnativo.cpp $(FILE_INC)reptilnativo.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)reptilexotico.o: $(FILE_CPP)reptilexotico.cpp $(FILE_INC)reptilexotico.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)ave.o: $(FILE_CPP)ave.cpp $(FILE_INC)ave.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

run:
	./$(PROJ)

clean:
	rm -rf $(FILE_OBJ)*.o $(PROJ)
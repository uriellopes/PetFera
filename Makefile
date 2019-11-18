INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib
BIN_DIR = bin

CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -I. -I$(INC_DIR)
AR = ar

petfera.a: $(INC_DIR)/*.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/anfibio.cpp -o $(OBJ_DIR)/anfibio.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/animal.cpp -o $(OBJ_DIR)/animal.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/animalSilvestre.cpp -o $(OBJ_DIR)/animalSilvestre.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/ave.cpp -o $(OBJ_DIR)/ave.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/exotico.cpp -o $(OBJ_DIR)/exotico.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/funcionario.cpp -o $(OBJ_DIR)/funcionario.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/funcoes_gerais.cpp -o $(OBJ_DIR)/funcoes_gerais.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/mamifero.cpp -o $(OBJ_DIR)/mamifero.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/nativo.cpp -o $(OBJ_DIR)/nativo.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/reptil.cpp -o $(OBJ_DIR)/reptil.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/tratador.cpp -o $(OBJ_DIR)/tratador.o
	$(CC) -c $(CFLAGS) $(SRC_DIR)/veterinario.cpp -o $(OBJ_DIR)/veterinario.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/anfibio.o $(OBJ_DIR)/animal.o $(OBJ_DIR)/animalSilvestre.o $(OBJ_DIR)/ave.o $(OBJ_DIR)/exotico.o $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/funcoes_gerais.o $(OBJ_DIR)/mamifero.o $(OBJ_DIR)/nativo.o $(OBJ_DIR)/reptil.o $(OBJ_DIR)/tratador.o $(OBJ_DIR)/veterinario.o
	@echo "+++ [BIBLIOTECA ESTATICA CRIADA EM $(LIB_DIR)/$@]+++"

petfera.so: $(SRC_DIR)/anfibio.cpp $(SRC_DIR)/animal.cpp $(SRC_DIR)/animalSilvestre.cpp $(SRC_DIR)/ave.cpp $(SRC_DIR)/exotico.cpp $(SRC_DIR)/funcionario.cpp $(SRC_DIR)/funcoes_gerais.cpp $(SRC_DIR)/mamifero.cpp $(SRC_DIR)/nativo.cpp $(SRC_DIR)/reptil.cpp $(SRC_DIR)/tratador.cpp $(SRC_DIR)/veterinario.cpp $(INC_DIR)/*.h
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/anfibio.cpp -o $(OBJ_DIR)/anfibio2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/animal.cpp -o $(OBJ_DIR)/animal2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/animalSilvestre.cpp -o $(OBJ_DIR)/animalSilvestre2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/ave.cpp -o $(OBJ_DIR)/ave2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/exotico.cpp -o $(OBJ_DIR)/exotico2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/funcionario.cpp -o $(OBJ_DIR)/funcionario2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/funcoes_gerais.cpp -o $(OBJ_DIR)/funcoes_gerais2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/mamifero.cpp -o $(OBJ_DIR)/mamifero2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/nativo.cpp -o $(OBJ_DIR)/nativo2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/reptil.cpp -o $(OBJ_DIR)/reptil2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/tratador.cpp -o $(OBJ_DIR)/tratador2.o
	$(CC) -fPIC -c $(CFLAGS) $(SRC_DIR)/veterinario.cpp -o $(OBJ_DIR)/veterinario2.o	
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/anfibio2.o $(OBJ_DIR)/animal2.o $(OBJ_DIR)/animalSilvestre2.o $(OBJ_DIR)/ave2.o $(OBJ_DIR)/exotico2.o $(OBJ_DIR)/funcionario2.o $(OBJ_DIR)/funcoes_gerais2.o $(OBJ_DIR)/mamifero2.o $(OBJ_DIR)/nativo2.o $(OBJ_DIR)/reptil2.o $(OBJ_DIR)/tratador2.o $(OBJ_DIR)/veterinario2.o
	@echo "+++ [BIBLIOTECA DINAMICA CRIADA EM $(LIB_DIR)/$@] +++"

petfera_static.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/petfera.cpp $(LIB_DIR)/petfera.a -o $(BIN_DIR)/$@
	@echo "+++[CRIADO EXCUTAVEL STATIC EM $(BIN_DIR)/$@]+++"

petfera_dinamic.exe:
	#sudo mv $(HOME)/PETFERA/lib/petfera.so /usr/lib
	#sudo ldconfig
	#ldconfig -p | grep petfera
	$(CC) $(CFLAGS) $(SRC_DIR)/petfera.cpp $(LIB_DIR)/petfera.so -o $(BIN_DIR)/$@
	@echo "+++[CRIADO EXCUTAVEL DINAMIC EM $(BIN_DIR)/$@]+++"

exportar_static.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/exportar.cpp $(LIB_DIR)/petfera.a -o $(BIN_DIR)/$@
	@echo "+++[CRIADO EXCUTAVEL STATIC EM $(BIN_DIR)/$@]+++"

exportar_dinamic.exe:
	#sudo mv $(HOME)/PETFERA/lib/exportar.so /usr/lib
	#sudo ldconfig
	#ldconfig -p | grep exportar
	$(CC) $(CFLAGS) $(SRC_DIR)/exportar.cpp $(LIB_DIR)/exportar.so -o $(BIN_DIR)/$@
	@echo "+++[CRIADO EXCUTAVEL DINAMIC EM $(BIN_DIR)/$@]+++"

clean:
	rm -r ./bin/*.exe
	rm -r ./build/*.o 
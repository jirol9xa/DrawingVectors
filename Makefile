CC = clang++
I_FLAG = -I ./src/Include
C_FLAG = -c -O3
SFML_FLAGS 	= -lsfml-graphics -lsfml-window -lsfml-system


all: main.o vector.o
	$(CC) main.o vector.o -o test $(SFML_FLAGS)
clear:
	rm -rf *.o

main.o:		main.cpp
	$(CC) $(C_FLAG)	main.cpp -o main.o 
vector.o:	src/Vector/vector.cpp
	$(CC) $(C_FLAG) src/Vector/vector.cpp -o vector.o
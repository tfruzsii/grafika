all:
	g++ -Isrc/Include -Lsrc/lib -o main main.c -lmingw32 -lSDL2main -lSDL2 -lopengl32
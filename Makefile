INC_DIRS = -Iinclude
CFLAGS = -Wall -c

compilation: obj/getoptFunction.o obj/functions.o obj/utils.o obj/main.o
	@ gcc obj/*.o -o bin/output
	@ echo "Compilation."

obj/getoptFunction.o: src/getoptFunction.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/getoptFunction.c -o obj/getoptFunction.o

obj/functions.o: src/functions.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/functions.c -o obj/functions.o

obj/utils.o: src/utils.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/utils.c -o obj/utils.o

obj/main.o: src/main.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/main.c -o obj/main.o

clean:
	@ echo "Clean."
	@ rm -rf obj/*
	@ rm -rf bin/*
	@ rm -rf output/*

run:
	@ echo "Running...\n"
	@ ./bin/output -i 1 -o 2 -N 256 -d 1

start: clean compilation run
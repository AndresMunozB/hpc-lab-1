INC_DIRS = -Iinclude
CFLAGS = -Wall -c

compilation: obj/functions.o obj/utils.o obj/main.o
	@ gcc obj/*.o -o bin/main.out
	@ echo "Compilation success."

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
	@ ./bin/main.out -i ./data/65536floats.raw -o output.raw -N 65536 -d 0

start: clean compilation run
INC_DIRS = -Iinclude
CFLAGS = -Wall -c

compilation: obj/functions.o obj/utils.o obj/listlist.o obj/list.o obj/main.o
	@ gcc obj/*.o -o bin/main.out
	@ echo "Compilation success"

obj/functions.o: src/functions.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/functions.c -o obj/functions.o

obj/listlist.o: src/listlist.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/listlist.c -o obj/listlist.o

obj/list.o: src/list.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/list.c -o obj/list.o

obj/utils.o: src/utils.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/utils.c -o obj/utils.o

obj/main.o: src/main.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/main.c -o obj/main.o

clean:
	@ rm -rf obj/*
	@ rm -rf bin/*
	@ rm -rf output/*
	@ echo "Clean success"

run:
	@ echo "Running..."
	@ ./bin/main.out -i ./data/65536floats.raw -o output.raw -N 65536 -d 0

start: clean compilation run


# gcc -o bubblesort.out listlist.c list.c functions.c utils.c bubblesort.c
#./bubblesort.out -i ../data/65536floats.raw -o salida.out -N 65536 -d 1
INC_DIRS = -Iinclude
CFLAGS = -Wall -c

compilation: obj/functions.o obj/utils.o obj/listlist.o obj/list.o obj/main.o obj/bubblesort.o 
	@ gcc obj/functions.o obj/utils.o obj/listlist.o obj/list.o obj/main.o -o bin/simdsort.out
	@ gcc obj/functions.o obj/utils.o obj/listlist.o obj/list.o obj/bubblesort.o -o bin/bubblesort.out
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

obj/bubblesort.o: src/bubblesort.c
	@ gcc $(CFLAGS) $(INC_DIRS) src/bubblesort.c -o obj/bubblesort.o

clean:
	@ rm -rf obj/*
	@ rm -rf bin/*
	@ rm -rf output/*
	@ echo "Clean success"

run:
	@ echo "Running..."
	@ ./bin/simdsort.out -i ./data/65536floats.raw -o output.raw -N 65536 -d 1

start: clean compilation run

run_bubblesort:
	@ echo "Running..."
	@ ./bin/bubblesort.out -i ./data/65536floats.raw -o salida.out -N 65536 -d 1
	
start_bubblesort: clean compilation run_bubblesort

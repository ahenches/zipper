DEBUG ?= 0
CFLAGS = -Wall
ifeq ($(DEBUG),1)
    CFLAGS += -g
endif

prog: main.o file_reader_util.o huffman_code.o linked_list.o safe_alloc.o
	gcc $(CFLAGS) -o prog main.o file_reader_util.o huffman_code.o linked_list.o safe_alloc.o

main.o : main.c
	gcc $(CFLAGS) -c main.c

huffman_code.o : huffman_code.c
	gcc $(CFLAGS) -c huffman_code.c

file_reader_util.o : file_reader_util.c
	gcc $(CFLAGS) -c file_reader_util.c

linked_list.o : linked_list.c
	gcc $(CFLAGS) -c linked_list.c

safe_alloc.o : safe_alloc.c
	gcc $(CFLAGS) -c safe_alloc.c

clean:
	rm -f *.o prog

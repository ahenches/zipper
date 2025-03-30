prog: main.o file_reader_util.o huffman_code.o
	gcc -o prog main.o file_reader_util.o huffman_code.o

main.o : main.c
	gcc -c -Wall main.c

huffman_code.o : huffman_code.c
	gcc -c -Wall huffman_code.c

file_reader_util.o : file_reader_util.c
	gcc -c -Wall file_reader_util.c

clean:
	rm -f *.o prog

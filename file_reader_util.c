#include <stdio.h>
#include <stdlib.h>
#include "file_reader_util.h"

FILE *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    return file;
}


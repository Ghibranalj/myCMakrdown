#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>

#include "fileio.h"


FILE *GetFile(const char *path)
{
    return fopen(path, "rw");
}

void Read(FILE *file, char *out, int size)
{
    fread(out, sizeof(char), size, file);
    out[size] = '\0';
}

int GetSize(FILE *file)
{
    fseek(file, 0L, SEEK_END);

    // get the total number of bytes (chars) in infile
    int size = ftell(file); // ask for the position

    // Rewind file position indicator back to the start of the file
    rewind(file);

    return size;
}

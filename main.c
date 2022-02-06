#include <stdio.h>
#include<stdlib.h>

#include "fileio/fileio.h"


int main()
{
    FILE *file = GetFile("test.md");
    if(!file) return 1;

    int size = GetSize(file);
    char str[size+1];
    Read(file, str, size);
    
    printf(str);
}
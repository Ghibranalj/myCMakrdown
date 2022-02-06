#pragma once
#include <stdio.h>

FILE *GetFile(const char *path);
void Read(FILE *file, char *out, int size);
int GetSize(FILE *file);
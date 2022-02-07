#pragma once

#include "dstructs/linkedlist.h"

typedef struct tokens tokens;

struct tokens {
    int len;
    char** val;
};

// linkedlist *tkn_getindices(const char *inp);
// void tkn_gettokens(const char* text, linkedlist *indeces, char * strings[], int size); 
tokens *tkn_tokenize(const char *text);
void tkn_free(tokens * token);
#pragma once

#include "dstructs/linkedlist.h"
linkedlist *tkn_getindices(const char *inp);

void tkn_gettokens(const char* text, linkedlist *indeces, char * strings[], int size); 
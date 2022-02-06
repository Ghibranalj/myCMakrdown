#include "dstructs/hashtable.h"


char* hellostr(){
    HashTable* ht = CreateHT();
    FreeHT(ht);
}
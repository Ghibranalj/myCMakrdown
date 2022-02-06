#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dstructs/hashtable.h"
#include "fileio/fileio.h"

int main(int argc, char **argv) {
  // if(argc < 2 ){
  //     printf("Please provide a markdown file");
  //     return -1;
  // }

  // FILE *file = GetFile("test.md");
  // if(!file) return 1;

  // int size = GetSize(file);

  // char str[size+1];
  // Read(file, str, size);

  // printf(str);

  HashTable *ht = CreateHT();

  SetHT(ht, "name1", "em");
  SetHT(ht, "name2", "russian");
  SetHT(ht, "name3", "pizza");
  SetHT(ht, "name4", "doge");
  SetHT(ht, "name5", "pyro");
  SetHT(ht, "name6", "joost");
  SetHT(ht, "name7", "kalix");

  DumpHT(ht);


  char* s = GetHT(ht, "name1");

  printf("name1 : %s\n",s);
  FreeHT(ht);
  return 0;
}
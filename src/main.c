#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dstructs/linkedlist.h"
#include "fileio/fileio.h"

int main(int argc, char **argv) {

  linkedlist *list = ll_create(5);
  ll_append(list, 6);
  ll_append(list, 7);

  ll_gethead(list);

  ll_forward(&list);
  ll_dump(list, false);


  ll_dump(list, true);

  ll_free(list);
  return 0;
}
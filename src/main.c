#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#include "tokenizer/tokenizer.h"

#include "dstructs/linkedlist.h"

int main(int argc, char **argv) {
    //           
    char *text = "hello world this is amazing ***ghibran*** \n\n am i great";

    int len;
    tokens *t = tkn_tokenize(text);

    tkn_free(t);
    printf("\n");
}
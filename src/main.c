#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#include "tokenizer/tokenizer.h"

#include "dstructs/linkedlist.h"

int main(int argc, char **argv) {
    char str [2];


    printf("%s\n", str);

    //           
    char *text = "hello world this is amazing ***ghibran*** \n\n am i great";
    linkedlist *ind = tkn_getindices(text);

    int len = (ll_length(ind, true)) -1;
    char *tokens[len];
    // ll_dump(ind, true);
    tkn_gettokens(text, ind, tokens,len); 
    ll_free(ind);

    for (int i = 0; i < len; i++)
    {
       printf("[%s] ", tokens[i]);
    }
    

    printf("\n");
}
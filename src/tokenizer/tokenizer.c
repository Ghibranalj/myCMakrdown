#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dstructs/hashset.h"
#include "dstructs/linkedlist.h"
#include "stringutil/stringutil.h"

#include "tokenizer.h"

// returns indeces where tokenization should occur
linkedlist *tkn_getindices(const char *inp) {
    linkedlist *list = NULL;
    hashset *set = hs_create();

    // list of special char
    hs_insert(set, "#");
    hs_insert(set, " ");
    hs_insert(set, ">");
    hs_insert(set, "*");
    hs_insert(set, "\n");

    int i = 0;
    char c = inp[i];
    bool is_prev_special = false;
    char p_char = c;
    while (c != '\0') {

        char c_string[2];
        char_to_string(c, c_string);
        bool is_special = hs_contains(set, c_string);

        char n_char = inp[i + 1];
        char n_string[2];
        char_to_string(n_char, n_string);
        bool is_next_special = hs_contains(set, n_string);

        bool charswitch = (p_char != c);
        bool isboundary = (is_special != is_prev_special) ||
                          (is_special && charswitch) || i == 0;

        if (isboundary) {
            if (list == NULL)
                list = ll_create(i);
            else
                ll_append(list, i);
        }

        // walk to next char
        i++;
        p_char = c;
        c = inp[i];
        is_prev_special = is_special;
    }
    ll_append(list, i + 1);
    hs_free(set);

    return list;
}

void tkn_gettokens(const char *text, linkedlist *indices, char *strings[],
                   int size) {
    linkedlist *curr = ll_gethead(indices);
    int i = 0;
    while (curr->next != NULL) {
        int c = curr->val;
        int n = curr->next->val;
        int len = n - c;

        char *token = malloc(sizeof(char) * (len + 1));
        memcpy(token, &text[c], len);
        token[len] = '\0';

        strings[i] = token;

        i++;
        curr = curr->next;
    }
    printf("\n");
}

tokens *tkn_tokenize(const char *text) {
    linkedlist *ind = tkn_getindices(text);

    int len = (ll_length(ind, true)) - 1;

    char **tkns = malloc(len * sizeof(char *));
    tkn_gettokens(text, ind, tkns, len);
    ll_free(ind);

    tokens *ret = malloc(sizeof(tokens));

    ret->len = len;
    ret->val = tkns;

    return ret;
}

void tkn_free(tokens *token) {
    int len = token->len;
    for (int i = 0; i < len; i++) {
        free(token->val[i]);
    }

    free(token);
}
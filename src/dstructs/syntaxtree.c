#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "syntaxtree.h"

syntaxtree *st_create(syntax s, char *value) {
    syntaxtree *st = malloc(sizeof(syntaxtree));
    st->syntax = s;

    int len = strlen(value);
    char *val = malloc(sizeof(char) * len);
    strcpy(val, value);
    st->val = val;
    st->children_len = 0;
    st->children = NULL;
    return st;
}

void st_add_child(syntaxtree *st, syntaxtree *child) {

    syntaxtree **children = st->children;
    // case 1 has no children
    if (children == NULL) {

        syntaxtree **n_children = malloc(sizeof(syntaxtree *) * 1);
        n_children[0] = child;
        st->children = n_children;
    }
    // case 2 has children
    else {
        int len = st->children_len;
        st->children = realloc(st->children, sizeof(syntaxtree *) * len + 1);
        st->children[len] = child;
    }

    st->children_len++;
}

void free_one(syntaxtree *st) {

    free(st->val);
    if (st->children != NULL)
        free(st->children);
    free(st);
}

void st_dump(syntaxtree *st, char *tab) {
    if (st == NULL)
        return;
    // char * out = strcat(st->val , tab);
    printf("%s%s\n", tab, st->val);
    int len = st->children_len;
    for (int i = 0; i < len; i++) {
        syntaxtree *child = st->children[i];
        int len = strlen(tab) * 2;
        char *n_tab = malloc((sizeof(char) * len) + 1);
        strcpy(n_tab, tab);
        strcpy(&n_tab[len / 2], tab);
        st_dump(child, n_tab);
        free(n_tab);
    }
}

void st_free(syntaxtree *st) {
    // if (st == NULL)
    //     return;
    int len = st->children_len;
    for (int i = 0; i < len; i++) {
        syntaxtree *child = st->children[i];
        st_free(child);
    }
    free_one(st);
}
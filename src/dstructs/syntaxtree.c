#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


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
    free(st->children);
    free(st);
}

void st_dump(syntaxtree *st) {
    printf("val : %s; children : %d\n", st->val, st->children_len);
}

void st_free(syntaxtree *st) {
    if(st == NULL) return;
    int len = st->children_len;
    for (int i = 0; i < len; i++) {
        syntaxtree * child = st->children[i];
        st_dump(st);
        st_free(child);
    }
    free_one(st);
}
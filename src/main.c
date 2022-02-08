#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#include "dstructs/syntaxtree.h"

int main(int argc, char **argv) {

    syntax s = none;
    syntaxtree * st = st_create(s, "hello world");
    st_add_child(st, st_create(s,"hello world2"));
    st_add_child(st, st_create(s,"hello world3"));
    // st_dump(st);
    
    st_free(st);
}

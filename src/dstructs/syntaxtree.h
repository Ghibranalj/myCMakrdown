

typedef enum { bold, p, text, quote, none } syntax;


typedef struct syntaxtree syntaxtree;
struct syntaxtree {
    syntax syntax;
    char *val;
    int children_len;
    syntaxtree **children;
};



void st_free(syntaxtree *tree);
void st_dump(syntaxtree *tree);

void st_add_child(syntaxtree *tree, syntaxtree *child);

syntaxtree* st_create();


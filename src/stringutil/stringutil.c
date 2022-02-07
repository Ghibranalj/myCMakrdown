// #include <stdio.h>
#include <string.h>

void char_to_string(const char in, char* out ){

    char ret [2];
    ret[0] = in;
    ret[1] = '\0';
    // printf("converted %s\n", ret);
    strcpy(out, ret);
}


char string_to_char(const char* in){
    return in[0];
}
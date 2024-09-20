#include "cli.h"
#include <stdio.h>

char* menu_labels[] = {"Test1", "Test2"};
menu_f menu_funcs[] = {&test1, &test2};

// Used for testing purposes
int main(int argc, char** argv) {
    if (labels_length() != funcs_length())
        return 1; 

    printf("=============\n");
    printf("  CANMAN V1  \n");
    printf("=============\n");

    int i;
    for (i = 0; i < labels_length(); i++) {
        printf("1. %s\n", menu_labels[i]);
    }

    (menu_funcs[0])();
    (menu_funcs[1])();

    return 0;
}

inline size_t labels_length() {
    return sizeof(menu_labels)/sizeof(*menu_labels);
}

inline size_t funcs_length() {
    return sizeof(menu_funcs)/sizeof(*menu_funcs);
}

void test1() {
    printf("Test 1 has been called\n");
}

void test2() {
    printf("Test 2 has been called\n");
}
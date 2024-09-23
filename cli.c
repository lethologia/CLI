#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>


#include "cli.h"



// Used for testing purposes
int main(int argc, char** argv) {
    while (1) {
        root();
    }

    return 0;
}

// Main menu
void root() {
    print_banner();

    menu_navigation(root_items, _countof(root_items));
}

// root sub-menus
void root_monitor() {
    print("<Monitor>\n");
}

// Configure Menu
void root_configure() {
    print_banner();
    print_heading("Configure");

    menu_navigation(configure_items, _countof(configure_items));
}

// Configure sub-menus
void configure_setname() {

}

void configure_setid() {

}

void configure_calibrate_adc() {

}

void configure_samplerate() {

}

void configure_outputrate() {

}

void configure_verbosity() {

}


// IO Wrapper Definitions.
static void print(const char* string, ...) {
    // printf wrapper
    va_list args;
    va_start(args, string);
    vprintf(string, args);
    va_end(args);
}

static void get_input(char* buffer, size_t buffer_size) {
    // scanf wrapper
    fgets(buffer, buffer_size, stdin);
}

static void clear() {
    // windows clear screen
    system("cls");
}

// Core Function Definitions.
void print_banner() {
    print("=======================\n");
    print("====   CANMAN-V1   ====\n");
    print("=======================\n\n");
}

void print_heading(const char* head) {
    print("%s\n", head);
}

void menu_navigation(menu_item* menu, size_t length) {
    char buffer[64];
    
    for (int i = 0; i < length; i++) {
        print("%d. %s\n", i + 1, menu[i].label);
    }

    while (1) {
        print("\n> ");
        get_input(buffer, sizeof(buffer));

        if (isdigit(buffer[0]) && atoi(buffer[0]) > 0 && atoi(buffer[0]) < length)
            break;
    }

    clear();

    (menu[atoi(buffer) - 1].func)();
}
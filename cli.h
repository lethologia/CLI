#ifndef CLI_H
#define CLI_H

#include <stdio.h>

#define _countof(array) (sizeof(array) / sizeof(array[0]))

// function pointer typedef
typedef void (*menu_f)();

// menu item datastructure
typedef struct menu_item {
	char* label;
	menu_f func;
} menu_item;

// Core CLI functions.
void print_banner();
void print_heading(const char* head);
void menu_navigation(menu_item* menu, size_t length);

// IO wrapper functions defined depending on the platform. Should be defined properly prior to compilation.
static void print(const char* string, ...);
static void get_input(char* buffer, size_t buffer_size);
static void clear();


// ---------------------------------------------
// Menu Definition Section.

// Root Menu
void root();
void root_monitor();
void root_configure();

menu_item root_items[] = {
	{"Monitor", &root_monitor},
	{"Configure", &root_configure},
};

// Configure Menu
void configure_setname();
void configure_setid();
void configure_calibrate_adc();
void configure_samplerate();
void configure_outputrate();
void configure_verbosity();

menu_item configure_items[] = {
	{"Set Node Name", &configure_setname},
	{"Set CAN ID", &configure_setid},
	{"Calibrate ADC", &configure_calibrate_adc},
	{"Set Sample Rate", &configure_samplerate},
	{"Set Output Rate", &configure_outputrate},
	{"Set Log Verbosity", &configure_verbosity},
};

#endif
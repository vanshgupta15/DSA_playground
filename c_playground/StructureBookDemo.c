// 1. create a structure of Book create 
// 2. create a structure pointer
// 3. enter the value in the structures variables using pointer [struct[0]-> name]

#include <stdio.h>
#include <string.h>

// Define the structure globally
struct Book {
    char name[100];
    int prices;
    int pages;
};

void main() {
    void *arr[3];  // array of void pointers

    struct Book B1, B2, B3;

    // Assigning values
    strcpy(B1.name, "DSA Book");
    B1.prices = 400;
    B1.pages = 500;

    strcpy(B2.name, "PS Book");
    B2.prices = 700;
    B2.pages = 650;

    strcpy(B3.name, "AFL Book");
    B3.prices = 969;
    B3.pages = 424;

    // Store the addresses of the structures in the void pointer array
    arr[0] = &B1;
    arr[1] = &B2;
    arr[2] = &B3;

    // Loop through and print
    for (int i = 0; i < 3; i++) {
        struct Book *ptr = (struct Book *)arr[i];  // cast back to correct type

        printf("Book %d:\n", i + 1);
        printf("Name: %s\n", ptr->name);
        printf("Prices: %d\n", ptr->prices);
        printf("Pages: %d\n\n", ptr->pages);
    }
}

#include <stdio.h>
#include <string.h>

struct Book {
    char name[100];
    int prices;
    int pages;
};

int main() {
    // Create an array of Book structures directly
    struct Book books[3];

    // Assign data directly
    strcpy(books[0].name, "DSA Book");
    books[0].prices = 400;
    books[0].pages = 500;

    strcpy(books[1].name, "PS Book");
    books[1].prices = 700;
    books[1].pages = 650;

    strcpy(books[2].name, "AFL Book");
    books[2].prices = 969;
    books[2].pages = 424;

    // Print all book details
    for (int i = 0; i < 3; i++) {
        printf("Book %d:\n", i + 1);
        printf("Name: %s\n", books[i].name);
        printf("Prices: %d\n", books[i].prices);
        printf("Pages: %d\n\n", books[i].pages);
    }

    return 0;
}

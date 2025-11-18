#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int quantity;
    float price;
} Item;

typedef struct {
    Item* items;
    int size;
    int capacity;
} Inventory;

int initializeInventory(Inventory* inv) {
    inv->capacity = 2;
    inv->size = 0;
    inv->items = (Item*)malloc(inv->capacity * sizeof(Item));
    if (inv->items == NULL) {
        printf("Memory allocation failed.\n");
        return 0; 
    }
    return 1; // success
}

int addItem(Inventory* inv) {
    if (inv->size >= inv->capacity) {
        inv->capacity += 2;
        Item* newItems = (Item*)realloc(inv->items, inv->capacity * sizeof(Item));
        if (newItems == NULL) {
            printf("Memory reallocation failed.\n");
            return 0;
        }
        inv->items = newItems;
        free(newItems);
    }

    printf("Enter book name (no spaces): ");
    scanf("%s", inv->items[inv->size].name);

    printf("Enter quantity: ");
    scanf("%d", &inv->items[inv->size].quantity);

    printf("Enter price: ");
    scanf("%f", &inv->items[inv->size].price);

    inv->size++;
    return 1;
}

void viewInventory(const Inventory* inv) {
    if (inv->size == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    for (int i = 0; i < inv->size; i++) {
        printf("%d. Name: %s | Quantity: %d | Price: %.2f\n",
               i + 1, inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

void searchItem(const Inventory* inv) {
    char searchName[100];
    printf("Enter name of book to search (no spaces): ");
    scanf("%s", searchName);

    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, searchName) == 0) {
            printf("Found: %s | Quantity: %d | Price: %.2f\n",
                   inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
            return;
        }
    }
    printf("Book not found in inventory.\n");
}

int main() {
    Inventory inv;
    if (!initializeInventory(&inv)) {
        return 1; 
    }

    int choice;
    while (1) {
        printf("\nInventory Menu:\n");
        printf("1. Add item\n");
        printf("2. View inventory\n");
        printf("3. Search item\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (!addItem(&inv)) {
                printf("Unable to add item.\n");
            }
        } else if (choice == 2) {
            viewInventory(&inv);
        } else if (choice == 3) {
            searchItem(&inv);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

  
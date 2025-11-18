#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MANAGER_PASSWORD "manager123"
#define COUNTER_PASSWORD "counter123"
#define MAX_ITEM 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

void login();
void managerMenu();
void counterMenu();
void addItem();
void updateItem();
void deleteItem();
void showMenu();
void placeOrder();
void generateDailySummary();
void checkNotifications();

int invoiceNumber = 1; // Tracks invoice number

int main() {
    login();
    return 0;
}

void login() {
    char password[20];
    int role;

    printf("Select Role:\n1. Manager\n2. Counter\n> ");
    scanf("%d", &role);

    printf("Enter Password: ");
    scanf("%s", password);

    if (role == 1 && strcmp(password, MANAGER_PASSWORD) == 0) {
        managerMenu();
    } else if (role == 2 && strcmp(password, COUNTER_PASSWORD) == 0) {
        counterMenu();
    } else {
        printf("Invalid credentials!\n");
    }
}

void managerMenu() {
    int choice;
    do {
        printf("\n--- Manager Menu ---\n");
        printf("1. Add Item\n2. Update Item\n3. Delete Item\n4. View Menu\n5. Generate Daily Summary\n6. Logout\n> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addItem(); break;
            case 2: updateItem(); break;
            case 3: deleteItem(); break;
            case 4: showMenu(); break;
            case 5: generateDailySummary(); break;
        }
    } while (choice != 6);
}

void counterMenu() {
    checkNotifications();  // Show notifications
    int choice;
    do {
        printf("\n--- Counter Menu ---\n");
        printf("1. View Menu\n2. Place Order\n3. Logout\n> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: showMenu(); break;
            case 2: placeOrder(); break;
        }
    } while (choice != 3);
}
void addItem() {
    FILE *fp = fopen("menu.txt", "a");
    if(fp == NULL){
        printf("Error opening menu.txt\n");
        return;
    }

    Item item;

    printf("Enter Item ID: ");
    scanf("%d", &item.id);
    getchar(); // clear newline left by scanf

    printf("Enter Item Name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; // remove trailing newline

    printf("Enter Price: ");
    scanf("%f", &item.price);

    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);

    fprintf(fp, "%d %s %.2f %d\n", item.id, item.name, item.price, item.quantity);
    fclose(fp);

    // Write notification
    fp = fopen("notify.txt", "a");
    if(fp == NULL){
        printf("Error opening notify.txt\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "[%04d-%02d-%02d %02d:%02d] New item added: %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, item.name);
    fclose(fp);

    printf("Item added successfully and counter notified!\n");
}

void updateItem() {
    FILE *fp = fopen("menu.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Item item;
    int id, found = 0;

    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f %d", &item.id, item.name, &item.price, &item.quantity) != EOF) {
        if (item.id == id) {
            printf("Enter new name: "); scanf("%s", item.name);
            printf("Enter new price: "); scanf("%f", &item.price);
            printf("Enter new quantity: "); scanf("%d", &item.quantity);
            found = 1;
        }
        fprintf(temp, "%d %s %.2f %d\n", item.id, item.name, item.price, item.quantity);
    }

    fclose(fp);
    fclose(temp);
    remove("menu.txt");
    rename("temp.txt", "menu.txt");

    if (found)
        printf("Item updated.\n");
    else
        printf("Item not found.\n");
}

void deleteItem() {
    FILE *fp = fopen("menu.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Item item;
    int id, found = 0;

    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f %d", &item.id, item.name, &item.price, &item.quantity) != EOF) {
        if (item.id != id)
            fprintf(temp, "%d %s %.2f %d\n", item.id, item.name, item.price, item.quantity);
        else
            found = 1;
    }

    fclose(fp);
    fclose(temp);
    remove("menu.txt");
    rename("temp.txt", "menu.txt");
    if (found)
        printf("Item deleted.\n");
    else
        printf("Item not found.\n");
}

void showMenu() {
    FILE *fp = fopen("menu.txt", "r");
    Item item;

    printf("\n--- Menu ---\n");
    printf("ID\tName\tPrice\tQty\n");
    while (fscanf(fp, "%d %s %f %d", &item.id, item.name, &item.price, &item.quantity) != EOF) {
        printf("%d\t%s\t%.2f\t%d\n", item.id, item.name, item.price, item.quantity);
    }

    fclose(fp);
}

void placeOrder() {
    FILE *fp = fopen("menu.txt", "r");
    FILE *sale = fopen("sales.txt", "a");
    Item items[MAX_ITEM];
    int n = 0, id, qty, i, found;
    float total = 0;

    while (fscanf(fp, "%d %s %f %d", &items[n].id, items[n].name, &items[n].price, &items[n].quantity) != EOF)
        n++;

    fclose(fp);

    FILE *temp = fopen("menu.txt", "w");

    // Generate invoice file
    char filename[50];
    sprintf(filename, "invoice_%03d.txt", invoiceNumber++);
    FILE *invoice = fopen(filename, "w");

    // Date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(invoice, "========== INVOICE ==========\n");
    fprintf(invoice, "Date: %04d-%02d-%02d %02d:%02d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
    fprintf(invoice, "-----------------------------\n");
    fprintf(invoice, "ID  Item       Qty Price  Total\n");

    printf("\n--- Place Order ---\n");
    while (1) {
        printf("Enter Item ID (0 to finish): ");
        scanf("%d", &id);
        if (id == 0) break;

        found = 0;
        for (i = 0; i < n; i++) {
            if (items[i].id == id) {
                found = 1;
                printf("Enter quantity: ");
                scanf("%d", &qty);
                if (items[i].quantity >= qty) {
                    items[i].quantity -= qty;
                    float amt = qty * items[i].price;
                    total += amt;
                    fprintf(sale, "%d %d %.2f\n", id, qty, amt);
                    fprintf(invoice, "%-3d %-10s %-3d %.2f  %.2f\n", id, items[i].name, qty, items[i].price, amt);
                    printf("Added %s x%d = %.2f\n", items[i].name, qty, amt);
                } else {
                    printf("Not enough stock.\n");
                }
                break;
            }
        }
        if (!found)
            printf("Item not found.\n");
    }

    for (i = 0; i < n; i++)
        fprintf(temp, "%d %s %.2f %d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);

    fprintf(invoice, "-----------------------------\n");
    fprintf(invoice, "Grand Total:           %.2f\n", total);
    fprintf(invoice, "========== THANK YOU ==========\n");

    fclose(temp);
    fclose(sale);
    fclose(invoice);

    printf("Invoice saved to %s\n", filename);
    printf("Total = %.2f\n", total);
}

void generateDailySummary() {
    FILE *fp = fopen("sales.txt", "r");
    int id, qty;
    float amt, total = 0;

    printf("\n--- Daily Summary ---\n");
    printf("ID\tQty\tAmount\n");


    FILE *out = fopen("summary.txt", "a");
    fprintf(out, "Daily Summary\nID\tQty\tAmount\n");
    
    
    
    while (fscanf(fp, "%d %d %f", &id, &qty, &amt) != EOF) {
        printf("%d\t%d\t%.2f\n", id, qty, amt);
        fprintf(out, "%d\t%d\t%.2f\n", id, qty, amt);
        total += amt;
    }

    printf("Total Sales: %.2f\n", total);
    fprintf(out, "Total Sales: %.2f\n", total);

    fclose(fp);
    fclose(out);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char archivename[100];
    sprintf(archivename, "summary_%04d%02d%02d.txt", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
    rename("summary.txt",archivename);
    FILE *newsummary = fopen("summary.txt", "a");
    fclose(newsummary);

    // Archive sales file
    time_t r = time(NULL);
    struct tm tn = *localtime(&r);
    char archiveName[100];
    sprintf(archiveName, "sales_%04d%02d%02d.txt", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);

    rename("sales.txt", archiveName);
    FILE *newSales = fopen("sales.txt", "a");
    fclose(newSales);

    printf("Sales archived to %s\n", archiveName);
}

void checkNotifications() {FILE *fp = fopen("notify.txt", "a");
    char msg[200];
    if (fp != NULL) {
        printf("\n Notifications:\n");
        while (fgets(msg, sizeof(msg), fp)) {
            printf("%s", msg);
        }
        fclose(fp);
        // Clear after reading
        fp = fopen("notify.txt", "a");
        fclose(fp);
    }
}
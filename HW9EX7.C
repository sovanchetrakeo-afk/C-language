#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
  int* data;           // The list of items
  int size;			// How many items are currently in the list of items
  int capacity;		// What is the space allocated for the list of items
} List;
void addToList(List* list, int value) {
  if (list->size >= list->capacity) {
    list->capacity *= 2;  // Double capacity
    int* newData = (int*)realloc(list->data, list->capacity * sizeof(int));
    if (newData == NULL) {
      printf("Reallocation failed\n");
      free(list->data);
      exit(1);
    }
    list->data = newData;
  }
  list->data[list->size] = value;
  list->size++;
}

int main() {

  // Create a list and start with enough space for 2 items
  List myList;  
  myList.size = 0;
  myList.capacity = 2;
  myList.data = (int*)malloc(myList.capacity * sizeof(int));

  // Find out if memory allocation was successful
  if (myList.data == NULL) {
    printf("Memory allocation failed");
    return 1; // Exit the program with an error code
  }
  // Add 5 items to the list
  for (int i = 0; i < 5; i++) {
    addToList(&myList, i + 1);
  }

  // Display the contents of the list
  printf("Final list content:");
  for (int j = 0; j < myList.size; j++) {
    printf("%d ", myList.data[j]);
  }

  // Free the memory when it is no longer needed
  free(myList.data);
  myList.data = NULL;

  return 0;
}





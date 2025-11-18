#include <stdio.h>
#include <string.h>
int main(){
char names[3][10]={"Alice", "Bob", "Charlie"};
strcpy(names[1], "Charlie");
printf("%s\n", names[1]);
}

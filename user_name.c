#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int length, i;

   
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);  


    name[strcspn(name, "\n")] = '\0';

   
    length = strlen(name);

    
    printf("Reversed name: ");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", name[i]);
    }

    printf("\n");

    return 0;
}

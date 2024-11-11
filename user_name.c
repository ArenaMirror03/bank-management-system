#include <stdio.h>
#include <string.h>

int main() {
  char str[10];
  int length, i;

  printf("Enter your name: ");
  gets(str);
  length = strlen(str);
  printf("Reverse: \n");
  for (i=length; i >= 0; i-- )

  {
    printf("%c", str[i]);
  }

  

  return 0;
}

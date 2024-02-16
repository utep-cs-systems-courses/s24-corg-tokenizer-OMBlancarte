#include "stdio.h"

int main()
{
  char input[20];
  printf("$ ");
  scanf("%[^\n]",input);
  printf("%s\n", input);
  return 0;
}

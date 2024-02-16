#include "stdio.h"
#include "tokenizer.h"

int main()
{
  char input[20];
  printf("$ ");
  scanf("%[^\n]",input);
  printf("%s\n", input);
  
  int outcome = space_char('A');
  printf("%d\n", outcome);
  outcome = space_char(' ');
  printf("%d\n", outcome);
  return 0;
}

int space_char(char c)
{
  return c == ' ' || c == '\t' ? 1 : 0;
}

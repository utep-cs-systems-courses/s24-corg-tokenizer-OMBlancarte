#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"

int main()
{
  char input[20];
  printf("$ ");
  scanf("%[^\n]",input);
  printf("%s\n", input);
  int outcome;
  /*
  //Testing space_char method
  outcome = space_char('A');
  printf("Space_char test with A: %d\n", outcome);
  outcome = space_char(' ');
  printf("Space_char test with space char: %d\n", outcome);
  */
  // Testing non_space_char method
  outcome = count_tokens(input);
  printf("Number of tokens: %d\n", outcome);
  char *beggining = token_start(input);
  printf("%c\n", *beggining);
  char *end = token_terminator(input);
  printf("%c", *end);
  printf("alksdjf\n");
  
  return 0;
}

int space_char(char c)
{
  return c == ' ' || c == '\t' ? 1 : 0;
}

int non_space_char(char c)
{
  return c != ' ' && c != '\t' ? 1 : 0;
}

char *token_start(char *str)
{
  if(*str == '\0')
    return NULL;

  while(space_char(*str++))
    ;
  return str - 1;
}

char*token_terminator(char *token)
{
  while(non_space_char(*token))
    token++;
  return token;
}
  
int count_tokens(char *s)
{
  int count, state;
 
  state = OUT;
  count = 0;

  while(*s++){
    if(space_char(*s))
      state = OUT;
    else if(state == OUT){
      state = IN;
      ++count;
    }
  }
  return count;
}

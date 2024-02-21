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
  
  /*testing token_start and token_terminator and copy_str
  outcome = count_tokens(input);
  printf("Number of tokens: %d\n", outcome);
  char *begin = token_start(input);
  char*end = token_terminator(input);
  int length = end - begin;
  printf("length of token: %d\n", length);
  char *copye = copy_str(begin, length);
  printf("copy: %s\n", copye);
  */
  
  char **final = tokenize(input);
  print_tokens(final);
  /*
  char *dumb = beggin;
  while (*dumb != '\0')
    dumb++;
  short length = dumb - beggin;
  printf("Length of word: %d\n", length);
  char *copy = copy_str(beggin, length);
  printf("Copy word: %s\n", copy);
  */
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

char *token_terminator(char *token)
{
  while((*token != '\0') && (non_space_char(*token)))
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

char *copy_str(char *inStr, short len)
{
  char *str_copy = malloc(sizeof(char) * (len + 1));
  int i;
  
  for(i = 0; i < len; i++) 
    str_copy[i] = inStr[i];

  str_copy[i+1] = '\0';

  return str_copy;
}

char **tokenize(char* str)
{
  int token_count = count_tokens(str);

  char **tokens = malloc(sizeof(char *) * (token_count));

  for(int i = 0; i < token_count; i++){
    str = token_start(str);
    char *terminator = token_terminator(str);
    int length = terminator - str;
    printf("Length of token: %d\n", length);
    tokens[i] = malloc(sizeof(char) * (length+1));
    char *str_copy = copy_str(str,length);
    for(int j = 0; j < length; j++)
      tokens[i][j] = str_copy[j];
    free(str_copy);
    tokens[i][length] = '\0';
    str = token_start(terminator);
  }
  tokens[token_count] = NULL;
  return tokens;
}

void print_tokens(char **tokens)
{
  for(int i = 0; token[i] != NULL; i++)
    printf("%s\n", tokens[i]);
}

void free_tokens(char **tokens) {
  for(int i = 0; tokens[i] != NULL; i++)
    free(tokens[i]);

  free(tokens);
}

#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"

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
  // Allocate space for copy
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

  // Allocate enough memory for the array of pointers with the number of tokens
  char **tokens = malloc(sizeof(char *) * (token_count));

  // Iterate through the string, find tokens, allocate and copy into tokenizer 
  for(int i = 0; i < token_count; i++){
    str = token_start(str);
    char *terminator = token_terminator(str);
    int length = terminator - str;
    tokens[i] = malloc(sizeof(char) * (length+1));
    char *str_copy = copy_str(str,length);
    for(int j = 0; j < length; j++)
      tokens[i][j] = str_copy[j];
    // Free the string copy and add \0 at the end
    free(str_copy);
    tokens[i][length] = '\0';
    // Begin looping through with the token_starting at the beginning
    str = token_start(terminator);
  }
  // Have the end of the array be null
  tokens[token_count] = NULL;
  return tokens;
}

void print_tokens(char **tokens)
{
  for(int i = 0; tokens[i] != NULL; i++)
    printf("%s\n", tokens[i]);
}

void free_tokens(char **tokens) {
  for(int i = 0; tokens[i] != NULL; i++)
    free(tokens[i]);

  free(tokens);
}

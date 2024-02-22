#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"

int history_recall_command(char *str);
int quit_check(char *str);

// Use page 24
int main()
{
  char input[1000];
  List *history = init_history();
  int id = 0;
  // infinite loop, enter quit to terminate program
  while(1) {
    printf("$ ");
    scanf(" %[^\n]", input);
    printf("\n");
    
    // Check if input starts with a ! and if following  characters are ints
    if((input[0] == '!') && (id = history_recall_command(input) > 0)) {
      // If id > 0 then it is a history recall command 
      char *past = get_history(history, id);
      // past is NULL whitch list is empty or id does not exist
      if(past == NULL){
	printf("Error cannot retrieve history number: %d\n", id);
      }
      // Print history with associated id
      else {
	printf("%d: %s\n", id, past);
      }
      
    }
    else if((input[0] == 'q') && (strLength(input) == 4) && (quit_check(input))) {
      goto quit;
    }
    else {
      add_history(history, input);
      char **tokens = tokenize(input);
      int token_count = count_tokens(input);
      printf("Token count: %d\n", token_count);
      printf("Print Tokens:\n");
      print_tokens(tokens);
      printf("\nPrint History:\n");
      print_history(history);
    }
  }

 quit:
  printf("Goodbye\n");
  return 0;
}

// Checks if the input is a history recall command, returns 0 if iteration is not equal to length
int history_recall_command(char *str)
{
  int i, n, length;

  length = strLength(str);
  n = 0;
  printf("length: %d\n", length);
  // Iterate through the string converting the string to int
  for(i = 1; (str[i] >= '0') && (str[i] <= '9'); i++) {
    n = 10 * n + (str[i] - '0');
  }
  printf("n: %d\n", n);
  printf("i: %d\n", i);
  // If i is equal to length then it is a history recall command
  if(i == length)
    return n;
  // If it is not then it will be treated as a string
  else
    return 0;
}

int quit_check(char *str)
{
  char *quit = "quit";

  for(int i = 0; str[i] == quit[i]; i++){
    if(str[i] == '\0')
      return 1;
  }
    return 0;
}

#include "stdio.h"
#include "stdlib.h"
#include "history.h"

List* init_history()
{
  List *history = malloc(sizeof(List));

  // In case malloc returns null pointer
  if(history == NULL) {
    printf("Allocation failure history\n");
    return NULL;
  }

  // Linked List is empty, root is NULL
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{
  // Allocate memory for new item
  Item *new_item = malloc(sizeof(Item));

  // In case malloc returns null pointer
  if(new_item == NULL){
    printf("Allocation failure new_item\n");
    return;
  }

  // Copy string into Items's string
  int length = strLength(str);
  char *str_copy = malloc(sizeof(char) * (length + 1));

  for(int i = 0; i < length; i++){
    str_copy[i] = str[i];
  }
  str_copy[length] = '\0';
  new_item->str = str_copy;
  new_item->next = NULL;

  // Add to list
  // If root is NULL then first item in list
  if(list->root == NULL) {
    new_item->id = 1;
    list->root = new_item;
  }
  // If list root is not NULL then traverse through list till Item-> next is NULL 
  else {
    Item *temp = list->root;
    while(temp->next != NULL)
      temp = temp->next;
    // Add new_item to end of list and increment id
    new_item->id = temp->id + 1;
    temp->next = new_item;
  }
}

/* Get string length */
int strLength(char *s)
{
  /*
  char *sc = s;
  while(*sc++)
    ;
  return sc - s;
  */
  char *sc = s;
  while(*sc != '\0')
    sc++;
  return sc - s;
}

char *get_history(List *list, int id)
{

  Item *temp = list->root;

  // If history is empty
  if(temp == NULL){
    printf("History is empty");
    return NULL;
  }

  // Iterate through list till if is found if not then return NULL
  while((temp != NULL) && (temp->id != id))
    temp = temp->next;
  if(temp == NULL) {
    printf("%d in history is unavaliable", id);
    return NULL;
  }
  else 
    return temp->str;
}

void print_history(List *list)
{
  
  Item *temp = list->root;

  if(temp == NULL){
    printf("History is empty");
    return;
  }
  while(temp != NULL) {
    printf("%d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item *temp = list->root;

  if(list == NULL)
    return;

  while(temp != NULL) {
    Item *current_item = temp;
    temp = temp->next;
    free(current_item->str);
    free(current_item);
  }
  free(list);
}

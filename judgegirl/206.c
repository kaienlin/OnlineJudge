#include "card.h"
#include <stdio.h>

void shuffle(int *deck[])
{
    int i;
    int size;
    int *ptr1, *ptr2;
    for ( i = 0; deck[i] != NULL; i++) {
        ;
    }
    size = i;
    ptr1 = deck[0];
    ptr2 = deck[size % 2 ? size / 2 + 1 : size / 2];
    for ( i = 0; i < size; i += 2 ) {
        deck[i] = ptr1++;
    }
    for ( i = 1; i < size; i += 2) {
        deck[i] = ptr2++;
    }
}

void print(int *deck[])
{
    for ( int i = 0; deck[i] != NULL; i++) {
        printf("%d ", *deck[i]);
    }
}
/*
int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;
 
  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);  
  return 0;
}
*/
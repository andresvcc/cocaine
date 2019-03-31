
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "file.cpp"
int main()
{
  if(is_empty_Queue())
          printf("la file est vide \n ");
      else
          printf("la file est non vide \n ");
          /*----------------------------------------*/

  printf("la taille de la file:%d\n" , queue_length ());
  print_Queue();

         /*----------------------------------------*/
  push_Queue (14);
  push_Queue (28);
  push_Queue (16);
  push_Queue (5);
  printf("la taille de la file:%d\n" , queue_length ());
  print_Queue();


        /*----------------------------------------*/
  pop_Queue ();
  printf("la taille de la file:%d\n" , queue_length ());
  print_Queue();

  /*clear_Queue();    //pour effacer tous les élément de la file tout d'un coup
  print_Queue();*/
        /*----------------------------------------*/

  printf("hallo world\n");
  return 0;

}

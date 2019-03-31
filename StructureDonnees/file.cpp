//#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "file.h"

/* prototype */
/*-----------------------------------------------------------------------*/
// une fonction qui vérifie la pile est vide et ici je met pas le file pour pramètre de la fonction ici
bool is_empty_Queue(void) {

    if (first == NULL && last == NULL)
    return true;

    return false ;

}

/*-----------------------------------------------------------------------*/
//pour  voir la lengeur ou nombre d'element de la file
int queue_length (void){

    return nb_element;

}

/*-----------------------------------------------------------------------*/
//pour acceder à la première élement
int queue_first (void) {


    if (is_empty_Queue())
    exit(1);
    return first->valeur;
}


/*-----------------------------------------------------------------------*/
//pour acceder à la première élement
int queue_last (void) {


    if (is_empty_Queue())
    exit(1);
    return last->valeur;
}

/*-----------------------------------------------------------------------*/
void  print_Queue(void){

    if (is_empty_Queue())
    {
        printf ("rien à afficher, la pile est vide.\n ");
        return;
    }
    //si la file n'est pas vide dans ce cas on va créer une variable temporaira
    //créer une espace de copie de pointeur qui point vers première élement (ce n'est pas le première élement c'est un pointeur vers la première élement)
    QueueElement *temp = first ;

    while (temp != NULL )
    {
        printf("[%d]" ,temp-> valeur );
        temp = temp -> next;
    }

    printf ("\n");
}
/*-----------------------------------------------------------------------*/
//fonction pour empiler la file
void push_Queue (int x)
{
QueueElement *element;
element = malloc(sizeof(element));
      if (element == NULL)               //comme tous les allocation il faut le tester
      {
        printf(stderr , "errur d'allocation.\n")
        exit(1);
      }
element->valeur = x ;
element->next = NULL;

      if (is_empty_Queue())
      {
        first = element ;
        last = element ;
      }
      else
      {
       last->next = element ; //on ajout un element à la suit de last
       last = element ;
      }
      nb_element ++ ;     //pour dire que on ajout un nouvelle element
}

/*-----------------------------------------------------------------------*/
//fonction pour depiler la file
void pop_Queue(void)
{
    if(is_empty_Queue())
    {
        printf("la file est vide \n ");
        return;
    }

   QueueElement *temp = first ;   //un vériable temporaire qui point vers first

   if (first = last)              //dans le cas ou on a un seul nb_element
   {
     first = NULL;
     last = NULL;
   }
   else
   first = first->next ;         //càd tout la file seuf la première élément
   free(temp);
   nb_element -- ;                  //pour libérer la memoire car on la pas toujours perdu la variable dépilé à cause de ligne (104)
 }

/*-----------------------------------------------------------------------*/

void clear_Queue (void)
{
    if(is_empty_Queue())
    {
      printf("rien à nettoyer, la file est déjà vide \n ");
      return;
    }
  while (!is_empty_Queue())
  pop_Queue();                //autant d'element que exist tu le dépile (nettvoyer la file).
}

/*-----------------------------------------------------------------------*/

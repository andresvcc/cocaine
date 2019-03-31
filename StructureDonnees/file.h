#ifndef HEADER_FILE_H
#define HEADER_FILE_H

/*-----------------------------------------------------------------------*/
/* défimition d'une type booléen */
typedef enum{

    false ,
    true

}bool;

/*-----------------------------------------------------------------------*/

/* définition d'une file */

typedef struct QueueElement{

    int valeur;                     //on veut travailler avec des entiers
    struct QueueElement *next;      //un pointeur vers le prochain element

}QueueElement, *Queue;

/*-----------------------------------------------------------------------*/

/* pour une seul file on procède de cette manière , pour avoir plusieur files c'est logique de définir une fonction car on va avoir plusieur first et lst*/

static QueueElement *first = NULL ;  //on garde à chaque fois l'element en tete de la file pour y accéder facilement
static QueueElement *last  = NULL ;
static int nb_element  = 0 ;         //pour garder les nombre d'élément de la file

/*-----------------------------------------------------------------------*/

//là avec ces deux fonction j'ai une file vide que je peux directement travailler sur Ca

/*-----------------------------------------------------------------------*/
//déclaration des fonctions utilisé dans le programme
bool is_empty_Queue();
int queue_length ();
int queue_first ();
int queue_last ();
void print_Queue ();
void push_Queue ();
void pop_Queue ();
void clear_Queue ();


#endif

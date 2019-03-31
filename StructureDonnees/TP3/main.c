
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "arbre.h"




int main()
{
  List * passagers = newList();

  lireFichie(passagers);
  listShow(passagers);

  ARBRE * arbreP = newArbre();

  saveInArbre(arbreP);
  //showArbre(arbreP);



  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "arbre.h"




int main()
{
  //List * passagers = newList();

  //lireFichie(passagers);
  //listShow(passagers);

  ARBRE * arbreP = newArbre();

  //saveInArbre(arbreP);
  //showArbre(arbreP);
  addNodeArbre(1,"a","a",1,1,arbreP);
  addNodeArbre(1,"b","b",1,1,arbreP);
  addNodeArbre(1,"c","c",1,1,arbreP);


  showArbre(arbreP);



  return 0;
}

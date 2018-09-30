//declaracion
var names:Set = ["andres","jeisy","violeta"]
//declaration espesificant le type
var names2:Set<String> = ["manuel","tony","rita"]

//demander si l'ensemble est vide
if names.isEmpty {
  print("l'ensemble est vide")
}

//demander le nombre des element dans l'ensemble
print(names.count)

//demander si un element apartians à l'ensemble
if names.contains("andres") {
  print("oui, andres est dans l'ensamble")
}

//demander si deux ensables ont les memes element
if names == names2 {
  print("oui, les deux ensembles sont egaux")
}

//demander si un ensable est une sub-ensemble d'un autre
if names2.isSubset(of:names){
  print("oui, est un sub-ensemble")
}

//demander la capasite total de l'ensemble
print(names.capacity)

//ajouter un element dans l'ensemble
names.insert("hola")
print(names)

//filtrer une ensemble()
print(names.filter{$0.contains("a")})// dans ce cas si $0(element) contiens "a"

//enlever un element de l'ensemble
names.remove("andres")
print(names)

//enlever le premier element
names.removeFirst()
print(names)

//fusioner deux ensembles
names = names.union(names2)
print(names)

//intersection de deux ensembles
var name3 = names.intersection(names2)
print(name3)

//diference simetrique
var name4 = names.symmetricDifference(names2)
print(name4)

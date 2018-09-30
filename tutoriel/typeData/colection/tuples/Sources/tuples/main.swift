var point = (12,5)

print("le type tuple se define comme \(type(of:point))")
print("pour acceder au premier valeur on ecri \(point.0)")
print("pour acceder au deuxieme valeur on ecri \(point.1)")

//modifier un valeur

point.0 = 2
print("apres le changement la tuple est \(point)")

//multiples asignaciones

var (a, b, c) = (1, 2, 3)
print("les valeurs sont a = \(a), b = \(b), c = \(c)")

// multiples variable à une seul tuple
var valeur = (a,b,c)
print("le valeur est \(valeur)")
print(valeur.2)


// d'une tuple avec plusiers valeurs a plusierus variables
var (d,f,g) = valeur
print("les valeur de d,f,g sont \(d) \(f) \(g)")

// avec etiquetes
a = 12
b = 20
c = 60

var ages = (andres:a,vicente:b,caballero:c)
print(ages.andres)
print(ages.vicente)
print(ages.caballero)

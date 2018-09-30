// Des colections
// Arrays

var table:Array<Int> = [0,1,2,3,4,5,6,7]

print("la variable table est de type \(type(of:table)) et contien les valeur \(table)")
var size = table.count
print("la taille du tableau est \(size)")
table.append(8)
print("pour ajouter un nouveau element il faut utiliser append(Int), donc table.append(8) est \(table)")
table.remove(at:3)
print("pour enlever un element a partir de ça position on peut utiliser remove(at:Int), donc table.remove(at:3) est \(table) ")
table.removeFirst()
print("pour enlever le premiere element du table on peut utiliser removeFirst, donc table.removeFirst est \(table)")
table.removeLast()
print("pour enlever le derniere element du table on peut utiliser removeLast, donc table.removeLast est \(table)")
table.removeAll(where: { $0 % 2 == 1 })
print("pour enlever des elements qui ne remplisent pas une condition, on peut utiliser removeALL, donc table.removeAll(where: { $0 % 2 == 1 }) est \(table)")
table.append(contentsOf:[8,10,12,14])
print("pour ajouter plusieurs elements au meme moment on peut utiliser apend(contentsOf: []), donc table.append(contentsOf:[8,10,12,14]) est \(table)")
table.insert(3, at:1)
print("pour ajouter un element dans une position on peut utiliser insert(_,at:Int), donc table.insert(3, at:1) est \(table)")
let i = table.firstIndex(of:4)
print("pour chercher l'index d'un element qui est dans le tableau, on peut utiliser firstIndex(of:), donc l'index du nombre 4 est [table.firstIndex(of:4)] -> \(i!)")
let minimun = table.min()
let maximun = table.max()
print("le minimun est la propiete min et maximun est la propriete max, donc minimun = table.min() est \(minimun!) et maximun = table.max() est \(maximun!)")

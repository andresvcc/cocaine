//types numeriques

var valBinaire:Int = 0b01001 // forme de ecrire une valeur binaire 0b puis le nombre 1001 donc 0b1001 mais le valeur est converti en Integer
var valOctal:Int = 0o1237 // forme de ecrire une valeur octal 0o puis le nombre 1237 donc 0o1237 mais le valeur est converti en Integer
var valHexadecimal:Int = 0x3FA // forme de ecrire une valeur valHexadecimal 0x puis le nombre 3FA donc 0x3FA mais le valeur est converti en Integer
var entiere:Int = 30
var decimale:Double = 3.52

print("la valeur 01001 en base est garde en entirer avec lo valeur \(valBinaire)")
print("la valeur 0o1237 en base est garde en entirer avec lo valeur \(valOctal)")
print("la valeur 0x3FA en base est garde en entirer avec lo valeur \(valHexadecimal)")


print("//----------------------")

// types non numeriques
var texte:String = "Bonjours"
var character:Character = "a"
var booleanne:Bool = true


print("ceci permet de voir le type d'une variable, par exemple la variable texte est de type \(type(of:texte))")

print("//----------------------")

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

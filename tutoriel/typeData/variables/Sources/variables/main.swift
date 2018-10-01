//types numeriques

var valBinaire:Int = 0b01001 // forme de ecrire une valeur binaire 0b puis le nombre 1001 donc 0b1001 mais le valeur est converti en Integer
var valOctal:Int = 0o1237 // forme de ecrire une valeur octal 0o puis le nombre 1237 donc 0o1237 mais le valeur est converti en Integer
var valHexadecimal:Int = 0x3FA // forme de ecrire une valeur valHexadecimal 0x puis le nombre 3FA donc 0x3FA mais le valeur est converti en Integer
var entiere:Int = 30
var decimale:Double = 3.52

print("la valeur 01001 en base est garde en entirer avec lo valeur \(valBinaire)")
print("la valeur 0o1237 en base est garde en entirer avec lo valeur \(valOctal)")
print("la valeur 0x3FA en base est garde en entirer avec lo valeur \(valHexadecimal)")


// types non numeriques
var texte:String = "Bonjours"
var character:Character = "a"
var booleanne:Bool = true


print("ceci permet de voir le type d'une variable, par exemple la variable texte est de type \(type(of:texte))")

var myDictionary:[String:String] = ["andres":"caballero", "jeisy":"mina", "violeta":"caballero"]
var dictionaryVide:[String:String] = [:]

//demander si un dictionaire est vide
if dictionaryVide.isEmpty {
  print("le dictionaire est vide")
}

//demander la taille de dictionaire
print("la taille de dictionaire est \(myDictionary.count)")

//demander la liste des keys
var dicKeys = Array(myDictionary.keys)
print(dicKeys)

//demander la liste de keys simplifie
print(myDictionary.keys)


//demander une liste de valeurs
print(myDictionary.values)

//ajouter un nouveau item
myDictionary["David"] = "Cantillo"
print(myDictionary)


//enlever un item
myDictionary["andres"] = nil
print(myDictionary)

//demander une valeur avec la key et si il n'est present envoier une default
print(myDictionary["jimena", default: "introuvable"])

print(myDictionary["violeta"]!)

//declaration
enum famille {
case mama
case papa
case fis
}

//declaration simplifié
enum famille2{
case mama, papa, fis
}

// acces au donneés
print (famille.mama) //-> andres

//type
print (type(of:famille.self))
print (type(of:famille.mama))

//declarations des variables avec type enum
var luck:famille = .papa
print(luck)
print(type(of:luck))

//enum avec valeurs numeriques
enum nouriture {
case lait(_ litre:Int)
case yaougur(_ litres:Double)
case riz(_ kilo:Int)
}

var desert = nouriture.lait(3)
print(desert)


//enum avec valeur abstrait
indirect enum BinaryTree {
case leaf
case node(BinaryTree, BinaryTree)
}

let aTree:BinaryTree = .node(.leaf, .node(.leaf, .leaf))
print(aTree)

typealias Nom = (nom:String,cod:Int)

struct Etudiant {
  let id:Nom
  var note:Int
}


var andres = Etudiant(id:(nom:"andres",cod:1),note:5)
print(andres)

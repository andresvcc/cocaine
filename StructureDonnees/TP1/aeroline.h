#define charSize 20

//definition de type
typedef struct vol Vol;
typedef struct avion Avion;
typedef struct employe Employe;
typedef struct passage Passage;
typedef struct equipage Equipage;
typedef struct listVol ListVol;
typedef struct listAvion ListAvion;
typedef struct listEmploye ListEmploye;
typedef struct listEquipage ListEquipage;
typedef struct listPassage ListPassage;
typedef struct listHotesse ListHotesse;

//function
Avion * newAvion();
Employe * newEmploye();
Passage * newPassage();
Vol * newVol();
Equipage * newEquipage();
ListHotesse * newlistHotesse();
ListPassage * newlistPassages();
void addHotesse();
void addPassage();
void addVol();
void addAvion();
void addEquipage();
ListVol * newlistVol();
ListAvion * newlistAvion();
int showAvion();
int showEquipage();
void menuNewEquipage();
void menuNewAvion();
Avion * findAvion();
Equipage * findEquipage();
Employe * findEmploye();
void showEmployebyCompetence();

//struct

struct vol {
  int id;
  int heureDepart;
  int heureDarrivage;
  char aeroportDepart[charSize];
  char aeroportDestination[charSize];
  struct avion * avion;
  struct equipage * equipage;
  struct listPassage * listPassages;
};

struct avion {
  int   id;
  char  modele[charSize];
  int  nombreChaises;
  int  dateMisCirculation;
};

struct employe {
  int   id;
  char  nom[charSize];
  char  prenom[charSize];
  int  dateNaissance;
  // competences 1:pilot, 2:chefHotesse, 3:hotesse.
  int  competence;
};

struct passage {
  int   id;
  char  nom[charSize];
  char  prenom[charSize];
  int  chaisse;
};

struct equipage{
  int id;
  Employe * pilot;
  Employe * copilot;
  Employe * chefHotesse;
  ListHotesse * listHotesse;
};

struct listHotesse {
  Employe * data;
  ListHotesse * next;
};

struct listVol {
  Vol * data;
  ListVol * next;
};

struct listAvion {
  Avion * data;
  ListAvion * next;
};

struct listEmploye {
  Employe * data;
  ListEmploye * next;
};

struct listEquipage {
  Equipage * data;
  ListEquipage * next;
};

struct listPassage {
  Passage * data;
  ListPassage * next;
};

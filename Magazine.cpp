#include "Magazine.h"

Magazine::Magazine(int id, string titre, int annee, int numero, string periodicite)
    : Document(id, titre, annee), numero(numero), periodicite(periodicite) {}

void Magazine::afficher() const {
    cout << "Magazine #" << id << " - \"" << titre << "\" (" << annee
         << "), n*" << numero << ", " << periodicite << " - "
         << (disponible ? "Disponible" : "Emprunte") << endl;
}

string Magazine::getType() const {
    return "Magazine";
}

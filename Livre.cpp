#include "Livre.h"

Livre::Livre(int id, string titre, int annee, string auteur, string isbn, int nbPages)
    : Document(id, titre, annee), auteur(auteur), isbn(isbn), nbPages(nbPages) {}

void Livre::afficher() const {
    cout << "Livre #" << id << " - \"" << titre << "\" de " << auteur
         << " (" << annee << "), ISBN " << isbn << ", " << nbPages << " pages - "
         << (disponible ? "Disponible" : "Emprunte") << endl;
}

string Livre::getType() const {
    return "Livre";
}

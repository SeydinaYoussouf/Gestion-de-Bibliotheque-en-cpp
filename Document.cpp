#include "Document.h"

Document::Document(int id, string titre, int annee)
    : id(id), titre(titre), annee(annee), disponible(true) {}

Document::~Document() {}

int Document::getId() const { return id; }
string Document::getTitre() const { return titre; }
int Document::getAnnee() const { return annee; }
bool Document::isDisponible() const { return disponible; }

void Document::setDisponible(bool dispo) { disponible = dispo; }

string Document::getType() const { return "Document"; }

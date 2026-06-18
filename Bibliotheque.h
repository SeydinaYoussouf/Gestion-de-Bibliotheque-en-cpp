#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <string>
#include <vector>
#include "Document.h"
#include "Membre.h"
using namespace std;

class Bibliotheque {
private:
    string nom;
    vector<Document*> documents;
    vector<Membre> membres;

public:
    Bibliotheque(string nom);
    ~Bibliotheque();

    void ajouterDocument(Document* doc);
    void ajouterMembre(const Membre& m);

    Document* rechercherDocument(int id);
    Membre* rechercherMembre(int id);

    void emprunter(int idMembre, int idDoc);
    void retourner(int idMembre, int idDoc);

    void afficherCatalogue() const;
    void afficherMembres() const;
    void afficherStatistiques() const;
};

#endif

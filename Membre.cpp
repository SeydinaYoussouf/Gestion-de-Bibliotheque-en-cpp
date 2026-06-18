#include "Membre.h"
#include <iostream>

Membre::Membre(int idMembre, string nom, string prenom)
    : idMembre(idMembre), nom(nom), prenom(prenom) {}

int Membre::getIdMembre() const { return idMembre; }
string Membre::getNom() const { return nom; }
string Membre::getPrenom() const { return prenom; }
vector<int> Membre::getDocumentsEmpruntes() const { return documentsEmpruntes; }

void Membre::ajouterEmprunt(int idDoc) {
    documentsEmpruntes.push_back(idDoc);
}

void Membre::retirerEmprunt(int idDoc) {
    for (int i = 0; i < documentsEmpruntes.size(); i++) {
        if (documentsEmpruntes[i] == idDoc) {
            documentsEmpruntes.erase(documentsEmpruntes.begin() + i);
            break;
        }
    }
}

int Membre::nbEmpruntsActifs() const {
    return documentsEmpruntes.size();
}

void Membre::afficher() const {
    cout << "Membre #" << idMembre << " : " << prenom << " " << nom;
    cout << " - Emprunts actifs : " << nbEmpruntsActifs() << endl;
    for (int i = 0; i < documentsEmpruntes.size(); i++) {
        cout << "   -> Document #" << documentsEmpruntes[i] << endl;
    }
}

bool Membre::estEgal(int id) const {
    return idMembre == id;
}

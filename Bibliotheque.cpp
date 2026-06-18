#include "Bibliotheque.h"
#include <iostream>

Bibliotheque::Bibliotheque(string nom) : nom(nom) {}

Bibliotheque::~Bibliotheque() {
    for (int i = 0; i < documents.size(); i++) {
        delete documents[i];
    }
    documents.clear();
}

void Bibliotheque::ajouterDocument(Document* doc) {
    documents.push_back(doc);
}

void Bibliotheque::ajouterMembre(const Membre& m) {
    membres.push_back(m);
}

Document* Bibliotheque::rechercherDocument(int id) {
    for (int i = 0; i < documents.size(); i++) {
        if (documents[i]->getId() == id) return documents[i];
    }
    return nullptr;
}

Membre* Bibliotheque::rechercherMembre(int id) {
    for (int i = 0; i < membres.size(); i++) {
        if (membres[i].estEgal(id)) return &membres[i];
    }
    return nullptr;
}

void Bibliotheque::emprunter(int idMembre, int idDoc) {
    Membre* m = rechercherMembre(idMembre);
    Document* d = rechercherDocument(idDoc);

    if (m == nullptr) {
        cout << "Erreur : membre introuvable (ID " << idMembre << ")." << endl;
        return;
    }
    if (d == nullptr) {
        cout << "Erreur : document introuvable (ID " << idDoc << ")." << endl;
        return;
    }
    if (!d->isDisponible()) {
        cout << "Erreur : \"" << d->getTitre() << "\" n'est pas disponible." << endl;
        return;
    }

    d->setDisponible(false);
    m->ajouterEmprunt(idDoc);
    cout << "Emprunt reussi : " << m->getPrenom() << " " << m->getNom()
         << " a emprunte \"" << d->getTitre() << "\"." << endl;
}

void Bibliotheque::retourner(int idMembre, int idDoc) {
    Membre* m = rechercherMembre(idMembre);
    Document* d = rechercherDocument(idDoc);

    if (m == nullptr) {
        cout << "Erreur : membre introuvable (ID " << idMembre << ")." << endl;
        return;
    }
    if (d == nullptr) {
        cout << "Erreur : document introuvable (ID " << idDoc << ")." << endl;
        return;
    }

    d->setDisponible(true);
    m->retirerEmprunt(idDoc);
    cout << "Retour reussi : " << m->getPrenom() << " " << m->getNom()
         << " a rendu \"" << d->getTitre() << "\"." << endl;
}

void Bibliotheque::afficherCatalogue() const {
    cout << "\n=== Catalogue de " << nom << " ===" << endl;
    for (int i = 0; i < documents.size(); i++) {
        documents[i]->afficher();
    }
}

void Bibliotheque::afficherMembres() const {
    cout << "\n=== Membres de " << nom << " ===" << endl;
    for (int i = 0; i < membres.size(); i++) {
        membres[i].afficher();
    }
}

void Bibliotheque::afficherStatistiques() const {
    int total = documents.size();
    int dispo = 0;
    for (int i = 0; i < documents.size(); i++) {
        if (documents[i]->isDisponible()) dispo++;
    }
    int empruntsActifs = total - dispo;

    cout << "\n=== Statistiques de " << nom << " ===" << endl;
    cout << "Documents au total : " << total << endl;
    cout << "Documents disponibles : " << dispo << endl;
    cout << "Emprunts actifs : " << empruntsActifs << endl;
}

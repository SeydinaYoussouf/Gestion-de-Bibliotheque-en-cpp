#ifndef MEMBRE_H
#define MEMBRE_H

#include <string>
#include <vector>
using namespace std;

class Membre {
private:
    int idMembre;
    string nom;
    string prenom;
    vector<int> documentsEmpruntes;

public:
    Membre(int idMembre, string nom, string prenom);

    int getIdMembre() const;
    string getNom() const;
    string getPrenom() const;
    vector<int> getDocumentsEmpruntes() const;

    void ajouterEmprunt(int idDoc);
    void retirerEmprunt(int idDoc);
    int nbEmpruntsActifs() const;
    void afficher() const;

    bool estEgal(int id) const;
};

#endif

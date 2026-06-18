#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
using namespace std;

class Document {
protected:
    int id;
    string titre;
    int annee;
    bool disponible;

public:
    Document(int id, string titre, int annee);
    virtual ~Document();

    int getId() const;
    string getTitre() const;
    int getAnnee() const;
    bool isDisponible() const;

    void setDisponible(bool dispo);

    virtual void afficher() const = 0;
    virtual string getType() const;
};

#endif

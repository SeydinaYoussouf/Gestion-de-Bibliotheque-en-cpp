#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Document.h"

class Magazine : public Document {
private:
    int numero;
    string periodicite;

public:
    Magazine(int id, string titre, int annee, int numero, string periodicite);

    void afficher() const override;
    string getType() const override;
};

#endif

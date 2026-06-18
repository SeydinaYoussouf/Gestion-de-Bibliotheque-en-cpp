#ifndef LIVRE_H
#define LIVRE_H

#include "Document.h"

class Livre : public Document {
private:
    string auteur;
    string isbn;
    int nbPages;

public:
    Livre(int id, string titre, int annee, string auteur, string isbn, int nbPages);

    void afficher() const override;
    string getType() const override;
};

#endif

#include <iostream>
#include "Document.h"
#include "Livre.h"
#include "Magazine.h"
#include "Membre.h"
#include "Bibliotheque.h"

using namespace std;

int main() {
    Bibliotheque bu("BU Centrale");

    // --- Livres ---
    Livre* l1 = new Livre(1, "Une si longue lettre", 1979, "Mariama Ba", "978-2-7236-1234-0", 163);
    Livre* l2 = new Livre(2, "L'Aventure ambigue", 1961, "Cheikh Hamidou Kane", "978-2-264-04567-2", 192);
    Livre* l3 = new Livre(3, "Les Bouts de bois de Dieu", 1960, "Ousmane Sembene", "978-2-264-01122-4", 384);

    // --- Magazines ---
    Magazine* m1 = new Magazine(4, "Jeune Afrique", 2026, 3315, "Hebdomadaire");
    Magazine* m2 = new Magazine(5, "Amina", 2026, 652, "Mensuel");

    bu.ajouterDocument(l1);
    bu.ajouterDocument(l2);
    bu.ajouterDocument(l3);
    bu.ajouterDocument(m1);
    bu.ajouterDocument(m2);

    // --- Membres ---
    Membre mb1(101, "Diop", "Cheikh");
    Membre mb2(102, "Fall", "Aminata");
    Membre mb3(103, "Ndiaye", "Moussa");

    bu.ajouterMembre(mb1);
    bu.ajouterMembre(mb2);
    bu.ajouterMembre(mb3);

    cout << "----- Emprunts -----" << endl;
    bu.emprunter(101, 1);
    bu.emprunter(102, 4);
    bu.emprunter(103, 2);

    cout << "\n----- Cas d'erreur : document deja emprunte -----" << endl;
    bu.emprunter(102, 1);

    bu.afficherCatalogue();

    cout << "\n----- Retour de document -----" << endl;
    bu.retourner(101, 1);

    bu.afficherMembres();
    bu.afficherStatistiques();

    cout << "\n=== Demonstration du polymorphisme ===" << endl;
    Document* tableau[] = { l1, l2, l3, m1, m2 };
    for (int i = 0; i < 5; i++) {
        tableau[i]->afficher();
    }

    return 0;
}

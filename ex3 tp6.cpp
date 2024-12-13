#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    static int numeroSerie;
    static int numeroVehicule;
    int annee;
    double prix;
    int matriculeSerie;
    int matriculeVehicule;

public:
    Vehicule(int annee, double prix) : annee(annee), prix(prix) {
        matriculeVehicule = ++numeroVehicule;
        if (matriculeVehicule > 10000) {
            numeroSerie++;
            numeroVehicule = 1;
            matriculeVehicule = 1;
        }
        matriculeSerie = numeroSerie;
    }

    virtual void accelerer() const = 0;

    virtual void afficher() const {
        cout << matriculeSerie << " TUN " << matriculeVehicule << ", Modele: "
             << annee << ", Prix: " << prix << endl;
    }
};

int Vehicule::numeroSerie = 1;
int Vehicule::numeroVehicule = 0;

class Voiture : public Vehicule {
private:
    int nbPlaces;

public:
    Voiture(int annee, double prix, int nbPlaces)
        : Vehicule(annee, prix), nbPlaces(nbPlaces) {}

    void accelerer() const override {
        cout << "Je peux atteindre 200km/h" << endl;
    }
};

class Camion : public Vehicule {
private:
    double chargeMax;

public:
    Camion(int annee, double prix, double chargeMax)
        : Vehicule(annee, prix), chargeMax(chargeMax) {}

    void accelerer() const override {
        cout << "Je peux atteindre 120km/h" << endl;
    }
};

int main() {
    Vehicule* v1 = new Voiture(2023, 30000, 5);
    Vehicule* v2 = new Camion(2022, 50000, 10);

    v1->afficher();
    v1->accelerer();

    v2->afficher();
    v2->accelerer();

    delete v1;
    delete v2;

    return 0;
}

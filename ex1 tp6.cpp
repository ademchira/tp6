#include <iostream>
using namespace std;

class Vecteur {
protected:
    double x, y;

public:
    Vecteur() : x(0), y(0) {}
    Vecteur(double x, double y) : x(x), y(y) {}
    void afficher() const {
        cout << "(" << x << " , " << y << ")" << endl;
    }

    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

class Vecteur3D : public Vecteur {
private:
    double z;

public:
    Vecteur3D() : Vecteur(), z(0) {}
    Vecteur3D(double x, double y, double z) : Vecteur(x, y), z(z) {}

    void afficher() const {
        cout << "(" << x << " , " << y << " , " << z << ")" << endl;
    }
};

int main() {
    Vecteur v1;
    cout << "Vecteur nul: ";
    v1.afficher();
    v1.deplacer(3.5, 4.5);
    cout << "Apres deplacement: ";
    v1.afficher();
    Vecteur3D* v3 = new Vecteur3D(1.0, 2.0, 3.0);
    cout << "Vecteur3D: ";
    v3->afficher();

    delete v3;
    return 0;
}

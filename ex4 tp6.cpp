#include <iostream>
#include <vector>
using namespace std;

class Piece {
protected:
    string couleur;
    int x, y;

public:
    Piece(string couleur, int x, int y) : couleur(couleur), x(x), y(y) {}

    virtual void deplacer(int dx, int dy) = 0;

    virtual void afficher() const {
        cout << "Type: Inconnu, Couleur: " << couleur << ", Position: (" << x << ", " << y << ")" << endl;
    }
};

class Pion : public Piece {
public:
    Pion(string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer(int dx, int dy) override {
        y += 1;
        if (y > 8) {
            cout << "Deplacement invalide, hors echiquier." << endl;
        }
    }

    void afficher() const override {
        cout << "Type: Pion, Couleur: " << couleur << ", Position: (" << x << ", " << y << ")" << endl;
    }
};

class Roi : public Piece {
public:
    Roi(string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer(int dx, int dy) override {
        x += dx;
        y += dy;
        if (x < 1 || x > 8 || y < 1 || y > 8) {
            cout << "Deplacement invalide, hors echiquier." << endl;
        }
    }

    void afficher() const override {
        cout << "Type: Roi, Couleur: " << couleur << ", Position: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    vector<Piece*> pieces;
    pieces.push_back(new Pion("Blanc", 1, 2));
    pieces.push_back(new Pion("Noir", 2, 7));
    pieces.push_back(new Roi("Blanc", 5, 1));

    for (auto piece : pieces) {
        piece->afficher();
        delete piece;
    }

    return 0;
}

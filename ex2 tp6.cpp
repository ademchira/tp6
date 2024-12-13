#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Robot {
protected:
    string nom;
    double x, y;
    double portee;
    bool estMort;

public:
    Robot(string nom, double x, double y, double portee)
        : nom(nom), x(x), y(y), portee(portee), estMort(false) {}

    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void afficher() const {
        cout << "Nom: " << nom << ", Position: (" << x << ", " << y << ")"
             << ", Portee: " << portee << ", Statut: "
             << (estMort ? "Mort" : "Vivant") << endl;
    }

    bool estDansLaPortee(const Robot& autre) const {
        double distance = sqrt(pow(x - autre.x, 2) + pow(y - autre.y, 2));
        return distance <= portee;
    }

    void tuer(Robot& autre) {
        if (estDansLaPortee(autre) && !autre.estMort) {
            autre.estMort = true;
            cout << autre.nom << " a ete tue par " << nom << endl;
        }
    }
};

class RobotChasseur : public Robot {
public:
    RobotChasseur(string nom, double x, double y, double portee)
        : Robot(nom, x, y, portee) {}
};

int main() {
    RobotChasseur optimus("optimus", 2, 3, 25);
    optimus.deplacer(33, 19);
    optimus.afficher();

    vector<Robot> robots = {
        {"Robot1", 10, 10, 0},
        {"Robot2", 20, 20, 0},
        {"Robot3", 30, 30, 0},
        {"Robot4", 40, 40, 0},
        {"Megatron", 35, 22, 0}
    };

    for (auto& robot : robots) {
        optimus.tuer(robot);
    }

    return 0;
}

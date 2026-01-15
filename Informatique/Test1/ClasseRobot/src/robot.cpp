#include "Robot.h"
#include <iostream>

Robot::Robot()
    : id("N/A"), nom("Robot"), modeAuto(false), batterie(100.0),
      marque("Generic"), modele("Base") {}

std::string Robot::getId() const { return id; }
std::string Robot::getNom() const { return nom; }

std::string Robot::getEtat() const {
    return batterie > 20.0 ? "Fonctionnel" : "Batterie faible";
}

void Robot::setNom(const std::string& n) { nom = n; }
void Robot::setModeAuto(bool m) { modeAuto = m; }
void Robot::setBatterie(double b) { batterie = b; }
void Robot::setNavigation(const Navigation& nav) { navigation = nav; }
void Robot::setMarque(const std::string& m) { marque = m; }
void Robot::setModele(const std::string& mo) { modele = mo; }

std::vector<Capteur> Robot::getCapteurs() const { return capteurs; }
void Robot::setCapteurs(const std::vector<Capteur>& c) { capteurs = c; }

void Robot::ajouterCapteur(const Capteur& c) {
    capteurs.push_back(c);
    std::cout << "Capteur " << c.getNom() << " ajouté.\n";
}

void Robot::obtenirInfos() const {
    std::cout << "Robot: " << nom
              << " | Batterie: " << batterie << "%"
              << " | Mode: " << (modeAuto ? "Auto" : "Manuel") << std::endl;
    navigation.position();
}

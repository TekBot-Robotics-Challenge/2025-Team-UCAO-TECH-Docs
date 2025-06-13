#include "Capteur.h"

Capteur::Capteur() : nom(""), type(""), precision(0.0), portee(0.0), actif(false) {}

std::string Capteur::getNom() const { return nom; }
std::string Capteur::getType() const { return type; }
double Capteur::getPrecision() const { return precision; }
double Capteur::getPortee() const { return portee; }
bool Capteur::getActif() const { return actif; }

void Capteur::setNom(const std::string& n) { nom = n; }
void Capteur::setType(const std::string& t) { type = t; }
void Capteur::setPrecision(double p) { precision = p; }
void Capteur::setPortee(double p) { portee = p; }
void Capteur::setActif(bool a) { actif = a; }

void Capteur::etatCapteur(bool a) {
    actif = a;
    std::cout << "Le capteur " << nom << " est maintenant " << (actif ? "actif" : "inactif") << std::endl;
}

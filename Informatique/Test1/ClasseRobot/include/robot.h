#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <vector>
#include "Navigation.h"
#include "Capteur.h"

class Robot {
protected:
    std::string id;
    std::string nom;
    bool modeAuto;
    Navigation navigation;
    double batterie;
    std::vector<Capteur> capteurs;
    std::string marque;
    std::string modele;

public:
    Robot();
    virtual ~Robot() = default;

    std::string getId() const;
    std::string getNom() const;
    std::string getEtat() const;

    void setNom(const std::string&);
    void setModeAuto(bool);
    void setBatterie(double);
    void setNavigation(const Navigation&);
    void setMarque(const std::string&);
    void setModele(const std::string&);

    std::vector<Capteur> getCapteurs() const;
    void setCapteurs(const std::vector<Capteur>&);
    void ajouterCapteur(const Capteur&);

    void obtenirInfos() const;

    virtual void move(double dx, double dy, double dz) = 0;
};

#endif


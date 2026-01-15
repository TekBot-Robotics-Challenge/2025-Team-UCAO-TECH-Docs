#ifndef CAPTEUR_H
#define CAPTEUR_H

#include <string>
#include <iostream>

class Capteur {
private:
    std::string nom;
    std::string type;
    double precision;
    double portee;
    bool actif;

public:
    Capteur();
    std::string getNom() const;
    std::string getType() const;
    double getPrecision() const;
    double getPortee() const;
    bool getActif() const;

    void setNom(const std::string&);
    void setType(const std::string&);
    void setPrecision(double);
    void setPortee(double);
    void setActif(bool);

    void etatCapteur(bool);
};

#endif

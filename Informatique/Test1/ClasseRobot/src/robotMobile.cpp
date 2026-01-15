#include "RobotMobile.h"
#include <iostream>

RobotMobile::RobotMobile() : vitesse(0.0), direction("N"), typeRoues("Standard") {}

double RobotMobile::getVitesse() const { return vitesse; }
void RobotMobile::setVitesse(double v) { vitesse = v; }

std::string RobotMobile::getDirection() const { return direction; }
void RobotMobile::setDirection(const std::string& d) { direction = d; }

std::string RobotMobile::getTypeRoues() const { return typeRoues; }
void RobotMobile::setTypeRoues(const std::string& t) { typeRoues = t; }

void RobotMobile::move(double dx, double dy, double dz) {
    std::cout << "RobotMobile se déplace de (" << dx << ", " << dy << ", " << dz
              << ") avec vitesse: " << vitesse << std::endl;
}

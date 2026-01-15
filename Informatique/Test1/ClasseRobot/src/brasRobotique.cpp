#include "BrasRobotique.h"
#include <iostream>

BrasRobotique::BrasRobotique() : nombreAxes(6), typePince("standard"), etatPince(false) {}

int BrasRobotique::getNombreAxes() const { return nombreAxes; }
void BrasRobotique::setNombreAxes(int n) { nombreAxes = n; }

std::string BrasRobotique::getTypePince() const { return typePince; }
void BrasRobotique::setTypePince(const std::string& t) { typePince = t; }

bool BrasRobotique::getEtatPince() const { return etatPince; }
void BrasRobotique::setEtatPince(bool e) { etatPince = e; }

void BrasRobotique::move(double dx, double dy, double dz) {
    std::cout << "BrasRobotique bouge de (" << dx << ", " << dy << ", " << dz
              << ") avec " << nombreAxes << " axes." << std::endl;
}

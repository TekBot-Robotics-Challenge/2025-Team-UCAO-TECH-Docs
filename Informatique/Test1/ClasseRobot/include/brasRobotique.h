#ifndef BRASROBOTIQUE_H
#define BRASROBOTIQUE_H

#include "Robot.h"

class BrasRobotique : public Robot {
private:
    int nombreAxes;
    std::string typePince;
    bool etatPince;

public:
    BrasRobotique();

    int getNombreAxes() const;
    void setNombreAxes(int);

    std::string getTypePince() const;
    void setTypePince(const std::string&);

    bool getEtatPince() const;
    void setEtatPince(bool);

    void move(double dx, double dy, double dz) override;
};

#endif

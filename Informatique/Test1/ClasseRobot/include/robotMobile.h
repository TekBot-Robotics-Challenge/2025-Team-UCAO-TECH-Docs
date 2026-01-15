#ifndef ROBOTMOBILE_H
#define ROBOTMOBILE_H

#include "Robot.h"

class RobotMobile : public Robot {
private:
    double vitesse;
    std::string direction;
    std::string typeRoues;

public:
    RobotMobile();

    double getVitesse() const;
    void setVitesse(double);

    std::string getDirection() const;
    void setDirection(const std::string&);

    std::string getTypeRoues() const;
    void setTypeRoues(const std::string&);

    void move(double dx, double dy, double dz = 0.0) override;
};

#endif

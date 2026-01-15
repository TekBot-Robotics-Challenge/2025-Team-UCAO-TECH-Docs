#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <string>
#include <iostream>

class Navigation {
private:
    double x, y, z;
    std::string orientation;
    std::string timestamp;

public:
    Navigation();
    double getX() const;
    double getY() const;
    double getZ() const;
    std::string getOrientation() const;
    std::string getTimestamp() const;

    void setX(double);
    void setY(double);
    void setZ(double);
    void setOrientation(const std::string&);
    void setTimestamp(const std::string&);
    void position() const;
};

#endif

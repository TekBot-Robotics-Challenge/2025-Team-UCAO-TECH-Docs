#include "Navigation.h"

Navigation::Navigation() : x(0), y(0), z(0), orientation("N/A"), timestamp("N/A") {}

double Navigation::getX() const { return x; }
double Navigation::getY() const { return y; }
double Navigation::getZ() const { return z; }
std::string Navigation::getOrientation() const { return orientation; }
std::string Navigation::getTimestamp() const { return timestamp; }

void Navigation::setX(double x_) { x = x_; }
void Navigation::setY(double y_) { y = y_; }
void Navigation::setZ(double z_) { z = z_; }
void Navigation::setOrientation(const std::string& ori) { orientation = ori; }
void Navigation::setTimestamp(const std::string& ts) { timestamp = ts; }

void Navigation::position() const {
    std::cout << "Position actuelle: (" << x << ", " << y << ", " << z
              << ") Orientation: " << orientation << " Timestamp: " << timestamp << std::endl;
}

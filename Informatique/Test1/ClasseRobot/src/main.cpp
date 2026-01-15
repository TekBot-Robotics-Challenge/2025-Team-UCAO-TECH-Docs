#include "RobotMobile.h"
#include "BrasRobotique.h"

int main() {
    RobotMobile rm;
    rm.setNom("ExplorerX");
    rm.setVitesse(2.5);
    rm.move(1.0, 0.0);

    BrasRobotique br;
    br.setNom("Pinceur3000");
    br.move(0.0, 0.5, 0.2);

    return 0;
}

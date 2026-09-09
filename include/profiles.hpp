#include "pros/misc.h"
#include "subsystem.hpp"
int counter = 0;
void kenzy() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        counter += 1;
        if (counter > 8) {
            counter = 0;
        }
    }
}
 #include "main.h"
 #include "ui/screens.hpp"
 #include "PID.hpp"
 #include "subsystem.hpp"


 void autonomous() {

     if (auton_select == 1 || auton_select == 4) {
      drivey(0.15);
      pros::delay(200);
      bdrivey(0.35);
      pros::delay(200);
      drivey(0.5);
      clawlift.move(127);
      leftt(100);
      
     }
     else if (auton_select == 2 || auton_select == 5) {

     }
     else if (auton_select == 3 || auton_select == 6) {

     }
     else if (auton_select == 7) {
        
      }
}
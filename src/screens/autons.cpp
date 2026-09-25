 #include "main.h"
 #include "ui/screens.hpp"
 #include "PID.hpp"

 void autonomous() {

     if (auton_select == 1 || auton_select == 4) {

     }
     else if (auton_select == 2 || auton_select == 5) {

     }
     else if (auton_select == 3 || auton_select == 6) {

     }
     else if (auton_select == 7) {
        odom(0.3,0);
        odom(0,0);
        odom(0.8,1);
        odom(2.5,0);
        odom(1.2,1);
        odom(2.5,0);
        odom(2,1.8);
        odom(3,3);
        odom(1,3);
      }
}
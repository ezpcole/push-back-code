/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Edward                                                    */
/*    Created:      5/8/2025, 11:30:07 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "orange.h"

using namespace vex;

competition Competition;
vex::motor_group left(vex::motor(1),vex::motor(2),vex::motor(3));
vex::motor_group right(vex::motor(4),vex::motor(5),vex::motor(6));
vex::controller Controller = vex::controller();
orange::Drivetrain drivetrain(left,right);

void pre_auton(void) {

}

void autonomous(void) {

}

void usercontrol(void) {
  while (1) {
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    int leftController = Controller.Axis3.position();
    int rightController = Controller.Axis2.position();
    
    left.spin(vex::forward,600*(leftController/100));
    right.spin(vex::forward,600*(rightController/100));

    wait(10, msec);
  }
}

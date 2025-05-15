/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Eza                                                       */
/*    Created:      5/8/2025, 11:30:07 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "orange.hpp"
#include "vex.h"

vex::competition Competition;
vex::motor motor1(1);
vex::motor motor2(2, true);
vex::motor motor3(3);
vex::motor motor4(4);
vex::motor motor5(5);
vex::motor motor6(6);
vex::motor_group left(motor1, motor2, motor3);
vex::motor_group right(motor4, motor5, motor6);
vex::controller Controller = vex::controller();
// orange::Drivetrain drivetrain(orange::BLUE, left, right);

void pre_auton(void) {}

void autonomous(void) {}

void usercontrol(void) {
  left.setMaxTorque(100, vex::percent);
  while (1) {
    double leftController = Controller.Axis3.position();
    int rightController = Controller.Axis2.position();
    left.spin(vex::forward, 600 * (leftController / 100.0), vex::rpm);
    // right.spin(vex::forward, 600 * (rightController / 100), vex::rpm);
    vex::wait(20, vex::msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {

    vex::wait(10, vex::msec);
  }
}

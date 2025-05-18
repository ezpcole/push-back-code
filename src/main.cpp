/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Eza                                                       */
/*    Created:      5/8/2025, 11:30:07 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "graph.hpp"
#include "orange.hpp"
#include "vex.h"
#include <iostream>
#include <string>
#include <vector>

vex::competition Competition;
vex::brain Brain;
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
  // Brain.Screen.clearScreen();

  std::vector<orange::point> examplePoints;
  examplePoints.push_back({0, 0});

  left.setMaxTorque(100, vex::percent);

  double count = 0;
  while (1) {

    double leftController = Controller.Axis3.position();
    int rightController = Controller.Axis2.position();
    left.spin(vex::forward, 600 * (leftController / 100.0), vex::rpm);
    // right.spin(vex::forward, 600 * (rightController / 100), vex::rpm);

    Brain.Screen.clearScreen();
    count += 10;
    examplePoints.push_back({count, 1.5 * count});
    // orange::graph::drawGraph(0, 100, 0, 100, examplePoints);

    vex::wait(20, vex::msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // orange::graph::drawGraph(0, 100, 0, 100, examplePoints);
}

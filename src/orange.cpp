#include "orange.hpp"
#include "vex.h"

orange::Drivetrain::Drivetrain(orange::gearboxType gearbox,
                               vex::motor_group left, vex::motor_group right) {
  this->left = left;
  this->right = right;
  this->gearbox = gearbox;
}
// orange::Drivetrain::Drivetrain(orange::gearboxType gearbox,
//                                vex::motor_group left, vex::motor_group right,
//                                vex::rotation odom) {
//   this->left = left;
//   this->right = right;
//   this->odom = odom;
//   this->gearbox = gearbox;
// }
// orange::Drivetrain::Drivetrain() {
//   this->left = vex::motor_group(vex::motor(1), vex::motor(2), vex::motor(3));
//   this->right = vex::motor_group(vex::motor(4), vex::motor(5),
//   vex::motor(6)); this->gearbox = orange::gearboxType::BLUE;
// }
std::array<vex::motor_group, 2> orange::Drivetrain::GetMotorGroups() {
  return std::array<vex::motor_group, 2>{{this->left, this->right}};
}

void orange::Drivetrain::drive(bool forward, double units,
                               orange::driveType driveType) {
  switch (driveType) {
  case orange::ROTATIONS_PER_MINUTE:
    this->left.spin(vex::forward, units, vex::rpm);
    this->left.spin(vex::forward, units, vex::rpm);
    break;
  case orange::DEGREES_PER_SECOND:
    this->left.spin(vex::forward, units, vex::dps);
    this->left.spin(vex::forward, units, vex::dps);
    break;
  case orange::PERCENTAGE:
    this->left.spin(vex::forward, (units / 100) * this->gearbox, vex::rpm);
    this->left.spin(vex::forward, (units / 100) * this->gearbox, vex::rpm);
    break;
  }
}
// local rpm = gearbox *

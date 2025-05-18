#include "orange.hpp"
#include "vex.h"
#include <cstdarg>
#include <vector>

orange::MotorGroup(orange::gearboxType gearbox,
                   std::vector<vex::motor> motors) {
  this->gearboxType = gearbox;
  this->motors = motors;
}
std::vector<vex::motor> orange::MotorGroup::GetMotors() { return this->motors; }
void orange::MotorGroup::drive(bool forward, double units,
                               orange::driveType driveType) {}

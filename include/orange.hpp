#pragma once
#include <array>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#include "v5.h"
#include "v5_vcs.h"
#include "vex.h"

namespace orange {

enum gearboxType { BLUE = 600, GREEN = 200, RED = 100 };
enum driveType { ROTATIONS_PER_MINUTE, DEGREES_PER_SECOND, PERCENTAGE };

class MotorGroup {
private:
  std::vector<vex::motor> motors;

public:
  MotorGroup(...);
  std::vector<vex::motor> GetMotors();
  void drive();
};

class Drivetrain {
private:
  vex::motor_group left;
  vex::motor_group right;
  vex::rotation odom;
  double wheelTravel;
  double trackWidth;
  double wheelBase;
  double gearRatio;
  orange::gearboxType gearbox;

public:
  void forward(float_t inches);
  void forward_async(float_t inches);
  void turn(float_t deg);
  void turn_async(float_t deg);
  void drive(bool forward, orange::driveType driveType);
  void brake(vex::brakeType mode);

  double GetWheelTravel();
  void SetWheelTravel(double wheelTravel);

  double GetTrackWidth();
  void SetTrackWidth(double trackWidth);

  double GetWheelBase();
  void SetWheelBase(double wheelBase);

  double GetGearRatio();
  void SetGearRatio(double gearRatio);

  std::array<vex::motor_group, 2> GetMotorGroups();

  Drivetrain(orange::gearboxType gearbox, vex::motor_group left,
             vex::motor_group right);
  //   Drivetrain(orange::gearboxType gearbox, vex::motor_group left,
  //              vex::motor_group right, vex::rotation odom);
  //   Drivetrain();
};
} // namespace orange

// TODO:
/*
 - make pid code :3
 - make rpm and dps work with gearing and gearboxes
 - make custom motor group class
*/

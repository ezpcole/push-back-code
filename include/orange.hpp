#pragma once
#include <array>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <functional>
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
  orange::gearboxType gearbox;

public:
  MotorGroup(orange::gearboxType gearbox, std::vector<vex::motor> motors);
  std::vector<vex::motor> GetMotors();
  void drive(bool forward, double units, orange::driveType driveType);
};

class Drivetrain {
private:
  orange::MotorGroup left;
  orange::MotorGroup right;
  // vex::rotation odom;
  double wheelTravel;
  double trackWidth;
  double wheelBase;
  double gearRatio;
  orange::gearboxType gearbox;
  double ki;
  double kp;
  double kd;
  double previousError;
  double integral;

public:
  void forward(float_t inches);
  void forward_async(float_t inches);
  void turn(float_t deg);
  void turn_async(float_t deg);
  void drive(bool forward, double units, orange::driveType driveType);
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

struct point {
  double x;
  double y;
};

class graph {
public:
  static void drawGraph(double minX, double maxX, double minY, double maxY,
                        std::vector<orange::point> points);
  static double convertPoint(double n, double min, double max);
  static int windowOffsetX;
  static int windowOffsetY;
  static int windowEndX;
  static int windowEndY;
  static int hue;
};
} // namespace orange

// TODO:
/*
 - make pid code :3
 - make rpm and dps work with gearing and gearboxes
 - make custom motor group class
*/

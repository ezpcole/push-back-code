#include "orange.hpp"
#include "vex.h"

orange::graph::windowOffsetX = 10;
orange::graph::windowOffsetY = 10;
orange::graph::windowEndX = 240;
orange::graph::windowEndY = 150;
orange::graph::hue = 199;

double orange::graph::convertPoint(double n, double min, double max,
                                   double startWindow, double endWindow) {
  return (((n / (max - min))) * (endWindow - startWindow)) + startWindow
}

void orange::graph::drawGraph(double minX, double maxX, double minY,
                              double maxY, std::vector<orange::point> points) {
  vex::brain Brain;
  Brain.Screen.clearScreen();
  Brain.Screen.setOrigin(10, 10);

  Brain.Screen.drawRectangle(
      orange::graph::windowOffsetX, orange::graph::windowOffsetY,
      orange::graph::windowEndX, orange::graph::windowEndY, orange::graph::hue);

  Brain.Screen.setPenWidth(5);
  Brain.Screen.setPenColor(0xFFFFFF);

  for (int i = 1; i < points.size(); i += 1) {
    orange::point startPoint = points.at(i);
    orange::point endPoint = points.at(i + 1);

    double positionX =
        convertPoint(startPoint.x, minX, maxX, orange::graph::windowOffsetX,
                     orange::graph::windowEndX);
    double positionY =
        convertPoint(startPoint.y, minY, maxY, orange::graph::windowOffsetY,
                     orange::graph::windowEndY);
    double endPositionX =
        convertPoint(endPoint.x, minX, maxX, orange::graph::windowOffsetX,
                     orange::graph::windowEndX);
    double endPositionY =
        convertPoint(endPoint.y, minY, maxY, orange::graph::windowOffsetY,
                     orange::graph::windowEndY);

    Brain.Screen.drawLine(positionX, positionY, endPositionX, endPositionY);
  }
}

#pragma once

#include <chrono>
#include <iostream>

#define FPS60 (1.0 / 60)

class timer
{
private:
  const double delay;
  double last_render = 0;
  double creationTime;
  //double criticalTime; now its not used
  static double deltaTime;

public:
  void deltaUpdate();
  bool FrameTimeout();
  timer(double dealy);
  timer();
  ~timer();

  static double GetCurrentTime();
  static bool timeout(double source, double delay);
  static double GetDelta();
};

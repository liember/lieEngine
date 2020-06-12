#pragma once
class core
{
private:
  bool isrunning;

  int cnt = 0;
  int w, h;

public:
  void Init();
  void Update();
  bool IsRunning();

  core(/* args */);
  ~core();
};

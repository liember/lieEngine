#include "core.hpp"

using namespace std;

core::core(/* args */) {}

core::~core()
{
}

void core::Init()
{
  isrunning = true;
}

void core::Update()
{
}

bool core::IsRunning()
{
  return isrunning;
}
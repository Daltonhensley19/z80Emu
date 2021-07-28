#include <chrono>
#include <cstddef>
#include <iostream>

class Timer
{
private:
  std::chrono::steady_clock m_stopwatch;
  std::chrono::time_point<std::chrono::steady_clock> m_start_point;
  std::chrono::time_point<std::chrono::steady_clock> m_stop_point;
  

public:
  void start();
  void stop();
  void timer_duration();

};

#include "../../include/timer.h"

void Timer::start()
{
 m_start_point =  m_stopwatch.now();
}

void Timer::stop()
{
 m_stop_point = m_stopwatch.now();
}

void Timer::timer_duration()
{
  auto diff = std::chrono::duration<double>(m_stop_point - m_start_point);

  std::cout << "[DEBUG]: Timer took " << diff.count() << " seconds. \n";
}

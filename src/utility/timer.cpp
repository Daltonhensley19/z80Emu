#include "../../include/timer.h"

// Start elapsed time. Used for benchmarking.
void Timer::start()
{
  m_start_point = m_stopwatch.now();
}

// Stop elapsed time. Used for benchmarking.
void Timer::stop()
{
  m_stop_point = m_stopwatch.now();
}

// Calculates total elapsed time. (total_time = time_end - time_start)
void Timer::timer_duration()
{
  auto diff = std::chrono::duration<double>(m_stop_point - m_start_point);

  std::cout << "[DEBUG]: Timer took " << diff.count() << " seconds. \n";
}

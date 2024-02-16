#pragma once

#include <chrono>

template <typename Units>
class timer {
public:
  void start();
  void stop();
  typename Units::rep count() const; // Units::rep is some numeric type
private:
  std::chrono::steady_clock clock;
  std::chrono::steady_clock::time_point start_time;
  std::chrono::steady_clock::duration elapsed_time;
};

template <typename Units>
void timer<Units>::start()
{
  start_time = clock.now();
}

template <typename Units>
void timer<Units>::stop()
{
  elapsed_time = clock.now() - start_time;
}

template <typename Units>
typename Units::rep timer<Units>::count() const
{
  return std::chrono::duration_cast<Units>(elapsed_time).count();
}

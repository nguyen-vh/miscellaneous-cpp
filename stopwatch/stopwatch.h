// Copyright (c) 2023-present nguyen-vh
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

//----------------------------------------------------------------------------//

#ifndef STOPWATCH_H
#define STOPWATCH_H

//----------------------------------------------------------------------------//
//*                             === INCLUDES ===                             *//
//----------------------------------------------------------------------------//

#include <chrono>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

//----------------------------------------------------------------------------//
//*                         === STOPWATCH MAGIC ===                          *//
//----------------------------------------------------------------------------//

class AutomaticStopwatch {
 public:
  AutomaticStopwatch() { m_start_time = std::chrono::steady_clock::now(); }

  ~AutomaticStopwatch() {
    std::cout << "\n------------------------------\n";
    for (const auto& section : m_section_timings) {
      std::cout << "\033[36m" << "Timed section '" << section.first
                << "': " << "\033[1m";

      if (section.second >= 1000) {
        const long seconds = section.second / 1000;
        const long milliseconds = section.second % 1000;

        std::cout << seconds << "." << (milliseconds < 100 ? "0" : "")
                  << (milliseconds < 10 ? "0" : "") << milliseconds
                  << "\033[0m\033[36m seconds";
      } else {
        std::cout << section.second << "\033[0m\033[36m milliseconds";
      }
      std::cout << "\033[0m\n";
    }

    const auto m_stop_time = std::chrono::steady_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
        m_stop_time - m_start_time);

    long milliseconds = duration.count();
    const long seconds = milliseconds / 1000;
    milliseconds %= 1000;

    std::cout << "\033[32m" << "> " << m_program_name
              << " total time: " << "\033[1m";

    if (seconds >= 1) {
      std::cout << seconds << "." << (milliseconds < 100 ? "0" : "")
                << (milliseconds < 10 ? "0" : "") << milliseconds
                << "\033[0m\033[32m seconds";
    } else {
      std::cout << milliseconds << "\033[0m\033[32m milliseconds";
    }
    std::cout << "\033[0m" << std::endl;
  }

  auto addSectionTiming(const std::string& name, long milliseconds) -> void {
    m_section_timings.emplace_back(name, milliseconds);
  }

 private:
  const std::string m_program_name = "Program";
  std::chrono::steady_clock::time_point m_start_time;
  std::vector<std::pair<std::string, long>> m_section_timings;
};

//----------------------------------------------------------------------------//

static AutomaticStopwatch _global_stopwatch;

//----------------------------------------------------------------------------//
//*                          === TIME SECTIONS ===                           *//
//----------------------------------------------------------------------------//

//? Use START_TIME(NAME) and STOP_TIME(NAME) to measure specific code sections.
//? Needs semicolon at the end.

#define START_TIME(NAME) \
  const auto _start_time_##NAME = std::chrono::steady_clock::now()

//----------------------------------------------------------------------------//

#define STOP_TIME(NAME)                                                 \
  do {                                                                  \
    const auto _stop_time_##NAME = std::chrono::steady_clock::now();    \
    auto duration_##NAME =                                              \
        std::chrono::duration_cast<std::chrono::milliseconds>(          \
            _stop_time_##NAME - _start_time_##NAME);                    \
    _global_stopwatch.addSectionTiming(#NAME, duration_##NAME.count()); \
  } while (0)

#endif

/*

auto main(int argc, char* argv[]) -> int {

START_TIME(algorithm);
testAlgorithm();
STOP_TIME(algorithm);

otherCode();

return 0;
}

*/

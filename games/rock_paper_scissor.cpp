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

//? Program which plays Rock, Paper, Scissors in terminal against itself with
//? named pipes and parallel processing

/*

for LINUX/MAC:

mkfifo in out
g++ -std=c++2b rock_paper_scissor.cpp
./a.out Peter < in > out & ./a.out Vincent > in < out

*/

//----------------------------------------------------------------------------//
//*                             === INCLUDES ===                             *//
//----------------------------------------------------------------------------//

#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>

//----------------------------------------------------------------------------//
//*                       === ROCK, PAPER, SCISSOR ===                       *//
//----------------------------------------------------------------------------//

inline auto delay() -> void {
  std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

auto playRockPaperScissor(const std::string& player_1,
                          const std::string& player_2) {
  if (player_1 == "Rock") {
    if (player_2 == "Scissors") {
      return 1;
    } else {
      return 0;
    }
  }

  if (player_1 == "Paper") {
    if (player_2 == "Rock") {
      return 1;
    } else {
      return 0;
    }
  }

  if (player_1 == "Scissors") {
    if (player_2 == "Paper") {
      return 1;
    } else {
      return 0;
    }
  }

  return 0;
}

auto getResult(const int& team_1, const int& team_2) -> std::string {
  if (team_1 > team_2) {
    return " WON";
  }

  if (team_1 < team_2) {
    return " LOST";
  }

  if (team_1 == team_2) {
    return " TIED";
  }

  return "ERROR";
}

auto main(int argc, char* argv[]) -> int {
  std::string s{argv[1]}, player_1{}, player_2{}, result_1{}, result_2{};
  int score{0}, score2{}, matches{3};

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<> dist(1, 999);

  std::cerr << "\nMatches: " + std::to_string(matches) << std::endl;
  delay();

  for (int i = 1; i < matches + 1; i++) {
    std::cerr << "-----" << std::flush;
    delay();
    int random_number{dist(mt)};
    int capped_random_number{random_number % 3 + 1};

    switch (capped_random_number) {
      case 1:
        player_1 = "Rock";
        break;
      case 2:
        player_1 = "Paper";
        break;
      case 3:
        player_1 = "Scissors";
        break;
    }

    std::cerr << "\n" + std::to_string(i) + ". " + s + ": " + player_1 +
                     " random_number(" + std::to_string(random_number) + ")\n"
              << std::flush;
    std::cout << player_1 << std::endl;
    std::cin >> player_2;

    score += playRockPaperScissor(player_1, player_2);

    if (i == (matches)) {
      std::cout << score << std::endl;
      std::cin >> score2;
      result_1 = getResult(score, score2);
      std::cerr << "-----" << std::flush;
      delay();
      std::cerr << "\n" + s + result_1 + "\n" << std::flush;
      delay();

      if (result_1 == " TIED") {
        int random_number_2 = dist(mt);
        int capped_random_number_2 = random_number_2 % 4 + 1;

        if (capped_random_number_2 == 1) {
          std::cout << "Nope" << std::endl;
          std::cerr << "Nope \n";
        } else {
          std::cout << "Again" << std::endl;
          std::cerr << "Again \n";
        }

        std::cin >> result_2;

        if ((result_2 == "Again") && (!(capped_random_number_2 == 1))) {
          matches += 1;
        }
      }
    }
  }

  std::cerr << "=====" << std::flush;
  delay();
  std::cerr << "\n" + s + " won " + std::to_string(score) + " out of " +
                   std::to_string(matches) + " matches."
            << std::endl;
}

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

#ifndef CURRENCY_CONVERSION_HPP
#define CURRENCY_CONVERSION_HPP

#include <string>
#include <unordered_map>

// Add more by looking for 1000000 (Currency adding) converted to USD
// ex. 1000000 EUR -> 1121675.00 USD

std::unordered_map<std::string, double> currencyER = {
    {"USD", 1000000},  {"EUR", 1121675.00}, {"CNY", 139363.10},
    {"CUP", 41680.94}, {"HKD", 127966.70},  {"INR", 12190.48},
    {"JPY", 7178.80},  {"KRW", 788.30},     {"SEK", 97401.14},
    {"TRY", 37945.34}, {"VND", 42.30}};

inline double conversion(const double& amount, const std::string& currencyIN,
                         const std::string& currencyOUT) {
  return (amount * (currencyER[currencyIN]) / (currencyER[currencyOUT]));
}

#endif
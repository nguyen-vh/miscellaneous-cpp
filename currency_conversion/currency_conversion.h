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

#ifndef CURRENCY_CONVERSION_H
#define CURRENCY_CONVERSION_H

//----------------------------------------------------------------------------//
//*                             === INCLUDES ===                             *//
//----------------------------------------------------------------------------//

#include <string>
#include <unordered_map>

//----------------------------------------------------------------------------//
//*                       === CURRENCY CONVERSION ===                        *//
//----------------------------------------------------------------------------//

// How to add more? Take 1,000,000.00 of the currency you want to add and
// convert it into EUR. The number you get will be the exchange rate you want to
// use.  EX.: 1,000,000.00 USD in EUR equals 864,350.00

// Updated exchange rates on Nov 2025
std::unordered_map<std::string, double> currency_exchange_rate = {
    {"EUR", 1'000'000.00}, {"USD", 864'350.00}, {"CNY", 121'387.50},
    {"CUP", 36'050.37},    {"HKD", 111'074.10}, {"INR", 9'829.37},
    {"JPY", 5'628.32},     {"KRW", 593.69},     {"SEK", 90'747.41},
    {"TRY", 20'485.00},    {"VND", 32.85}};

//----------------------------------------------------------------------------//

inline auto currencyConversion(const double& amount_currency_have,
                               const std::string& name_currency_have,
                               const std::string& name_currency_want)
    -> double {
  return (amount_currency_have * (currency_exchange_rate[name_currency_have]) /
          (currency_exchange_rate[name_currency_want]));
}

#endif
# miscellaneous-cpp
>[!NOTE]
>Cpp files are creations of boredom.


## Header Features
 + dependency-free
 + tiny and compact
 + ready to use

----
## [`Collection of Snippets`](snippets)
   JSON file with C++ snippets for VSCode to speed up repetitive code. WIP


## [`stopwatch.h`](stopwatch)
   By including, the performance speed of the program will be measured and output at the end.
   If wanting to measure specific sections, use '*START_TIME(NAME);*' and '*STOP_TIME(NAME);*', where the '*NAME*' 
   for a section must be the same.


## [`hmac_sha256.h`](hmac_sha256)
   By including, the function '*hmac_sha256(key, message)*' can be used to hash strings.


## [`sha256.h`](sha256)
   By including, the function '*sha256(message)*' can be used to hash strings.


## [`currency_conversion.h`](currency_conversion)
   By including, gives a static currency conversion with the function '*currencyConversion(amount, currency_have, currency_want)*'.
   The function will convert the '*amount*' from '*currency_have*' to '*currency_want*'. The currencies are currently limited to EUR,
   USD, CYN, CUP, HKD, INR, JPY, KRW, SEK, TRY and VND, but can be easily expended and updated.


## [`program_hash.h`](program_hash)
   By including, a simple program-wide hash can be set up for all user-defined #includes. After the first program execution, the output
   hash should be copied at the end and pasted into '*m_program_hash*'. The following code executions perform a code integrity test
   before the main() function is executed and provides the option to terminate the program immediately if the hashes do not match.


----    
>[!TIP]
>For best experience have "Better Comments" (VSCode) Extension by Aaron Bond.

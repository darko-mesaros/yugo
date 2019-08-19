// Doing it CPP style

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

int main() {
  long array[] = {120259084288,63763084476416,140735340871680,70368209387520,140737463181312,109951162773504,76965813942272,10995116277504,1099511627664,824633720816,549755813872,137438953456,21474836472,5368709116,4831838192,66846712,7372784,1056752,8188,16382,8184,3840};
  // Using just sizeof(array) would give us the array size in bytes.
  for (unsigned int a = 0; a < sizeof(array)/sizeof(array[0]); a = a + 1)
  {
    string binary = bitset<48>(array[a]).to_string(); //to binary
    replace ( binary.begin(), binary.end(), '0', ' ');
    replace ( binary.begin(), binary.end(), '1', '#');
  
    // Print out characters one by one
    int k = 0; 
    while ( binary[k] != '\0' )
    {
      cout << binary[k] << flush;
      std::this_thread::sleep_for(std::chrono::milliseconds(20));
      k++;
    };
    cout << endl;
  } 
  return 0;
}

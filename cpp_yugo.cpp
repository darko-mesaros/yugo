// Doing it CPP style

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>
#include <map>
#include <sstream>

using namespace std;

/*
 * Colors:
 * 1 - Blue
 * 2 - White
 * 3 - Red
 */

int main() {
  
  // TODO: MAKE MAPS WORK
  // OR USE ARRAYS
  map<int, string> color_map;
  color_map.insert(make_pair(1,"\033[1;34m"));
  color_map.insert(make_pair(2,"\033[1;37m"));
  color_map.insert(make_pair(3,"\033[1;31m"));
  
// OG array 
// long array[] = {120259084288,63763084476416,140735340871680,70368209387520,140737463181312,109951162773504,76965813942272,10995116277504,1099511627664,824633720816,549755813872,137438953456,21474836472,5368709116,4831838192,66846712,7372784,1056752,8188,16382,8184,3840};
  
  long colorcode[] = {11120259084288,1163763084476416,11140735340871680,1170368209387520,11140737463181312,11109951162773504,1176965813942272,1210995116277504,121099511627664,12824633720816,12549755813872,12137438953456,1221474836472,125368709116,124831838192,1366846712,137372784,131056752,138188,1316382,138184,133840};
  // Using just sizeof(array) would give us the array size in bytes.
  for (unsigned int a = 0; a < sizeof(colorcode)/sizeof(colorcode[0]); a = a + 1)
  {
    /* - get the color info - */
    string code = to_string(colorcode[a]);
    // converts this to int
    int metadata_length(code.at(0) - 48);
    char color = code.at(metadata_length);
    
    string map_code_temp = code.erase(0, metadata_length + 1);
    long map_code = stol ( map_code_temp);

    string binary = bitset<48>(map_code).to_string(); //to binary
    replace ( binary.begin(), binary.end(), '0', ' ');
    replace ( binary.begin(), binary.end(), '1', '#');
  
    // Print out characters one by one
    int k = 0; 
    while ( binary[k] != '\0' )
    {
      
      switch (color) {
        case '1': 
          cout <<"\033[0;34m"<<binary[k]<< flush;
          break;
        case '2': 
          cout <<"\033[0;37m"<<binary[k]<< flush;
          break;
        case '3': 
          cout <<"\033[0;31m"<<binary[k]<< flush;
          break;
        default:
          break;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(20));
      k++;
    };
    cout << endl;
  } 
  return 0;
}

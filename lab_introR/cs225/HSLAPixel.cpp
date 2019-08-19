/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {
  // Default Constructor (no parameters)
  HSLAPixel::HSLAPixel() {
    l = 1.0;
    a = 1.0;
  }

  // Constructor with three parameters
  HSLAPixel::HSLAPixel(double hue, double sat, double lum) {
    h = hue;
    s = sat;
    l = lum;
    a = 1.0;
  }

  // Constructor with four parameters
  HSLAPixel::HSLAPixel(double hue, double sat, double lum, double alpha) {
    h = hue;
    s = sat;
    l = lum;
    a = alpha;
  }
}


///////////////////////////////////////////////////////////////

/*
---------------------------------------------------------------
For any special tips in future labs/MPs,
refer to the bottom of the file

I may sometimes put an astrick in comments after a line of code.
I will put extra notes along with the line number here
for that line of code.
---------------------------------------------------------------
*/

/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {

  class HSLAPixel {
  public:
    //Constructors
    HSLAPixel();  //default - no parameters
    HSLAPixel(double hue, double sat, double lum);  //three parammeters
    HSLAPixel(double hue, double sat, double lum, double alpha);  //four params

    // Parameters (HSLA - hue, saturation, luminance, alpha)
    double h, s, l, a;
  };

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

/**
 * @file lab_intro.cpp
 * Implementations of image manipulation functions.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <math.h> /*1*/

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "lab_intro.h"

using cs225::HSLAPixel;
using cs225::PNG;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * "bla bla bla".....
**/
PNG grayscale(PNG image) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel& pixel = image.getPixel(x, y);
      pixel.s = 0;
    }
  }
  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * "bla bla bla".....
**/
PNG createSpotlight(PNG image, int centerX, int centerY) {
  //Traverses over every pixel of the image
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel& currentPixel = image.getPixel(x, y);

  // Pathagorean Theorem --> find distance z and adjust luminance accordingly
      int x_as_int = (int) x;  /*1*/
      int y_as_int = (int) y;
      double distanceX = (centerX - x_as_int);
      double distanceY = (centerY - y_as_int);
      double x_squared = distanceX * distanceX;
      double y_squared = distanceY * distanceY;
      double z = sqrt(x_squared + y_squared); /*2*/ /*3*/

      if (z > 160) z = 160;   /*4*/

      currentPixel.l *= (1 - (z*.005));  /*5*/

    }
  }
  return image;
}



/**
 * Returns a image transformed to Illini colors.
 *
 * "bla bla bla"......
**/
PNG illinify(PNG image) {
  //Traverses over every pixel of the image
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel& currentPixel = image.getPixel(x, y);

  //check if the pixel's hue(0-360) is closer to orange or blue
      if (currentPixel.h <= 294 && currentPixel.h >= 114) {    /*6*/
        currentPixel.h = 216; //blue
      } else {
        currentPixel.h = 11;  //orange
      }
                              /*7*/
    }
  }
  return image;
}



/**
 * Returns an immge that has been watermarked by another image.
 *
 * "bla bla bla".....
**/
PNG watermark(PNG firstImage, PNG secondImage) {
  //Traverses over every pixel of the image
  for (unsigned x = 0; x < firstImage.width(); x++) {
    for (unsigned y = 0; y < firstImage.height(); y++) {
      HSLAPixel& currentPixel_1 = firstImage.getPixel(x, y);
      HSLAPixel& currentPixel_2 = secondImage.getPixel(x, y); /*8*/

      if (currentPixel_2.l == 1) {    /*9*/
        currentPixel_1.l += .2;         /*10*/
        if (currentPixel_1.l > 1) {
          currentPixel_1.l = 1;
        }
      }

    }
  }
  return firstImage;
}



/* READ THIS BEGINNING CS225 STUDENTS

!!!!!!!!!!!!! -------------------------------------------- !!!!!!!!!!!!!
My notes probably won't be as lengthy in the future, but I wanted to give
as much help now for the very first assignment.

Also, you should know that the cs225 webpage instructions suck!
Especially on how to set up various things during these first two weeks.
They are not done well AT ALL --- so don't be afraid to ask multiple
questions on Piazza. I swear they make it annoying on purpose lol. :P
!!!!!!!!!!!!! -------------------------------------------- !!!!!!!!!!!!!


=============================================================

1 - This is a stupid little thing. Our x and y values are unsigned to
  keep warnings from appearing in the terminal. However we need to
  'type cast' them into integers so we can use them in the rest of our code.
  (get used to using unsigned in your for loops to traverse PNGs,
  otherwise you'll have to get used to seeing your compiler complain a lot)

2 - sqrt() is apart of Math.h which I imported. These lines of code
  follow the Pathagorean Theorem to find the euclidean distance.

3 - Also, in this section, I was messy and made so many variables.
  This is bad practice. You should try to do this in fewer lines!

4 - if we will decrease the luminance by .5% every time, it will take
  160 pixels distance before we keep the lumiance fixed at 20% luminance.
  The line at / *2* / is for all pixels outside of the spotlight (further
  than 160 pixels euclidean distance away from our defined center point)

5 - same explanatation as number 2. This is the actual line of code that
  decreases the luminance and sets a pixel's luminance accordingly based
  on its euclidean distance to our defined center point. 1 is 100% and .005
  is .5%. This should create a 'round' spotlight with a radius of 160 pixels.
  (remember to multiply this luminance value by the currently existing
  luminance value of the pixel!)

6 - It takes a little guess and checking to find this range. Check your
  guesses by taking the difference of a number by each of the hue values
  for blue and orange, 11 and 216. whichever one has the smaller
  difference should be the closest hue value to that number. (YOU DON'T
  ACTUALLY HAVE TO CODE THIS PROCESS -- ONLY FIND THE NUMBERS)

7 - Also, to know you're right, 180 hue values will always be closer to blue
  and the other 180 values will always be closer to orange (Oh ya, I almost
  forgot. The hint about 'hue values being a circle' means that the range
  starts back at 1 after reaches 360 and vice verca)

8 - keep a reference to a pixel for both images; you will need to keep track
  of the current pixel for both images since we will be altering both at the
  same time.

9 - You only need to alter the pixel location that appear on the 2nd image,
  where the luminance is equal to 1 on the 2nd image.
  And remember that you are ONLY increasing the luminance on a image,
  you aren't actually taking the other image's pixel and placing them on the
  other image. (ONLY CHANGE THE LUMINANCE of ONE of the images)

10 - add the .2 before you check, since the luminance can't go over 1. if
  it does go over 1, then just set it equal to max luminance which is 1.


==================================================================

(Ubuntu Terminal Extra Help)
P.S.
When creating a symboloic link (shortcut) in Ubuntu terminal do this
and ignore the awful instructions on the CS225 page:
type "ln -s <path to real file-or-folder> <name of shortcut>" as soon
as you open the terminal. The path should always start exactly as
"/mnt/c....."

*/

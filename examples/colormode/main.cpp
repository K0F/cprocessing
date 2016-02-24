/*
 * main.cpp
 *
 *  Created on: Sep 2, 2011
 *      Author: nilton.gduarte
 */

#include <cprocessing.hpp>

using namespace cprocessing;

int q = 0;

void setup () {
    size (1024,768);
}

void draw() {
    noStroke();
    colorMode(HSB, width);
    for (int i = 0; i < width; i++) {
       for (int j = 0; j < height; j++) {
          stroke(i, (j+q)%width , 100);
          point(i, j);
       }
    }
    q+=10;
}


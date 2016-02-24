#include <cprocessing.hpp>

using namespace cprocessing;


//int frameCount= 0;
int num = 10000;

void setup() {
  size(1024,768);
  rectMode(CENTER);
  colorMode(HSB);
}

void draw() {
  background(0);
  noStroke();
  fill(255,5);
  for(int i = 1 ; i < num;i++)
    rect(width/2+sin(frameCount/(i/100.01+frameCount/10.0))*width/2,height/2+cos(frameCount/(i/110.0))*height/2,100,2);
}



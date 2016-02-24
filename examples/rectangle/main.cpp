#include <cprocessing.hpp>

using namespace cprocessing;

void setup(){
	size(1600,900,"HELLO!");
}

void draw() {

  background(0);
  stroke(255,15);
  for(float i = 0 ; i < width;i+=(sin(10)+1)*2){
    line(i,0,i,height);
  }
}

class Test{
  Test(){

  }

};

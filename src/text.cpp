/*
 * text.cpp
 * Addition by kof 2016
 *
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "cprocessing.hpp"
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace cprocessing;
using namespace std;

namespace cprocessing {

void text(const char *input, int x, int y) {
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, width, 0.0, height);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  // glColor3f(1.0, 1.0, 1.0);
  glRasterPos2i(x, height - y);

  string s = strdup(input); // strdup(input.c_str());
  void *font = GLUT_BITMAP_8_BY_13;
  for (string::iterator i = s.begin(); i != s.end(); ++i) {
    char c = *i;
    glutBitmapCharacter(font, c);
  }

  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
}
};

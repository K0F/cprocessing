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

struct PFont {
  PFont() {}
};

static PFont font;

namespace cprocessing {
void text(string input) {
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, width, 0.0, height);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glColor3f(1.0, 1.0, 1.0);
  glRasterPos2i(10, 10);

  string s = strdup(input.c_str());
  void *font = GLUT_BITMAP_9_BY_15;
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

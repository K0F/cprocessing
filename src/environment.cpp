/*
 * environment.cpp
 *
 *  Created on: Jul 27, 2012
 *      Author: claudio
 *
 *  Cprocessing Environment 
 */

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include "cprocessing.hpp"

namespace cprocessing {
	
	/// Sets the mouse pointer cursor type
	void cursor (CursorType type) {
		switch (type) {
			case ARROW: {
				glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
				break;
			}
			case CROSS:{
				glutSetCursor(GLUT_CURSOR_CROSSHAIR);
				break;
			}
			case HAND: {
				glutSetCursor(GLUT_CURSOR_INFO);
				break;
			}
			case MOVE: {
				glutSetCursor(GLUT_CURSOR_CYCLE);
				break;
			}
			case TEXT: {
				glutSetCursor(GLUT_CURSOR_TEXT);
				break;
			}
			case WAIT: {
				glutSetCursor(GLUT_CURSOR_WAIT);
				break;
			}
		}
	}
	
	/// Sets an invisible mouse cursor
	void noCursor() {
		glutSetCursor(GLUT_CURSOR_NONE);
	}
}

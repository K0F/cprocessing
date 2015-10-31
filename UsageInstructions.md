# Writing a cprocessing application #

In order to work, the application must define a callback function called draw(). By default, draw() is called continuously 60 times per second.
Cprocessing **must** call draw() and call the functions inside draw(), unlike Processing.

Cprocessing works in much the same fashion as Processing. In fact, most functions in cprocessing mimic the equivalent Processing functions to the letter. If you are familiar with Processing and C++, you already know almost everything you need to write cprocessing applications. To cut a long story short, the only thing you need to do is to include the cprocessing environment (library, header and namespace), write the rest of your code using cprocessing functions and data structures.


# Simple usage #

Unlike Processing, cprocessing is not a full fledged IDE but merely a C++ library. Thus, you must use your favorite text editor or C++ IDE to write a regular C++ program which include the cprocessing library. We suggest doing it at the beginning of your application:
```
#include <cprocessing.hpp>  //including cprocessing header
using namespace cprocessing; //setting cprocessing namespace
```
Include and library path must be set to work properly.

After the includes, a setup() with default 100x100 pixel window is defined, on which the application may now draw using cprocessing functions and other C++ commands. For instance:
```
void draw(){
  smooth();
  for(int i=0; i<10; i++){
    line(i*5+5,20,i*5+50,80);
  }
}
```

Compile and run it, the graphics window, will finally be shown and the application will enter the event dispatching loop.

In case you're wondering, here's the complete script and the contents of the drawing:
<table>
<tr>
<td>

<img src='http://pyprocessing.googlecode.com/svn/wiki/UsageInstructions.figs/basicusage.png' />

</td>
<td>
<pre><code>#include &lt;cprocessing.hpp&gt;  //include cprocessing header<br>
<br>
using namespace cprocessing; //using cprocessing namespace<br>
<br>
void draw(){<br>
  smooth();<br>
  for(int i=0; i&lt;10; i++){<br>
    line(i*5+5,20,i*5+50,80);<br>
  }<br>
}<br>
</code></pre>
</td>
</tr>
</table>

# Changing the default window #

As with Processing, the window size may be changed with the size() function. It has two required arguments: the width and height of the desired window in pixels. In cprocessing it must be called inside setup(). Thus,
```
void setup(){
  size(200,200)
}
```

will open a 200x200 pixels window.

Cprocessing will adjust the coordinate system to reflect the changed window dimensions. Thus, if the window is resized so that it is now 250 pixels wide and 150 pixels high, the pixels will be addressed by x in interval [0, 250) and y in interval [0, 150), where pixel (0,0) is the top left corner of the window, i.e., the y axis points down.

Of course, if the window is resized, the original contents drawn so far will be lost, and cprocessing will automatically call the draw() function you defined in your program.

# Animation #


Cprocessing also supports the setup() callback convention, i.e., if you define a function called setup(), it will be called exactly once by.

In the example below, which implements an animation with a ball, setup() is automatically called once to initialize the screen and some drawing modes, whereas draw() is called repeatedly to update the ball position and draw the frame.

```
#include <cprocessing.hpp>
using namespace cprocessing;

int x = 0;
int y = 0;
void setup(){
	size(200,200);
	noStroke();
}
void draw() {
	if (x>200) x = 0;
	if (y>200) y = 0;
        background (200,200,200);
        ellipse(x, y, 55, 55);
	x = x+2;
	y++;
}
```

# Interaction #

An interactive application must process user input such as mouse clicks or keyboard typing. Again, following Processing's practice, the state of input devices is kept in global variables which can either be polled in your draw() function or queried only when their value changes by means of callback functions.

The example program shown below illustrates a simple scribbling application where dragging the mouse paints freehand lines and hitting the 'C' key clears the screen.
<table>
<tr>
<td> <img src='http://pyprocessing.googlecode.com/svn/wiki/UsageInstructions.figs/interactioncallback001.png' />
</td>
<td>
<pre><code>#include &lt;cprocessing.hpp&gt;<br>
<br>
using namespace cprocessing;<br>
void setup(){<br>
	size(200,200);<br>
}<br>
<br>
void draw(){<br>
    // scribble a line with the mouse<br>
    if (mousePressed){<br>
        line (pmouseX, pmouseY, mouseX, mouseY);<br>
    }<br>
    // typing 'C' clears the screen<br>
    if (keyPressed &amp;&amp; (key == 'c' || key == 'C')){<br>
        background(200);<br>
    }<br>
}<br>
</code></pre>
</td>
</tr>
</table>

The same application can be rewritten in a more efficient manner by using callback functions:

```
#include <cprocessing.hpp>

using namespace cprocessing;
void setup(){
	size(200,200);
}

void mouseDragged(){
	line (pmouseX, pmouseY, mouseX, mouseY);
}
void keyPressed()
{
	if (key == 'c' || key == 'C'){
		background(200);
	}
}
void draw(){}
```
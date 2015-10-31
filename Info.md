# Introduction #

This project has been started in order to port the Processing (http://www.processing.org) API to the C++ language. The idea is to enable the writing of graphical applications using Processing's simple commands but levered by C++'s superior performance.

Video demonstrating the performance of cProcessing

<a href='http://www.youtube.com/watch?feature=player_embedded&v=c3XcWDl-SuU' target='_blank'><img src='http://img.youtube.com/vi/c3XcWDl-SuU/0.jpg' width='425' height=344 /></a>

# Details #

At this point, just the basics are ported:

  * Overall event dispatching (mouse, keyboard)
  * 2D drawing primitives
  * 3D drawing primitives

# Porting #
Porting a Processing code to cprocessing:

<table>
<tr>
<td>
<img src='http://www.processing.org/learning/drawing/imgs/1.11.jpg' />
</td>
<td>
<pre><code>//<br>
// Processing <br>
//<br>
size(200,200);<br>
<br>
<br>
<br>
<br>
<br>
rectMode(CENTER);<br>
rect(100,100,20,100);<br>
ellipse(100,70,60,60);<br>
ellipse(81,70,16,32); <br>
ellipse(119,70,16,32); <br>
line(90,150,80,160);<br>
line(110,150,120,160);<br>
</code></pre>
</td>
<td>
<pre><code>// <br>
// cprocessing <br>
//<br>
#include &lt;cprocessing.hpp&gt;<br>
using namespace cprocessing;<br>
<br>
void setup(){<br>
  size(200,200);<br>
}<br>
void draw(){<br>
  rectMode(CENTER);<br>
  rect(100,100,20,100);<br>
  ellipse(100,70,60,60);<br>
  ellipse(81,70,16,32); <br>
  ellipse(119,70,16,32); <br>
  line(90,150,80,160);<br>
  line(110,150,120,160);<br>
}<br>
</code></pre>
</td>
</tr>
</table>

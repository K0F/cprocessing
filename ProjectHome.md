# Objective #
Library which tries to recreate in C++ the intuitive graphics API of the Processing language / IDE.

# Usage #
Usage is very similar to the Processing framework, but you must explicitly import the cprocessing namespace
<table>
<tr>
<td>
<img src='http://www.processing.org/learning/drawing/imgs/1.11.jpg' />
</td>
<td>
<pre><code>//<br>
// Processing <br>
//<br>
void setup() {<br>
    size(200,200);<br>
}<br>
<br>
void draw() {<br>
   rectMode(CENTER);<br>
   rect(100,100,20,100);<br>
   ellipse(100,70,60,60);<br>
   ellipse(81,70,16,32); <br>
   ellipse(119,70,16,32); <br>
   line(90,150,80,160);<br>
   line(110,150,120,160);<br>
}<br>
</code></pre>
</td>
<td>
<pre><code>// <br>
// cprocessing <br>
//<br>
#include &lt;cprocessing.hpp&gt;<br>
using namespace cprocessing;<br>
<br>
void setup(){<br>
  size(200,200);<br>
}<br>
void draw(){<br>
  rectMode(CENTER);<br>
  rect(100,100,20,100);<br>
  ellipse(100,70,60,60);<br>
  ellipse(81,70,16,32); <br>
  ellipse(119,70,16,32); <br>
  line(90,150,80,160);<br>
  line(110,150,120,160);<br>
}<br>
</code></pre>
</td>
</tr>
</table>
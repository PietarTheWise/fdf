<h1 align="center">
  <br>
    Fdf
  <br>
</h1>

<div align="center">
  <img src="screenshots/42_cropped_fdf.gif"></img>
</div>

<h3 align="center">Wireframe graphics rendering with bresenham line drawing algorithm.</h3>

<p align="center">
  <a href="#what-does-it-do">What does it do?</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#disclaimer">Disclaimer</a>
</p>


## What does it do?

* Presents different wireframes as isometric objects.
* You can zoom in and rotate the objects.
* Takes in a file as a parameter on the command line.
* This file determines the size and elevation of the wireframe.
* You can move forward and backwards into the fractal with your <kbd>mouse scroll</kbd>.
* You can rotate the object by holding the <kbd>left mouse button</kbd> and moving the mouse.
* The arrow keys <kbd>up</kbd> and <kbd>down</kbd> increase and decrease the elevation.
* By pressing the key <kbd>p</kbd> you can toggle between different perspectives.


## Supports larger files as well


<img src="screenshots/cropped_fdf.gif"></img>


## How To Use

To clone and run this application, you'll need [Git](https://git-scm.com) and gcc compiler installed on your computer. Also you need miniLibX graphics library which to my knowledge doesn't work on windows. This has been tested only on MacOs and linux. Run the following commands on the command line:

```bash
# Clone this repository
$ git clone https://github.com/PietarTheWise/fdf.git
# Build the program by typing:
$ make
# in command line

#then run:
$ ./fdf maps/42.fdf

# Note: You can run different files, there are plenty of different examples in the /maps folder.
# You can also make your own. Make sure that each row and each column is the same length. For example, take a look at the content of 42.fdf:

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

# Each number defines the elevation of the intersection of lines. 

# Happy wireframing.
```

## DISCLAIMER

<p>
This is a project from the 42 school, which is a school that utilizes peer to peer learning.
We're only given a document that gives us the details of the assignment, therefore each implementation
is unique. Each assignment is tested for crashes and other bugs thoroughly by other peers. Apart from some exceptions, existing
libraries are banned, these projects utilize our self made version of libc called libft.
</p>

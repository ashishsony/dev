This game has been built in OpenGL using the SDL library.

The attached file contains the full source code along with texture and font files used by the code.

Already built 32-bit executable is also included with name "myGame"

The exe would require the libsdl-ttf2.0-dev package to work. this package is easily available on ubuntu OS through Synaptic Package Manager. If SDL is also not present on the machine where you would run this exe,then installing the same package will also install the SDL package along with any other missing packages.
The following command should install all the required dependencies.

sudo apt-get install  libsdl-ttf2.0-dev

the source can be compiled using make once the above libraries are in place.

Note: the following packages need to be installed if not already available

apt-get install libsdl-mixer1.2-dev

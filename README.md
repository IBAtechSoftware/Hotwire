# Hotwire
Cross-platform dlopen implementation for C/C++


## About
Hotwire provides a cross-platform API for loading DLLs, its based on the UNIX ```dlopen()``` API.
This project was mainly built for the fusion engine, but is avalible under the BSD license

## Running examples
The ```Makefile``` provided has a native GNU/Linux build system, along with a build system to cross-compile to windows using MinGW. Testing on windows is done using [wine](https://winehq.org). To build the UNIX example use ```make exampleUnix```, and for windows use ```make exampleWin```. The binarys and the example dlls can be found in the ```bin``` folder.
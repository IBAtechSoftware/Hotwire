exampleUnix: examples/unix/main.c examples/unix/lib.c src/dlopen.c
	## BUILD UNIX EXAMPLES ##

	mkdir -p bin

	gcc examples/unix/main.c src/dlopen.c -o bin/exampleUnix -ldl
	gcc examples/unix/lib.c -shared -o bin/exampleUnixLib.dll

exampleWin: examples/win/main.c examples/win/lib.c src/dlopen.c
	## BUILD WINDOWS EXAMPLES ##

	mkdir -p bin

	x86_64-w64-mingw32-gcc examples/win/main.c src/dlopen.c -o bin/exampleWin
	x86_64-w64-mingw32-gcc examples/win/lib.c -shared -o bin/exampleWinLib.dll

all: exampleUnix exampleWin
g++ -Iinclude -Iinclude/SDL2 -Iinclude/headers -Llib -o Main src/*.cpp -lmingw32 -lSDL2main -lSDL2
pause
: -I includes directories (declared types .h)
: -L library directory
: -o means compile to exe
: Main is name of the exe file
: src/*.cpp are the files we want to compile
: -l links packages (static libraries with implemented objects .dll)

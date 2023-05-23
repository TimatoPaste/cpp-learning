g++ *.cpp -ISDL2/include -LSDL2/lib -Wall -lmingw32 -lSDL2main -lSDL2 -o main
pause
: *.cpp compiles all cpp files
: -I includes headers
: -L gets libraries
: -Wall turns on all warnings for compiler, more info
: -l links packages (mingw32, SDL2main, SDL2)
: -o makes executable
: main is the name
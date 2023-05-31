g++ *.cpp -o main -ISDL2/include -ISDL2_ttf/include -LSDL2/lib -LSDL2_ttf/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
pause

:Most important thing is to place the flags after the source files and the exe name so that the flags work for those files. If the flags are before, they won't work

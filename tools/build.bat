
cd ..\
cl /MD /LD /Fe:mllib.dll^
    mllib.cpp^
rm *.obj
rm *.lib
rm *.exp
cd tools

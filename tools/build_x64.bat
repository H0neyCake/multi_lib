
cd ..\
cl /MD /LD /Fe:mllib_x64.dll^
    mllib.cpp
rm *.obj
rm *.lib
rm *.exp
cd tools

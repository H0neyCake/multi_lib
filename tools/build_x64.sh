
#!/bin/bash

cd ../
g++ -shared \
    -fPIC \
    -o mllib_x64.so \
    mllib.cpp \
    -std=c++11

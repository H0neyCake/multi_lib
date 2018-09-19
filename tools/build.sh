
#!/bin/bash

cd ../
g++ -shared \
    -fPIC \
    -m32 \
    -o mllib.so \
    mllib.cpp\
    -std=c++11

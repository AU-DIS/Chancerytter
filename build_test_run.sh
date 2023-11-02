#!/bin/bash
cmake -S. -Bbuild
if [ $? -eq 0 ]; then 
    echo Cmake complete
else
    echo
    echo Cmake failed
    exit
fi

cmake --build build
if [ $? -eq 0 ]; then 
    echo Build complete
else
    echo
    echo Build failed
    exit
fi


./build/bin/unit_tests
if [ $? -eq 0 ]; then
    ./build/bin/build    
else
    echo
    echo Test failed
fi
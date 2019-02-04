#!/bin/bash
if [ ! -d "build" ] 
then
	mkdir build
fi
rm -r build/*
cmake -Bbuild .
make -j8 -C build/

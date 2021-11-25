#! /bin/bash

g++ -c coffee_maker.cpp
g++ -c main.cpp
g++ -o coffer coffee_maker.o main.o
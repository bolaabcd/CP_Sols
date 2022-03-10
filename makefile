CXX = g++ -I $(dir $(abspath $(lastword $(MAKEFILE_LIST)))) # gets the path to this makefile
CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold

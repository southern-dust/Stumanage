#! /bin/bash

# This file written for make the project -- Student Infomation Management Ststem (SIMS)

# DEBUG USE
#gcc -g Main.c Operation/FileOperation.c Operation/InfoOperation.c Operation/ListOperation.c UIOperation/UIOperation.c -o Stumage

# BUILD
gcc Main.c Operation/FileOperation.c Operation/InfoOperation.c Operation/ListOperation.c UIOperation/UIOperation.c -o Stumage

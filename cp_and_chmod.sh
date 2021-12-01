#!/bin/bash

echo "sending a copy to the following directory"

g++ read_button.cpp GPIO.cpp -o read_button.cgi -l cgicc -pthread

sudo cp read_button.cgi /usr/lib/cgi-bin/

sudo chmod +s /usr/lib/cgi-bin/read_button.cgi

config-pin -a p8.16 in+ 


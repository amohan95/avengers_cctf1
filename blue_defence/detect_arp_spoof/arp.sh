#!/bin/bash

source 'mac.sh'

for i in "${!MAC[@]}"; do
	sudo arp -d "$i" && sudo arp -s "$i" "${MAC[$i]}"
done

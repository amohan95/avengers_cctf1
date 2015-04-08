#!/bin/bash
# Using the associative array from IPs to MACs generated with scan.sh, check
# that each IP has its original MAC.

source 'ping.sh'
source 'mac.sh'

ping_hosts

for i in "${!MAC[@]}"; do
	OLD="${MAC[$i]}"
	ARP_OUT="$(arp -a $i)"
	if [[ "$ARP_OUT" =~ 'no match found' ]]; then
		echo "No entry found for $i; probably this machine: Ping or run from another host"
	else
		NEW="$(cut --delimiter ' ' --fields 4 <<< $ARP_OUT)"
		if [[ "$OLD" != "$NEW" ]]; then
			echo "Current MAC $NEW for $i doesn't match stored MAC $OLD; looks like spoofing"
		fi
	fi
done

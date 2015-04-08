#!/bin/bash
# Function for pinging each host to ensure they show up in arp

declare -A HOSTNAME
HOSTNAME=(['white']='1.1.1.40' ['wcache']='1.1.1.41' ['blue']='1.1.1.50')

ping_hosts() {
	for i in "${HOSTNAME[@]}"; do
			ping -q -c 1 "$i" 2>&1 > /dev/null
			# If ping returned nonzero there's something wrong
			if [[ ! $? ]]; then
				echo "ping failed for host $?"
			fi
	done
}

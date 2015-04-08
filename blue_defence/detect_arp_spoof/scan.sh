#!/bin/bash
# Get the (hopefully) real MAC address for each host

MAC_FILE='mac.sh'

source 'ping.sh'

ping_hosts

declare -A MAC

for i in "${HOSTNAME[@]}"; do
	# Parse MAC from arp output
	MAC["$i"]="$(arp -a "$i" | cut --delimiter ' ' --fields 4)"
done

# Store the array
echo 'declare -A MAC' > "$MAC_FILE"

for i in "${!MAC[@]}"; do
	echo "MAC['$i']='${MAC[$i]}'" >> "$MAC_FILE"
done

# Add this machine's MAC
echo "MAC['1.1.1.51']='$(cat /sys/class/net/eth0/address)'" >> "$MAC_FILE"

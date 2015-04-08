#!/bin/bash
if [[ ! -n $1 || ! -n $2 ]]; then
  echo "Usage is ./blue_monitor.sh <servers_file> <ip_map_file>"
else
  BCACHE_IP=1.1.1.51
  servers_file=$1
  ip_map_file=$2
  counter=0

  while true; do
    sudo ./ip_map_creator.sh "${servers_file}" "${BCACHE_IP}" _b_"${ip_map_file}"
    diff --unchanged-line-format= --old-line-format= --new-line-format='%L' "${ip_map_file}" _b_"${ip_map_file}" > _blue_diffs.txt
    while read line; do
      set -- "${line}"
      servername=$1
      unbound-control flush "${servername}"
      counter=$((counter+1))
      echo "Flushed ${servername}"
      echo "Times Flushed: ${counter}"
      # Write to file
      if [-f "flushLog.txt"]
      then
      	echo "Flushed ${servername}" >  "flushLog.txt"
      fi
    done < _blue_diffs.txt
    rm _b_"${ip_map_file}" _blue_diffs.txt
    sleep 5
  done
fi

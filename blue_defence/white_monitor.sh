#!/bin/bash
if [[ ! -n $1 || ! -n $2 ]]; then
  echo "Usage is ./white_monitor.sh <servers_file> <ip_map_file>"
else
  WCACHE_IP=1.1.1.41
  servers_file=$1
  ip_map_file=$2
  while true; do
    sudo ./ip_map_creator.sh "${servers_file}" "${WCACHE_IP}" _w_"${ip_map_file}"
    diff -w --unchanged-line-format= --old-line-format= --new-line-format='%L' "${ip_map_file}" _w_"${ip_map_file}" > _white_diffs.txt
    while read line; do
      set -- "${line}"
      servername=$1
      ip_addr=$2
      sudo ./wcache_flush.sh "${servername}"
      echo "Flushed ${servername} with ip ${ip_addr} from white cache"
    done < _white_diffs.txt
    rm _w_"${ip_map_file}" _white_diffs.txt
    sleep 5
  done
fi

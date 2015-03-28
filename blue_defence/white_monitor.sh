if [[ ! -n $1 || ! -n $2 ]]; then
  echo "Usage is ./white_monitor.sh <servers_file> <ip_map_file>"
else
  while true; do
    servers_file=$1
    ip_map_file=$2
    ./ip_map_creator.sh "${servers_file}" "${WCACHE_IP}" _"${ip_map_file}"
    diff --unchanged-line-format= --old-line-format= --new-line-format='%L' "${ip_map_file}" _"${ip_map_file}" > _blue_diffs.txt
    while read line; do
      set -- "${line}"
      servername=$1
      ip_addr=$2
      ssh < /dev/null -i /var/keys/wcache.id_rsa ubcontrol@wcache | "${servername}"
      echo "Flushed ${servername} with ip ${ip_addr}"
    done < _blue_diffs.txt
    rm _"${ip_map_file}" _blue_diffs.txt
    sleep 5
  done
fi
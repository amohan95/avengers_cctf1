if [[ ! -n $1 || ! -n $2 || ! -n $3 ]]; then
  echo "Usage is ./ip_map_creator.sh <input_servers_file> <cache_ip> <output_file>"
else 
  servers_file=$1
  cache_ip=$2
  output_file=$3
  if [ -f "${output_file}" ]; then
    $(rm "${output_file}")
  fi
  dig -f "${servers_file}" @"${cache_ip}" +short >> _${output_file}
  paste ${servers_file} _${output_file} > ${output_file}
  rm _${output_file}
  echo "Finished IP Map in ${output_file}"
  exit
fi
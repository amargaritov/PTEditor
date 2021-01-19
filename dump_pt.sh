pid=$1
sudo ./pagedump/pagemap_dump.out $pid | awk -v pid=$pid '{print pid" "$1" "$2 }' | grep -v addr | sudo ./test/get_all.py


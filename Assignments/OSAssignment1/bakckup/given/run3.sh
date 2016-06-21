./start 25
sleep 1
./producer 1 3 & 
./consumer 1 &
./consumer 2 &
./producer 2 6 &
./producer 3 15 &
./consumer 3

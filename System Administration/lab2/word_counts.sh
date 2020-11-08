#START SCRIPT
#rivnakm
#!/bin/bash

i=1
tot=0

while read -r line
do
    count=$( echo $line | wc -w )
    echo "Line $i: $count"
    i=$(( i + 1 ))
    tot=$(( tot + count ))
done

echo "Total: $tot"

#END SCRIPT
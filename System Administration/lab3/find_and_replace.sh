#START SCRIPT
#rivnakm
#!/bin/bash

echo "" > $2
i=0

while read line
do
    new_line=${line/$3/$4}
    echo $new_line
    if [[ i -eq 0 ]]
    then
        echo $new_line > $2
    else
        echo $new_line >> $2
    fi
    i=1
done < $1

#END SCRIPT
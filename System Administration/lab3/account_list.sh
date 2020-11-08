#START SCRIPT
#rivnakm
#!/bin/bash

while read line
do
    if [[ "$(echo $line | cut -f 3 -d ':')" -ge 1000 ]]
    then
        if [[ "$(echo $line | cut -f 3 -d ':')" == "/bin/bash" ]]
        then
            echo "$(echo $line | cut -f 1 -d ':')"
        else
            echo "$(echo $line | cut -f 1 -d ':')*"
        fi
    fi
done < /etc/passwd

#END SCRIPT
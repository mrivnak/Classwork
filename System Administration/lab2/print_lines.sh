#START SCRIPT
#rivnakm
#!/bin/bash

if [[ ! $# -eq 3 ]]
then
    echo "Error: insufficient number of arguments provided (must be 3)"
    exit 1
fi

if [[ ! -f $3 ]]
then
    echo "Error: the file specified ($3) does not exist"
    exit 1
fi

if [[ $1 -gt $2 ]]
then
    echo "Error: the start line must be less than or equal to the end line"
    exit 1
fi

if [[ $2 -gt $(cat $3 | wc -l) ]]
then
    echo "Error: the specified lines must not be beyond the length of the file"
    exit 1
fi

head -n $2 $3 | tail -n $(( $2 - $1 + 1 ))
 
#END SCRIPT
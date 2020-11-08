#START SCRIPT
#rivnakm
#!/bin/bash

read -p "Enter and integer: " int1
read -p "Enter another integer: " int2
read -p "Enter an operation (add, sub, mul, div, exp): " op

case $op in
    add)
        echo "$int1 + $int2 = $(( $int1 + $int2 ))"
    ;;
    sub)
        echo "$int1 - $int2 = $(( $int1 - $int2 ))"
    ;;
    mul)
        echo "$int1 * $int2 = $(( $int1 * $int2 ))"
    ;;
    div)
        echo "$int1 / $int2 = $(( $int1 / $int2 ))"
    ;;
    exp)
        echo "$int1 ^ $int2 = $(( $int1 ** $int2 ))"
    ;;
    *)
        echo "Error: invalid operation"
        exit 1
    ;;
esac

#END SCRIPT
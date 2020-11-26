#START SCRIPT
#rivnakm
#!/bin/bash

if [[ $# -ne 1 ]]
then
    echo "usage: ./bootlog.sh boot|shutdown"
    exit 1
fi

case $1 in
    boot)
        echo "$(date) $HOSTNAME booted!" >> $HOME/lab5/boot.log
        ;;
    shutdown)
        echo "$(date) $HOSTNAME shutdown!" >> $HOME/lab5/boot.log
        ;;
    *)
        echo "usage: ./bootlog.sh boot|shutdown"
        exit 1
        ;;
esac

#END SCRIPT
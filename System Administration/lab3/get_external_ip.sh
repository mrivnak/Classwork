#START SCRIPT
#rivnakm
#!/bin/bash

page=$(wget -qO- http://ipchicken.com)

if [[ $page =~ ([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}) ]]
then
    ip=${BASH_REMATCH[1]}
    echo $ip
else
    echo $page
fi

#END SCRIPT
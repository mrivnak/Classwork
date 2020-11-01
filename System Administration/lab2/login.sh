#START SCRIPT
#rivnakm
#!/bin/bash

FULLNAME="$(grep $USERNAME /etc/passwd | cut -d ":" -f 5)"

echo "Welcome to $HOSTNAME, $FULLNAME"
echo "You are logged in as $USERNAME and your current directory is $PWD"
echo "The time is $(date +%l:%M%P)"
#END SCRIPT
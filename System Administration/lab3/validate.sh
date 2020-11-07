#START SCRIPT
#rivnakm
#!/bin/bash

read -p "First name: " first
if [[ ! $first =~ ^[A-Z][a-zA-Z-]+$ ]]
then
    echo "Error: First name must start with a capital letter and contain only letters and hyphens"
    exit 1
fi

read -p "Last name: " last
if [[ ! $last =~ ^[A-Z][a-zA-Z-]+$ ]]
then
    echo "Error: Last name must start with a capital letter and contain only letters and hyphens"
    exit 1
fi

read -p "Zip code: " zip
if [[ ! $zip =~ ^[0-9]{5}$ ]]
then
    echo "Error: Zip code must be exactly 5 digits"
    exit 1
fi

read -p "Email address: " email
email_reg="^[0-9a-zA-Z\._-]+@[0-9a-zA-Z\._-]+$"
if [[ ! $email =~ $email_reg ]]
then
    echo "Error: Email address must be USER@DOMAIN, where both USER and DOMAIN must be only letters, numbers, dots, underscores, and hyphens!"
    exit 1
fi

echo "Validated!"

#END SCRIPT
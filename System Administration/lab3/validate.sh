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

read -p "Zip code: " zip
if [[ ! $zip =~ ^[0-9]{5}$ ]]
then
    echo "Error: Zip code must be exactly 5 digits"
    exit 1
fi

#END SCRIPT
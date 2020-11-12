#START SCRIPT
#rivnakm
#!/bin/bash

if [[ $# -ne 1 ]]
then
    echo "usage: ./fix_exec.sh filename"
    exit 1
fi

if [[ ! -f $1 ]]
then
    echo "Error: file $1 does not exist or is not a regular file"
    exit 1
fi

perms=$(ls -lah $1 | cut -f 1 -d ' ')
if [[ $perms =~ [rw-]{2}([x-])[rw-]{2}([x-])[rw-]{2}([x-]) ]]
then
    owner_exec=${BASH_REMATCH[1]}
    group_exec=${BASH_REMATCH[2]}
    other_exec=${BASH_REMATCH[3]}
fi

if [[ $(file $1) == *"executable"* ]]
then
    type="executable"
fi

if [[ $type == "executable" ]]
then
    if [[ $owner_exec == "-" ]]
    then
        read -p "should the execute bit for $1 be set for the owner (y/N)? " prompt
        if [[ $prompt == "y" ]]
        then
            chmod u+x $1
        fi
    fi

    if [[ $group_exec == "-" ]]
    then
        read -p "should the execute bit for $1 be set for the group (y/N)? " prompt
        if [[ $prompt == "y" ]]
        then
            chmod g+x $1
        fi
    fi

    if [[ $other_exec == "-" ]]
    then
        read -p "should the execute bit for $1 be set for others (y/N)? " prompt
        if [[ $prompt == "y" ]]
        then
            chmod o+x $1
        fi
    fi
else
    if [[ $owner_exec == "x" ]]
    then
        chmod u-x $1
        echo "removing owner execute bit from $1"
    fi

    if [[ $group_exec == "x" ]]
    then
        chmod g-x $1
        echo "removing group execute bit from $1"
    fi

    if [[ $other_exec == "x" ]]
    then
        chmod o-x $1
        echo "removing others execute bit from $1"
    fi
fi

#END SCRIPT
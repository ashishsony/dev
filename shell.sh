#!/bin/bash
X=3
Y=4
empty_string=""
if [ $X -lt $Y ]  # is $X less than $Y ? 
then
    echo "\$X=${X}, which is smaller than \$Y=${Y}"
fi

if [ -n "$empty_string" ]; then
    echo "empty string is non_empty"
fi

if [ -e "${HOME}/.fvwmrc" ]; then                       # test to see if ~/.fvwmrc exists
    echo "you have a .fvwmrc file"
    if [ -L "${HOME}/.fvwmrc" ]; then           # is it a symlink ?  
        echo "it's a symbolic link"
    elif [ -f "${HOME}/.fvwmrc" ]; then         # is it a regular file ?
        echo "its a regular file"
    fi
else
    echo "you have no .fvwmrc file"
fi

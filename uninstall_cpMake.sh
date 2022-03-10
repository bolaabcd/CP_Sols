#!/bin/sh

if rm ~/.local/bin/cpMake 2> /dev/null
    then echo 'Successfully uninstalled cpMake.'
else
    echo 'Error: cpMake not installed.'
fi

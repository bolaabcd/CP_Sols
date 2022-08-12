#!/bin/sh

if rm ~/.local/bin/cpMake 2> /dev/null
    then echo 'Successfully uninstalled cpMake.'
else
    echo 'Error: could not uninstall cpMake (maybe it is already installed).'
fi

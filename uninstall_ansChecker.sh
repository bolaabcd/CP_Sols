#!/bin/sh

if rm ~/.local/bin/ansChecker 2> /dev/null
    then echo 'Successfully uninstalled ansChecker.'
else
    echo 'Error: could not uninstall ansChecker (maybe it is already installed).'
fi

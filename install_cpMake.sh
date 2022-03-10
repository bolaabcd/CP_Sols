#!/bin/sh

if test ! -f  "$(pwd)/makefile"
    then echo "Error: $(pwd)/makefile does not exist."
elif test -f ~/.local/bin/cpMake
    then echo "Error: cpMake already installed."
else
    echo '#!/bin/sh
    if test -z $1 || test ! -f "$1.cpp"
        then echo '"'The first parameter should be the file to compile, without .cpp.'"'
    else
        clear
        make -f '"$(pwd)/makefile"' $1
        ./$1 <&0 >&1
    fi' > ~/.local/bin/cpMake

    chmod +x ~/.local/bin/cpMake
    
    echo "Sucessfully installed cpMake using the following makefile: $(pwd)/makefile"
    echo "It may be necessary to close and re-open the terminal to complete installation."
fi

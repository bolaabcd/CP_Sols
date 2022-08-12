#!/bin/sh

if test ! -f  "$(pwd)/makefile"
    then echo "Error: $(pwd)/makefile does not exist."
elif test -f ~/.local/bin/ansChecker
    then echo "Error: cpMake already installed."
else
    echo '#!/bin/sh

ls in*.txt | grep -o "[0-9]*" | while read l; do maratonaMaker $1 < in$l.txt | tail -n+2 > out$l.txt; done

# Compare if are equal: 
ls out*.txt | grep -o "[0-9]*" | while read l; do cmp ans$l.txt out$l.txt; done' > ~/.local/bin/ansChecker

    chmod +x ~/.local/bin/ansChecker
    
    echo "Sucessfully installed cpMake using the following makefile: $(pwd)/makefile"
    echo "It may be necessary to close and re-open the terminal to complete installation."
fi

#!/bin/sh

ls in*.txt | grep -o "[0-9]*" | while read l; do maratonaMaker $1 < in$l.txt | tail -n+2 > out$l.txt; done

# Compare if are equal: 
ls out*.txt | grep -o "[0-9]*" | while read l; do cmp ans$l.txt out$l.txt; done


make ${1} ${2} gen || exit 1
for ((i = 1; ; i++)) do
	./gen $i > in
	./${1} < in > out
	./${2} < in > out2
	if (! cmp -s out out2) then
		echo "--> entrada:"
		cat in
		echo "--> saida1:"
		cat out
		echo "--> saida2:"
		cat out2
		break;
	fi
	echo $i
done

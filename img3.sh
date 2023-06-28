sed 's/ //g' $1 > out.txt
touch dump
xxd -p -r out.txt > dump

for:
	gcc -o forloop forloop.c

while:
	gcc -o whileloop whileloop.c

for.txt: for
	./forloop > for.txt

while.txt: while
	./whileloop > while.txt

test: for.txt while.txt
	diff for.txt while.txt > diff.txt
	[ -s diff.txt ] && false || true

fizzbuzz:
	gcc -o fizzbuzz fizzbuzz.c

fizzbuzz.txt: fizzbuzz
	./fizzbuzz > fizzbuzz.txt

test: fizzbuzz.txt
	diff fizzbuzz.txt fuzzbuzz_expected.txt > diff.txt
	[ -s diff.txt ] && false || true

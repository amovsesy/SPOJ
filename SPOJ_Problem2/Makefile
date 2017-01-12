build:
	gcc -g -o prime.exe -Wall -pedantic prime.c

clean:
	del prime.exe
	del input

run: build
	echo 3 > input
	echo 1 10 >> input
	echo 3 5 >> input
	echo 999900000 1000000000 >> input
	.\prime.exe < input

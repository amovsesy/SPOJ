build:
	gcc -g -Wall -pedantic -o output.exe output.c

clean:
	del output.exe
	del input

run: build
	echo 1 > input
	echo 2 >> input
	echo 88 >> input
	echo 42 >> input
	echo 99 >> input
	.\output.exe < 	input

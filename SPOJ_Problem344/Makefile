build:
	gcc -g -Wall -pedantic -o poker.exe poker.c

clean:
	del poker.exe
	del input

run: build
	echo 10 > input
	echo AH KH QH TH JH >> input
	echo KH 5S 3C 5C 7D >> input
	echo QH QD 2S QC 2C >> input
	echo QH QD 6S QC 2C >> input
	echo QH 2D 6S QC 2C >> input
	echo QD TD 6D JD 2D >> input
	echo QH QD 6S QC QS >> input
	echo JC TC 9C 8C 7C >> input
	echo AH 2D 3S 4C 5C >> input
	echo QH AD TS 3C 2C >> input
	.\poker.exe < 	input

run1: build
	echo 1 > input
	echo AH KH QH TH JH >> input
	.\poker.exe < 	input

run2: build
	echo 2 > input
	echo QH KH AH TH JH >> input
	echo 8H 7H 9H JH TH >> input
	.\poker.exe < 	input

all:
	gcc -Wall -Wextra -Wpedantic -Werror main.c -o main

clean:
	rm -rf *.o main

tests:
	echo "Building graph..."
	make && echo "\nDone" || echo "\nFail"
	echo "\nStarting tests"
	echo "\nExec test 1\nChecking with reference"
	./main test1.txt && echo "\nSuccess!" || echo "\nError"
	echo "\nExec test 2\nChecking with reference"
	./main test2.txt && echo "\nSuccess!" || echo "\nError"
	echo "\nExec test 3\nChecking with reference"
	./main test3.txt && echo "\nSuccess!" || echo "\nError"
	echo "\nExec test 4\nChecking with reference"
	./main test4.txt && echo "\nSuccess!" || echo "\nError"
	make clean

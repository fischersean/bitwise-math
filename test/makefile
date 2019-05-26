all: test_suite.o

test_suite.o: # TestMath.c ../src/lrgmath.c ../unity/src/unity.c
	gcc -o test_suite.o TestMath.c ../src/lrgmath.c ../unity/src/unity.c

clean:
	rm test_suite.o

run:
	./test_suite.o
CLEANUP = rm -f

PASSED = `grep -s PASS build/results/TestMath.txt`
FAIL = `grep -s FAIL build/results/TestMath.txt`
IGNORE = `grep -s IGNORE build/results/TestMath.txt`


TestMath.txt: TestMath.o
	$ touch build/results/TestMath.txt
	$ ./build/objs/TestMath.o > build/results/TestMath.txt

TestMath.o: # TestMath.c ../src/lrgmath.c ../unity/src/unity.c
	gcc -o build/objs/TestMath.o test/TestMath.c src/lrgmath.c unity/src/unity.c

clean:
	#$(CLEANUP) $(PATHO)*.o
	$(CLEANUP) build/objs/*.o
	$(CLEANUP) build/results/*.txt

test: build/results/
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"
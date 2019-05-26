MKDIR = mkdir -p
CLEANUP = rm -f
GCFLAGS = -std=c11

.PHONY: clean
.PHONY: test

PASSED = `grep -s PASS build/results/TestMath.txt`
FAIL = `grep -s FAIL build/results/TestMath.txt`
IGNORE = `grep -s IGNORE build/results/TestMath.txt`

PATHB = build/
PATHD = build/depends/
PATHO = build/objs/
PATHR = build/results/

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR)

build/results/TestMath.txt: build/objs/TestMath.o
	$ touch build/results/TestMath.txt
	$ ./build/objs/TestMath.o
	$ ./build/objs/TestMath.o > build/results/TestMath.txt

build/objs/TestMath.o: # TestMath.c ../src/lrgmath.c ../unity/src/unity.c
	gcc -o build/objs/TestMath.o test/TestMath.c src/lrgmath.c unity/src/unity.c $(GCFLAGS)

clean:
	# $(CLEANUP) $(PATHO)*.o
	$(CLEANUP) build/objs/*.o
	$(CLEANUP) build/results/*.txt

test: $(BUILD_PATHS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"



$(shell $(MKDIR) $(PATHB))

$(shell $(MKDIR) $(PATHD))

$(shell $(MKDIR) $(PATHO))

$(shell $(MKDIR) $(PATHR))
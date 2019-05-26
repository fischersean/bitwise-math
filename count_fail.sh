#!/bin/sh
N_FAILED=`grep -s FAIL build/results/TestMath.txt | wc -l`

if (("$N_FAILED" > 0)); then
    exit 1
fi

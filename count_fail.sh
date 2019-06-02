#!/bin/sh
N_FAILED=`grep -s FAIL build/results/TestMath.txt | wc -l`

if (("$N_FAILED" > 0)); then
    echo "failed"
    exit 1
else
    echo "pass"
    exit 0
fi

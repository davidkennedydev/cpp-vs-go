#!/bin/bash ./benchmark.sh

measuring "threads" 
for (( i = 1; i < 1000; i+=100 )); do
  measure "./threads.o $i" $i 
done


# prime-bench
Simple C program that calculates all prime numbers up to an upper bound.
Use it to measure integer calculation speeds on your CPU or play around. Only loads a single core.


## Building
You can build with:
```bash
make
# If you don't have gcc:
make clang
```
Or, if you don't have Make:
```bash
gcc benchmark.c -o benchmark
# If you don't have gcc:
clang benchmark.c -o benchmark
```

## Changing the upper bound
Edit the `benchmark.c` file at line 4:
```c
#define UPPER_LIMIT 100000
```
Replace `100000` with your upper limit of choice.
Because the program uses an int as counter the max upper limit is 2^31 - 1 (~2.1 billion).
Finally, rebuild.

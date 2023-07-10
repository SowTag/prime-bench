gcc:
	gcc benchmark.c -o benchmark
	@echo "Done! (gcc)"
clang:
	clang benchmark.c -o benchmark
	@echo "Done! (clang)"

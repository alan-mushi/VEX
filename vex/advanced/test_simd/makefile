VEX_DIR ?= ~/vex-3.43

all: test_simd

test_simd: test_simd.c
	$(VEX_DIR)/bin/cc -ms -mas_g -O0 -H0 -o $@ $< -lvexsimd

clean:
	rm -f test_simd *.log* *.out *.s *.cs.c


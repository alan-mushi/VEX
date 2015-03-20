VEX_DIR ?= ~/vex-3.43
LIB_DIR = $(VEX_DIR)/lib
INC_DIR = $(VEX_DIR)/include

all: libvexsimd.so

libvexsimd.so: vex_simd.c vex_simd.h
	gcc -m32 -fPIC -shared -Wl,-soname,$@ -o $@ $<

.PHONY: install clean
install:
	cp libvexsimd.so $(LIB_DIR)
	cp vex_simd.h $(INC_DIR)
clean:
	rm -f libvexsimd.so


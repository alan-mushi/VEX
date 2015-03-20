VEX_DIR ?= /opt/vex-3.43
MM_FILE ?= ./vex_MachineModel.mm
CACHE_CFG ?= ./vex_cache.cfg
CFLAGS = -ms -mas_g -mas_t

all: help
 
test: test.c
	$(VEX_DIR)/bin/cc $(CFLAGS) -fmm=$(MM_FILE) -o $@ $< 


.PHONY: set_cache_cfg clean help

set_cache_cfg:
	export VEXCFG=$(CACHE_CFG)

clean:
	rm -f test *.cs.c *.s *.out *.log.*

help:
	@echo "Usage: make cmd... [variable=value]..."
	@echo "'cmd' can be:"
	@echo "   -test            Compile using VEX compiler"
	@echo "        -use variable 'VEX_DIR' to specify vex directory"
	@echo "        -use variable 'MM_FILE' to specify vex Machine Model"
	@echo "        -use variable 'CFLAGS' to specify compiling options"
	@echo "   -set_cache_cfg   Set the cache simulator to use configurations from file '$(CACHE_CFG)'"
	@echo "        -use variable 'CAHCE_CFG' to specify the path of configuration file"
	@echo "   -clean           Remove all generated files"
	@echo "   -help            Display this help message"

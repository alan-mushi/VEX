VEX_DIR ?= /opt/vex-3.43
#MM_FILE ?= ./vex_MachineModel.mm
MM_FILE ?= ./risc.mm
#VEXCFG ?= ./vex_cache.cfg
CFLAGS = -I../include/ -ms -mas_g -mas_t -O2
#-fmmdump
#-prefetch
SRC=../src/
all: help  
# $(SRC)/pgm.c $(SRC)/edge_detect.c$(SRC)/alloc.c

fused: clean edge_detect 
	export VEXCFG=$(CACHE_CFG)
	./edge_detect ../data/satellite.pgm ./deriche-satellite.pgm fixed_fast
	\mv ta.log.000 tp_ase.log.fused
	grep "Total Cycles" tp_ase.log.fused

slow: clean edge_detect
	export VEXCFG=$(CACHE_CFG)
	./edge_detect ../data/satellite.pgm ./deriche-satellite.pgm fixed_slow
	\mv ta.log.000 tp_ase.log.slow
	grep "Total Cycles" tp_ase.log.slow

array: clean edge_detect
	export VEXCFG=$(CACHE_CFG)
	./edge_detect ../data/satellite.pgm ./deriche-satellite.pgm fixed_array
	\mv ta.log.000 tp_ase.log.array
	grep "Total Cycles" tp_ase.log.array

float: clean edge_detect 
	export VEXCFG=$(CACHE_CFG)
	./edge_detect ../data/satellite.pgm ./deriche-satellite.pgm float_slow
	\mv ta.log.000 tp_ase.log.float
	grep "Total Cycles" tp_ase.log.float

edge_detect:  $(SRC)/pgm.c $(SRC)/alloc.c $(SRC)/edge_detect.c $(SRC)/deriche.c   $(MM_FILE)
	$(VEX_DIR)/bin/cc $(CFLAGS) -fmm=$(MM_FILE) -DVEX -o $@ $(SRC)/pgm.c $(SRC)/alloc.c $(SRC)/edge_detect.c $(SRC)/deriche.c 

report:
	$(VEX_DIR)/bin/runreport tp_ase.log.* > report.html

.PHONY: set_cache_cfg clean help

set_cache_cfg:
	export VEXCFG=$(CACHE_CFG)

clean:
	rm -f edge_detect *.out *.o ta.log.* *.pgm *.cs.c *.s

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

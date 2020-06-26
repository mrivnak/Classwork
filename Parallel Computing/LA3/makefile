red:=$(shell tput setaf 1)
yellow:=$(shell tput setaf 3)
reset:=$(shell tput sgr0)

ifeq ($(TAU_MAKEFILE),)
$(info $(yellow)Warning: TAU_MAKEFILE not set, using mpicc$(reset))
CC=mpicc
else
CC=tau_cc.sh
endif
all: 
	$(CC) -o LA3 LA3.c

clean:
	/bin/rm -rf LA3 LA3.o LA3_Primes.o*

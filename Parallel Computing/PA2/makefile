FCC = mpicc
LDC = mpicc
LD_FLAGS = -fopenmp
FLAGS = -fopenmp
PROG = PA2.cx
RM= /bin/rm

OBJS=PA2.o

#all rule
all: $(PROG)

$(PROG): $(OBJS)
	$(LDC) $(LD_FLAGS) $(OBJS) -o $(PROG)

%.o: %.c
	$(FCC) $(FLAGS) -c $*.c

#clean rule
clean:
	$(RM) -rf *.o $(PROG) COMP3450_PA2*


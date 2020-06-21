FCC = mpicc
LDC = mpicc
LD_FLAGS = -fopenmp
FLAGS = -fopenmp
PROG = mvp-student.cx
RM= /bin/rm

OBJS=mvp-student.o

#all rule
all: $(PROG)

$(PROG): $(OBJS)
	$(LDC) $(LD_FLAGS) $(OBJS) -o $(PROG)

%.o: %.c
	$(FCC) $(FLAGS) -c $*.c

#clean rule
clean:
	$(RM) -rf *.o $(PROG) COMP3450_LA2*


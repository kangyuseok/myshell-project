CC = gcc
Target = myshell
OBJS = builtin_command.o eval.o myshell.o parseline.o readline.o pipe_action.o
all: $(Target)

$(Target): $(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c -o $@ $<


clean:
	rm -f $(OBJS) $(Target)


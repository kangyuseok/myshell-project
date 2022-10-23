void eval(char *cmdline);
int builtin_command(char **argv);
char** parseline(char *buf);
char *readline();
int pipe_count;
int pipe_position;
void pipe_action(char ** pipe_split1, char ** pipe_split2);
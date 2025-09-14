#ifndef CMD_LN_ARGS_H
#define CMD_LN_ARGS_H

char *FILE_NAME = (char *)"onegin_ptr_sorted.txt";
char **PTR_FILE_NM = &FILE_NAME;

void whete_put_sorted_onegin(int argc, char **argv, char **ptrfile_to_put_results);

#endif // CMD_LN_ARGS_H
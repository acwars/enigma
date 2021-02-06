#ifndef ENIGMA_MESSAGES_H
#define ENIGMA_MESSAGES_H

#include "types.h"
#include "subscribe.h"

void handle_message(char *msg, int msg_len, FILE *rsp);
void process_message(char **args, int num, FILE *rsp);
void cmd_node(char **args, int num, FILE *rsp);
void cmd_desktop(char **args, int num, FILE *rsp);
void cmd_monitor(char **args, int num, FILE *rsp);
void cmd_query(char **args, int num, FILE *rsp);
void cmd_rule(char **args, int num, FILE *rsp);
void cmd_wm(char **args, int num, FILE *rsp);
void cmd_subscribe(char **args, int num, FILE *rsp);
void cmd_quit(char **args, int num, FILE *rsp);
void cmd_config(char **args, int num, FILE *rsp);
void set_setting(coordinates_t loc, char *name, char *value, FILE *rsp);
void get_setting(coordinates_t loc, char *name, FILE* rsp);
void handle_failure(int code, char *src, char *val, FILE *rsp);
void fail(FILE *rsp, char *fmt, ...);

#endif

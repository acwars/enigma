#ifndef ENIGMA_RESTORE_H
#define ENIGMA_RESTORE_H

#include "jsmn.h"

bool restore_state(const char *file_path);
monitor_t *restore_monitor(jsmntok_t **t, char *json);
desktop_t *restore_desktop(jsmntok_t **t, char *json);
node_t *restore_node(jsmntok_t **t, char *json);
presel_t *restore_presel(jsmntok_t **t, char *json);
client_t *restore_client(jsmntok_t **t, char *json);
void restore_rectangle(xcb_rectangle_t *r, jsmntok_t **t, char *json);
void restore_constraints(constraints_t *c, jsmntok_t **t, char *json);
void restore_padding(padding_t *p, jsmntok_t **t, char *json);
void restore_history(jsmntok_t **t, char *json);
void restore_subscribers(jsmntok_t **t, char *json);
void restore_subscriber(subscriber_list_t *s, jsmntok_t **t, char *json);
void restore_coordinates(coordinates_t *loc, jsmntok_t **t, char *json);
void restore_stack(jsmntok_t **t, char *json);
bool keyeq(char *s, jsmntok_t *key, char *json);

#endif

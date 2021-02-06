#ifndef ENIGMA_HISTORY_H
#define ENIGMA_HISTORY_H

#include "types.h"

history_t *make_history(monitor_t *m, desktop_t *d, node_t *n);
void history_add(monitor_t *m, desktop_t *d, node_t *n, bool focused);
void history_insert_after(history_t *a, history_t *b);
void history_insert_before(history_t *a, history_t *b);
void history_remove(desktop_t *d, node_t *n, bool deep);
void empty_history(void);
node_t *history_last_node(desktop_t *d, node_t *n);
desktop_t *history_last_desktop(monitor_t *m, desktop_t *d);
monitor_t *history_last_monitor(monitor_t *m);
bool history_find_newest_node(coordinates_t *ref, coordinates_t *dst, node_select_t *sel);
bool history_find_node(history_dir_t hdi, coordinates_t *ref, coordinates_t *dst, node_select_t *sel);
bool history_find_newest_desktop(coordinates_t *ref, coordinates_t *dst, desktop_select_t *sel);
bool history_find_desktop(history_dir_t hdi, coordinates_t *ref, coordinates_t *dst, desktop_select_t *sel);
bool history_find_newest_monitor(coordinates_t *ref, coordinates_t *dst, monitor_select_t *sel);
bool history_find_monitor(history_dir_t hdi, coordinates_t *ref, coordinates_t *dst, monitor_select_t *sel);
uint32_t history_rank(node_t *n);

#endif

#ifndef ENIGMA_RULE_H
#define ENIGMA_RULE_H

#define MATCH_ANY  "*"
#define CSQ_BLK    " =,\n"

rule_t *make_rule(void);
void add_rule(rule_t *r);
void remove_rule(rule_t *r);
void remove_rule_by_cause(char *cause);
bool remove_rule_by_index(int idx);
rule_consequence_t *make_rule_consequence(void);
pending_rule_t *make_pending_rule(int fd, xcb_window_t win, rule_consequence_t *csq);
void add_pending_rule(pending_rule_t *pr);
void remove_pending_rule(pending_rule_t *pr);
void postpone_event(pending_rule_t *pr, xcb_generic_event_t *evt);
event_queue_t *make_event_queue(xcb_generic_event_t *evt);
void _apply_window_type(xcb_window_t win, rule_consequence_t *csq);
void _apply_window_state(xcb_window_t win, rule_consequence_t *csq);
void _apply_transient(xcb_window_t win, rule_consequence_t *csq);
void _apply_hints(xcb_window_t win, rule_consequence_t *csq);
void _apply_class(xcb_window_t win, rule_consequence_t *csq);
void _apply_name(xcb_window_t win, rule_consequence_t *csq);
void parse_keys_values(char *buf, rule_consequence_t *csq);
void apply_rules(xcb_window_t win, rule_consequence_t *csq);
bool schedule_rules(xcb_window_t win, rule_consequence_t *csq);
void parse_rule_consequence(int fd, rule_consequence_t *csq);
void parse_key_value(char *key, char *value, rule_consequence_t *csq);
void list_rules(FILE *rsp);

#endif

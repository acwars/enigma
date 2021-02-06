#ifndef ENIGMA_STACK_H
#define ENIGMA_STACK_H

stacking_list_t *make_stack(node_t *n);
void stack_insert_after(stacking_list_t *a, node_t *n);
void stack_insert_before(stacking_list_t *a, node_t *n);
void remove_stack(stacking_list_t *s);
void remove_stack_node(node_t *n);
int stack_level(client_t *c);
int stack_cmp(client_t *c1, client_t *c2);
stacking_list_t *limit_above(node_t *n);
stacking_list_t *limit_below(node_t *n);
void stack(desktop_t *d, node_t *n, bool focused);
void restack_presel_feedbacks(desktop_t *d);
void restack_presel_feedbacks_in(node_t *r, node_t *n);

#endif

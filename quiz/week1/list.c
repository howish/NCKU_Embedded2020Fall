#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>

// Problem description:
typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node); //AA1
    new_node->value = new_value;
    new_node->next = NULL;

    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node; //AA2
}

node_t *find_entry(node_t *head, int value)
{
    node_t *current = head;
    for (; current && current->value != value; current = current->next)
        /* interate */;
    return current;
}

void remove_entry(node_t **head, node_t *entry)
{
    node_t **indirect = head;

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}

node_t *swap_pair(node_t *head)
{
    for (node_t **node = &head; *node && (*node)->next;
        node = &(*node)->next->next //BB1
        ) {
        node_t *tmp = *node;
        *node = (*node)->next; //BB2
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
    return head;
}

void new_swap_pair(node_t **head)
{
    for (; *head && (*head)->next;
        head = &(*head)->next->next
        ) {
        node_t *tmp = *head;
        *head = (*head)->next;

        tmp->next = (*head)->next;
        (*head)->next = tmp;
    }
}

node_t *reverse(node_t *head)
{
    node_t *cursor = NULL;
    while (head) {
        node_t *next = head->next;
        head->next = cursor, cursor = head; // CCC
        head = next;
    }
    return cursor;
}

void new_reverse(node_t **head)
{
    node_t *cursor = NULL;
    while (*head) {
        node_t *next = (*head)->next;
        (*head)->next = cursor, cursor = (*head);
        *head = next;
    }
    *head = cursor;
}

void rev_recursive(node_t *cursor, node_t **head)
{
    if (!*head) {
        *head = cursor;    
        return;
    }
    node_t *next = (*head)->next;
    (*head)->next = cursor, cursor = (*head);
    *head = next;
    rev_recursive(cursor, head);
}
void rec_reverse(node_t **head)
{
    rev_recursive(NULL, head);
}

void fisher_yates_shuffle(node_t **head)
{
    // Compute length
    int num = 0;
    for (node_t *itr = *head; itr; num++, itr=itr->next)
        /*iterate*/;

    srand(time(NULL));

    node_t *oldhead = *head;
    for (; num; num--) {
        // Pick the sampled node
        node_t **picker = &oldhead;
        for (int pos = rand() % num; pos; pos--)
            picker = &(*picker)->next;

        // Append picked node to result node
        *head = *picker;
        head = &(*head)->next;

        // Remove picked node from old list
        *picker = (*picker)->next;
    }
}


void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    node_t *head = NULL;

    print_list(head);

    add_entry(&head, 72);
    add_entry(&head, 101);
    add_entry(&head, 108);
    add_entry(&head, 109);
    add_entry(&head, 110);
    add_entry(&head, 111);
    add_entry(&head, 112);
    add_entry(&head, 113);
    add_entry(&head, 114);
    add_entry(&head, 115);

    print_list(head);

    node_t *entry = find_entry(head, 101);
    remove_entry(&head, entry);

    entry = find_entry(head, 111);
    remove_entry(&head, entry);

    print_list(head);

    /* swap pair.
     * See https://leetcode.com/problems/swap-nodes-in-pairs/
     */
    head = swap_pair(head);
    print_list(head);

    new_swap_pair(&head);
    print_list(head);

    head = reverse(head);
    print_list(head);

    new_reverse(&head);
    print_list(head);

    rec_reverse(&head);
    print_list(head);

    fisher_yates_shuffle(&head);
    print_list(head);

    return 0;
}

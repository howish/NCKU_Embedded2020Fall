#include "list.h"
#include <stddef.h>

list *sort(list *start) {
    if (!start || !start->next)
        return start;
    list *left = start;
    list *right = left->next;
    //LL0;

    left = sort(left);
    right = sort(right);

    for (list *merge = NULL; left || right; ) {
        if (!right || (left && left->data < right->data)) {
            if (!merge) {
                //LL1;
                
            } else {
                //LL2;
                merge = merge->next;
            }
            //LL3;
        } else {
            if (!merge) {
                //LL4;
            } else {
                //LL5;
                merge = merge->next;
            }
            //LL6;
        }
    }
    return start;
}

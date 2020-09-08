#ifndef D3801F9A_62DF_4E46_9BBA_48299FD521CB
#define D3801F9A_62DF_4E46_9BBA_48299FD521CB

typedef struct __list {
    int data;
    struct __list *next;
} list;

list *sort(list *start);

#endif /* D3801F9A_62DF_4E46_9BBA_48299FD521CB */

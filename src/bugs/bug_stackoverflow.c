#include <stdio.h>

typedef struct elem {
    struct elem *next;
} Elem;

int functional_list_length(Elem *h) {
    if (h == NULL)
	return 0;

    return 1 + functional_list_length(h->next);
}

int main() {
    // circular list
    Elem a;
    Elem b = { &a };
    a = (Elem){& b};
    Elem *head = &a;

    printf("list length: %d", functional_list_length(head));
    return 0;
}

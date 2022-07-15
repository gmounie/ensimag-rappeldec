#include <stdio.h>

typedef struct elem {
    struct elem *next;
} Elem;

// Python programmers, with shallow understanding of Python heap
// management, produce this kind of code in C.
// GGC warns you ! Clangd detects that too in your IDE !
// Read the warnings !
Elem *new_Elem() {
    Elem a = { .next= NULL }; // BUG: Elem *a = malloc(sizeof(Elem)); 
    return &a; // BUG: return a;
}

int list_length(Elem *h) {
    int l=0;
    while(h != NULL) {
	h = h->next;
	l++;
    }
    return l;
}

int main() {
    Elem *a= new_Elem();
    Elem *b = new_Elem();
    a->next = b; // the code should fail here
    Elem *head = a;

    printf("list length: %d", list_length(head));
    return 0;
}

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

typedef struct elem {
    struct elem *next;
} Elem;

uint64_t list_length(Elem *h) {
    uint64_t l=0;
    while(h != NULL) {
	h = h->next;
	l++;
    }
    return l;
}


int main(int argc, char **argv) {
    (void) argc;

    int mypid = getpid();
    printf("My PID is: %d. Catch me with 'gdb %s %d' !\n",
	   mypid, argv[0], mypid);
    
    // circular list
    Elem a;
    Elem b = { &a };
    a = (Elem){& b};
    Elem *head = &a;

    printf("list length: %lu", list_length(head));
    return 0;
}

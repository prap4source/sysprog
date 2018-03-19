#include <stdio.h>

typedef struct s_node {
    int data;
    struct s_node *next;
} s_node_t;

typedef struct d_node {
    int data;
    struct d_node *next;
    struct d_node *prev;
} d_node_t;

typedef s_node_t *SLIST; 
typedef d_node_t *DLIST; 


/* Add a node to  after Head */
s_addnode(SLIST new, int data, SLIST HEAD) {
    SLIST tmp = HEAD;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->data = data;
    new->next = NULL;
    
}
/* Traverse a Single Linked List */
s_traverse(SLIST HEAD) {
    SLIST tmp = HEAD;
    
    while (tmp != NULL) {
        printf ("Element ---%d %p\n", tmp->data, tmp);
        tmp = tmp->next;
    }
  
}

/* Delete All nodes leaving HEAD */

void s_delete(SLIST LIST) {
    SLIST P =LIST->next, tmp;
    LIST->next = NULL;
    
    while (P != NULL) {
       tmp = P->next;
       free(P);
       P = tmp;
    }
    
}

/* Reverse a List */
void s_reverse(SLIST HEAD) {
		SLIST newHead = HEAD;
		SLIST after, prev = NULL;
		
		while (newHead != NULL) {
			after = newHead->next;
			newHead->next = prev;
			prev = newHead;
			newHead = after;
		}
		HEAD = prev;
}


void main() {
    SLIST S_HEAD;
    DLIST D_HEAD;
    /*Create HEAD of Single List */
    S_HEAD = malloc(sizeof(s_node_t));
    S_HEAD->next = NULL;
    int i, total_nodes;
    
    printf ("Enter Number of nodes %d\n",sizeof(*D_HEAD));
    scanf ("%d", &total_nodes);
    
    for (i = 1; i <= total_nodes; i++) {
        SLIST  new = malloc(sizeof(s_node_t));
        s_addnode(new, i, S_HEAD);
    }
    
    s_traverse(S_HEAD);
	s_reverse(S_HEAD);
	s_traverse(S_HEAD);
    s_delete(S_HEAD);
    
}


/*
 * align.c
 * Copyright 2017 Pradeep Gopanapalli 
 * 
 */
#include <stdlib.h>
#include <stdio.h>

extern char *__progname;
void* aligned_malloc(size_t required_bytes, size_t alignment)
{
    void* p1; // original block
    void** p2; // aligned block
    int offset = alignment - 1 + sizeof(void*);
    if ((p1 = (void*)malloc(required_bytes + offset)) == NULL)
    {
       return NULL;
    }
    p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
    printf ("memory%p aligned%p %lu\n",p1, p2, sizeof(void*));
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *p)
{
    free(((void**)p)[-1]);
}

int  main (int argc, char *argv[])
{
    char **endptr;
    if (argc != 2) {
	  printf("Usage %s <bytealignment>\n",__progname);
	  return -1;
    }
    int align = strtol(argv[1], endptr, 10);
    int *p = aligned_malloc (100, align);

    aligned_free (p);
    
    return 0;
}


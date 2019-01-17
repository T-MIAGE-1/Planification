int NB_MALLOC = 0;
int NB_FREE = 0;
int LOG = 1;

typedef struct s_node {
    char *value;
} node;

void *malloc_wrapper(size_t __size) {
    void *rtr;
    rtr = malloc(__size);
    if (rtr != NULL)
        NB_MALLOC++;
    if (LOG) {
        if (rtr != NULL)
            printf("Allocation %p\n", rtr);
        else
            printf("Allocation impossible\n");
    }
    return rtr;
}  


/**
 * \brief Wrapper pour désallocation mémoire.
 *
 * @param p adresse de l'espace m�moire � d�sallouer
 */

void free_wrapper(void *p) {
    if (p != NULL)
        NB_FREE++;
    if (LOG) {
        printf("Liberation %p\n", p);
    }
    free(p);
}  




	

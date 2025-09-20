#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

/* 0. malloc_checked */
void *malloc_checked(unsigned int b);

/* 1. string_nconcat */
char *string_nconcat(char *s1, char *s2, unsigned int n);

#endif /* MAIN_H */

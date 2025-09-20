#ifndef MAIN_H
#define MAIN_H

#include <stddef.h> /* NULL */

/**
 * struct dog - represents a dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

/* Prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* MAIN_H */

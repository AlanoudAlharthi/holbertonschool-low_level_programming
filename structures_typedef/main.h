#ifndef MAIN_H
#define MAIN_H

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

/* typedef to simplify struct usage */
typedef struct dog dog_t;

#endif /* MAIN_H */

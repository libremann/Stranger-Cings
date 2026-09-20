#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct XOR_LINKED_NODE {
	int value;
	struct XOR_LINKED_NODE *link; /* link = NEXT^PREV */
} xornd;

xornd *xorn_root(int value) {
	xornd *result = malloc(sizeof(xornd));
	
	if(result==NULL) return NULL;

	result->value=value;
	result->link=NULL;

	return result;
}

void __attribute__((nonnull)) 
add_node(xornd *root, int value) {
	xornd *new=xorn_root(value);
	xornd *prev=NULL;

	if(!new) {
		fprintf(stderr, "%s:%d | `xorn_node/xorn_root` returned NULL\n", __FILE__, __LINE__);
		return;
	}

	if(!root) {
		fprintf(stderr, "%s:%d | `xorn_node` argument connot be NULL\n", __FILE__, __LINE__);
		return;
	}

	xornd *tmp;
	while((xornd*)((uintptr_t)(root->link)^(uintptr_t)prev)!=NULL) {
		tmp=(xornd*)((uintptr_t)(root->link)^(uintptr_t)(prev));
		prev=root;
		root=tmp;
	}
	
	root->link=(xornd*)((uintptr_t)prev^(uintptr_t)new);
	new->link=root;
}

int get_node(xornd *root, int n) {
	xornd *prev=NULL;
	xornd *current=root;

	int i=0;
	xornd *tmp;
	while(current!=NULL) {
		if(i++==n) return current->value;
		tmp=current;
		current=(xornd*)((uintptr_t)(current->link)^(uintptr_t)(prev));
		prev=tmp;
	}
	return -1;
}

void free_all(xornd *root) {
	xornd *prev=NULL;
	xornd *current=root;
	
	xornd *tmp;
	while(current!=NULL) {
		tmp=current;
		current=(xornd*)((uintptr_t)(current->link)^(uintptr_t)(prev));
		prev=tmp;
		free(tmp);
	}
}

int main(void) {
	xornd *root = xorn_root(10);

	if(root==NULL) {
		perror("xorn_root");
		return 1;
	}

	add_node(root, 11);
	add_node(root, 12);

	printf("%d\n", get_node(root, 0));
	printf("%d\n", get_node(root, 1));
	printf("%d\n", get_node(root, 2));
	printf("%d\n", get_node(root, 3)); /* out of range */

	free_all(root);
}

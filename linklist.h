#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <stdlib.h>

struct node
{
    void *data;
    struct node *next;
    struct node *prev;
};

struct linklist
{
    int size;
    struct node *head;
    struct node *tail;
};

#endif

struct linklist* init_linklist(void *data);
int insert_item(struct linklist *list, void *data);
int insert_index(struct linklist *list, void *data, int index);
int remove_item(struct linklist *list, void *data);
int remove_index(struct linklist *list, int index);
void *get(struct linklist *list, int index);
int indexOf(struct linklist *list, void *data);
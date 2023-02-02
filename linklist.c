/*
 * @Author: Ouanu
 * @Date: 2023-02-01 00:45:42
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-02-02 02:00:18
 * @FilePath: /collection/linklist.c
 * @Description: 链表的具体实现
 */
#include "linklist.h"
/**
 * @description: 初始化列表
 * @param {void} *data 内容
 * @return {*} 返回列表
 */
struct linklist *init_linklist(void *data)
{
    struct linklist *l = (struct linklist *)malloc(sizeof(struct link *));
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    l->size = 1;
    l->head = n;
    l->tail = n;
    return l;
}

/**
 * @description: 在列表尾部插入新的元素
 * @param {linklist} *list 列表
 * @param {void} *data 新的元素
 * @return {*} 返回结果，0为失败，1为成功
 */
int insert_item(struct linklist *list, void *data)
{
    if (list == NULL || data == NULL)
        return 0;

    struct node *n = (struct node *)malloc(sizeof(struct node *));
    n->data = data;

    if (list->head == NULL)
    {
        n->prev = NULL;
        n->next = NULL;
        list->head = n;
        list->tail = n;
        list->size++;
        return 1;
    }
    n->prev = list->tail;
    n->next = NULL;
    list->tail->next = n;
    list->tail = n;
    list->size++;
    return 1;
}

/**
 * @description: 在指定位置插入新的元素
 * @param {linklist} *list 列表
 * @param {void} *data 新的元素
 * @param {int} index 插入的位置
 * @return {*} 返回结果，0为失败，1为成功
 */
int insert_index(struct linklist *list, void *data, int index)
{
    if (list == NULL || data == NULL || index > list->size)
        return 0;
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    n->data = data;
    struct node *p = list->head;
    while (index--)
        p = p->next;
    n->prev = p->prev;
    n->next = p;
    p->prev = n;
    list->size++;
    return 1;
}

/**
 * @description: 删除指定元素
 * @param {linklist} *list 列表
 * @param {void} *data 元素
 * @return {*} 返回结果，0为失败，1为成功
 */
int remove_item(struct linklist *list, void *data)
{
    if (list == NULL || data == NULL || list->head == NULL)
        return 0;
    struct node *p = list->head;
    // 删除第一位
    if (p->data == data)
    {
        list->tail = list->tail == p ? NULL : list->tail;
        list->head = p->next;
        if (p->next != NULL)
            p->next->prev = NULL;
        list->size--;
        free(p);
        return 1;
    }
    // 删除中间位以及最后一位
    while (p->data != data)
    {
        if (p->next == NULL)
            break;
        p = p->next;
    }
    if (p->data != data)
        return 0;
    // 末尾
    if (p == list->tail)
    {
        list->tail = p->prev;
        p->prev->next = NULL;
        list->size--;
        free(p);
        return 1;
    }
    // 中间位
    p->next->prev = p->prev;
    p->prev->next = p->next;
    list->size--;
    free(p);
    return 1;
}

/**
 * @description: 删除指定位置的元素
 * @param {linklist} *list 列表
 * @param {int} index 指定位置
 * @return {*} 返回结果，0为失败，1为成功
 */
int remove_index(struct linklist *list, int index)
{
    if (list == NULL || index > list->size || list->head == NULL)
        return 0;
    struct node *p = list->head;
    while (index--)
        p = p->next;
    // 删除第一位
    if (list->head == p)
    {
        list->tail = list->tail == list->head ? NULL : list->tail;
        list->head = p->next;
        if (list->head != NULL)
            list->head->prev = NULL;
        p->prev = NULL;
        list->size--;
        free(p);
        return 1;
    }
    // 末尾
    if (p == list->tail)
    {
        list->tail = p->prev;
        p->prev->next = NULL;
        list->size--;
        free(p);
        return 1;
    }
    // 中间位
    p->next->prev = p->prev;
    p->prev->next = p->next;
    list->size--;
    free(p);
    return 1;
}

/**
 * @description: 获取指定位置的元素
 * @param {linklist} *list 列表
 * @param {int} index 下标
 * @return {*} 返回元素
 */
void *get(struct linklist *list, int index)
{
    if (list == NULL || list->size < index || list->size == 0)
        return NULL;
    struct node *n = list->head;
    for (int i = 0; i < index; i++)
        n = n->next;
    return n->data;
}

/**
 * @description: 获取元素的下标
 * @param {linklist} *list 列表
 * @param {void} *data 指定的内容
 * @return {*} 返回下标
 */
int indexOf(struct linklist *list, void *data)
{
    if (list == NULL || data == NULL || list->head == NULL)
        return -1;
    int index = 0;
    struct node *n = list->head;
    while (n->data != data)
    {
        if (n->next == NULL)
            break;
        n = n->next;
        index++;
    }
    if (n->data != data)
        return -1;
    return index;
}
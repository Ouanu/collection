#include "linklist.h"

int main() {
    struct linklist* list = init_linklist(123);
    insert_item(list, 234);
    insert_item(list, 345);
    // insert_item(list, "456");
    
    for (int i = 0; i < list->size; i++)
    {
        // printf("%s\n", (char *)get(list, i));
        printf("%d\n", get(list, i));
    }
    printf("------------------------\n");
    // remove_item(list, "123");
    remove_index(list, 0);
    printf("------------------------\n");
    get(list, 0);
    // printf("%s\n", (char *)get(list, 0));
    for (int i = 0; i < list->size; i++)
    {
        // printf("%s\n", (char *)get(list, i));
        printf("%d\n", get(list, i));
    }
    printf("%d\n", indexOf(list, 345));
    
    return 0;
}
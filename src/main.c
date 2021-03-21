#include <stdio.h>
#include <string.h>

#include "sds.h"
#include "adlist.h"

int keyMatch(void *ptr, void *key)
{
    return strcmp(ptr, key) == 0 ? 1 : 0;
}

void printList(list *li)
{
    listIter iter;
    listNode *node = NULL;

    printf("li size is %d, elements:", listLength(li));

    listRewind(li, &iter);
    while ((node = listNext(&iter)) != NULL)
    {
        printf("%s ", (char *)node->value);
    }

    printf("\n\n");
}

void sdsSample()
{
    sds s = sdsnew("hello redis");
    sdstoupper(s);
    printf("sds: %s\n",s);
    sdsfree(s);
}

/* 缺点:内存碎片 */
void listSample(){
    char *data[] = {"believe", "it", "or", "not"};
    listIter iter;
    listNode *node = NULL;

    list *li = listCreate();
    for (int i = 0; i < sizeof(data) / sizeof(*data); ++i)
    {
        listAddNodeHead(li, data[i]);
    }
    printList(li);

    printf("\nSearch a key :\n");
    listSetMatchMethod(li, keyMatch);
    listNode *ln = listSearchKey(li, data[1]);
    if (ln != NULL)
    {
        printf("find key is :%s\n", (char *)ln->value);
    }
    else
    {
        printf("not found\n");
    }

    printf("\nReverse output the list :\n");
    printf("li size is %d, elements:", listLength(li));
    listRewindTail(li, &iter);
    while ((node = listNext(&iter)) != NULL)
    {
        printf("%s ", (char *)node->value);
    }
    printf("\n\n");

    printf("duplicate a new list :\n");
    list *lidup = listDup(li);
    printList(lidup);

    printf("Connect two linked lists :\n");
    listJoin(li, lidup);
    printList(li);

    listRelease(li);
}

int main(int argc, char **argv)
{
    listSample();
    sdsSample();

    return 0;
}

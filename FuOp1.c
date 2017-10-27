#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funcs1.h"

enum {N = 10};

typedef struct Node
{
    struct Node *next;
    char *str;
} List;

int
check(const List *lis, char *src)
{
    const List *cur = lis;
    while (cur) {
        if (strcmp(cur->str, src) == 0) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

List *
add(List *lis, char *src)
{
    List *cur = calloc(1, sizeof(List));
    if (!cur) {
        printf("Lack of memory 1");
        return lis;
    }
    cur->next = lis;
    cur->str = calloc(1, strlen(src) + 1);
    if (!cur->str) {
        printf("lack of memory 2");
        return lis;
    }
    memcpy(cur->str, src, strlen(src) + 1);
    return cur;
}

List *
combine(const List *lis1, const List *lis2)
{
    const List *cur = lis1;
    List *lis3 = NULL;
    while (cur) {
        if (check(lis2, cur->str)) {
            lis3 = add(lis3, cur->str);
        }
        cur = cur->next;
    }
    return lis3;
}


char *
insert(void)
{
    char c;
    int newn = N;
    char *str = calloc(newn, sizeof(c));
    int i = 0;
    while ((c = getchar()) != '\n') {
        if (i >= newn - 1) {
            newn *= 2;
            str = realloc(str, newn);
            if (!str) {
                printf("Lack of memory 3");
                return NULL;
            }
        }
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    str = realloc(str, i+1);
    if (!str) {
        printf("Lack of memory 4");
        return NULL;
    }
    return str;
}

void
on_screen(const List *lis)
{
    printf("The new list is\n");
    while(lis) {
        char *pr_str = lis->str;
        printf("%s\n", pr_str);
        lis = lis->next;
    }
}

void
delete_lis(List *lis)
{
    List *ptr;
    while (lis) {
        ptr = lis;
        lis = lis->next;
        free(ptr->str);
        free(ptr);
    }
}

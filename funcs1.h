#ifndef FuOp1_c
#define FuOp1_c value

typedef struct Node List;

int
check(const List *lis, char *src);
List *
add(List *lis, char *src);
List *
combine(const List *lis1, const List *lis2);
char *
insert(void);
void
on_screen(const List *lis);
void
delete_lis(List *lis);

#endif

#include "stack.h"

int main()
{
    int n, m, i;    /* n - user input; m - output of POP */
    int ret;        /* ret - contains the return value of stack operations push and pop */
    Stack *s = create(sizeof(int), 3);
    assert(s);
    assert(s->member_size == sizeof(int));
    assert(s->capacity == 3);

    for(i = 0; i < 3; ++i)
    {
        printf("Enter a number : \n");
        scanf("%d", &n);

        ret = push(s, (void*)&n);
        assert(s->top == i);
        assert(ret == 0);
    }

    for(i = 2; i > -1; --i)
    {
        ret = pop(s, (void*)&m);
        printf("Pop'd value : %d\n", m);
        assert(ret == 0);
        assert(s->top == 0);
    }

    ret = destroy(s);
    assert(ret = 0);

    system("pause");
    return 0;
}
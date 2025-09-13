#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int len_id = printf("id) %d %d %d %d\n", INT_MIN, -1, 0, NULL);
	int len_u = printf("u) %u %u %u %u %u %u\n", 0, -1, -42, 4294967296u, INT_MIN, INT_MAX);
	int len_x = printf("x) %x %x %x %x\n", -1, -12345, -2147483648, 4294967295u);
	int len_X = printf("X) %X %X %X %X\n", -1, -12345, -2147483648, 4294967295u);
	int len_s = printf("s) %s %s %s\n", NULL, "", "hello");
	int len_p = printf("p) %p %p %p %p %p %p %p\n", NULL, (void*)0, (void*)0x1234, (void*)-1, (void*)0x7fffffffffffffff, (void*)1, (void*)0xdeadbeef);

	printf("%d %d %d %d %d %d", len_id, len_u, len_x, len_X, len_s, len_p);
}

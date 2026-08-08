#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int len_id = ft_printf("id) %d %d %d %d\n", INT_MIN, -1, 0, NULL);
	int len_u = ft_printf("u) %u %u %u %u %u %u\n", 0, -1, -42, 4294967296u, INT_MIN, INT_MAX);
	int len_x = ft_printf("x) %x %x %x %x\n", -1, -12345, -2147483648, 4294967295u);
	int len_X = ft_printf("X) %X %X %X %X\n", -1, -12345, -2147483648, 4294967295u);
	int len_s = ft_printf("s) %s %s %s\n", NULL, "", "hello");
	int len_p = ft_printf("p) %p %p %p %p %p %p %p\n", NULL, (void*)0, (void*)0x1234, (void*)-1, (void*)0x7fffffffffffffff, (void*)1, (void*)0xdeadbeef);
	int len_test1 = ft_printf("ft_printf: c s p d / %c aaaa%s %p %d\n", 'A',"", NULL, 4);
	int len_test2 = ft_printf("%% %u %x %X %c\n", -1, -1, -1, ' ');

	printf("%d %d %d %d %d %d %d %d", len_id, len_u, len_x, len_X, len_s, len_p, len_test1, len_test2);

}

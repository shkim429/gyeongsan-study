#include "get_next_line.h"

int	get_idx_find_first_chr(char	*stash, int find_chr)
{
	int				idx;
	int				offset;
	unsigned char	find_chr_copy;

	if (stash == NULL)
		return (-1);
	idx = 0;
	find_chr_copy = (unsigned char)find_chr;
	while (stash[idx] != find_chr_copy)
	{
		if (stash[idx] == '\0')
			return (-1);
		idx++;
	}
	offset = idx;
	return (offset);
}

#include <stdio.h>

int main()
{
	char *str = "abc\n";
	int	result;

	result = get_idx_find_first_chr(str, '\n');
	printf("%d", result);
}

// int	ft_strlen(const char *s)
// {
// 	int	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// #include <stdio.h>

// int main()
// {
// 	char *str = "abc";
// 	int result = ft_strlen(str);
// 	printf("%d", result);
// }
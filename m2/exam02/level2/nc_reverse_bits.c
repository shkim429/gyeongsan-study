unsigned char	reverse_bits(unsigned char octet)
{
	int	bit_len = 8;
	unsigned char	bite;

	while (bit_len--)
	{
		bite = bite >> 1 | octet & 1;
		bite <<= 1;
	}
	return (bite);
}
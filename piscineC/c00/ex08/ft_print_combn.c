#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_combn(int n)
{
	int nb1;
	int nb2;
	int nb3;
	int nb4;
	int nb5;

	nb1 = 0;

	if (n == 1)
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
	if (n == 2)
	{
		while (nb1 < 89)
		{
			if (nb1 % 10 > nb1 / 10)
			{
				ft_putchar('0' + nb1 / 10);
				ft_putchar('0' + nb1 % 10);
				if (nb1 != 89)
					write(1, ", ", 1);
			}
			nb1++;
		}
	}
	if (n == 3)
	{
		while (++nb1 <= 78)
		{
			nb2 = nb1 % 10;
			while (++nb2 <= 9)
			{
				if ((nb1 % 10 > nb1 / 10))
				{
					ft_putchar('0' + nb1 / 10);
					ft_putchar('0' + nb1 % 10);
					ft_putchar('0' + nb2 % 10);
					if (nb1 != 78)
						write(1, ", ", 2);
				}

			}
		}
	}
	if (n == 4)
	{
		while (++nb1 <= 67)
		{
			nb2 = nb1;
			while (++nb2 <= 89)
			{
				if ((nb1 % 10 > nb1 / 10) && (nb2 / 10 > nb1 % 10) && (nb2 % 10 > nb2 / 10))
				{
					ft_putchar('0' + nb1 / 10);
					ft_putchar('0' + nb1 % 10);
					ft_putchar('0' + nb2 / 10);
					ft_putchar('0' + nb2 % 10);
					if (nb1 != 67)
						write(1, ", ", 2);
				}

			}
		}
	}
	if (n == 5)
	{
		while (++nb1 <= 56)
		{
			nb2 = nb1;
			while (++nb2 <= 78)
			{
				nb3 = nb2 % 10;
				while (++nb3 <= 9)
				{
					if ((nb1 % 10 > nb1 / 10) && (nb2 / 10 > nb1 % 10) && (nb2 % 10 > nb2 / 10))
					{
						ft_putchar('0' + nb1 / 10);
						ft_putchar('0' + nb1 % 10);
						ft_putchar('0' + nb2 / 10);
						ft_putchar('0' + nb2 % 10);
						ft_putchar('0' + nb3 % 10);
						if (nb1 != 56)
							write(1, ", ", 2);
					}
				}

			}
		}
	}
	if (n == 6)
	{
		while (++nb1 <= 45)
		{
			nb2 = nb1;
			while (++nb2 <= 67)
			{
				nb3 = nb2;
				while (++nb3 <= 89)
				{
					if ((nb1 % 10 > nb1 / 10) && (nb2 / 10 > nb1 % 10) && (nb2 % 10 > nb2 / 10)
					&& (nb3 / 10 > nb2 % 10) && (nb3 % 10 > nb3 / 10))
					{
						ft_putchar('0' + nb1 / 10);
						ft_putchar('0' + nb1 % 10);
						ft_putchar('0' + nb2 / 10);
						ft_putchar('0' + nb2 % 10);
						ft_putchar('0' + nb3 / 10);
						ft_putchar('0' + nb3 % 10);
						if (nb1 != 45)
							write(1, ", ", 2);
					}
				}

			}
		}
	}
	if (n == 7)
	{
		while (++nb1 <= 34)
		{
			nb2 = nb1;
			while (++nb2 <= 56)
			{
				nb3 = nb2;
				while (++nb3 <= 78)
				{
					nb4 = nb3 % 10;
					while (++nb4 <= 9)
					{
						if ((nb1 % 10 > nb1 / 10) && (nb2 / 10 > nb1 % 10) && (nb2 % 10 > nb2 / 10)
						&& (nb3 / 10 > nb2 % 10) && (nb3 % 10 > nb3 / 10))
						{
							ft_putchar('0' + nb1 / 10);
							ft_putchar('0' + nb1 % 10);
							ft_putchar('0' + nb2 / 10);
							ft_putchar('0' + nb2 % 10);
							ft_putchar('0' + nb3 / 10);
							ft_putchar('0' + nb3 % 10);
							ft_putchar('0' + nb4 % 10);
							if (nb1 != 34)
								write(1, ", ", 2);
						}
					}
				}

			}
		}
	}
	if (n == 8)
	{
		while (++nb1 <= 23)
		{
			nb2 = nb1;
			while (++nb2 <= 45)
			{
				nb3 = nb2;
				while (++nb3 <= 67)
				{
					nb4 = nb3;
					while (++nb4 <= 89)
					{
						if ((nb1 % 10 > nb1 / 10) && (nb2 / 10 > nb1 % 10) && (nb2 % 10 > nb2 / 10)
						&& (nb3 / 10 > nb2 % 10) && (nb3 % 10 > nb3 / 10) &&
						(nb4 / 10 > nb3 % 10) && (nb4 % 10 > nb4 / 10))
						{
							ft_putchar('0' + nb1 / 10);
							ft_putchar('0' + nb1 % 10);
							ft_putchar('0' + nb2 / 10);
							ft_putchar('0' + nb2 % 10);
							ft_putchar('0' + nb3 / 10);
							ft_putchar('0' + nb3 % 10);
							ft_putchar('0' + nb4 / 10);
							ft_putchar('0' + nb4 % 10);
							if (nb1 != 23)
								write(1, ", ", 2);
						}
					}
				}

			}
		}
	}
	if (n == 9)
	{
		while (++nb1 <= 12)
		{
			nb2 = nb1;
			while (++nb2 <= 34)
			{
				nb3 = nb2;
				while (++nb3 <= 56)
				{
					nb4 = nb3;
					while (++nb4 <= 78)
					{
						nb5 = nb4 % 10;
						while (++nb5 <= 9)
						{
							if ((nb1 % 10 > nb1 / 10) && (nb2 / 10 > nb1 % 10) && (nb2 % 10 > nb2 / 10)
							&& (nb3 / 10 > nb2 % 10) && (nb3 % 10 > nb3 / 10) &&
							(nb4 / 10 > nb3 % 10) && (nb4 % 10 > nb4 / 10))
							{
								ft_putchar('0' + nb1 / 10);
								ft_putchar('0' + nb1 % 10);
								ft_putchar('0' + nb2 / 10);
								ft_putchar('0' + nb2 % 10);
								ft_putchar('0' + nb3 / 10);
								ft_putchar('0' + nb3 % 10);
								ft_putchar('0' + nb4 / 10);
								ft_putchar('0' + nb4 % 10);
								ft_putchar('0' + nb5 % 10);
								if (nb1 != 12)
									write(1, ", ", 2);
							}
						}
					}
				}

			}
		}
	}
}

int main()
{
	ft_print_combn(9);
}

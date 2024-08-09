/*
 * Author: bl4kcy
 * Description: This program takes command line arguments and converts them to uppercase.
 * If no arguments are provided, it outputs a default message.
 * Usage: ./megaphone [arguments]
 */

#include <iostream>

int	main(int c, char **av)
{
	switch (c)
	{
	case 1:
		// No arguments provided
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		break;
	default:
		// Loop through all arguments and convert them to uppercase
		for (int i = 1; i < c; i++)
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
		break;
	}
	return (0);
}

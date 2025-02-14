#ifndef TESTS_H
# define TESTS_H

# define RED "\e[31m"
# define GREEN "\e[32m"
# define CYAN "\e[36m"
# define GRAY "\e[2;37m"
# define COLOR_RESET "\e[0m"

# define KO "\e[31mKO\e[0m"
# define OK "\e[32mOK\e[0m"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Utils
void	ft_print_test_header(const char *str);

#endif

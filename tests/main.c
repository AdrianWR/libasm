/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:35:42 by aroque            #+#    #+#             */
/*   Updated: 2020/11/04 22:45:05 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include "minunit.h"

MU_TEST(test_ft_strlen)
{
	mu_assert(ft_strlen("42saopaulo") == 10, "Error: ft_strlen base case");
	mu_assert(ft_strlen("") == 0, "Error: ft_strlen empty string");
}

MU_TEST(test_ft_strcpy)
{
	const char src[] = "Let's disassembly ourselves!";
	char *dest;
	char *ret;

	dest = malloc(strlen(src) * sizeof(*dest));
	ret = ft_strcpy(dest, src);
	mu_assert(strcmp(src, dest) == 0, "Error: ft_strcpy base case");
	mu_assert(strcmp(ret, dest) == 0, "Error: ft_strcpy base case return");
	mu_assert(strcmp(ret, src) == 0, "Error: ft_strcpy base case return");
	free(dest);
}

MU_TEST(test_ft_strcmp)
{
	mu_assert_int_eq(strcmp("b", "a"), ft_strcmp("b", "a"));
	mu_assert_int_eq(strcmp("a", "b"), ft_strcmp("a", "b"));
	mu_assert_int_eq('b' - 'm', ft_strcmp("banana", "maca"));
	mu_assert_int_eq('a' - 'o', ft_strcmp("banana", "banano"));
	mu_assert_int_eq('a', ft_strcmp("a", ""));
	mu_assert_int_eq(-'a', ft_strcmp("", "a"));
	mu_assert_int_eq(0, ft_strcmp("", ""));
}

MU_TEST(test_ft_write)
{
	int				devNull;
	unsigned long	n;
	const char		buf[] = "Test ft_write";

	devNull = open("/dev/null", O_WRONLY);
	n = ft_write(devNull, buf, strlen(buf));
	mu_assert(n == strlen(buf), "Error: ft_write base case");
	close(devNull);
}

//MU_TEST(test_ft_read)
//{
//	char buf[100];
//
//	ft_read(STDIN_FILENO, buf, 100);
//	ft_write(STDOUT_FILENO, buf, ft_strlen(buf));
//}

MU_TEST(test_ft_strdup)
{
	char *test;
	test = ft_strdup("Teste");
	mu_assert(ft_strcmp("Teste", test) == 0, "Error: ft_strdup base case");
	mu_assert(ft_strcmp("Teste", ft_strdup("Teste")) == 0, "Error: ft_strdup base case");
	mu_assert(ft_strcmp("", ft_strdup("")) == 0, "Error: ft_strdup base case");
	free(test);
	//printf("Result -> %s\n", strdup(NULL));
}

MU_TEST_SUITE(mandatory)
{
	MU_RUN_TEST(test_ft_strlen);
	MU_RUN_TEST(test_ft_strcpy);
	MU_RUN_TEST(test_ft_strcmp);
	MU_RUN_TEST(test_ft_write);
	//MU_RUN_TEST(test_ft_read);
	MU_RUN_TEST(test_ft_strdup);
}

int	main(void)
{
	MU_RUN_SUITE(mandatory);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

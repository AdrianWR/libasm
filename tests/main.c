/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:35:42 by aroque            #+#    #+#             */
/*   Updated: 2020/11/06 00:45:45 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
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
	ssize_t		n;
	int		fd;
	const char	buf[] = "Test ft_write";

	fd = open("/dev/null", O_WRONLY);
	n = ft_write(fd, buf, 13);
	mu_assert(n == 13, "Error: ft_write base case");
	close(fd);

	ft_write(42, buf, strlen(buf));
	mu_assert_int_eq(EBADF, errno);

}

MU_TEST(test_ft_read)
{
	int	n;
	int	fd;
	char	buf[8];

	fd = open("/dev/urandom", O_RDONLY);
	n = ft_read(fd, buf, 8);
	mu_assert_int_eq(8, n);
	close(fd);

	ft_read(42, buf, 8);
	mu_assert_int_eq(EBADF, errno);
}

MU_TEST(test_ft_strdup)
{
	char *test;
	test = ft_strdup("Teste");
	mu_assert(ft_strcmp("Teste", test) == 0, "Error: ft_strdup base case");
	mu_assert(ft_strcmp("Teste", ft_strdup("Teste")) == 0, "Error: ft_strdup base case");
	mu_assert(ft_strcmp("", ft_strdup("")) == 0, "Error: ft_strdup base case");
	free(test);
}

#ifdef BONUS

MU_TEST(test_ft_list_push_front)
{
	t_list	*list;
	t_list	*first_list;
	char	*content1 = "My first content";
	char	*content2 = "My second content";

	list = NULL;
	mu_assert(list == NULL, "Error: Initialization error on t_list");
	ft_list_push_front(&list, content1);
	mu_assert(list != NULL, "Error: Push front error on t_list");
	mu_assert(list->data != NULL, "Error: Push front error on t_list");
	mu_assert(ft_strcmp(list->data, "My first content") == 0, "Error: Push front error on t_list");

	first_list = list;
	ft_list_push_front(&list, content2);
	mu_assert(list != NULL, "Error: Push front error on t_list");
	mu_assert(list->data != NULL, "Error: Push front error on t_list");
	mu_assert(ft_strcmp(list->data, "My second content") == 0, "Error: Push front error on t_list");
	mu_assert(ft_strcmp(first_list->data, "My first content") == 0, "Error: Push front error on t_list");
	free(first_list);
	free(list);
}

MU_TEST(test_ft_list_size)
{
	t_list	*list;

	list = NULL;
	mu_assert_int_eq(0, ft_list_size(list));
	ft_list_push_front(&list, "First content");
	mu_assert_int_eq(1, ft_list_size(list));
	ft_list_push_front(&list, "Second content");
	mu_assert_int_eq(2, ft_list_size(list));
	free(list->next);
	free(list);
}

#endif

MU_TEST_SUITE(mandatory)
{
	MU_RUN_TEST(test_ft_strlen);
	MU_RUN_TEST(test_ft_strcpy);
	MU_RUN_TEST(test_ft_strcmp);
	MU_RUN_TEST(test_ft_write);
	MU_RUN_TEST(test_ft_read);
	MU_RUN_TEST(test_ft_strdup);
	#ifdef BONUS
	MU_RUN_TEST(test_ft_list_push_front);
	MU_RUN_TEST(test_ft_list_size);
	#endif
}

int	main(void)
{
	MU_RUN_SUITE(mandatory);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

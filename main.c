/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:54:04 by rploeger          #+#    #+#             */
/*   Updated: 2025/11/04 17:19:31 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include "ft_printf.h"

#define TEST0(str) assert(printf(str) == ft_printf(str));
#define TEST(str, ...) assert(printf(str, __VA_ARGS__) == ft_printf(str, __VA_ARGS__));

int	main(void)
{
	void *ptr;
	ptr = malloc(1);
	free(ptr);

	printf("Test character\n\n");
	TEST("%c\n", 'z');
	TEST(" %c \n", 'z');
	TEST("%c\n", 'z');
	TEST("%c %c %c\n", 'a', 'b', 'c');
	TEST("%c\n", '\0');
	TEST("%c\n", '0');
	TEST("%c\n", '0' - 256);
	TEST("%c\n", '0' + 256);

	printf("Test string\n\n");
	TEST("%s\n", "");
	TEST("%s\n", NULL);
	TEST("%s\n", "1");
	TEST("%s\n", "hell yeah");
	TEST("string: %s\n", "");
	TEST("string: %s\n", NULL);

	printf("Test pointer\n\n");
	TEST("pointer: %p\n", NULL);
	TEST("pointer: %p\n", ptr);

	printf("Test integer\n\n");
	TEST("%d\n", 0);
	TEST("%d\n", 1);
	TEST("%d\n", -1);
	TEST("%i\n", 0);
	TEST("%i\n", 1);
	TEST("%i\n", -1);
	TEST("%i\n", UINT64_MAX);
	TEST("%i\n", UINT32_MAX);
	TEST("integer (d): %d\n", -123);
	TEST("integer (i): %i\n", 123);

	printf("Test unsigned integer\n\n");
	TEST("%u\n", -123);
	TEST("%u\n", 0);
	TEST("%u\n", 123);
	TEST("%u\n", UINT64_MAX);
	TEST("%u\n", UINT32_MAX);
	TEST("unsigned integer (u): %u\n", 123);

	printf("Test hex\n\n");
	TEST("%x\n", 0);
	TEST("%x\n", 123);
	TEST("%x\n", -123);
	TEST("%x\n", 1 << 31);
	TEST("%x\n", ~(1 << 31));
	TEST("%X\n", 0);
	TEST("%X\n", 123);
	TEST("%X\n", -123);
	TEST("%X\n", 1 << 31);
	TEST("%X\n", ~(1 << 31));
	TEST("hex integer (x): %x\n", -123);
	TEST("hex integer (X): %X\n", 123);
	TEST(" %x %x %x %x %x %x %x\n", INT32_MAX, INT32_MIN, INT64_MIN, INT64_MAX, UINT64_MAX, 0, -42);

	printf("Test width flag\n\n");
	TEST("%10d\n", -10);

	printf("Test 0 flag\n\n");
	TEST("%01d\n", 0);
	TEST("%02d\n", -1);
	TEST("%010d\n", 10);
	TEST("%010d\n", 0);
	TEST("%01u\n", -10);
	TEST("%013u\n", -10);
	TEST("%010d\n", INT32_MIN);
	TEST("%#010x\n", INT32_MIN);
	TEST("%010x\n", INT32_MIN);
	TEST("%#010x\n", INT64_MAX);
	TEST("%010x\n", INT64_MAX);
	TEST("%#01x\n", 0);
	TEST("%#01x\n", 1);
	TEST("%#010x\n", 1);
	TEST("%010x\n", 1);
	TEST("%#010X\n", INT32_MIN);
	TEST("%010X\n", INT32_MIN);
	TEST("%#010X\n", INT64_MAX);
	TEST("%010X\n", INT64_MAX);
	TEST("%#01X\n", 0);
	TEST("%#01X\n", 1);
	TEST("%#010X\n", 1);
	TEST("%010X\n", 1);

	printf("\n# flag\n\n");
	TEST("hex integer (#x): %#x\n", -123);
	TEST("hex integer (#x): %#x\n", 0);
	TEST("hex integer (#x): %#x\n", 123);
	TEST("hex integer (#X): %#X\n", -123);
	TEST("hex integer (#X): %#X\n", 0);
	TEST("hex integer (#X): %#X\n", 123);

	printf("\nspace flag\n\n");
	TEST("integer ( d): % d\n", 123);
	TEST("integer ( d): % d\n", 0);
	TEST("integer ( d): % d\n", -123);
	TEST("integer ( i): % i\n", 123);
	TEST("integer ( i): % i\n", 0);
	TEST("integer ( i): % i\n", -123);

	printf("\n+ flag\n\n");
	TEST("integer (+d): %+d\n", 123);
	TEST("integer (+d): %+d\n", 0);
	TEST("integer (+d): %+d\n", -123);
	TEST("integer (+i): %+i\n", 123);
	TEST("integer (+i): %+i\n", 0);
	TEST("integer (+i): %+i\n", -123);

	printf("\nwidth flag\n\n");
	TEST("integer (10c): %10c;\n", 'c');
	TEST("integer (10s): %10s;\n", "str");
	TEST("integer (10d): %10d;\n", -123);

	printf("\n- flag\n\n");
	TEST("integer (-10c) : %-10c;\n", 'c');
	TEST("integer (-10s) : %-10s;\n", "str");
	TEST("integer (+-10d): %+-10d;\n", -123);
	TEST("integer (10+-d): %+-10d;\n", -123);

	printf("\n0 flag\n\n");
	TEST("integer (010d): %010d;\n", -123);
	TEST("integer (010+-d): %+-10d;\n", -123);
	TEST("%X %x\n", -42, -42);

	TEST(" %-9x %-10x \n", INT64_MIN, INT64_MAX);
	TEST(" %-9p %-10p \n", INT64_MIN, INT64_MAX);

	printf("\n x with 0 \n\n");
	TEST("%#x\n", 0);
	TEST("%#01x\n", 0);
	TEST("%#02x\n", 0);

	printf("\n. flag with d\n\n");
	TEST("%.d\n", 0);
	TEST("%.0d\n", 0);
	TEST("%.1d\n", 0);
	TEST("%.1d\n", 1);
	TEST("%.2d\n", 1);
	TEST("%.3d\n", 1);
	TEST("%.1d\n", -1);
	TEST("%.2d\n", -1);
	TEST("%.3d\n", -1);
	TEST("%.10d\n", 0);
	TEST("%.10d\n", 123);
	TEST("%.10d\n", -123);
	TEST("%.10d\n", -123);
	TEST("%.9d\n", INT_MAX);
	TEST("%.10d\n", INT_MAX);
	TEST("%.11d\n", INT_MAX);
	TEST("%.9d\n", INT_MIN);
	TEST("%.10d\n", INT_MIN);
	TEST("%.11d\n", INT_MIN);

	printf("\n. flag with x\n\n");
	TEST("%.12x\n", 0);
	TEST("%#.12x\n", 0);
	TEST("%.12x\n", 555);
	TEST("%#.12x\n", 555);
	TEST("%.12x\n", -555);
	TEST("%#.12x\n", -555);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:54:04 by rploeger          #+#    #+#             */
/*   Updated: 2025/11/05 15:31:05 by rploeger         ###   ########.fr       */
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

#define TEST0(str) \
	printf("-----\n"); \
	printf("template: %s", str); \
	assert(printf(str) == ft_printf(str)); \
	printf("-----\n");
#define TEST(str, ...) \
	printf("-----\n"); \
	printf("template: %s", str); \
	assert(printf(str, __VA_ARGS__) == ft_printf(str, __VA_ARGS__)); \
	printf("-----\n");

void print_header(char *str)
{
	printf("=================================\n");
	printf("\t%s\n", str);
	printf("=================================\n");
}

int	main(void)
{
	void *ptr;
	ptr = malloc(1);
	free(ptr);

	print_header("Test character");
	TEST("%c\n", 'z');
	TEST(" %c \n", 'z');
	TEST("%c\n", 'z');
	TEST("%c %c %c\n", 'a', 'b', 'c');
	TEST("%c\n", '\0');
	TEST("%c\n", '0');
	TEST("%c\n", '0' - 256);
	TEST("%c\n", '0' + 256);
	TEST("{%4c}\n", 0);

	print_header("Test string");
	TEST("%s\n", "");
	TEST("%s\n", NULL);
	TEST("%s\n", "1");
	TEST("%s\n", "hell yeah");
	TEST("string: %s\n", "");
	TEST("string: %s\n", NULL);

	print_header("Test pointer");
	TEST("pointer: %p\n", NULL);
	TEST("pointer: %p\n", ptr);

	print_header("Test integer");
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

	print_header("Test unsigned integer");
	TEST("%u\n", -123);
	TEST("%u\n", 0);
	TEST("%u\n", 123);
	TEST("%u\n", UINT64_MAX);
	TEST("%u\n", UINT32_MAX);
	TEST("unsigned integer (u): %u\n", 123);

	print_header("Test hex");
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

	print_header("Test width flag");
	TEST("%10d\n", -10);

	print_header("Test 0 flag");
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

	print_header("# flag");
	TEST("hex integer (#x): %#x\n", -123);
	TEST("hex integer (#x): %#x\n", 0);
	TEST("hex integer (#x): %#x\n", 123);
	TEST("hex integer (#X): %#X\n", -123);
	TEST("hex integer (#X): %#X\n", 0);
	TEST("hex integer (#X): %#X\n", 123);

	print_header("space flag");
	TEST("integer ( d): % d\n", 123);
	TEST("integer ( d): % d\n", 0);
	TEST("integer ( d): % d\n", -123);
	TEST("integer ( i): % i\n", 123);
	TEST("integer ( i): % i\n", 0);
	TEST("integer ( i): % i\n", -123);

	print_header("+ flag");
	TEST("integer (+d): %+d\n", 123);
	TEST("integer (+d): %+d\n", 0);
	TEST("integer (+d): %+d\n", -123);
	TEST("integer (+i): %+i\n", 123);
	TEST("integer (+i): %+i\n", 0);
	TEST("integer (+i): %+i\n", -123);

	print_header("width flag");
	TEST("integer (10c): %10c;\n", 'c');
	TEST("integer (10s): %10s;\n", "str");
	TEST("integer (10d): %10d;\n", -123);

	print_header("- flag");
	TEST("integer (-10c) : %-10c;\n", 'c');
	TEST("integer (-10s) : %-10s;\n", "str");
	TEST("integer (+-10d): %+-10d;\n", -123);
	TEST("integer (10+-d): %+-10d;\n", -123);

	print_header("0 flag");
	TEST("integer (010d): %010d;\n", -123);
	TEST("integer (010+-d): %+-10d;\n", -123);
	TEST("%X %x\n", -42, -42);
	TEST(" %-9x %-10x \n", INT64_MIN, INT64_MAX);
	TEST(" %-9p %-10p \n", INT64_MIN, INT64_MAX);

	print_header("x with 0 ");
	TEST("%#x\n", 0);
	TEST("%#01x\n", 0);
	TEST("%#02x\n", 0);

	print_header(". flag with d");
	TEST("%.d\n", 0);
	TEST("%.d\n", 123);
	TEST("%.0d\n", 0);
	TEST("%.0d\n", 123);
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
	TEST("%5.10d\n", -123);
	TEST("%05.10d\n", -123);
	TEST("%0.0d\n", -123);
	TEST("%010.0d\n", -123);
	TEST("%10.5d\n", -123);
	TEST("%010.5d\n", -123);
	TEST("%-010.0d\n", -123);

	print_header(". flag with u");
	TEST("%.u\n", 0);
	TEST("%.0u\n", 0);
	TEST("%.1u\n", 0);
	TEST("%.1u\n", 1);
	TEST("%.2u\n", 1);
	TEST("%.3u\n", 1);
	TEST("%.1u\n", -1);
	TEST("%.2u\n", -1);
	TEST("%.3u\n", -1);
	TEST("%.10u\n", 0);
	TEST("%.10u\n", 123);
	TEST("%.10u\n", -123);
	TEST("%.10u\n", -123);
	TEST("%.9u\n", INT_MAX);
	TEST("%.10u\n", INT_MAX);
	TEST("%.11u\n", INT_MAX);
	TEST("%.9u\n", INT_MIN);
	TEST("%.10u\n", INT_MIN);
	TEST("%.11u\n", INT_MIN);

	print_header(". flag with s");
	TEST("%.s|\n", NULL);
	TEST("%.0s|\n", NULL);
	TEST("%.05s|\n", NULL);
	TEST("%.06s|\n", NULL);
	TEST("%20.06s|\n", NULL);
	TEST("%.1s|\n", "hi");
	TEST("%.2s|\n", "yesyes");
	TEST("%.3s|\n", "yesyes");
	TEST("%.8s|\n", "yesyes");
	TEST("%-8.s|\n", "yesyes");
	TEST("%-8.0s|\n", "yesyes");
	TEST("%-8.1s|\n", "yesyes");
	TEST("%-7.3s|\n", "yesyes");
	TEST("%7.3s|\n", "yesyes");
	TEST("%-3.7s|\n", "yesyes");
	TEST("%3.7s|\n", "yesyes");

	print_header(". flag with %%");
	TEST0("%3%|\n");
	TEST0("%.3%|\n");
	TEST0("%-.3%|\n");

	print_header(". flag with x");
	TEST("%.x\n", 0);
	TEST("%#.x\n", 0);
	TEST("%#.1x\n", 0);
	TEST("%#.2x\n", 0);
	TEST("%#.3x\n", 0);
	TEST("%.12x\n", 0);
	TEST("%#.12x\n", 0);
	TEST("%.12x\n", 555);
	TEST("%#.12x\n", 555);
	TEST("%.12x\n", -555);
	TEST("%#.12x\n", -555);
	TEST("%20.x\n", 0x1234abcdu);
	TEST("%3x\n", 0);

}


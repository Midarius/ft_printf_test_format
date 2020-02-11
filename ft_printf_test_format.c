#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef FANCY
#define TESTLINE ft_printf("\x1b[35m/---\x1b[0m \x1b[96m%03u\x1b[0m \x1b[35m---/\x1b[0m\n", __LINE__)
#else
#define TESTLINE ft_printf("/--- %03u ---/\n", __LINE__)
#endif

#ifndef EDGE
#define PRINTF_E(format, ...) PRINTF_M(format, __VA_ARGS__)
#else
#define PRINTF_E(format, ...) do {\
	TESTLINE;\
	printf("skipping (undefined behavior)\n");\
} while(0)
#endif

#define PRINTF_M(format, ...) do {\
	TESTLINE;\
	rtn = printf(format, __VA_ARGS__);\
	printf("   printf:\t%d\n", rtn);\
	rtn = ft_printf(format, __VA_ARGS__);\
	ft_printf("ft_printf:\t%d\n", rtn);\
} while(0)

int	ft_printf(const char *format, ...);

int	main(void)
{
	int rtn;
	int a = 0;
	int *p_a = &a;

	PRINTF_M("Test: %d %5.2s end %c %p\n", 0, "NULL", 'a', (void*)p_a);
	PRINTF_M("%-6s%s", "Hello", "World!\n");
	PRINTF_M("test %-12i et %--2.4s %24s !\n", 0, NULL, "coco");
	PRINTF_M("%x\t%X\n", 65535, 65535);
	PRINTF_M("%x->%X\n", 0x123abc, 0x123abc);
	PRINTF_M("UINT_MAX: %u %x\n", UINT_MAX, UINT_MAX);
	PRINTF_M("%%%s%5%\n", "string");
	PRINTF_M("test NULL -> %s\n", NULL);
	PRINTF_M("Numbers with spaces %05d %4i %-3uend\n", 24, 32, 84);
	PRINTF_M("void: %.d\n", 0);
	PRINTF_M("void2: %.2d\n", 2);
	PRINTF_M("void3: %.1x\n", 0);
	PRINTF_M("void u: %4.u\n", 0);
	PRINTF_M("test precision %04.5d\n", 248);
	PRINTF_M("test precision2 %6.5d\n", 248);
	PRINTF_M("test precision3 %.1d\n", 0);
	PRINTF_M("test precision4 %.8s\n", "Hello World!\n");
	PRINTF_M("test char* %*.*s\n", 9, 8, "Hello World!\n");
	PRINTF_M("one hex number: %x\n", 5);
	PRINTF_M("one hex number2: %x\n", 11);
	PRINTF_M("nostring%.s\n", NULL);
	PRINTF_M("neg: %.*d\n", -1, 1);
	PRINTF_M("%6p\n", (void *)100);
	PRINTF_M("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20);
	PRINTF_M("ptr: %4p\n", (void *)0x0);
	PRINTF_M("ptr: %4p\n", (void *)0xb);
	PRINTF_M("color :D \x1B[32m%s\x1b[0m\n", "paradise");
	PRINTF_M("negative spaces %-5u %*x\n", 25, -5, 25);
	PRINTF_M("negative2 <%------4d>\n", 112);
	PRINTF_M("_c; %c %5c %-5c %4c %*c %*c %.c\n", 'a', 'b', 'c', 'd', 5, 'e', -5, 'f', 'g');
	PRINTF_M("test \\0: %c next\n", '\0');
	PRINTF_M("test2 \\0: %5c next\n", '\0');
	PRINTF_M("%%*s neg: <%*s>\n", -10, "Hello!");
	PRINTF_M("%%7.5i %%05i %7.5i %05i\n", -5, -5);
	PRINTF_M("%%07.5i %%05.7i %07.5i %05.7i %07.5i %05.7i\n", -3, -3, 3, 3);
	PRINTF_M("neg0space: <%0*i>\n", -20, 35);
	PRINTF_M("%%7.5x %%05x %7.5x %05x\n", -5, -5);
	PRINTF_M("%%07.5x %%05.7x %07.5x %05.7x %07.5x %05.7x\n", -3, -3, 3, 3);
	PRINTF_M("UTF-8: é, %s %s %5s\n", "è", "à", "á");
	PRINTF_M("UTF-8 2: %s\n", "\xF0\x9F\x98\x80 \U0001F600 \U0001F602");
	PRINTF_M("main: %p %16p %-16p %.p\n", main, main, main, main);
	// PRINTF_M(NULL, NULL);
	PRINTF_M("%-.00s", "test"); // return 0 because "%.0s"
	PRINTF_M("%-.000000000000000000s", "test2"); // also works
	// PRINTF_M("ptr precision: %.5p", 0); undefined
	PRINTF_M("void4: %.p\n", NULL);
	PRINTF_M("%0*i\n", -7, -54); // Only print left-justify spaces
	PRINTF_M("test trailing: %0000000000000000000000008d %------------------------5s %.0000000000000000000001s\n", 32, NULL, NULL);
	PRINTF_E("%000000000000000000-----0---0--0--0-0-5d", 5);
	PRINTF_M("bignumber: %d %u\n", -465456546, 888888888);
	PRINTF_M("%d %d %u %u\n", 0, -1, 0, -1);
	PRINTF_M("%19.*siuFsM%%%018.*uTgRWZd\n", -7, NULL, -9, -2147483647);
	PRINTF_M("NK4P0LvPY%.2s%-.*i", NULL, 10, -149706742);
	PRINTF_M("pNULL: %.p", (void*)5);
	return (0);
}

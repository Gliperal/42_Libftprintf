#include <stdio.h>

int main()
{
	/* Format string tests */

	printf("[%d]\n", 42);
	printf("[%+d]\n", 42);
	printf("[%10d]\n", 42);
	printf("[%-10d]\n", 42);
	printf("[%.10d]\n", 42);
	printf("[% .10d]\n", 42);
	printf("[%10.4d]\n", 42);
	printf("[%-10.4d]\n", 42);

	printf("[%hhd]\n", 2090);
	printf("[% hhd]\n", 2090);
	printf("[%9hhd]\n", 2090);
	printf("[%010hhd]\n", 2090);
	printf("[%.9hhd]\n", 2090);
	printf("[%-.10hhd]\n", 2090);
	printf("[%10.4hhd]\n", 2090);
	printf("[%+20.10hhd]\n", 2090);

	// Flags overriding flags
	// More than one of the same flag
	// negative arg field width overriding flags
	// Are zeros allowed to start positional arguments or non-positional precision?
	// Throw some special characters in the string that aren't part of a format argument
	// I'm just not gonna worry about fied width / precision above INT_MAX - 1 (2147483646)
	// Specific flag tests
	// default precision for floats = 6
	// plus at the end of a number
	// field width / flags / precision on %
	// strings with a null terminator in the middle (use precision)

	/* Flag tests */
	/* the default printf doesn't seem to be able to use appostrophe correctly */

	printf("[%#-+'#-+'10.2f]\n", (double) 4242);
	printf("[%.0f]\n", 42.1234567);
	printf("[%f]\n", 42.1234567);

	/* Accessed arg tests */

	printf("[%1$d,%2$d]\n", 4, 2);
	printf("[%2$d,%1$d]\n", 2, 4);
	printf("[%1$c,%1$c]\n", 'a');
	// Accessed field width and precision

//	printf("[%18446744073709551615d]\n", 1);
//	printf("[%9750000000000000000d]\n", 1);

}

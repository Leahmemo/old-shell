#include "main.h"

int man_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int result = 0;
	char prefix[] = "[Custom Prefix] ";

	while (*format != '\0') 
	{
		if (*format == '\n') 
	{
		result += vprintf("%s", prefix);
	}
	result += vprintf("%c", *format);
	format++;
	}

	va_end(args);
	return (result);
}


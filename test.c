#include "main.h"

int main(void)
{
	 char name[6] = "paula";
    char n = 'A';
    _add("this should work\n");
    _add("%c\n", 'K');
    _add("%%");
    _add("%s\n", "this is a string");
    _add("%s code is top-notch %c-level\nI'll give 100%%", name, n);
    return 0;
}

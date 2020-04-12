#include <unistd.h>

extern int mx_strlen(const char *s);

void mx_printstr(const char *s){
	size_t str_size = mx_strlen(s);

	write(1, s, str_size);
}

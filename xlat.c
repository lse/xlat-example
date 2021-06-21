#include <stdio.h>
#include <stddef.h>
#include <elf.h>

#define XLAT(val)	{ (size_t)(val), #val }
#define XLAT_END	{ 0, 0 }

struct xlat {
	size_t      value;
	const char *string;
};

struct xlat xlat_e_version[] = {
	XLAT(EV_NONE),
	XLAT(EV_CURRENT),
	XLAT(EV_NUM),
	XLAT_END,
};

const char *xlat_get(struct xlat xlat[], size_t val, const char *def) {
	for (; xlat->string; ++xlat) {
		if (xlat->value == val)
			return xlat->string;
	}
	return def;
}

int main(void) {
	printf("enum string: %s\n", xlat_get(xlat_e_version, 2, NULL));
	printf("enum string: %s\n", xlat_get(xlat_e_version, 6, NULL));
	return 0;
}

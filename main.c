#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal_help() {
		printf("help:\n");
		printf("  ccal add/a\n");
		printf("  ccal list/l\n");
}

typedef struct str_t {
	char* buf;
	int len;
} str_t;

void get_str(str_t* sv, int cap) {
	int i = 0;
	while (1) {
		char c = getc(stdin);
		if (c == '\n') { break; }
		sv->buf[i] = c;
		i++;
		if (i >= cap) { break; }
	}
	sv->len = i;
}

#define SVFMT "%.*s"
#define SVARG(_sv) (_sv).len, (_sv).buf

int main(int argc, char** argv) {

	if (argc != 2) {
		cal_help();
		return 0;
	}

	char* arg = argv[1];

	if (!strcmp(arg, "a") || !strcmp(arg, "add")) {
		printf("ADDING\n");
		printf("name:\n");
		char name[1024];
		char pfc[1024];
		str_t svname = {name,0};
		str_t svpfc = {pfc,0};
		get_str(&svname, 1024);
		printf(SVFMT"\n", SVARG(svname));
		get_str(&svpfc, 1024);
		printf(SVFMT"\n", SVARG(svpfc));
	}

	if (!strcmp(arg, "l") || !strcmp(arg, "list")) {
		printf("LIST\n");
	}

	return 0;
}

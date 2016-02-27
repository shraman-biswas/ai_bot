#include "main.h"

int main(int argc, char **argv)
{
	char line[LEN], *u1=NULL, *u2=NULL, *m1=NULL, *m2=NULL;
	int cnt=0;
	FILE *fp;

	printf("[ ai bot ]\n");

	/* setup memory - open memory file */
	fp = fopen("mem.txt", "a+");
	if (fp == NULL)
		return EXIT_FAILURE;

	/* teaching process */
	if (argc > 2) {
		u1 = str_upper(argv[1]);
		u2 = str_upper(argv[2]);
	} else {
		fprintf(stderr, "no input provided!\n");
		disp_usage(argv[0]);
		return EXIT_FAILURE;
	}

	/* access memory - scan thorugh memory file */
	while (fgets(line, LEN, fp) != NULL) {
		line[strlen(line) - 1] = '\0';
		m1 = line;
		m2 = strchr(line, ' ');
		*m2++ = '\0';

		/* play process - access memory and make inferences*/
		if ((strncmp(u1, m1, LEN) == 0) && (strncmp(u2, m2, LEN) == 0))
			cnt++;
		if ((strncmp(u1, m1, LEN) != 0) && (strncmp(u2, m2, LEN) == 0))
			printf("%s %s, LIKE %s\n", u1, u2, m1);
		if (strncmp(u2, m1, LEN) == 0)
			printf("%s %s, SO %s %s\n", u1, u2, u1, m2);
	}

	/* learning process - store new information into memory */
	if (cnt == 0)
		fprintf(fp, "%s %s\n", u1, u2);

	fclose(fp);

	return EXIT_SUCCESS;
}

/* converts a string to uppercase */
static char *str_upper(char *str)
{
	char *p;
	for (p=str; *p; p++)
		*p = toupper(*p);
	return str;
}

/* displays the usage description */
static void disp_usage(const char *const str)
{
	printf("usage: %s word1 word2\n", str);
	printf("\tword1: noun\n\tword2: verb/noun\n");
	printf("example: %s cat animal\n", str);
}

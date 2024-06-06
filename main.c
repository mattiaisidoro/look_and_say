#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdint.h>
#include<stdio.h>

int look_and_say(char *n) {
	char num = n[0]; // sicuramente primo numero che leggo
	int count = 1;
	int res = 0;
	int i;
	int k = 0;
	int len = strlen(n);
	if (len == 1) {
		res = res + 1;
		res = res * 10;
		res = res + num-48;

	}
	else {
		for (i = 1; i < len; i++) {
			res = res * 10;
			while (1) {
				if (num == n[k + i]) {
					count++;
					k++;
				}
				else {
					i = i + k - 1;
					k = 1;
					break;
				}
			}
			res = res + count;
			res = res * 10;
			res = res + (num - 48);

			num = n[i + 1];
			count = 1;
		}
	}
	printf("%d", res);
	return res;
}





int main(void) {
	int numero = 1;
	int interazione = 5;
	char buffer[255];
	sprintf(buffer, "%d", numero);
	for (int i = 0; i < interazione; i++) {
		printf("\n");
		int newnumber = look_and_say(buffer);
		memset(buffer, 0, sizeof(buffer));
		sprintf(buffer, "%d", newnumber);
	}

	return 0;
}
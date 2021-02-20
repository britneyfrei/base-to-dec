#include <stdio.h>

int main(int argc, char *argv[]) {
	// check number of arguments
	if (argc != 3) {
		printf("Usage: ./dec <number> <base>\n");
		return 1;
	}	

	// save the number in an easier-to-use variable
	char *number = argv[1];
	char *base = argv[2];

	// get length of base
	int blen = 0;
	while (base[blen] != 0) {
		blen++;
	}
	// get base
	int b = 0;
	if (blen == 1) {
		b = *base - 48;
	}
	else {
		b = ((base[0] - 48) * 10) + (base[1] - 48);
	}
	
	// show an error if base is outside bounds
	if ((b < 2) || (b > 36)) {
		printf("INVALID BASE\n");
		return 1;
	}

	// find length of number
	int nlen = 0;
	while (number[nlen] != 0) {
		nlen++;
	}

	// calculate the decimal number of the given value
	int result = 0;
	int dec;
	int counter = 0;
	nlen = nlen - 1;
	while (nlen >= 0) {
		if (number[nlen] <= 57) {
			dec = number[nlen] - 48;
		}
		else {
			dec = number[nlen] - 55;
		}
		if (dec >= b) {
			printf("INVALID VALUE\n");
			return 1;
		}
		int pwr = counter;
		counter++;
		int pwrsum = 1;
		while (pwr != 0) {
			pwrsum = pwrsum * b;
			pwr--;
		}
		result = result + (dec * pwrsum);
		nlen--;
	}

	// print the result
	printf("%d\n", result);
	// program completed successfully, return 0
	return 0;
}

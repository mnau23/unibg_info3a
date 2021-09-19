#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* RESULT;

// *** Exercise 1 ***
/* NR: non recursive
 * s: string
 */
int hash_I(char *s) {
	int hash = 0;
	for(int i=0; s[i] != '\0'; i++) {
		//printf("ASCII value of %c = %d; position = %d\n", s[i], s[i], i+1);
		hash += s[i]*(i+1);
	}
	return hash;
}

/* R: recursive without tail recursion
 * s: string
 * w: weight of the first character in the string s
 */
int hash_R(char* s, int w) {
	if(*s == '\0')
		return 0;
	return (*s)*w + hash_R(s+1, w+1);
}

int hash_R_Call(char *s) {
	return hash_R(s, 1);
}

/* TR: recursive with tail recursion
 * s: string
 * w: weight of the first character in the string s
 * h: hash computed up to that point
*/
int hash_TR(char* s, int w, int h) {
	if(*s == '\0')
		return h;
	return hash_TR(s+1, w+1, h+(*s)*w);
}

int hash_TR_Call(char *s) {
	return hash_TR(s, 1, 0);
}


// *** Exercise 2 ***
// NR: non recursive
int sumEvenNums_I(int a[], int n) {
	int res = 0;
	for(int i=0; i < n; i++) {
		if(a[i]%2 == 0)
			res += a[i];
	}
	return res;
}

// R: recursive without tail recursion
int sumEvenNums_R(int a[], int n) {
	if(n == 0)	// base
		return 0;
	// call
	int res = sumEvenNums_R(a+1, n-1);
	return res + ((a[0]%2 == 0) ? *a : 0);
}

// TR: recursive with tail recursion
int sumEvenNums_TR(int a[], int n, int sum) {
	if(n == 0) // base
		return sum;
	if(a[0]%2 == 0) // call
		return sumEvenNums_TR(a+1, n-1, sum+*a);
	else
		return sumEvenNums_TR(a+1, n-1, sum);
}

int sumEvenNums_TR_Call(int a[], int n) {
	return sumEvenNums_TR(a, n, 0);
}


// *** Exercise 3 ***
// NR: non recursive
bool palindrome_I(char str[]) {
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int r = strlen(str)-1;
    // Keep comparing characters while they are same
    while (r > l) {
        if(str[l++] != str[r--])
            return false;
    }
    return true;
}

// R: recursive without tail recursion
bool palindrome_R(char str[], int l, int r) {
	// If there are more than two characters, check if
	// middle substring is also palindrome or not.
	if (l < r+1)
		return str[l] == str[r] && palindrome_R(str, l+1, r-1);
	return true;
}

bool palindrome_R_Call(char str[]) {
	int n = strlen(str);
	// An empty string is considered as palindrome
	if(n == 0)
		return true;
	return palindrome_R(str, 0, n-1);
}

// TR: recursive with tail recursion
bool palindrome_TR(char str[], int s, int e) {
	// If there is only one character
	if(s == e)
		return true;
	// If first and last characters do not match
	if(str[s] != str[e])
		return false;
	// If there are more than two characters, check if
	// middle substring is also palindrome or not.
	if(s < e+1)
		return palindrome_TR(str, s+1, e-1);
	return true;
}

bool palindrome_TR_Call(char str[]) {
	int n = strlen(str);
	// An empty string is considered as palindrome
	if(n == 0)
		return true;
	return palindrome_TR(str, 0, n-1);
}

// *** Exercise 4 ***
int divisible_8(int n) {
	char str[10];
	sprintf(str, "%d", n);
	int digits = strlen(str);

	// If n ends with 3 zeros, it is divisible by 8
	if(str[digits-1] == 0 && str[digits-2] == 0 && str[digits-3] == 0)
		return 1;

	if(digits > 3) {
		char str3[3];
		str3[3] = '\0';
		str3[2] = str[digits-1];
		str3[1] = str[digits-2];
		str3[0] = str[digits-3];
		return divisible_8(atoi(str3));
	} else {
		if(n%8 == 0) return 1;
		else return 0;
	}
}


// *** Exercise 5 ***
int divisible_7(int n) {
	int num = n;
	int digits = 0;

	// Count the digits of n
	do {
		digits++;
		num /= 10;
	} while(num != 0);

	if(digits > 2) {
		int all_but_unit = n/10;
		int unit = n%10;
		int diff = all_but_unit - 2*unit;
		if(diff == 0 || diff == 7)
			return 1;
		return divisible_7(diff);
	} else {
		if(n%7 == 0) return 1;
		else return 0;
	}
}


// *** Exercise 6 ***
void pointer_Int(int **p) {
	**p += 1;
}

void pointer_String(char **p) {
	**p = 'A';
}

void sum(int x, int y, int *z) {
	// In C, pass-by-reference is simulated
	// by passing the address of a variable
	*z = x + y;
}


// *** Exercise 7 ***
// NR: non recursive
char* vocalizza_I(char* str) {
	char* buff = (char*) malloc((strlen(str)+1)*sizeof(char));
	int i = 0, j = 0;
	while(str[i]) {
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			buff[j] = str[i];
			i++;
			j++;
		}else {
			i++;
		}
	}
	buff[j] = '\0';
	return buff;
}

// NR: non recursive
char* vocalizza_I_pointer(char* str) {
	char* buff = (char*) malloc((strlen(str)+1)*sizeof(char));
	int j = 0;
	while(*str != '\0') {
		if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
			//printf("Vocal: %c\n", *str);
			buff[j] = *str;
			j++;
		}
		str++;
	}
	buff[j] = '\0';
	return buff;
}

/* R: recursive without tail recursion
 * and freeing of memory
 */
char* vocalizza_R(char* str) {
	if(!str[0]) {
		char* b = (char*) malloc(sizeof(char));
		*b = '\0';
		return b;
	}
	char* r = vocalizza_R(str+1);
	if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
		char* b = (char*) malloc((strlen(r)+2)*sizeof(char));
		sprintf(b, "%c%s", str[0], r);
		free(r);
		return b;
	} else {
		return r;
	}
}

// TR: recursive with tail recursion
char* vocalizza_TR(char* str, char* buff, int j) {
	if(!str[0]) {
		buff[j] = '\0';
		return buff;
	}
	if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
		buff[j] = *str;
		return vocalizza_TR(str+1, buff, j+1);
	} else {
		return vocalizza_TR(str+1, buff, j);
	}
}


// Main
int main() {
	// *** Exercise 1 ***
	printf("\n---Exercise 1---\n");
	char name[] = "anna";
	printf("Hash iterative: %d\n", hash_I(name));
	printf("Hash recursive without TR: %d\n", hash_R_Call(name));
	printf("Hash recursive with TR: %d\n", hash_TR_Call(name));

	// *** Exercise 2 ***
	printf("\n---Exercise 2---\n");
	int numbers[] = {1,2,3,4,5,6};
	printf("Non recursive: %d\n", sumEvenNums_I(numbers, sizeof(numbers)/sizeof(int)));
	printf("Recursive without TR: %d\n", sumEvenNums_R(numbers, sizeof(numbers)/sizeof(int)));
	printf("Recursive with TR: %d\n", sumEvenNums_TR_Call(numbers, sizeof(numbers)/sizeof(int)));

	// *** Exercise 3 ***
	printf("\n---Exercise 3---\n");
	char string1[] = "abba";
	char string2[] = "nope";
	// NR: non recursive
	if(palindrome_I(string1))
		printf("String '%s' is palindrome. Method: NR.\n", string1);
	else
		printf("String '%s' is not palindrome. Method: NR.\n", string1);
	// R: recursive without tail recursion
	if(palindrome_R_Call(string2))
		printf("String '%s' is palindrome. Method: R.\n", string2);
	else
		printf("String '%s' is not palindrome. Method: R.\n", string2);
	// TR: recursive with tail recursion
	if(palindrome_TR_Call(string2))
		printf("String '%s' is palindrome. Method: TR.\n", string2);
	else
		printf("String '%s' is not palindrome. Method: TR.\n", string2);

	// *** Exercise 4 ***
	printf("\n---Exercise 4---\n");
	int x1 = 7408;		// digits>3, divisible by 8
	int x2 = 8000;		// digits>3, divisible by 8
	int x3 = 9932;		// digits>3, not divisible by 8
	int y1 = 888;		// digits=3, divisible by 8
	int y2 = 567;		// digits=3, not divisible by 8
	printf("Variable x1: %d\n", divisible_8(x1));
	printf("Variable x2: %d\n", divisible_8(x2));
	printf("Variable x3: %d\n", divisible_8(x3));
	printf("Variable y1: %d\n", divisible_8(y1));
	printf("Variable y2: %d\n", divisible_8(y2));

	// *** Exercise 5 ***
	printf("\n---Exercise 5---\n");
	int z1 = 147;		// digits>2, diff=0 > divisible by 7
	int z2 = 217;		// digits>2, diff=7 > divisible by 7
	int z3 = 945;		// digits>2, diff!=0 and diff!=7, diff%7=0 > divisible by 7
	int t1 = 243;		// digits>2, diff!=0 and diff!=7, diff%7!=0 > not divisible by 7
	int t2 = 36;		// digits=2, n%7!=0 > not divisible by 7
	printf("Variable z1: %d\n", divisible_7(z1));
	printf("Variable z2: %d\n", divisible_7(z2));
	printf("Variable z3: %d\n", divisible_7(z3));
	printf("Variable t1: %d\n", divisible_7(t1));
	printf("Variable t2: %d\n", divisible_7(t2));

	// *** Exercise 6 ***
	printf("\n---Exercise 6---\n");
	// pointer to an integer
	int val = 48;
	int *p1 = &val;
	printf("Before: %d\n", *p1);
	pointer_Int(&p1);
	printf("After: %d\n", *p1);
	// pointer to an array
	char s1[] = "Hello";
	char *c = s1;
	printf("Before: %s\n", c);
	pointer_String(&c);
	printf("After: %s\n", c);
	// pass-by-reference
	int z;
	sum(3, 4, &z);
	printf("Sum: %d\n", z);

	// *** Exercise 7 ***
	printf("\n---Exercise 7---\n");
	char str[] = "exercise";
	printf("Initial string: %s\n", str);
	// NR: non recursive
	RESULT = vocalizza_I(str);
	printf("Iterative: %s\n", RESULT);
	free(RESULT);
	// NR: non recursive
	RESULT = vocalizza_I_pointer(str);
	printf("Iterative (with pointer): %s\n", RESULT);
	free(RESULT);
	// R: recursive without tail recursion
	RESULT = vocalizza_R(str);
	printf("Recursion: %s\n", RESULT);
	free(RESULT);
	char* buff = (char*) malloc((strlen(str)+1)*sizeof(char));
	// TR: recursive with tail recursion
	RESULT = vocalizza_TR(str, buff, 0);
	printf("Tail recursion: %s\n", RESULT);
	free(RESULT);

	/* Nel caso della TR si può riutilizzare sempre la stessa
	 * area di memoria invece di creare nuovi record di attivazione.
	 * Questo comporta un grande risparmio di memoria ed è dovuto al fatto che
	 * ad ogni ciclo il RRA punta direttamente alla locazione di memoria in cui
	 * la funzione è invocata per la prima volta.
	 */
	//free(buff);

	return EXIT_SUCCESS;
}

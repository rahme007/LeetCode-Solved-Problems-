//The approach is to first to find the mid of the string using two-pointer approach. 
//Then, traverse each of the half string to check if the characters match with the vowels. 
//Subsequently count the number of vowels for each sub string.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char* findMid(char* s) {
	char* slow = s;
	char* fast = s;

	while (*fast != '\0') {
		slow++;
		fast += 2;
	}
	return slow;
}

bool halvesAreAlike(char* s) {

	char* b = findMid(s); // to divide the string into half

	int countFirst = 0, countSecond = 0;
	char vowels[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	// first half traversal
	while (s != b) {
		for (int i = 0; i < 10; i++) {
			if (*s == vowels[i]) {
				countFirst++;
			}
		}
		s++;
	}
	// Second half traversal
	while (*b != '\0') {
		for (int i = 0; i < 10; i++) {
			if (*b == vowels[i]) {
				countSecond++;
			}
		}
		b++;
	}

	return (countFirst== countSecond);
}



int main() {

	char* s = "book"; //"textbook"; //"tkPAdxpMfJiltOerItiv";
	bool isAlike = halvesAreAlike(s);

	isAlike== 1 ? printf("True\n") : printf("False\n");
	return 0;
}
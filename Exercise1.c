/*
1. Input a maximum 4-digit integer n. Write a program to read the number n.
 ________________________________________________
| Input: 1234                                    |
| Output: "one thousand two hundred thirty four" |
|________________________________________________|
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ex1(char *testcase) {
	int len = strlen(testcase);
	char *single_digit[] = { "zero", "one", "two", "three", "four","five", "six", "seven", "eight", "nine"};
	char *tens_place[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety"};
	char *tens_power[] = {"hundred", "thousand"};
	if (len == 1) {
		printf("%s\n", single_digit[*testcase - '0']);
		return;
	}
	while (*testcase != '\0') {
		if (len >= 3) {
			if (*testcase -'0' != 0) {
				printf("%s ", single_digit[*testcase - '0']);
				printf("%s ", tens_power[len-3]); 
			}
         	--len;
	}
      else {
		if (*testcase == '1') {
			int sum = *testcase - '0' + *(testcase + 1)- '0';
			printf("%s\n", tens_place[sum]);
			return;
         }
         else if (*testcase == '2' && *(testcase + 1) == '0') {
			printf("twenty\n");
			return;
         }
         else {
		int i = *testcase - '0';
		printf("%s ", i? tens_multiple[i]: "");
		++testcase;
		if (*testcase != '0')
		printf("%s ", single_digit[*testcase - '0']);
         }
      }
      ++testcase;
   }
}
int main() {
   char *testcase = 1234;
   ex1(testcase);
   return 0;
}

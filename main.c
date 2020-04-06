#include <stdio.h>
#include "fibonacci.h"


int main(int argc, char const *argv[])
{
	int n = 154;

	// Print n first fibonacci numbers
	for (int i = 0; i < n; i++)
	{
		// For fibonacci_recursive_1 (i + 1) is used as argument to match printing output of both functions since,  
		// fibonacci_iterative(0), fibonacci_recursive_1(1)...
		printf("Fibonacci_iterative/recursive[%d]: \
			%llu / %llu\n", i, fibonacci_iterative(i), fibonacci_recursive_1(i + 1));
	}
}
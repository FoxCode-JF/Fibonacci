/*

Treść zadania:

**Zadanie - Ciągi Fibonacciego**Zaimplementuj rekurencyjną i iteracyjną wersję ciągu Fibonacciego w dowolnym języku.
Funkcja powinna zachowywać się zgodnie z poniższymi regułami:

fib(n) = fib(n-1) + fib(n-2) → for n > 1
fib(n) = 1→ for n = 0, 1

Napisz testy, omów oba rozwiązania i uzasadnij dlaczego jedna z postaci nie zawsze poradzi sobie dobrze z obliczeniem wyniku dla dla wartości n > 100

*/
#include <stdio.h>
#include "fibonacci.h"


/**
 * Fibonacci iterative algorithm:
 * First two numbers are assumed to be 1,
 * Next number is sum of current and previous number
 * Time complexity: O(n)
 * Space complexity: O(1) since only three numbers are stored at a time
 * @param n - fibonacci sequence number index
 * @return - nth fibonacci number
 */
unsigned long long int fibonacci_iterative(int n)
{
	unsigned long long int next = 0;
	unsigned long long int current = 1, prev = 0;

	if (n < 2) return 1;

	for (int i = 0; i < n; ++i)
	{
		next = current + prev;

		prev = current;
		current = next;
	}

	return current;
}

/**
 * Fibonacci recursive, simple algorithm:
 * First two numbers are assumed to be 1,
 * Uses simple recursion to calculate nth fibonacci number
 * Time complexity: O(2^n), not strictly bound
 * Space complexity: O(n), proportional to fibonacci number index
 * @param n - fibonacci sequence number index
 * @return - nth fibonacci number
 */
unsigned long long int fibonacci_recursive(int n)
{
	// Base case
	if (n < 2)
	{
		return 1;
	}else
	{	
		//returns sum of two numbers before nth number
		return fibonacci_recursive(n-2) + fibonacci_recursive(n-1);	
	}
}

/**
 * Fibonacci recursive, complex algorithm:
 * First two numbers are assumed to be 0, 1 for easier implementation.
 * Recursion with two different formulas for calculating odd and even indexes of fibonacci sequence
 * Time complexity: O(Log(n)), not strictly bound
 * Space complexity: O(n), proportional to fibonacci number index
 * @param n - fibonacci sequence number index
 * @return - nth fibonacci number
 */
unsigned long long int fibonacci_recursive_1(int n) 
{ 
    // Base case
    if (n == 0) 
        return 0; 
    if (n == 1 || n == 2) 
        return 1; 
  	
  	// Figure out if is odd or even using logical AND
  	// if n & 1 is odd k == 1, if n is even k == 0
    int k = (n & 1)? (n+1)/2 : n/2; 

	
	/*	
	If n is even then k = n/2:
	F(n) = [2*F(k-1) + F(k)]*F(k)

	If n is odd then k = (n + 1)/2
	F(n) = F(k)*F(k) + F(k-1)*F(k-1)
	*/
    return (n & 1)? (fibonacci_recursive_1(k)*fibonacci_recursive_1(k) + fibonacci_recursive_1(k-1)*fibonacci_recursive_1(k-1)) 
           : (2*fibonacci_recursive_1(k-1) + fibonacci_recursive_1(k))*fibonacci_recursive_1(k); 
} 

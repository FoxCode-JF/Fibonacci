#include <stdio.h>
#include "minunit.h"
#include "fibonacci.h"
#include "fibonacci-test.h"
 
 int main(int argc, char **argv) 
 {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    return result != 0;
 }

 
static char * all_tests() {

    // Iterative algorithm tests
    mu_run_test(test_fibonacci_iter_0);
    mu_run_test(test_fibonacci_iter_1);
    mu_run_test(test_fibonacci_iter_4);
    mu_run_test(test_fibonacci_iter_10);
    mu_run_test(test_fibonacci_iter_49);
    mu_run_test(test_fibonacci_iter_93);
    mu_run_test(test_fibonacci_iter_150);

    // Recursive algorithm tests
    mu_run_test(test_fibonacci_rec_1);
    mu_run_test(test_fibonacci_rec_2);
    mu_run_test(test_fibonacci_rec_5);
    mu_run_test(test_fibonacci_rec_11);
    mu_run_test(test_fibonacci_rec_50);
    mu_run_test(test_fibonacci_rec_94);
    mu_run_test(test_fibonacci_rec_151);
    return 0;
}
static char * test_fibonacci_iter_0() 
{
    mu_assert("error, fibonacci_iterative(0) != 1", fibonacci_iterative(0) == 1);

    return 0;
}
static char * test_fibonacci_iter_1() 
{
    mu_assert("error, fibonacci_iterative(1) != 1", fibonacci_iterative(0) == 1);   
    return 0;
}
static char * test_fibonacci_iter_4() 
{
    mu_assert("error, fibonacci_iterative(4) != 5", fibonacci_iterative(4) == 5);
    
    return 0;
}
static char * test_fibonacci_iter_10() 
{
    mu_assert("error, fibonacci_iterative(10) != 89", fibonacci_iterative(10) == 89);
    
    return 0;
}
static char * test_fibonacci_iter_49() 
{
    mu_assert("error, fibonacci_iterative(49) != 12586269025", fibonacci_iterative(49) == 12586269025);
    return 0;
}
static char * test_fibonacci_iter_93() 
{    
    // Tests below will pass with warning: integer constant is too large for its type
    // Biggest displayed number will be 2^64 = 18,446,744,073,709,551,615
    mu_assert("error, fibonacci_iterative(93) != 19740274219868223167", fibonacci_iterative(93) == 19740274219868223167);
    return 0;
}
static char * test_fibonacci_iter_150() 
{    
    // Tests below will pass with warning: integer constant is too large for its type
    // Biggest displayed number will be 2^64 = 18,446,744,073,709,551,615
    mu_assert("error, fibonacci_iterative(150) != 16130531424904581415797907386349", fibonacci_iterative(150) == 16130531424904581415797907386349);
    return 0;
}
static char * test_fibonacci_rec_1() 
{
    mu_assert("error, fibonacci_recursive_1(1) != 1", fibonacci_recursive_1(1) == 1);
    
    return 0;
}

static char * test_fibonacci_rec_2() 
{
    mu_assert("error, fibonacci_recursive_1(2) != 1", fibonacci_recursive_1(2) == 1);
    return 0;
}
static char * test_fibonacci_rec_5() 
{
    mu_assert("error, fibonacci_recursive_1(5) != 5", fibonacci_recursive_1(5) == 5);
    
    return 0;
}
static char * test_fibonacci_rec_11() 
{
    mu_assert("error, fibonacci_recursive_1(11) != 89", fibonacci_recursive_1(11) == 89);
    
    return 0;
}
static char * test_fibonacci_rec_50() 
{
    mu_assert("error, fibonacci_recursive_1(50) != 12586269025", fibonacci_recursive_1(50) == 12586269025);
    return 0;
}
static char * test_fibonacci_rec_94() 
{    
    // Tests below will pass with warning: integer constant is too large for its type
    // Biggest displayed number will be 2^64 = 18,446,744,073,709,551,615
    mu_assert("error, fibonacci_recursive_1(94) != 19740274219868223167", fibonacci_recursive_1(94) == 19740274219868223167);
    return 0;
}
static char * test_fibonacci_rec_151() 
{    
    // Tests below will pass with warning: integer constant is too large for its type
    // Biggest displayed number will be 2^64 = 18,446,744,073,709,551,615
    mu_assert("error, fibonacci_recursive_1(151) != 16130531424904581415797907386349", fibonacci_recursive_1(151) == 16130531424904581415797907386349);
    return 0;
}
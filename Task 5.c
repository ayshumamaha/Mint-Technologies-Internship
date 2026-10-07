#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * TASK 5
 * C Programming - Testing and Build-Ready Implementation
 *
 * Features:
 * 1. Addition
 * 2. Subtraction
 * 3. Multiplication
 * 4. Division
 * 5. Division-by-zero handling
 * 6. Automated test functions
 * 7. Test summary
 */

/* Function declarations */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide_numbers(double a, double b, int *error);

/* Test counters */
int tests_passed = 0;
int tests_failed = 0;


/* ---------------------------------------------------------
   Calculator Functions
   --------------------------------------------------------- */

int add(int a, int b)
{
    return a + b;
}


int subtract(int a, int b)
{
    return a - b;
}


int multiply(int a, int b)
{
    return a * b;
}


double divide_numbers(double a, double b, int *error)
{
    if (b == 0.0)
    {
        if (error != NULL)
        {
            *error = 1;
        }

        return 0.0;
    }

    if (error != NULL)
    {
        *error = 0;
    }

    return a / b;
}


/* ---------------------------------------------------------
   Integer Test Function
   --------------------------------------------------------- */

void test_integer(const char *test_name,
                  int expected,
                  int actual)
{
    if (expected == actual)
    {
        printf("[PASS] %s\n", test_name);
        tests_passed++;
    }
    else
    {
        printf("[FAIL] %s\n", test_name);
        printf("       Expected: %d\n", expected);
        printf("       Actual  : %d\n", actual);

        tests_failed++;
    }
}


/* ---------------------------------------------------------
   Floating-Point Test Function
   --------------------------------------------------------- */

void test_double(const char *test_name,
                 double expected,
                 double actual)
{
    double difference = fabs(expected - actual);

    if (difference < 0.000001)
    {
        printf("[PASS] %s\n", test_name);
        tests_passed++;
    }
    else
    {
        printf("[FAIL] %s\n", test_name);
        printf("       Expected: %.6f\n", expected);
        printf("       Actual  : %.6f\n", actual);

        tests_failed++;
    }
}


/* ---------------------------------------------------------
   Automated Test Suite
   --------------------------------------------------------- */

void run_tests(void)
{
    int error = 0;

    printf("\n");
    printf("========================================\n");
    printf("        AUTOMATED TEST SUITE\n");
    printf("========================================\n\n");


    /* Addition test */
    test_integer(
        "Addition Test",
        30,
        add(10, 20)
    );


    /* Subtraction test */
    test_integer(
        "Subtraction Test",
        10,
        subtract(20, 10)
    );


    /* Multiplication test */
    test_integer(
        "Multiplication Test",
        200,
        multiply(10, 20)
    );


    /* Division test */
    test_double(
        "Division Test",
        5.0,
        divide_numbers(10.0, 2.0, &error)
    );


    /* Division by zero */
    divide_numbers(10.0, 0.0, &error);

    test_integer(
        "Division by Zero Detection",
        1,
        error
    );


    /* Negative number test */
    test_integer(
        "Negative Addition Test",
        -10,
        add(-20, 10)
    );


    /* Zero test */
    test_integer(
        "Zero Multiplication Test",
        0,
        multiply(100, 0)
    );


    printf("\n========================================\n");
    printf("             TEST SUMMARY\n");
    printf("========================================\n");

    printf("Tests Passed : %d\n", tests_passed);
    printf("Tests Failed : %d\n", tests_failed);

    printf("========================================\n");

    if (tests_failed == 0)
    {
        printf("RESULT: ALL TESTS PASSED\n");
    }
    else
    {
        printf("RESULT: SOME TESTS FAILED\n");
    }
}


/* ---------------------------------------------------------
   Main Function
   --------------------------------------------------------- */

int main(void)
{
    printf("========================================\n");
    printf("       TASK 5 - C TESTING PROJECT\n");
    printf("========================================\n");

    printf("\nRunning calculator test suite...\n");

    run_tests();

    printf("\nProgram execution completed.\n");

    if (tests_failed == 0)
    {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
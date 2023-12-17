#include <CUnit/Basic.h>
#include "quotes.c"

void test_check_quotes(void) {
    // Redirect stdout to a buffer
    char buffer[1024];
    FILE* temp = stdout;
    stdout = fmemopen(buffer, 1024, "w");

    // Test 1: Double quotes are closed
    check_quotes("\"hello\"");
    fflush(stdout);
    CU_ASSERT_STRING_EQUAL(buffer, "Comillas dobles cerradas o no hay\nComillas simples cerradas o no hay\n");
    memset(buffer, 0, 1024);

    // Test 2: Single quotes are closed
    check_quotes("'hello'");
    fflush(stdout);
    CU_ASSERT_STRING_EQUAL(buffer, "Comillas dobles cerradas o no hay\nComillas simples cerradas o no hay\n");
    memset(buffer, 0, 1024);

    // Test 3: Double quotes are open
    check_quotes("\"hello");
    fflush(stdout);
    CU_ASSERT_STRING_EQUAL(buffer, "Comillas dobles abiertas\nComillas simples cerradas o no hay\n");
    memset(buffer, 0, 1024);

    // Test 4: Single quotes are open
    check_quotes("'hello");
    fflush(stdout);
    CU_ASSERT_STRING_EQUAL(buffer, "Comillas dobles cerradas o no hay\nComillas simples abiertas\n");
    memset(buffer, 0, 1024);

    // Test 5: Mixed quotes
    check_quotes("\"hol'\"");
    fflush(stdout);
    CU_ASSERT_STRING_EQUAL(buffer, "Comillas dobles cerradas o no hay\nComillas simples cerradas o no hay\n");
    memset(buffer, 0, 1024);

    // Restore stdout
    fclose(stdout);
    stdout = temp;
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("check_quotes_test", 0, 0);

    CU_add_test(suite, "test_check_quotes", test_check_quotes);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
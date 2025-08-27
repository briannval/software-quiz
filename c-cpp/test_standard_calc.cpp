#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_basic1(CuTest *tc) {
    CuAssertDblEquals(tc, 0.0, bound_to_180(0.0f), 0.0001);
    CuAssertDblEquals(tc, 0.0, bound_to_180(0), 0.0001);

    CuAssertDblEquals(tc, -180.0, bound_to_180(180.0f), 0.0001);
    CuAssertDblEquals(tc, 30.0, bound_to_180(30.0f), 0.0001);
    CuAssertDblEquals(tc, -90.0, bound_to_180(270.0f), 0.0001);
    CuAssertDblEquals(tc, 175.0, bound_to_180(8815.0f), 0.0001);

    CuAssertDblEquals(tc, 179.5, bound_to_180(179.5f), 0.0001);
    CuAssertDblEquals(tc, 179.99999, bound_to_180(179.99999f), 0.0001);

    CuAssertDblEquals(tc, -180.0, bound_to_180(-180.0f), 0.0001);
    CuAssertDblEquals(tc, 179.0, bound_to_180(-181.0f), 0.0001);
    CuAssertDblEquals(tc, -179.0, bound_to_180(-179.0f), 0.0001);

    CuAssertDblEquals(tc, 179.0, bound_to_180(179.0f), 0.0001);
    CuAssertDblEquals(tc, -180.0, bound_to_180(-180.0f), 0.0001);
    CuAssertDblEquals(tc, 0.0, bound_to_180(360000000.0f), 0.0001);
}

/**************** Tests for is_angle_between() *******************/
void test_between_basic1(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(0.0f, 1.0f, 2.0f));

    CuAssertTrue(tc, is_angle_between(1.0f, 1.0f, 2.0f));
    CuAssertTrue(tc, is_angle_between(1.0f, 2.0f, 2.0f));
    CuAssertTrue(tc, is_angle_between(170.0f, -170.0f, -170.0f));
    CuAssertTrue(tc, is_angle_between(179.9999f, 180.0f, -179.9999f));

    CuAssertTrue(tc, is_angle_between(0.0f, 450.0f, -180.0f));
    CuAssertTrue(tc, is_angle_between(1080.0f, 67890029.0f, 1260.0f));

    CuAssertTrue(tc, !is_angle_between(45.0f, 90.0f, 270.0f));
    CuAssertTrue(tc, !is_angle_between(10.0f, 50.0f, 350.0f));
    CuAssertTrue(tc, !is_angle_between(-170.0f, 0.0f, 170.0f));
    CuAssertTrue(tc, !is_angle_between(170.0f, -90.0f, -170.0f));

    CuAssertTrue(tc, is_angle_between(10.0f, 0.0f, 350.0f));
    CuAssertTrue(tc, is_angle_between(80.0f, 90.0f, -170.0f));
    CuAssertTrue(tc, is_angle_between(-170.0f, 180.0f, 170.0f));
    CuAssertTrue(tc, is_angle_between(-150.0f, 160.0f, 150.0f));
    CuAssertTrue(tc, is_angle_between(-150.0f, -160.0f, 150.0f));
    CuAssertTrue(tc, is_angle_between(181.95f, 180.721f, 179.44f));

    CuAssertTrue(tc, !is_angle_between(0.0f, 192.0f, 270.0f));
    CuAssertTrue(tc, !is_angle_between(0.0f, 200.0f, 359.0f));
}

int main(int argc, char const *argv[]) {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_basic1);
    SUITE_ADD_TEST(suite, test_between_basic1);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}

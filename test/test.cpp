#include <test.h>

void TestJson::signaled(void)
{
    mCount++;
}

QTEST_MAIN(TestJson)

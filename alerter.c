#include <stdio.h>
#include <assert.h>

extern void test_alerter(void);

int alertFailureCount = 0;

int GetalertFailureCount(void)
{
    return alertFailureCount;
}

void alertInCelcius(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    test_alerter();
    return 0;
}

#include <stdio.h>
#include <assert.h>

extern void alertInCelcius(float farenheit);
extern int GetalertFailureCount(void);
extern int networkAlertStub(float celcius);

int networkAlert(float celcius)
{
    return networkAlertStub(celcius);
}

int networkAlertStub(float celcius)
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void test_alerter(void)
{
    assert(GetalertFailureCount() == 0);
    alertInCelcius(392);
    assert(GetalertFailureCount() == 0);
    alertInCelcius(400.5);
    assert(GetalertFailureCount() == 1);
    alertInCelcius(303.6);
    assert(GetalertFailureCount() == 2);
    alertInCelcius(392);
    assert(GetalertFailureCount() == 2);
    printf("%d alerts failed.\n", GetalertFailureCount());
    printf("All is well (maybe!)\n");
}

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

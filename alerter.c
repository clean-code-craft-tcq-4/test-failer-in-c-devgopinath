#include <stdio.h>
#include <assert.h>

extern void alertInCelcius(float farenheit);
extern int GetalertFailureCount(void);
extern int networkAlertStub(float celcius);

#define TEMPERATURE_LIMIT_IN_C 201.0

int networkAlert(float celcius)
{
    return networkAlertStub(celcius);
}

int networkAlertStub(float celcius)
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);

    if (celcius < TEMPERATURE_LIMIT_IN_C)
    {
        // Return 200 for ok
        return 200;
    }
    else
    {
        // Return 500 for not-ok
        return 500;
    }
}

void test_alerter(void)
{
    assert(GetalertFailureCount() == 0);
    alertInCelcius(392);
    assert(GetalertFailureCount() == 0);
    alertInCelcius(400.5);
    assert(GetalertFailureCount() == 1);
    alertInCelcius(303.6);
    assert(GetalertFailureCount() == 1);
    alertInCelcius(393.8);
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
    if (returnCode != 200)
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    test_alerter();
    return 0;
}

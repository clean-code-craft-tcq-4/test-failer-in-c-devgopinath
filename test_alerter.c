#include <stdio.h>
#include <assert.h>

extern void alertInCelcius(float farenheit);
extern int GetalertFailureCount(void);

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

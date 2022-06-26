#include <stdio.h>
#include <assert.h>

#define DEFAULT_SIZE_NULL   ('\0')
#define CLASSIFY_SHIRT_NAME_SHORT   ('S')
#define CLASSIFY_SHIRT_NAME_MEDIUM   ('M')
#define CLASSIFY_SHIRT_NAME_LARGE   ('L')

#define MIN_SHIRT_SIZE  MIN_SHIRT_SIZE_S
#define MAX_SHIRT_SIZE  MAX_SHIRT_SIZE_L

#define MIN_SHIRT_SIZE_S    34
#define MAX_SHIRT_SIZE_S    38

#define MIN_SHIRT_SIZE_M    39
#define MAX_SHIRT_SIZE_M    42

#define MIN_SHIRT_SIZE_L    43
#define MAX_SHIRT_SIZE_L    45

char getShirtSizeName(int shirtSizeInCms)
{
    char sizeName = DEFAULT_SIZE_NULL;

    if (shirtSizeInCms < MIN_SHIRT_SIZE)
    {
        /* not classified, return default */
    }
    else if ((shirtSizeInCms >= MIN_SHIRT_SIZE_S) && (shirtSizeInCms <= MAX_SHIRT_SIZE_S))
    {
        sizeName = CLASSIFY_SHIRT_NAME_SHORT;
    }
    else if ((shirtSizeInCms >= MIN_SHIRT_SIZE_M) && (shirtSizeInCms <= MAX_SHIRT_SIZE_M))
    {
        sizeName = CLASSIFY_SHIRT_NAME_MEDIUM;
    }
    else if ((shirtSizeInCms >= MIN_SHIRT_SIZE_L) && (shirtSizeInCms <= MAX_SHIRT_SIZE_L))
    {
        sizeName = CLASSIFY_SHIRT_NAME_LARGE;
    }
    else
    {
        /* not classified, return default */
    }
    return sizeName;
}

int main() {
    assert(getShirtSizeName(33) == DEFAULT_SIZE_NULL);
    /* classify as SHORT, if length is less than or equal to 38 */
    assert(getShirtSizeName(34) == CLASSIFY_SHIRT_NAME_SHORT);
    assert(getShirtSizeName(37) == CLASSIFY_SHIRT_NAME_SHORT);
    assert(getShirtSizeName(38) == CLASSIFY_SHIRT_NAME_SHORT);

    /* classify as MEDIUM, if length is in the range 39-42 */
    assert(getShirtSizeName(39) == CLASSIFY_SHIRT_NAME_MEDIUM);
    assert(getShirtSizeName(42) == CLASSIFY_SHIRT_NAME_MEDIUM);

    /* classify as LARGE, if length is in the range 43-45 */
    assert(getShirtSizeName(43) == CLASSIFY_SHIRT_NAME_LARGE);
    assert(getShirtSizeName(44) == CLASSIFY_SHIRT_NAME_LARGE);
    assert(getShirtSizeName(45) == CLASSIFY_SHIRT_NAME_LARGE);

    assert(getShirtSizeName(46) == DEFAULT_SIZE_NULL);

    printf("All is well (maybe!)\n");
    return 0;
}

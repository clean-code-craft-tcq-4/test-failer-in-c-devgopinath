#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    /* classify as 'S', if length is less than or equal to 38 */
    assert(size(37) == 'S');
    assert(size(38) == 'S');

    /* classify as 'M', if length is greater than 38 and less than or equal to 42 */
    assert(size(39) == 'M');
    assert(size(40) == 'M');
    assert(size(42) == 'M');

    /* classify as 'L', if length is greater than 43 */
    assert(size(43) == 'L');

    printf("All is well (maybe!)\n");
    return 0;
}

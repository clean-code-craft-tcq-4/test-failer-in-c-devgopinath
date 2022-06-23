#include <stdio.h>
#include <assert.h>

typedef struct
{
    int pairNumber;
    const char * majorColor;
    const char * minorColor;
} colorMapStruct;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

#define MAX_MAJOR_COLORS    (sizeof(majorColor)/sizeof(majorColor[0]))
#define MAX_MINOR_COLORS    (sizeof(minorColor)/sizeof(minorColor[0]))

#define MAX_COMBINATIONS    (MAX_MAJOR_COLORS * MAX_MINOR_COLORS)

colorMapStruct ColorMaps[MAX_COMBINATIONS];


int GetColorMap(colorMapStruct * colorMaps)
{
    int i = 0, j = 0, index = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            colorMaps[index].pairNumber = i * 5 + j;
            colorMaps[index].majorColor = majorColor[i];
            colorMaps[index].minorColor = minorColor[i];
            ++index;
        }
    }
    return i * j;
}

void printColorMap()
{
    int numCombinations = GetColorMap(ColorMaps);
    for (int index = 0; index < numCombinations; ++index)
    {
        printf("%d | %s | %s\n", ColorMaps[index].pairNumber, ColorMaps[index].majorColor, ColorMaps[index].minorColor);
    }
}

void testColorMap(void)
{
    int numCombinations = GetColorMap(ColorMaps);

    assert(numCombinations == MAX_COMBINATIONS);

    for (int index = 0, pairNumber = 1; index < numCombinations; ++index, ++pairNumber)
    {
        assert(pairNumber == ColorMaps[index].pairNumber);
        assert(majorColor[(index % MAX_MAJOR_COLORS)] == ColorMaps[index].majorColor);
        assert(minorColor[(index % MAX_MINOR_COLORS)] == ColorMaps[index].minorColor);
    }
    printf("All is well (maybe!)\n");
}

int main() {
    printColorMap();
    testColorMap();
    return 0;
}

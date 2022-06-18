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

colorMapStruct ColorMaps[30];


int GetColorMap(colorMapStruct * colorMaps)
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            colorMaps.pairNumber = i * 5 + j;
            colorMaps.pairNumber = majorColor[i];
            colorMaps.pairNumber = minorColor[i];
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
    for (int index = 0, pairNumber = 1; index < numCombinations; ++index, ++pairNumber)
    {
        assert(pairNumber == ColorMaps[index].pairNumber);
        assert(majorColor[index] == ColorMaps[index].majorColor);
        assert(minorColor[index] == ColorMaps[index].minorColor);
    }
    printf("All is well (maybe!)\n");
}

int main() {
    printColorMap();
    testColorMap();
    return 0;
}

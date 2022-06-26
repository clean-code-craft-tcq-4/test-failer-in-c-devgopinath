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

int getPairNumber(int majorColorIndex, int minorColorIndex)
{
    return (majorColorIndex * 5 + minorColorIndex + 1);
}

int GetColorMap(colorMapStruct * colorMaps)
{
    int majorColorIndex, minorColorIndex, colorMapIndex;

    colorMapIndex = 0;

    for(majorColorIndex = 0; majorColorIndex < MAX_MAJOR_COLORS; majorColorIndex++)
    {
        for(minorColorIndex = 0; minorColorIndex < MAX_MINOR_COLORS; minorColorIndex++)
        {
            colorMaps[colorMapIndex].pairNumber = getPairNumber(majorColorIndex, minorColorIndex);
            colorMaps[colorMapIndex].majorColor = majorColor[majorColorIndex];
            colorMaps[colorMapIndex].minorColor = minorColor[minorColorIndex];
            ++colorMapIndex;
        }
    }
    return majorColorIndex * minorColorIndex;
}

void printColorMap()
{
    colorMapStruct ColorMaps[MAX_COMBINATIONS];
    int numCombinations = GetColorMap(ColorMaps);

    for (int colorMapIndex = 0; colorMapIndex < numCombinations; ++colorMapIndex)
    {
        printf("%d | %s | %s\n", ColorMaps[colorMapIndex].pairNumber, 
                                 ColorMaps[colorMapIndex].majorColor, 
                                 ColorMaps[colorMapIndex].minorColor);
    }
}

void testColorMap(void)
{
    colorMapStruct ColorMaps[MAX_COMBINATIONS];

    int numCombinations = GetColorMap(ColorMaps);

    assert(numCombinations == MAX_COMBINATIONS);

    for (int colorMapIndex = 0, pairNumber = 1; colorMapIndex < numCombinations; ++colorMapIndex, ++pairNumber)
    {
        assert(pairNumber == ColorMaps[colorMapIndex].pairNumber);
        assert(majorColor[(colorMapIndex % MAX_MAJOR_COLORS)] == ColorMaps[colorMapIndex].majorColor);
        assert(minorColor[(colorMapIndex % MAX_MINOR_COLORS)] == ColorMaps[colorMapIndex].minorColor);
    }
    printf("All is well (maybe!)\n");
}

int main()
{
    printColorMap();
    testColorMap();
    return 0;
}

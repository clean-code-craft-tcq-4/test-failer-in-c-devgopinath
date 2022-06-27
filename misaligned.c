#include <stdio.h>
#include <assert.h>

typedef struct
{
    unsigned int pairNumber;
    const char * majorColor;
    const char * minorColor;
} colorMapStruct;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

#define MAX_MAJOR_COLORS    (sizeof(majorColor)/sizeof(majorColor[0]))
#define MAX_MINOR_COLORS    (sizeof(minorColor)/sizeof(minorColor[0]))

#define MAX_COMBINATIONS    (MAX_MAJOR_COLORS * MAX_MINOR_COLORS)

unsigned int getPairNumber(unsigned int majorColorIndex, unsigned int minorColorIndex)
{
    return (majorColorIndex * 5 + minorColorIndex + 1);
}

unsigned int GetColorMap(colorMapStruct * colorMaps)
{
    unsigned int majorColorIndex, minorColorIndex, colorMapIndex;

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
    unsigned int numCombinations = GetColorMap(ColorMaps);

    for (unsigned int colorMapIndex = 0; colorMapIndex < numCombinations; ++colorMapIndex)
    {
        printf("%d | %s | %s\n", ColorMaps[colorMapIndex].pairNumber, 
                                 ColorMaps[colorMapIndex].majorColor, 
                                 ColorMaps[colorMapIndex].minorColor);
    }
}

void testColorMap(void)
{
    colorMapStruct ColorMaps[MAX_COMBINATIONS];

    unsigned int numCombinations = GetColorMap(ColorMaps);
    int maxMajorColors = MAX_MAJOR_COLORS;
    int maxMinorColors = MAX_MINOR_COLORS;

    assert(numCombinations == MAX_COMBINATIONS);

    for (unsigned int colorMapIndex = 0, pairNumber = 1; colorMapIndex < numCombinations; ++colorMapIndex, ++pairNumber)
    {
        printf("\n");
        printf("%d ", pairNumber);
        printf("%d ", ColorMaps[colorMapIndex].pairNumber);
        printf("%s ", majorColor[(colorMapIndex / MAX_MAJOR_COLORS)]);
        printf("%s ", ColorMaps[colorMapIndex].majorColor);
        printf("%s ", minorColor[(colorMapIndex / MAX_MINOR_COLORS)]);
        printf("%s", ColorMaps[colorMapIndex].minorColor);

        // assert(pairNumber == ColorMaps[colorMapIndex].pairNumber);
        // assert(majorColor[(colorMapIndex / maxMajorColors)] == ColorMaps[colorMapIndex].majorColor);
        // assert(minorColor[(colorMapIndex / maxMinorColors)] == ColorMaps[colorMapIndex].minorColor);
    }
    printf("All is well (maybe!)\n");
}

int main()
{
    printColorMap();
    testColorMap();
    return 0;
}

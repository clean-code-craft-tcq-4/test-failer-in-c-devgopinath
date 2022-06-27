#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct
{
    unsigned int pairNumber;
    const char * majorColor;
    const char * minorColor;
} colorMapStruct;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int maxMajorColorStrLength;
int maxPairNumberStrLength;

#define MAX_MAJOR_COLORS    (sizeof(majorColor)/sizeof(majorColor[0]))
#define MAX_MINOR_COLORS    (sizeof(minorColor)/sizeof(minorColor[0]))

#define MAX_COMBINATIONS    (MAX_MAJOR_COLORS * MAX_MINOR_COLORS)

#define EMPTY_STRING    ("")
#define SEPARATOR_STRING    (" | ")
#define SPACE_STRING (" ")

#define EXPECTED_STR_LENGTH_AFTER_PAIR_NUMBER (maxPairNumberStrLength)
#define EXPECTED_STR_LENGTH_AFTER_MAJOR_COLOR (EXPECTED_STR_LENGTH_AFTER_PAIR_NUMBER + \
                                               strlen(SEPARATOR_STRING) + \
                                               maxMajorColorStrLength)

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

int getMaxMajorColorStrLength(void)
{
    int maxLength = 0;
    int length;
    for (int index = 0; index < MAX_MAJOR_COLORS; ++index)
    {
        length = strlen(majorColor[index]);
        if (length > maxLength)
        {
            maxLength = length;
        }
    }
    return maxLength;
}
int getMaxPairNumberStrLength(void)
{
    char buffer[10];
    sprintf(buffer, "%d", (int)(MAX_COMBINATIONS));
    return (strlen(buffer));
}

void addSpaces(char * str, int expectedStringLength)
{
    int length = strlen(str);

    while (length < expectedStringLength)
    {
        strcat(str, SPACE_STRING);
        ++length;
    }
}

void getColorCodeAlignedString(int pairNumber, const char * majorColor, const char * minorColor, char * alignedString)
{
    strcpy(alignedString, EMPTY_STRING);
    strcat(alignedString, pairNumber);
    addSpaces(alignedString, EXPECTED_STR_LENGTH_AFTER_PAIR_NUMBER);
    strcat(alignedString, SEPARATOR_STRING);
    strcat(alignedString, majorColor);
    addSpaces(alignedString, EXPECTED_STR_LENGTH_AFTER_MAJOR_COLOR);
    strcat(alignedString, SEPARATOR_STRING);
    strcat(alignedString, minorColor);
}

void printColorMap()
{
    colorMapStruct ColorMaps[MAX_COMBINATIONS];
    char alignedString[25];
    unsigned int numCombinations = GetColorMap(ColorMaps);

    for (unsigned int colorMapIndex = 0; colorMapIndex < numCombinations; ++colorMapIndex)
    {
        getColorCodeAlignedString(ColorMaps[colorMapIndex].pairNumber, 
                                  ColorMaps[colorMapIndex].majorColor, 
                                  ColorMaps[colorMapIndex].minorColor,
                                  alignedString);
        printf("%s\n", alignedString);
    }
}

void testColorMap(void)
{
    colorMapStruct ColorMaps[MAX_COMBINATIONS];

    unsigned int numCombinations = GetColorMap(ColorMaps);

    assert(numCombinations == MAX_COMBINATIONS);

    for (unsigned int colorMapIndex = 0, pairNumber = 1; colorMapIndex < numCombinations; ++colorMapIndex, ++pairNumber)
    {
        assert(pairNumber == ColorMaps[colorMapIndex].pairNumber);
        assert(majorColor[(colorMapIndex / MAX_MAJOR_COLORS)] == ColorMaps[colorMapIndex].majorColor);
        assert(minorColor[(colorMapIndex % MAX_MINOR_COLORS)] == ColorMaps[colorMapIndex].minorColor);
    }
    printf("All is well (maybe!)\n");
}

int main()
{
    maxMajorColorStrLength = getMaxMajorColorStrLength();
    maxPairNumberStrLength = getMaxPairNumberStrLength();
    printColorMap();
    testColorMap();
    return 0;
}

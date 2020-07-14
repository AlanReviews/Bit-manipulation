#include <stdio.h>

unsigned char lookupTable[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,  // 0 - 15
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  // 16 - 31
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  // 32 - 47
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  // 48 - 63
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  // 64 - 79
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  // 80 - 95
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  // 96 - 111
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,  // 112 - 127
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  // 128 - 143
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  // 144 - 159
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  // 160 - 175
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,  // 176 - 191
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,  // 192 - 207
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,  // 208 - 223
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,  // 224 - 239
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,  // 240 - 255
}; 

unsigned char clearBit(const unsigned char input, const unsigned int pos) {
    // Shift 1 by pos
    const unsigned char temp = 1 << pos;
    // Invert the temporary variable to generate the appropraite mask for clearing the bit
    unsigned char mask = ~temp;
    // Use the AND bitwise operator to clear the bit at the position pos
    unsigned char result = input & mask;
    return result;
}

unsigned char setBit(const unsigned char input, const unsigned int pos) {
    // Shift 1 by pos
    const unsigned int mask = 1 << pos;
    // Use the OR bitwise operator to set the bit at the position pos
    unsigned char result = input | mask;
    return result;
}

unsigned int readBit(const unsigned char input, const unsigned int pos) {
    const unsigned int mask = 1 << pos;
    unsigned int result = input & mask;
    return result >> pos;
}

unsigned int countBitsByLookupTable(const unsigned char input) {
    return lookupTable[input];
}

unsigned int countBitsManually(const unsigned char input) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        if (readBit(input, i) == 1) {
            counter++;
        }
    }
    return counter;
}

int main() {
    // unsigned char input = 7;
    // unsigned int position = 1;
    // printf("%u\n", clearBit(input, position));
    // unsigned int newPos = 3;
    // unsigned char setBitResult = setBit(input, newPos);
    // printf("%u\n", setBitResult);
    // printf("%u\n", countBits(setBitResult));
    int passTally = 0;
    int failTally = 0;

    for (int i = 0; i < 256; i++) {
        if (countBitsManually(i) == countBitsByLookupTable(i)) {
            passTally++;
        }
        else {
            failTally++;
        }
    }
    printf("Pass tally = %d, fail tally = %d", passTally, failTally);
    
    return 0;
}
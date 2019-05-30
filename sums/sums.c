#include <stdio.h>

int main(int argc, char **argv)
{
    int matches[100];
    int target;
    int value;
    int count = 0;
    
    for (int hundreds = 0; hundreds < 10; hundreds++) {
        for (int tens = 0; tens < 10; tens++) {
            for (int ones = 0; ones < 10; ones++) {
                target = hundreds*100 + tens*10 + ones;
                value = hundreds * hundreds * hundreds;
                if (value <= target) {
                    value += tens * tens * tens;
                    if (value <= target) {
                        value += ones * ones * ones;
                        if (value == target) {
                            matches[count++] = value;
                        }
                    }
                }
            }
        }
    }

	printf("Found %d items:\n", count);
    for (int ndx = 0; ndx < count; ndx++) {
        printf("  %d\n", matches[ndx]);
    }

    printf("Enter 'q' to quit...");
    char retval[100];
    scanf("%s", retval);

    return 0;
}

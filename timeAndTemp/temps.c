#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void computeTemps(int cel, int far) {
    char quit = 'f';
    int temperature;
    char direction[20];
    int retval;
    
    // This gives precision to the second. for higher precision, see:
    // https://stackoverflow.com/questions/361363/how-to-measure-time-in-milliseconds-using-ansi-c
    time_t timer;
    char timeBuffer[26];
    struct tm* tm_info;
    
    while (quit != 't') {
        if (cel == -10000) {
            // Convert from farenheit
            cel = (far - 32) * 5/9;
        } else {
            // Convert from celcius
            far = (9 * cel / 5) + 32;
        }
        time(&timer);
        tm_info = localtime(&timer);
        strftime(timeBuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
//        puts(timeBuffer);

        printf("Temperature at %s: %df, %dc\n\n\n", timeBuffer, far, cel);
        printf("Enter a new temperature or 'q' to quit: ");
        retval = scanf("%d", &temperature);
        if (retval == 0) {
            quit = 't';
        } else {
            printf("Enter 'c' if you entered a celcius value, 'f' if you entered farenheit: ");
            retval = scanf("%s", direction);
            if (retval == 0) {
                quit = 't';
            } else if (direction[0] == 'c') {
                cel = temperature;
                far = -10000;
            } else if (direction[0] == 'f') {
                far = temperature;
                cel = -10000;
            } else {
                quit = 't';
            }
        }
    }
    
}

int main(int argc, char **argv)
{
    
    int argNdx;
    char *arg;
    int temperature;
    char *direction;

    temperature = 0;
    direction = NULL;

    // For each argument...
    for (argNdx = 1; argNdx < argc; argNdx++) {
        // Get the next argument and see what it is
        arg = argv[argNdx];
        switch (arg[0]) {
            case '-':
            case '/':
                // It's an argument; which one?
                switch (arg[1]) {
                    case '?':
                    case 'h':
                    case 'H':
                        // Help request
                        printf ("Usage:  temps -t <temperature:integer> -d <direction:ftoc|ctof>\n\n");
                        return (0);
                        break;
                    case 't':
                    case 'T':
                        // Param T requires a value; make sure it is there
                        argNdx++;
                        if (argNdx >= argc) {
                            printf ("Error:  missing value after '%s'.\n\n", arg);
                            return (1);
                        }
                        arg = argv[argNdx];
                        temperature = atoi (arg);
                        break;
                    case 'd':
                    case 'D':
                        // Param D requires a value; make sure it is there
                        argNdx++;
                        if (argNdx >= argc) {
                            printf ("Error:  missing value after '%s'.\n\n", arg);
                            return (1);
                        }
                        // The value is there; get it and convert it to an int (1..10)
                        arg = argv[argNdx];
                        direction = arg;
                        if (strcmp(direction, "ctof") != 0 && strcmp(direction, "ftoc") != 0) {
                            printf ("Error:  invalid value for '%s'; must be either ctof or ftoc.\n\n", arg);
                            return (1);
                        }
                        break;
//                    case 'y':
//                    case 'Y':
//                        // Param Y doesn't expect a value after it
//                        ParamY = 1;
//                        break;
                    default:
                        // Unexpected argument
                        printf ("Error:  unexpected parameter '%s'; type 'command -?' for help.\n\n", arg);
                        return (1);
                        break;
                }
                break;
            default:
                break;
         }
    }
    
    int cel = -10000;
    int far = -10000;
    if (direction != NULL) {
        if (strcmp(direction, "ctof") != 0) {
            cel = temperature;
        } else {
            far = temperature;
        }
    } else {
        // Default a value to start
        far = 75;
    }

    computeTemps(cel, far);
}
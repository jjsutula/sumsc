#include <stdio.h>
#include <calc.h>

void calculator() {
    char quit = ' ';
    struct in_s in = {.left=0, .right=0, .op=' '};

    printf("Anyone?\n");
    
    
    while (quit != 'q') {
        gatherInput(&in);
        if (in.op == 'q') {
            quit = 'q';
        } else {
            printf("Left: %d, Right: %d, Op: '%c'\n", in.left, in.right, in.op);
        }
    }
    
    /*
            res = doMath(left, parts[1], right)
            print(str(left) + ' ' + parts[1] + ' ' + str(right) + ' = ' + str(res))
     */
}

void gatherInput(struct in_s *in ) {
    int left;
    int right;
    char op;
    int retval;

    printf("Enter an equation: ");
    retval = scanf("%d %c %d", &left, &op, &right);
//    char *c = entered;
//    for (char *c = entered; *c != '\0'; c++) {
//        printf("%c\n", *c);
//    }
    if (retval == 0) {
        in->op = 'q';
    } else {
        in->left = left;
        in->right = right;
        in->op = op;
    }  
}

int doMath(struct in_s *in) {
    return 10;
}

int main(int argc, char **argv)
{
    calculator();
    printf("We done.\n");
    char entered[100];
    scanf("%s", entered);
    return 0;
}

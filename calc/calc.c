#include <stdio.h>
#include <calc.h>

void calculator() {
    char quit = ' ';
    struct in_s in = {.left=0, .right=0, .op=' '};
    int value;

    while (quit != 'q') {
        gatherInput(&in);
        if (in.op == 'q') {
            quit = 'q';
        } else {
            value = doMath(&in);
            printf("Value of %d %c %d = %d\n", in.left, in.op, in.right, value);
        }
    }
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
    char op = in->op;
    if (op == '*') {
        return in->left * in->right;
    } else if (op == '/') {
        return in->left / in->right;
    } else if (op == '+') {
        return in->left + in->right;
    }

    return in->left - in->right;
}

int main(int argc, char **argv)
{
    calculator();
    printf("We done.\n");
    char entered[100];
    scanf("%s", entered);
    return 0;
}

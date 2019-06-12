#ifndef CALC_H
#define CALC_H

struct in_s {
    int left;
    int right;
    char op;
};

void calculator();
int doMath(struct in_s *in);
void gatherInput(struct in_s *in );

#endif
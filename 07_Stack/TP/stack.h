#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 15; // Ukuran maksimum stack
typedef char infotype;

struct stack {
    infotype info[MAX_SIZE];
    int top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);

#endif

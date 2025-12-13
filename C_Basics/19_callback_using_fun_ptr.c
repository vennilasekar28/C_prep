#include <stdio.h>

// 3 possible callback functions
void add(int a, int b) { printf("Sum = %d\n", a + b); }
void sub(int a, int b) { printf("Sub = %d\n", a - b); }
void mul(int a, int b) { printf("Mul = %d\n", a * b); }

// higher order function using callback
void compute(void (*operation)(int,int), int x, int y) {
    operation(x, y);
}

int main() {
    compute(add, 10, 5);
    compute(sub, 10, 5);
    compute(mul, 10, 5);

    return 0;
}

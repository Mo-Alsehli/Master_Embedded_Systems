/* 
-- Adding Two Complex Numbers Using Structures.
*/

#include <stdio.h>


struct SComplex {
    double m_R; // Real Value
    double m_I; // Imaginary Value
};

struct SComplex readComplex(char name[]){
    struct SComplex c;
    printf("Enter Values Of %s Struct As (real, complex): ", name);
    scanf("%lf %lf ", &c.m_R, &c.m_I);

    return c;
}

struct SComplex addComplex(struct SComplex c1, struct SComplex c2){
    struct SComplex sum;

    sum.m_R = c1.m_R + c2.m_R;
    sum.m_I = c1.m_I + c2.m_I;

    return sum;
}

void printComplex(char name[], struct SComplex c){
    printf("%s = (%.2lf) + j(%.2lf) \r\n", name, c.m_R, c.m_I);
}


int main() {
    struct SComplex x, y, z;

    x = readComplex("X");
    y = readComplex("Y");
    z = addComplex(x, y);

    printComplex("Z", z);


    return 0;
}
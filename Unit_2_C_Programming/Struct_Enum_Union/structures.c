#include <stdio.h>

// Program-1 & Program-4
struct SStudent {
    unsigned char name[100];
    unsigned int roll;
    float marks;
};

// Program-2
struct SDistance {
    int feet;
    float inch;
};

// Program-3
struct SComplex {
    float real;
    float imag;
};

// Program-5
#define PI 3.14

struct SComplex addComplex(struct SComplex c1, struct SComplex c2){
    struct SComplex sum;

    printf("Enter real and imaginary respectively: \n");
    printf("For 1st Complex Number: ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("For 2nd Complex Number: ");
    scanf("%f %f", &c2.real, &c2.imag);

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;


    return sum;
}


int main() {
    printf("############ Program-1 #############\n");
    printf("EX1: C Program To Store Information (name, roll and marks) Of A Student Using Structures: \n\n");

    struct SStudent student1;
    
    printf("Enter Information Of Student: \n");
    printf("Enter Name: ");
    scanf("%[^\n]%*c", &student1.name);

    printf("Enter Roll Number: ");
    scanf("%d", &student1.roll);

    printf("Enter Marks: ");
    scanf("%f", &student1.marks);

    printf("\nDisplaying Information: \n");
    printf("Name: %s\n", student1.name);
    printf("Roll: %d\n", student1.roll);
    printf("Marks: %.2f", student1.marks);
    printf("\n\n"); 

// ######################################################################################

    printf("########### Program-2 ############\n");
    printf("C Program To Add Two Distances (in inch-feet) System Using Structres \n\n");

    struct SDistance dist1, dist2, sum;

    printf("Enter Information Of First Distance: \n");
    printf("Feet: ");
    scanf("%d", &dist1.feet);
    printf("Inch: ");
    scanf("%f", &dist1.inch);

    printf("Enter Information Of Second Distance: \n");
    printf("Feet: ");
    scanf("%d", &dist2.feet);
    printf("Inch: ");
    scanf("%f", &dist2.inch);

    sum.feet = dist1.feet + dist2.feet;
    sum.inch = dist1.inch + dist2.inch;

    if(sum.inch > 12.0){
        sum.inch -= 12;
        sum.feet++;
    }

    printf("\nSum Of 2 Distances = %d\' - %.2f \n\n", sum.feet, sum.inch);

// ######################################################################################

    printf("############# Program-3 ############\n");
    printf("C Program To Add Two Complex Numbers By Bassing Structure To A Function \n\n");

    struct SComplex c1, c2;

    struct SComplex sum2 = addComplex(c1, c2);

    printf("sum = %.2f + %.2fi\n\n", sum2.real, sum2.imag);

// ######################################################################################

    printf("############# Program-4 ############\n");
    printf("C Program To Store Information of Multiple Students Using Structure \n\n");

    struct SStudent studArr[10];
    int i;

    printf("Enter Information Of Students: \n");
    for(i = 0; i < 10; i++){
        studArr[i].roll = i + 1;
        printf("For roll number %d: \n", studArr[i].roll);
        printf("Enter Name: ");
        scanf(" %[^\n]%*c", &studArr[i].name);
        printf("Enter Marks: ");
        scanf(" %f", &studArr[i].marks);
    }

    printf("\nDisplaying Information Of Students: \n");
    for(i = 0; i < 10; i++){
        printf("Information for roll number %d\n", studArr[i].roll);
        printf("Name: %s\n", studArr[i].name);
        printf("Marks: %.2f\n", studArr[i].marks);
        printf("\n");
    } 
    printf("\n\n");

// ######################################################################################

    printf("########### Program-5 ###########\n");
    printf("EX5: C Program To Find Area Of A Circle, Passing Arguments To Macros\n\n");

    int raduis;
    float area;

    printf("Enter Raduis: ");
    scanf(" %d", &raduis);

    area = 2 * raduis * PI;

    printf("\nArea = %.2f\n\n", area);

    printf("\n\n");

 // ######################################################################################

    printf("############# Program-6 #############\n");
    // union size depend on the biggest data type inside the union, size = 32 byte.
    printf("size of union = 32 byte");
    // structure size depend on the sum of all data types inside the structure, size = 32 byte + 4 byte + 4 byte.
    printf("size of structure = 40 byte");

    return 0;
}
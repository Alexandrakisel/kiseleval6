#include <stdio.h>
#include <locale.h>
 
#define MAX_X 3
#define R2 4

int z1(int years);
double z2(double x);
int z3(int n);
int dz(double x, double y);


int main() {
    setlocale(LC_CTYPE, "Rus");

    printf("Задание 1\n\n");

    int years;
    printf("Впишите год: ");
    scanf("%d", &years);
    int year = z1(years);
    if (year == 1) {
        printf("Год %d високосный\n", years);
    }
    else {
        printf("Год %d не високосный\n", years);
    }

    printf("\nЗадание 2\n\n");

    double x;
    printf("Введите x: ");
    scanf("%lf", &x);
    printf("F(%.2f) = %.2f\n", x, (x < 0 || x > MAX_X) ? 4.0 : x * x);
    
    printf("\nЗадание 3\n\n");

    int n;
    printf("Введите N (N < 1000): ");
    scanf("%d", &n);
    int sum = z3(n);
    printf("Сумма цифр = %d - %s число\n", sum, (sum >= 10 && sum <= 99) ? "двузначное" : "не двузначное");

    printf("\nдз\n\n");

    double px, py;
    printf("Введите x: ");
    scanf("%lf", &px);
    printf("Введите y: ");
    scanf("%lf", &py);
    if (dz(px,py) == 1)
            printf("Точка принадлежит области\n\n");
        else
            printf("Точка не принадлежит области\n\n");
    return 0;

}


int z1(int years) {
    int a = 0;
    if (years % 4 == 0 && years % 100 != 0 || years % 400 == 0) {
        a = 1;
    }
    else {
        a = 0;
    }
    return a;
}

double z2(double x) {
    if (x < 0 || x > MAX_X)
        return 4;
    return x * x;
}


int z3(int n) {
    int temp = n;
    int sum = 0;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

int dz(double x, double y) {
    if (x * x + y * y <= R2 && x >= 0 && y >= x)
        return 1;
    return 0;
}
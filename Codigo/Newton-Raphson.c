#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double a;

//Função f(x)
double f(double x) {
    return x/a - tan(a*x);
}

// Derivada de f(x)~~~> f'(x) = 1/a - a * sec²(a*x)
double f_deriva(double x) {
    double sec = 1/ cos(a*x);
    return (1/a) - a * sec * sec;
}

// g(x) = x - f(x)/f'(x)
double fun_g(double x) {
    return x - f(x) / f_deriva(x);
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    double x0;
    double TOL;        // Tolerância
    double x;
    double xold;
    double ea = 100; // Erro aproximado
    int Imax, i = 0;   // Máximo de iterações e contador

    // Entrada de dados
    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o valro inicial x0 : ");
    scanf("%lf", &x0);
    printf("Digite a tolerância: ");
    scanf("%lf", &TOL);
    printf("Digite o máximo de iterações: ");
    scanf("%d", &Imax);

    x = x0;


    while (ea > TOL && i < Imax) {
        xold = x;
        x = fun_g(xold);
        i++;

        // Cálculo do erro aproximado
        if (x != 0) {
            ea = fabs((x - xold)/x) * 100;
        } else {
            ea = 0;
        }
    }

    printf("\nRaiz aproximada: %.4lf\n", x);
    printf("Iterações realizadas: %d\n", i);
    printf("Erro aproximado: %.4lf%%\n", ea);

    return 0;
}

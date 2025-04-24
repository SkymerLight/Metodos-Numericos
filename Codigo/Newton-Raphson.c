#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double a;

//Fun��o f(x)
double f(double x) {
    return x/a - tan(a*x);
}

// Derivada de f(x)~~~> f'(x) = 1/a - a * sec�(a*x)
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
    double TOL;        // Toler�ncia
    double x;
    double xold;
    double ea = 100; // Erro aproximado
    int Imax, i = 0;   // M�ximo de itera��es e contador

    // Entrada de dados
    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o valro inicial x0 : ");
    scanf("%lf", &x0);
    printf("Digite a toler�ncia: ");
    scanf("%lf", &TOL);
    printf("Digite o m�ximo de itera��es: ");
    scanf("%d", &Imax);

    x = x0;


    while (ea > TOL && i < Imax) {
        xold = x;
        x = fun_g(xold);
        i++;

        // C�lculo do erro aproximado
        if (x != 0) {
            ea = fabs((x - xold)/x) * 100;
        } else {
            ea = 0;
        }
    }

    printf("\nRaiz aproximada: %.4lf\n", x);
    printf("Itera��es realizadas: %d\n", i);
    printf("Erro aproximado: %.4lf%%\n", ea);

    return 0;
}

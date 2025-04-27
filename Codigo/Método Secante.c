#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double a;


double f(double x) {

    return x/a - tan(a*x);


}

int main() {
    setlocale(LC_ALL, "Portuguese");

    double x0, x1, TOL;
    double f0;
    double f1;
    int Imax;

    // Entrada de dados
    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o primeiro chute inicial: ");
    scanf("%lf", &x0);
    printf("Digite o segundo chute inicial: ");
    scanf("%lf", &x1);
    printf("Digite a tolerância: ");
    scanf("%lf", &TOL);
    printf("Digite o máximo de iterações: ");
    scanf("%d", &Imax);

    double xold, x, ea = 100.0;
    int i = 0;

    while (ea > TOL && i < Imax) {
        i++;
        f0 = f(x0);
        f1 = f(x1);
        xold = x1;

        x = x1 - f1 * (x0 - x1) / (f0 - f1);

        if (x != 0) {
            ea = fabs((x - xold) / x) * 100;
        }

        x0 = x1;
        x1 = x;
    }

    printf("\nRaiz aproximada: %.4lf\n", x);
    printf("Iterações realizadas: %d\n", i);
    printf("Erro aproximado: %.4f%%\n", ea);

}

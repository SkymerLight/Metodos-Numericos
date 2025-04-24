#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double a;

//f(x) = x/a - tg(a*x) ~~> -x/a = -tg(x*a) ~~> x/a = tg(x*a) ~~> x = a * tg(x*a)
double g(double x) {
    return a * tan(x*a);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    double x0;
    double TOL;        // Tolerância
    double x;
    double xold;
    double ea = 100; // Erro aproximado
    int Imax, i = 0;   // Máximo de iterações e contador

    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o chute inicial: ");
    scanf("%lf", &x0);
    printf("Digite a tolerância: ");
    scanf("%lf", &TOL);
    printf("Digite o máximo de iterações: ");
    scanf("%d", &Imax);

    x = x0;

    while (ea > TOL && i < Imax) {
        xold = x;
        i++;
        x = g(xold);

        if (x != 0) {
            ea = fabs((x - xold) / x) * 100;
        }
    }

    printf("\nRaiz aproximada: %.4lf\n", x);
    printf("Iterações realizadas: %d\n", i);
    printf("Erro aproximado: %.4lf%%\n", ea);

}

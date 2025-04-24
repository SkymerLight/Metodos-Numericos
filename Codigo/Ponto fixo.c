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
    double TOL;        // Toler�ncia
    double x;
    double xold;
    double ea = 100; // Erro aproximado
    int Imax, i = 0;   // M�ximo de itera��es e contador

    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o chute inicial: ");
    scanf("%lf", &x0);
    printf("Digite a toler�ncia: ");
    scanf("%lf", &TOL);
    printf("Digite o m�ximo de itera��es: ");
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
    printf("Itera��es realizadas: %d\n", i);
    printf("Erro aproximado: %.4lf%%\n", ea);

}

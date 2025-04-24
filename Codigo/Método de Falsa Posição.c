#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double a;

// Função: x/a - tan(a*x)
double f(double x) {
    return x/a - tan(a*x);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    double xl;
    double xu;
    double TOL;          // Tolerância
    double x = 0, xold;  // Ponto atual e anterior
    double fl, fu, fx;   // Valores da função
    double ea = 100;   // Erro aproximado
    int Imax, i = 0;     // Máximo de iterações e contador

    // Entrada de dados
    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o limite inferior (xl): ");
    scanf("%lf", &xl);
    printf("Digite o limite superior (xu): ");
    scanf("%lf", &xu);
    printf("Digite a tolerância: ");
    scanf("%lf", &TOL);
    printf("Digite o máximo de iterações: ");
    scanf("%d", &Imax);


    fl = f(xl);
    fu = f(xu);

    // verficando se temn mudança de sinal
    if (fl * fu >= 0) {
        printf("Erro: Nenhuma raiz no intervalo [%.2lf, %.2lf]\n", xl, xu);
        return 1;
    }


    // Algoritmo da Falsa Posição
    while (ea > TOL && i < Imax) {
        xold = x; // Armazena o x anterior
        i++;

        // Calcula novo x usando a fórmula
        x = xu + (fu * (xl - xu)) / (fu - fl);
        fx = f(x);

        // Calcula o erro aproximado
        if (x != 0) {
            ea = fabs((x - xold) / x) * 100;
        } else {
            ea = 0;
        }

        // Atualiza o intervalo
        if (fabs(fl) < fabs(fu)) {
            xl = x;
            fl = fx;
        } else {
            xu = x;
            fu = fx;
        }
    }

    printf("\nRaiz aproximada: %.4lf\n", x);
    printf("Iterações realizadas: %d\n", i);
    printf("Erro aproximado: %.4lf%%\n", ea);

    return 0;
}

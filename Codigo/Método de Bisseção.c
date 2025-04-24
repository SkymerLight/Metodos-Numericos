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

    // Declaração de variáveis
    double x1;
    double xu;          // Limites do intervalo
    double TOL;         // Tolerância
    double x;           // Ponto médio atual
    double xold;        // Valor anterior do ponto médio
    double fx;          // Valor da função no ponto médio
    double f1;          // Valor da função no limite inferior
    double ea = 100;    // Erro aproximado inicial
    int Imax;           // Número máximo de iterações
    int i = 0;          // Contador de iterações

    // Entrada de parâmetros pelo usuário
    printf("Digite o valor de a: ");
    scanf("%lf", &a);

    printf("Digite o limite inferior do intervalo (x1): ");
    scanf("%lf", &x1);
    printf("Digite o limite superior do intervalo (xu): ");
    scanf("%lf", &xu);


    printf("Digite a tolerância (%%): ");
    scanf("%lf", &TOL);
    printf("Digite o máximo de iterações: ");
    scanf("%d", &Imax);

    //irei considerar tudo como até 4 casas decimais
    // Verifica se os extremos são raízes, acho que nem precisa
    if (f(x1) == 0) {
        printf("Raiz encontrada em x = %.4lf\n", x1);
        return 0;
    }
    if (f(xu) == 0) {
        printf("Raiz encontrada em x = %.4lf\n", xu);
        return 0;
    }

    // Verifica mudança de sinal
    if (f(x1) * f(xu) >= 0) {
        printf("Erro: Nenhuma raiz no intervalo [%.2lf, %.2lf]\n", x1, xu);
        return 1;
    }


    // Algoritmo da Bisseção
    while (ea > TOL && i < Imax) {
        xold = x;          // Armazena o valor anterior para cálculo do erro
        x = (x1 + xu) / 2; // Calcula novo ponto médio
        fx = f(x);
        i++;

        if (fx == 0) { // Raiz exata encontrada
            ea = 0;
            break;
        }

        // Cálculo do erro aproximado (evitar divisão por zero)
        if (x != 0) {
            ea = fabs((x - xold)/x) * 100;

        }else {
            ea = 0;
        }

        // Atualização do intervalo
        if (f1 * fx < 0) {// A raiz está na metade esquerda. To na duvida se ele falou isso mesmo ou se sou doido
            xu = x;
        } else { // A raiz está na metade direita
            x1 = x;
            f1 = fx;
        }
    }


    printf("\nRaiz aproximada: %.4f\n", x);
    printf("Iterações realizadas: %d\n", i);
    printf("Erro aproximado: %.4f%%\n", ea);

    return 0;
}

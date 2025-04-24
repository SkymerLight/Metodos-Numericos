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

    // Declara��o de vari�veis
    double x1;
    double xu;          // Limites do intervalo
    double TOL;         // Toler�ncia
    double x;           // Ponto m�dio atual
    double xold;        // Valor anterior do ponto m�dio
    double fx;          // Valor da fun��o no ponto m�dio
    double f1;          // Valor da fun��o no limite inferior
    double ea = 100;    // Erro aproximado inicial
    int Imax;           // N�mero m�ximo de itera��es
    int i = 0;          // Contador de itera��es

    // Entrada de par�metros pelo usu�rio
    printf("Digite o valor de a: ");
    scanf("%lf", &a);

    printf("Digite o limite inferior do intervalo (x1): ");
    scanf("%lf", &x1);
    printf("Digite o limite superior do intervalo (xu): ");
    scanf("%lf", &xu);


    printf("Digite a toler�ncia (%%): ");
    scanf("%lf", &TOL);
    printf("Digite o m�ximo de itera��es: ");
    scanf("%d", &Imax);

    //irei considerar tudo como at� 4 casas decimais
    // Verifica se os extremos s�o ra�zes, acho que nem precisa
    if (f(x1) == 0) {
        printf("Raiz encontrada em x = %.4lf\n", x1);
        return 0;
    }
    if (f(xu) == 0) {
        printf("Raiz encontrada em x = %.4lf\n", xu);
        return 0;
    }

    // Verifica mudan�a de sinal
    if (f(x1) * f(xu) >= 0) {
        printf("Erro: Nenhuma raiz no intervalo [%.2lf, %.2lf]\n", x1, xu);
        return 1;
    }


    // Algoritmo da Bisse��o
    while (ea > TOL && i < Imax) {
        xold = x;          // Armazena o valor anterior para c�lculo do erro
        x = (x1 + xu) / 2; // Calcula novo ponto m�dio
        fx = f(x);
        i++;

        if (fx == 0) { // Raiz exata encontrada
            ea = 0;
            break;
        }

        // C�lculo do erro aproximado (evitar divis�o por zero)
        if (x != 0) {
            ea = fabs((x - xold)/x) * 100;

        }else {
            ea = 0;
        }

        // Atualiza��o do intervalo
        if (f1 * fx < 0) {// A raiz est� na metade esquerda. To na duvida se ele falou isso mesmo ou se sou doido
            xu = x;
        } else { // A raiz est� na metade direita
            x1 = x;
            f1 = fx;
        }
    }


    printf("\nRaiz aproximada: %.4f\n", x);
    printf("Itera��es realizadas: %d\n", i);
    printf("Erro aproximado: %.4f%%\n", ea);

    return 0;
}

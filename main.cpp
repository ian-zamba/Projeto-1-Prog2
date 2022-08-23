#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include "gconio.h"
#include "funcoes.h"
using namespace std;

#define MAX_COL 89
#define MAX_LIN 25
#define LIN 6
#define COL 7



int main(void) {//=============================Main=========================================

    system("mode con:cols=89 lines=25");//deixar o cmd do tamanho da tela do jogo

    int tabuleiro [LIN][COL];
    int escolha, jogador = 2;
    char continuar;

    TelaInicial();

    do{

        int contar[] = {0, 0, 0, 0, 0, 0, 0};
        int vitoria = 0;
        IniciarFunc(tabuleiro);
        ImprimirTabuleiro(tabuleiro);
        int cont = 0;

        do{

            cont++;

            jogador = Jogador(jogador);

            Checar(escolha, contar, jogador);

            MontarTabuleiro(tabuleiro, jogador, escolha);

            CalcVitoria(vitoria, tabuleiro);

            ImprimirTabuleiro(tabuleiro);

            if(cont == 42 && vitoria == 0){
                CalcVitoria();
                break;
            }

        }while(vitoria == 0);

        Checar(continuar);

    }while(continuar == 's');

    return 0;
}


/*
                 .eeeeeeeee
                .$$$$$$$$P"
               .$$$$$$$$P
              z$$$$$$$$P
             z$$$$$$$$"
            z$$$$$$$$"
           d$$$$$$$$"
          d$$$$$$$$"
        .d$$$$$$$P
       .$$$$$$$$P
      .$$$$$$$$$.........
     .$$$$$$$$$$$$$$$$$$"
    z$$$$$$$$$$$$$$$$$P"
   -**********$$$$$$$P
                     d$$$$$$"
                   .d$$$$$$"
                  .$$$$$$P"
                 z$$$$$$P
                d$$$$$$"
              .d$$$$$$"
             .$$$$$$$"
            z$$$$$$$beeeeee
           d$$$$$$$$$$$$$*
          ^""""""""$$$$$"
                      d$$$*
                     d$$$"
                    d$$*
                   d$P"
                 .$$"
                .$P"
               .$"
              .P"
             ."
            /"

ZAMBA
*/

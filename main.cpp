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

    TelaInicial();
    char op;
    char* arquivo = "historico.dat";

    do{
        Menu(op);

        if(op == '0'){
            return 0;
        }

        if(op == '1'){
           jogo(arquivo);
        }
        else if(op == '2'){
            DadoArq(arquivo);
        }

    }while(op != '0');

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

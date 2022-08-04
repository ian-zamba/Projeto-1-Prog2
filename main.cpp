#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

#define MAX_COL 89
#define MAX_LIN 25
#define LIN 6
#define COL 7

void IniciarFunc(int tabuleiro[LIN][COL]);
void CalcVitoria(int& vitoria, int tabuleiro[LIN][COL]);
void Checar(char& continuar);
void Checar(int& escolha, int contar[]);
int Jogador(int jogador);


int main(void) {

    system("mode con:cols=89 lines=25");//deixar o cmd do tamanho da tela do jogo

    int tabuleiro [LIN][COL];
    int escolha;
    int jogador = 1;
    char continuar;

    do{

    int contar[] = {0, 0, 0, 0, 0, 0, 0};
    int vitoria = 0;
    IniciarFunc(tabuleiro);

    do{
    cout << "Jogador: " << jogador << "\n";
    cout << "Qual coluna deseja jogar?\n";
    Checar(escolha, contar);

    for (int i = LIN - 1; i >= 0; i--) {
        if(tabuleiro[i][escolha - 1] == 0){
            tabuleiro[i][escolha - 1] = jogador;
            break;
        }
    }

    jogador = Jogador(jogador);

    CalcVitoria(vitoria, tabuleiro);

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    }while(vitoria == 0);

    cout << "vitoriaaaaaaa " << vitoria << "\n";

    cout << "Deseja continuar? s/n\n";

    Checar(continuar);

    cout << "\n";
    }while(continuar == 's');



/*
    cout << "  _      _____ _____   _  _    \n";
    cout << " | |    |_   _/ ____| | || |   \n";
    cout << " | |      | || |  __  | || |_  \n";
    cout << " | |      | || | |_ | |__   _| \n";
    cout << " | |____ _| || |__| |    | |   \n";
    cout << " |______|_____\\_____|    |_|   \n";
*/




    return 0;
}


void IniciarFunc(int tabuleiro[LIN][COL]){

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            tabuleiro[i][j] = 0;
        }
    }

}

void CalcVitoria(int& vitoria, int tabuleiro[LIN][COL]){

    int jog = 1;

    for (int i = LIN; i >= 0; i--) {
        for (int j = COL; j >= 0; j--) {
            int jog = 1;
            do{

//===============================horizontal==================================

                if(j - 3 > 0){
                    if(tabuleiro[i][j] == jog && tabuleiro[i][j-1] == jog && tabuleiro[i][j-2] == jog && tabuleiro[i][j-3] == jog){
                        vitoria = jog;
                    }
                }

                if(j + 3 < 7){
                    if(tabuleiro[i][j] == jog && tabuleiro[i][j+1] == jog && tabuleiro[i][j+2] == jog && tabuleiro[i][j+3] == jog){
                        vitoria = jog;
                    }
                }

//==============================vertical=======================================

                if(i - 3 > 0){
                    if(tabuleiro[i][j] == jog && tabuleiro[i-1][j] == jog && tabuleiro[i-2][j] == jog && tabuleiro[i-3][j] == jog){
                        vitoria = jog;
                    }
                }

                if(i + 3 < LIN){
                    if(tabuleiro[i][j] == jog && tabuleiro[i+1][j] == jog && tabuleiro[i+2][j] == jog && tabuleiro[i+3][j] == jog){
                        vitoria = jog;
                    }
                }

//=============================diagonal=========================================

                if(j + 3 < 7 && i - 3 > 0){
                    if(tabuleiro[i][j] == jog && tabuleiro[i-1][j+1] == jog && tabuleiro[i-2][j+2] == jog && tabuleiro[i-3][j+3] == jog){
                        vitoria = jog;
                    }
                }

                if(j + 3 < 7 && i + 3 < LIN){
                    if(tabuleiro[i][j] == jog && tabuleiro[i+1][j+1] == jog && tabuleiro[i+2][j+2] == jog && tabuleiro[i+3][j+3] == jog){
                        vitoria = jog;
                    }
                }

                jog++;
            }while(jog <= 2);
        }
    }

}

void Checar(char& continuar){
    do {
        continuar = getch();
        tolower(continuar);
    }while(continuar != 's' && continuar != 'n');
}
void Checar(int& escolha, int contar[]){

    int aux;

    do{

        cin >> escolha;
        if(escolha > COL || escolha < 1 || contar[escolha-1] == 6){
            cout << "Coluna invalida, tente novamente: ";
            aux = 0;
        }else{
            contar[escolha-1]++;
            aux = 1;
        }

    }while(escolha > COL || escolha < 1 || aux == 0);

}

int Jogador(int jogador){

    if(jogador == 1){
        jogador++;
    }else if (jogador == 2){
        jogador--;
    }

    return jogador;
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

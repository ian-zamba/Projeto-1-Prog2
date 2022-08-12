#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include "gconio.h"
using namespace std;

#define MAX_COL 89
#define MAX_LIN 25
#define LIN 6
#define COL 7

void IniciarFunc(int tabuleiro[LIN][COL]);
void CalcVitoria(int& vitoria, int tabuleiro[LIN][COL]);
void Checar(char& continuar);
void Checar(int& escolha, int contar[], int jogador);
int Jogador(int jogador);
void TelaInicial ();
void ImprimirTabuleiro(int tabuleiro[LIN][COL]);
int MexerQuadrado(int jogador);



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

        do{

            jogador = Jogador(jogador);

            Checar(escolha, contar, jogador);

            for (int i = LIN - 1; i >= 0; i--) {
                if(tabuleiro[i][escolha - 1] == 0){
                    tabuleiro[i][escolha - 1] = jogador;
                    break;
                }
            }

            CalcVitoria(vitoria, tabuleiro);


            cout << "\n";
            ImprimirTabuleiro(tabuleiro);

        }while(vitoria == 0);

        Checar(continuar);

    }while(continuar == 's');

    return 0;
}


void IniciarFunc(int tabuleiro[LIN][COL]){//====================Iniciar a matriz com 0=========================================


    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            tabuleiro[i][j] = 0;
        }
    }

}

void CalcVitoria(int& vitoria, int tabuleiro[LIN][COL]){//=============checar se tem algum vencedor=========================================


    for (int i = LIN - 1; i >= 0; i--) {
        for (int j = COL - 1; j >= 0; j--) {
            int jog = 1;
            do{

//===============================horizontal==================================

                if(j - 3 >= 0){
                    if(tabuleiro[i][j] == jog && tabuleiro[i][j-1] == jog && tabuleiro[i][j-2] == jog && tabuleiro[i][j-3] == jog){
                        vitoria = jog;
                    }
                }

                if(j + 3 < COL){
                    if(tabuleiro[i][j] == jog && tabuleiro[i][j+1] == jog && tabuleiro[i][j+2] == jog && tabuleiro[i][j+3] == jog){
                        vitoria = jog;
                    }
                }

//==============================vertical=======================================

                if(i - 3 >= 0){
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

                if(j + 3 < COL && i - 3 >= 0){
                    if(tabuleiro[i][j] == jog && tabuleiro[i-1][j+1] == jog && tabuleiro[i-2][j+2] == jog && tabuleiro[i-3][j+3] == jog){
                        vitoria = jog;
                    }
                }

                if(j + 3 < COL && i + 3 < LIN){
                    if(tabuleiro[i][j] == jog && tabuleiro[i+1][j+1] == jog && tabuleiro[i+2][j+2] == jog && tabuleiro[i+3][j+3] == jog){
                        vitoria = jog;
                    }
                }

                jog++;
            }while(jog <= 2);
        }
    }

    if(vitoria != 0){
        gotoxy(1,1);
        cout << "          ";
        if(vitoria == 1){
            textbackground(BLUE);
        }else if(vitoria == 2){
            textbackground(GREEN);
        }
        gotoxy(35, 3);
        cout << "Jogador numero " << vitoria << " WINS";

    }

}

void Checar(char& continuar){//=====================ver se continua=========================================

    gotoxy(34,24);
    cout << "Deseja continuar? s/n";
    do {
        continuar = tolower(getch());
        gotoxy(35, 3);
        cout << "                            ";
    }while(continuar != 's' && continuar != 'n');
    gotoxy(1,25);
}

void Checar(int& escolha, int contar[], int jogador){//============ver se a coluna é valida ou esta disponivel=========================================

    int aux;

    do{

        if(jogador == 1){
            textbackground(BLUE);
        }else if(jogador == 2){
            textbackground(GREEN);
        }
        gotoxy(1,1);

        cout << "Jogador: " << jogador << "\n";

        escolha = MexerQuadrado(jogador);

        if(contar[escolha-1] == 6){
            gotoxy(1, 2);
            textbackground(WHITE);
            cout << "Coluna invalida";
            aux = 0;
        }else{
            contar[escolha-1]++;
            aux = 1;
        }

    }while(escolha > COL || escolha < 1 || aux == 0);

}

int Jogador(int jogador){//================trocar de jogador por rodada=========================================

    if(jogador == 1){
        jogador++;
        textbackground(GREEN);
    }else if (jogador == 2){
        jogador--;
        textbackground(BLUE);
    }

    return jogador;
}

void TelaInicial(){//========================fazer a tela inicial do programa=========================================

    textbackground(WHITE);
    textcolor(BLACK);
    gotoxy(1,1);

    for (int i = 1; i <= MAX_LIN; i++){
        for (int c = 1; c <= MAX_COL; c++){
            printf(" ");
        }
        printf("\n");
    }

    gotoxy(30, 4);
    cout << "  _      _____ _____   _  _    ";
    gotoxy(30, 5);
    cout << " | |    |_   _/ ____| | || |   ";
    gotoxy(30, 6);
    cout << " | |      | || |  __  | || |_  ";
    gotoxy(30, 7);
    cout << " | |      | || | |_ | |__   _| ";
    gotoxy(30, 8);
    cout << " | |____ _| || |__| |    | |   ";
    gotoxy(30, 9);
    cout << " |______|_____\\_____|    |_|   ";

    gotoxy(26,16);
    cout << "Pressione qualquer tecla para continuar";
    getch();

    gotoxy(12, 16);
    printf("CARREGANDO");

    gotoxy(40,18);
    printf("          ");

    gotoxy(79,24);
    printf("        ");
    textbackground(BLACK);
    gotoxy(24, 16);
    printf("                                                        ");

    textbackground(RED);
    gotoxy(24, 16);

    for (int c = 16; c <= 25; c++){
        printf(" ");
        //Sleep(200);
    }
    for (int c = 26; c <= 66; c++){
        printf(" ");
        //Sleep(70);
    }
    for (int c = 67; c <= 71; c++){
        printf(" ");
       //Sleep(300);
    }

    textbackground(WHITE);
    system("cls");
    gotoxy(1,1);

}

void ImprimirTabuleiro(int tabuleiro[LIN][COL]){//=================imprimir o tabuleiro na tela=========================================


    int linha = 6, coluna = 22, colunas = 1;
    int lin = 0, col = 0;

    textbackground(RED);
    gotoxy(20,5);

    for (int l = 5; l <= MAX_LIN - 1; l++){
        for (int c = 6; c <= MAX_COL-34; c++){
            printf(" ");
        }
        gotoxy(20 ,l);
    }

    do{
        linha = 6;
        lin = 0;
        do{

            if(tabuleiro[lin][col] == 0){
                textbackground(WHITE);
            }else if(tabuleiro[lin][col] == 1){
                textbackground(BLUE);
            }else if(tabuleiro[lin][col] == 2){
                textbackground(GREEN);
            }



            gotoxy(coluna,linha);

            for (int i = linha; i < linha + 2; i++) {
                for (int j = coluna; j < coluna + 4; j++) {
                    gotoxy(j,i);
                    cout << " ";
                }
            }
            linha += 3;
            lin ++;

        }while(linha < 24);
        coluna += 7;
        colunas ++;
        col++;
    }while(coluna < 79 && colunas <= 7);
}

int MexerQuadrado(int jogador){//==================mexer o quadrado superior=====================

    int coluna = 1;
    int l = 2 , c = 22;
    int tecla;


    gotoxy(c , l);
    cout << "    ";
    l++;
    gotoxy(c , l);
    cout << "    ";

    do{

            l = 2;

            tecla =getch();

            if(jogador == 1){
                textbackground(BLUE);
            }else if(jogador == 2){
                textbackground(GREEN);
            }

            if(coluna < COL){
                if(tecla == 100 || tecla == 77){//=======ir para a direita========
                    c += 7;
                    coluna++;

                    gotoxy(c , l);
                    cout << "    ";
                    l++;
                    gotoxy(c , l);
                    cout << "    ";

                    c -= 7;
                    l = 2;

                    textbackground(WHITE);
                    gotoxy(c , l);
                    cout << "    ";
                    l++;
                    gotoxy(c , l);
                    cout << "    ";

                    c += 7;
                    gotoxy(c , l);
                }
            }

            if(coluna > 1){
                if(tecla == 97 || tecla == 75){//=======ir para a esquerda========
                    c -= 7;
                    coluna--;

                    gotoxy(c , l);
                    cout << "    ";
                    l++;
                    gotoxy(c , l);
                    cout << "    ";

                    c += 7;
                    l = 2;

                    textbackground(WHITE);
                    gotoxy(c , l);
                    cout << "    ";
                    l++;
                    gotoxy(c , l);
                    cout << "    ";

                    c -= 7;
                    gotoxy(c , l);
                }
            }

   }while(tecla != 32 && tecla != 13 && tecla != 80 && tecla != 115);

    textbackground(WHITE);
    gotoxy(c , l);
    cout << "    ";
    l++;
    gotoxy(c , l);
    cout << "    ";

    return coluna;
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

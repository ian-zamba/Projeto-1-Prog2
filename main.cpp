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
void Checar(int& escolha, int contar[]);
int Jogador(int jogador);
void TelaInicial ();
void ImprimirTabuleiro(int tabuleiro[LIN][COL]);


int main(void) {

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
            gotoxy(1,1);
            cout << "Jogador: " << jogador << "\n";
            textbackground(WHITE);
            cout << "Qual coluna deseja jogar?\n   ";
            gotoxy(1,3);
            Checar(escolha, contar);

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


        cout << "vitoriaaaaaaa " << vitoria << "\n";
        cout << "Deseja continuar? s/n\n";

        Checar(continuar);

        cout << "\n";
    }while(continuar == 's');





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
        textbackground(GREEN);
    }else if (jogador == 2){
        jogador--;
        textbackground(BLUE);
    }

    return jogador;
}

void TelaInicial(){

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

void ImprimirTabuleiro(int tabuleiro[LIN][COL]){

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

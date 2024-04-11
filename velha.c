#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    const int linha = 3, coluna = 3;

    srand(time(NULL));

    char tabuleiro[linha][coluna];
    int posHJ, posVJ, posHM, posVM;
    //as var de count são M = maquina, J = jogador
    //DP = diagonal principal
    //DS = diagonal secundaria
    int countJDP = 0;
    int countMDP = 0;
    int countJDS = 0;
    int countMDS = 0;
    int turno = 0;
    int turnoM = 1;
    int andamento = 1;

    //popula o tabuleiro

    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            tabuleiro[l][c] = '_';
        }
    }

    printf("Bem-vindo ao jogo da velha! \n");
    do{
        for(int l = 0; l < linha; l++){
            for(int c = 0; c < coluna; c++){
                printf("%3c", tabuleiro[l][c]);
            }
            printf("\n");
        }

        //jogada
        printf("Digite sua posição horizontal (0 / 2): \n");
        scanf("%d", &posHJ);
        printf("\n");
        printf("Digite sua posição vertical (0 / 2): \n");
        scanf("%d", &posVJ);
        printf("\n");

        if(posHJ > 2 || posHJ < 0 || posVJ > 2 || posVJ < 0){
            printf("Digite uma posição entre 0 e 2!")
            continue;
        }

        //registra jogada jogador
        if(tabuleiro[posHJ][posVJ] == '_'){
            tabuleiro[posHJ][posVJ] = 'X';
        }else{
            printf("Essa posição esta ocupada! \n");
            continue;
        }

        //registra jogada maquina
        //esse loop repete a´te a maquina encontrar uma posição valida
        turnoM = 1;
        while(turnoM){
                posHM = rand() % 3;
                posVM = rand() % 3;
            if(tabuleiro[posHM][posVM] == '_'){
                tabuleiro[posHM][posVM] = 'O';
                turnoM = 0;
            }else{
                continue;
            }
        }
        turno += 1;
        if(turno >= 9){
            andamento = 0;
            }
        //checa se as condições de vitória pela diagonal principal foram supridas por X
        countJDP = 0;
        countMDP = 0;
        for(int l = 0; l < linha; l++){
            for(int c = 0; c < coluna; c++){
                }
                if(tabuleiro[l][l] == 'X'){
                    countJDP++;
                    if(countJDP == 3){
                        printf("Você venceu! Uma vitoria pela diagonal principal.\n");
                        andamento = 0;
                }
        //checa se as condições de vitória pela diagonal principal foram supridas por O
                if(tabuleiro[l][l] == 'O'){
                    countMDP++;
                    if(countMDP == 3){
                        printf("Você perdeu!\n");
                        andamento = 0;
                    }
                }
            }
        }
        //checa se as condições de vitória pela diagonal secundarias foram supridas por X
        countJDS = 0;
        countMDS = 0;
        for(int l = 0; l < linha; l++){
            for(int c = 0; c < coluna; c++){
                if(l + c == 2){
                    if(tabuleiro[l][c] == 'X'){
                        countJDS++;
                        if(countJDS == 3){
                            printf("Você ganhou! Uma vitoria pela diagonal secundaria.\n");
                            andamento = 0;
                        }
                    }
        //checa se as condições de vitória pela diagonal secundarias foram supridas por O
                    if(tabuleiro[l][c] == 'O'){
                        countMDS++;
                        if(countMDS == 3){
                            printf("Você perdeu!\n");
                            andamento = 0;
                        }
                    }
                }
            }
        }
        //checa as condições de vitoria pela horizontal
        for(int l = 0; l < linha; l++){
            for(int c = 0; c < coluna; c++){
                if(c == 0){
                    if(tabuleiro[l][c+1] == 'X' && tabuleiro[l][c+2] == 'X'){
                        printf("Você ganhou! Uma vitoria pela horizontal. \n");
                        andamento = 0;
                    }
                }
            }
        }
        //checa as condições de vitoria pela vertical
        for(int c = 0; c < coluna; c++){
            for(int l = 0; l < linha;l++){
                if(l == 0){
                    if(tabuleiro[l+1][c] == 'X' && tabuleiro[l+2][c] == 'X'){ //TODO, adequar para as condições verticais
                        printf("Você ganhou! Uma vitoria pela vertical. \n");
                        andamento = 0;
                    }
                }
            }
        }



    }while(andamento);
    printf("Fim de jogo :)");

    return 0;
}

#include <stdio.h>
#include <stdlib.h> //para usar rand e afins. E tambem para para limpar a tela
#include <conio.h> //para mudar a cor da tela
#include <windows.h> // para utilizar sleep
#define LARG_TABELA 20

//apresentacao do sudoku
void titulo(){
  printf("               000000000   000000    0000000   000000 \n");
  printf("               000000000  00000000  00000000  00000000\n");
  printf("                  000     000  000  000       000  000\n");
  printf("                  000     000  000  000  000  000  000\n");
  printf("                  000     000  000  000  000  000  000\n");
  printf("               000000     00000000  00000000  00000000\n");
  printf("               00000       000000    000000    000000\n\n");
  printf("                                  Do \n\n");
  printf("      00000000  000  000  0000000    000000   000   000  000  000 \n");
  printf("     000000000  000  000  00000000  00000000  000   000  000  000 \n");
  printf("     000        000  000  000  000  000  000  000  000   000  000 \n");
  printf("      0000000   000  000  000  000  000  000  0000000    000  000 \n");
  printf("           000  000  000  000  000  000  000  0000000    000  000 \n");
  printf("     000000000  00000000  00000000  00000000  000  000   00000000  \n");
  printf("     00000000    000000   0000000    000000   000   000   000000  \n\n");
  printf("   -=-=-=-=-=-=-=-=-=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=-=-");
  printf(" \n\t\t\t\t\tJogo do Sudoku v1.0\n\n");
  printf("         Grupo: Gabriel, Gessica, Larissa e Lucas - turma A\n\n");
   printf("                        IFSP - Hortolandia - 2018");
}

//bordas do menu
void borda_superior(){
int i;
printf("%c", 201);
for(i=0; i < LARG_TABELA; i++)
  printf("%c", 205);
printf("%c\n", 187);
}

void borda_inferior(int tamX){
int i;
printf("%c", 200);
for(i=0; i < LARG_TABELA; i++)
  printf("%c", 205);
printf("%c\n", 188);
}


void coluna(int tamX, char str[]){
int i;

printf("%c",186);
printf("%-19s",str);
  printf("%c",32);
printf("%c\n",186);
}
void linha_horizontal(int tamX){
int i;
printf("%c",204);
for(i=0; i < tamX; i++)
  printf("%c",205);
printf("%c\n",185);
}


void bordas1(){ //fun��o para gerar o menu
borda_superior();
coluna(LARG_TABELA,"  SUDOKU: THE GAME");
linha_horizontal(LARG_TABELA);
coluna(LARG_TABELA,"     DIFICULDADE ");
coluna(LARG_TABELA," ");
coluna(LARG_TABELA,"    f -> FACIL ");
coluna(LARG_TABELA,"    m -> MEDIO ");
coluna(LARG_TABELA,"    d -> DIFICIL ");
linha_horizontal(LARG_TABELA);
coluna(LARG_TABELA,"       MODELO  ");
coluna(LARG_TABELA," ");
coluna(LARG_TABELA,"    1 -> Jogo 1 ");
coluna(LARG_TABELA,"    2 -> Jogo 2 ");
coluna(LARG_TABELA,"    3 -> Jogo 3 ");
coluna(LARG_TABELA,"    4 -> Jogo 4 ");
coluna(LARG_TABELA,"    5 -> Jogo 5 ");
coluna(LARG_TABELA,"    6 -> Jogo 6 ");
coluna(LARG_TABELA,"    7 -> Jogo 7 ");
coluna(LARG_TABELA,"    8 -> Jogo 8 ");
coluna(LARG_TABELA,"    9 -> Jogo 9 ");
coluna(LARG_TABELA," ");
coluna(LARG_TABELA,"     0 -> Sair ");
borda_inferior(LARG_TABELA);

printf("\n");
}

void jogox(int dif, int jogo[9][9], int i, int j, int randomc, int desafio[9][9]){ //fun��o para imprimir a matriz com o jogo que ser� jogado pelo usu�rio
    int aux; //auxiliar para transfer�ncia segura dos valores
    if (dif=='d'){ //se a dificuldade for dificil
        for (i = 0; i < 9; i++){
            if (i==3 || i==6){
                printf("------+-------+-------"); //vai imprimir faixas antes da quarta e s�tima linhas
                printf("\n");
            }
            for (j = 0; j < 9; j++){
                if (j==3 || j==6){
                    printf("| "); //vai imprimir faixas antes da quarta e s�tima colunas
                }
                if (((i==rand()%9 || j==rand()%9) || ((rand()%9)%2==0) || ((rand()%9)%7==0) || ((rand()%9)%3==0) || ((rand()%9)%5==0) && randomc<8)){
                /*rand's para gerar n�meros, se eles corresponderem as condi��es propostas, esses valores n�o estar�o na matriz exibida nem na que o usu�rio
                dever� preencher. Mais alto a dificuldade, mais condi��es e maior limite de espa�os vazios por linha. Menor a dificuldade, menos condi��es*/
                    printf("  "); //imprime um espa�o aonde que representa a casa vazia que o usu�rio dever� achar o valor
                    desafio[i][j]=NULL; //d� valor nulo para a matriz desafio, que dever� depois ser preenchida pelo usu�rio
                    randomc++;//contador de casas vazias, nesse caso o limite � 8 por linha, sendo menor nas outras dificuldades
                }else{
                    printf("%d ",jogo[i][j]); //se os rand's n�o equivalerem �s condi��es, � impresso o valor da posi��o normalmente
                    aux=jogo[i][j];
                    desafio[i][j]=aux; //nesse caso, o valor daquela posi��o na matriz original ser� passada para a matriz desafio, n�o sendo mais necess�rio preencher
                }
            }
            randomc=0; //zera o contador, para que na pr�xima linha ainda possa ter 7 espa�os vazios
            printf("\n");//pula para a pr�xima linha
        }
        //abaixo, exatamente as mesmas coisas, mas para as dificuldades m�dio e f�cil, com condi��es menos variadas, logo mais n�meros exibidos
        }else if (dif=='m'){
            for (i = 0; i < 9; i++){
                if (i==3 || i==6){
                    printf("------+-------+-------");
                    printf("\n");
                }
                    for (j = 0; j < 9; j++){
                        if (j==3 || j==6){
                            printf("| ");
                        }
                        if (((i==rand()%9 || j==rand()%9) || ((rand()%9)%2==0) || ((rand()%9)%3==0)  && randomc<6)){
                            printf("  ");
                            desafio[i][j]=NULL;
                            randomc++;
                        }else{
                            printf("%d ",jogo[i][j]);
                            aux=jogo[i][j];
                            desafio[i][j]=aux;
                          }
                    }
                    randomc=0;
                    printf("\n");
            }
        }else{
            for (i = 0; i < 9; i++){
                if (i==3 || i==6){
                    printf("------+-------+-------");
                    printf("\n");
                }
                for (j = 0; j < 9; j++){
                    if (j==3 || j==6){
                        printf("| ");
                    }
                    if (((i==rand()%9 || j==rand()%9) || ((rand()%9)%2==0) || ((rand()%9)%7==0) && randomc<4)){
                        printf("  ");
                        desafio[i][j]=NULL;
                        randomc++;
                    }else{
                        printf("%d ",jogo[i][j]);
                        aux=jogo[i][j];
                        desafio[i][j]=aux;
                    }
                }
                randomc=0;
                printf("\n");
            }
        }
}

void gameplay(int x, int y, int res, int desafio[9][9], int jogo[9][9],int vida){ //fun��o do gameplay em si, aonde o usu�rio ir� preencher o sudoku
    int fim=0; //declara uma vari�vel para conferir se o sudoku est� todo preenchido

    do{
        printf("\nVOCE POSSUI %d VIDAS\n",vida); //exibe quantas vidas o usu�rio ainda possui, perdendo uma a uma conforme erra uma casa
        fim=0;
        do{
            printf("\n\nInsira uma linha (1 a 9): ");
            scanf("%d",&x); //recebe o n�mero da linha que o usu�rio deseja preencher
        }while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6 && x!=7 && x!=8 && x!=9); //se o n�mero n�o estiver entre 1 e 9, a mensagem ser� reexibida
        x=x-1; //como a matriz se inicia em 0, ser� diminuido 1 do valor dado pelo usu�rio
        do{
            printf("\n\nInsira uma coluna (1 a 9): ");
            scanf("%d",&y); //recebe o n�mero da coluna que o usu�rio deseja preencher
        }while(y!=1 && y!=2 && y!=3 && y!=4 && y!=5 && y!=6 && y!=7 && y!=8 && y!=9); //se o n�mero n�o estiver entre 1 e 9, a mensagem ser� reexibida
        y=y-1; //como a matriz se inicia em 0, ser� diminuido 1 do valor dado pelo usu�rio
        if(desafio[x][y]!=NULL){
            printf("\nPosicao ja preenchida.\n"); //se o usu�rio der a posi��o de um espa�o j� preenchido, ele dever� dar outras coordenadas (n�o perdendo vida por isso)
        }else{
            printf("\nInsira um valor para preencher (1 a 9): ");
            scanf("%d",&res); //usu�rio responde que valor acha que dever� ser preenchido no campo vazio
            if(res==jogo[x][y]){
                printf("\nRESPOSTA CORRETA!!!\n\n"); //se o valor dado pelo usu�rio for exatamente o mesmo presente na matriz original, naquela posi��o, ele acertou
                desafio[x][y]=res; //como acertou, o valor ser� atribuido ao campo que estava vazio
                }else{
                printf("\nRESPOSTA ERRADA, TENTE NOVAMENTE\n\n"); //se o valor dado n�o for igual ao da matriz original naquela posi��o, ele errou
                vida--; //como errou, perder� uma vida
            }
            //abaixo, ser� impresso o sudoku inteiro, se o usu�rio tiver acertado, o valor respondido tamb�m ser� exibido dentro da tabela
            for (x = 0; x < 9; x++){
                if (x==3 || x==6){
                    printf("------+-------+-------");
                    printf("\n");
                }
                for (y = 0; y < 9; y++){
                    if (y==3 || y==6){
                        printf("| ");
                    }
                    if (desafio[x][y]==NULL){
                        printf("  ");//se o valor for nulo, a tabela apenas mostrar� um espa�o vazio
                    }else{
                        printf("%d ",desafio[x][y]); //se n�o for vazio, exibe o valor
                    }
                }
                printf("\n");
            }
        }
        for (x = 0; x < 9; x++){
                for (y = 0; y < 9; y++){
                    if(desafio[x][y]==jogo[x][y]){ //aqui o sistema confere casa por casa se na tabela preenchida est�o iguais a da matriz original
                        fim++; //se a casa estiver preenchida, soma +1 para a vari�vel fim
                    }
                }
        }
        if(vida==0){
            printf("\nVOCE PERDEU!!!\n"); //se o usu�rio perder todas as vidas, ele perde
            exit(0); //se perder, o jogo fecha
        }
    }while(fim<81); //o ciclo do DO ser� feito enquanto a vari�vel fim valer menos que 81, se chegar a 81 todos os campos est�o preenchidos
    printf("\nPARABENS, VOCE VENCEU!!!!!!\n"); //se todos os campos est�o preenchidos, voc� venceu
}


int main(){
    system("color 5F"); //cor de fundo roxo (5) e cor das letras branco brilhante (F)
    system("color 5F"); //cor de fundo roxo (5) e cor das letras branco brilhante (F)
    titulo();
    Sleep(5000);//utilizamos sleep para aguardar 5 segundos antes de limpar a tela e mostrar o menu
    system("cls");
    system("color 5F");//cor de fundo roxo (5) e cor das letras branco brilhante (F)

    printf("BEM-VINDO AO SUDOKU\n\n");
    printf("O objetivo deste jogo e a colocacao de numeros de 1 a 9 ");
    printf("em cada uma das celulas vazias numa grade de 9x9, constituida por 3x3 subgrades chamadas regioes.\n");
    printf("Este quebra-cabeca contem algumas pistas iniciais, que sao numeros inseridos");
    printf(" em algumas celulas, de maneira a permitir uma inducao ou deducao dos numeros em celulas que estejam vazias.\n");
    printf("Cada coluna, linha e regiao so pode ter um numero de cada um dos 1 a 9.\n");
    printf("Resolver o problema requer apenas raciocinio logico e algum tempo.\n\n");
    printf("BOA SORTE!\n");
    Sleep(15000);//utilizamos sleep para aguardar 15 segundos antes de limpar a tela e mostrar o menu
    system("cls"); // utilizamos system("cls") para limpar a tela

    char dif; //vari�vel da dificuldade
    int i,j,op, desafio[9][9], randomc=0, x, y, res,vida=20, /*auxiliares para contar e imprimir matrizes, matriz jog�vel, contador de condi��es de
    dificuldade, resposta do usu�rio no jogo e vidas, iniciadas em 20*/
        //abaixo, 9 modelos prontos de sudoku, os quais ter�o casas escondidas e n�o transferidas para a matriz de jogo e que ser�o usadas para conferir
         jogo1[9][9]=
        {{8,3,5,4,1,6,9,2,7},
         {2,9,6,8,5,7,4,3,1},
         {4,1,7,2,9,3,6,5,8},
         {5,6,9,1,3,4,7,8,2},
         {1,2,3,6,7,8,5,4,9},
         {7,4,8,5,2,9,1,6,3},
         {6,5,2,7,8,1,3,9,4},
         {9,8,1,3,4,5,2,7,6},
         {3,7,4,9,6,2,8,1,5}},
         jogo2[9][9]=
        {{8,7,6,5,4,3,2,1,9},
         {2,5,3,6,1,9,7,8,4},
         {1,9,4,8,7,2,3,6,5},
         {4,8,5,7,3,1,9,2,6},
         {3,6,2,9,5,8,4,7,1},
         {9,1,7,2,6,4,5,3,8},
         {6,2,9,4,8,7,1,5,3},
         {5,4,1,3,2,6,8,9,7},
         {7,3,8,1,9,5,6,4,2}},
         jogo3[9][9]=
        {{5,6,3,2,1,9,8,4,7},
         {7,1,8,4,5,3,9,2,6},
         {2,9,4,6,7,8,3,1,5},
         {1,2,5,7,9,6,4,3,8},
         {6,8,7,3,4,2,1,5,9},
         {3,4,9,1,8,5,7,6,2},
         {4,5,1,8,2,7,6,9,3},
         {9,7,6,5,3,1,2,8,4},
         {8,3,2,9,6,4,5,7,1}},
         jogo4[9][9]=
        {{1,3,2,6,5,8,9,4,7},
         {5,7,8,1,9,4,2,3,6},
         {9,4,6,7,3,2,5,8,1},
         {8,1,7,9,2,3,4,6,5},
         {6,2,3,5,4,1,7,9,8},
         {4,9,5,8,7,6,3,1,2},
         {2,8,9,4,1,7,6,5,3},
         {7,5,1,3,6,9,8,2,4},
         {3,6,4,2,8,5,1,7,9}},
         jogo5[9][9]=
        {{9,2,5,4,7,8,3,6,1},
         {6,7,3,1,5,9,4,8,2},
         {4,8,1,6,3,2,9,5,7},
         {2,3,8,7,6,1,5,4,9},
         {7,6,4,2,9,5,8,1,3},
         {1,5,9,8,4,3,7,2,6},
         {5,9,6,3,2,4,1,7,8},
         {3,1,2,5,8,7,6,9,4},
         {8,4,7,9,1,6,2,3,5}},
         jogo6[9][9]=
        {{7,5,9,1,2,8,4,6,3},
         {1,2,6,4,9,3,7,5,8},
         {3,8,4,6,7,5,9,1,2},
         {4,3,7,8,5,9,1,2,6},
         {6,9,5,2,4,1,3,8,7},
         {8,1,2,7,3,6,5,4,9},
         {2,6,3,5,1,7,8,9,4},
         {9,4,1,3,8,2,6,7,5},
         {5,7,8,9,6,4,2,3,1}},
         jogo7[9][9]=
        {{8,2,7,1,3,9,6,5,4},
         {6,3,4,2,5,7,1,8,9},
         {1,5,9,4,8,6,3,7,2},
         {4,9,5,3,6,2,7,1,8},
         {7,8,6,9,1,4,5,2,3},
         {3,1,2,5,7,8,4,9,6},
         {5,4,8,6,2,1,9,3,7},
         {2,6,1,7,9,3,8,4,5},
         {9,7,3,8,4,5,2,6,1}},
         jogo8[9][9]=
        {{3,7,4,1,6,8,2,5,9},
         {5,1,9,4,2,7,6,8,3},
         {2,8,6,3,9,5,7,1,4},
         {6,9,8,5,4,1,3,7,2},
         {1,2,3,7,8,6,9,4,5},
         {4,5,7,9,3,2,1,6,8},
         {9,6,2,8,7,4,5,3,1},
         {8,3,5,6,1,9,4,2,7},
         {7,4,1,2,5,3,8,9,6}},
         jogo9[9][9]=
        {{3,6,1,4,7,2,5,8,9},
         {9,8,4,5,1,6,7,2,3},
         {5,7,2,9,3,8,6,1,4},
         {4,5,3,7,2,1,9,6,8},
         {6,1,7,8,9,3,2,4,5},
         {2,9,8,6,4,5,1,3,7},
         {8,4,6,1,5,7,3,9,2},
         {7,2,9,3,6,4,8,5,1},
         {1,3,5,2,8,9,4,7,6}};

    bordas1();
    do{
        printf("Selecione a dificuldade (f, m ou d): ");
        scanf("%c", &dif); //jogador responde a dificuldade em que deseja jogar
        if (dif!='f' && dif!='m' && dif!='d'){
            printf("\nDificuldade incorreta, insira novamente. \n"); //se a dificuldade n�o ser nenhuma das 3 existentes, ser� enviado um aviso
        }
    }while(dif!='f' && dif!='m' && dif!='d'); //o sistema ir� pedir a dificuldade at� que seja respondido uma resposta v�lida
    do{
        printf("\nSelecione qual modelo de jogo deseja (de 1 a 9, 0 para sair): ");
        scanf("%d", &op); //usu�rio responde qual dos jogos quer jogar, responde 0 se quiser sair
        printf("\n");
        printf("\n");
        switch(op)
        {
            case 1:
                jogox(dif,jogo1,i,j,randomc,desafio); /*chama a fun��o para exibir o sudoku a ser resolvido, usando as vari�veis equivalentes.
                Apenas a matriz jogo ser� diferente de caso para caso, mantendo as mesmas vari�veis nos outros casos*/
                gameplay(x,y,res,desafio,jogo1,vida);/*chama a fun��o aonde ser� feito o gameplay, usando as vari�veis equivalentes.
                Apenas a matriz jogo ser� diferente de caso para caso, mantendo as mesmas vari�veis nos outros casos*/
                break;

            case 2:
                jogox(dif,jogo2,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo2,vida);
                break;

            case 3:
                jogox(dif,jogo3,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo3,vida);
                break;

            case 4:
                jogox(dif,jogo4,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo4,vida);
                break;

            case 5:
                jogox(dif,jogo5,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo5,vida);
                break;

            case 6:
                jogox(dif,jogo6,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo6,vida);
                break;

            case 7:
                jogox(dif,jogo7,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo7,vida);
                break;

            case 8:
                jogox(dif,jogo8,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo8,vida);
                break;

            case 9:
                jogox(dif,jogo9,i,j,randomc,desafio);
                gameplay(x,y,res,desafio,jogo9,vida);
                break;

            case 0:
                printf("\n\nFECHANDO...");
                exit(0); //se o usu�rio responder '0', o jogo se encerrar�
                break;

            default:
                printf("Comando incorreto, responda novamente.\n\n");//se o usu�rio n�o responder nenhum valor inteiro entre 0 e 9, ser� avisado e ter� que responder novamente
        }
    }while(op!=0 && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 && op!=7 && op!=8 && op!=9); //sistema pedir� qual jogo o usu�rio quer at� que d� uma resposta v�lida
    return 0;
}


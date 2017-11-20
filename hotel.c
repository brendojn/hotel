#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void quartosOcupados(int reservasOcupadas[181][6][7]) //Inicializa quartos.
{
    int i, j, q, randI, randJ, randQ, contLugarOcup=0, cpf, aux=0;

    srand(time(0));
    for(q = 0; q < 181; q++)
    {
        for (i = 0; i<6; i++) //Limpa as listas de reservas dos quartos.
        {
            for(j=0; j<7; j++)
            {
                reservasOcupadas[q][i][j] = 0;
            }
        }
    }

    while (contLugarOcup <= 1000) //Preenche os quartos vagos aleatoriamente.
    {
        randQ = rand ()% 181;
        randI =  rand()%6;
        randJ = rand()%7;
        aux = 0;

        //Verifica se o quarto esta vago.
        if (reservasOcupadas[randQ][randI][randJ] == 0)
        {
            cpf=(rand()%1000)*1000000;
            cpf=cpf+(rand()%1000)*1000;
            cpf=cpf+(rand()%1000);

            //Verifica se o usuario ja esta em alguma reserva.

            for (j=0; j<7; j++)
            {
                if (cpf==reservasOcupadas[randQ][randI][j])
                {
                    aux = 1; //Indica que o cliente ja possui reserva.
                }

            }
            if (aux==0)  // Adiciona o cliente ao quarto.
            {
                reservasOcupadas[randQ][randI][randJ] = cpf;
                contLugarOcup ++;
            }
        }
    }
    return;
}
int exibirReservas (int reservasOcupadas[181][6][7]) //Exibe as vagas de todos os quartos existentes.
{
    int i, j, q, dia = 1, andar=1, quarto=101;
    char jan[15], fev[15], mar[15], abr[15], mai[15], jun[15];
    for(q = 0; q < 181; q++ )
    {
        if(reservasOcupadas[q] == reservasOcupadas[0]){
        sprintf(jan, "[JANEIRO]");
        for(int i = 0; i < strlen(jan); i++){
        printf("%c", jan[i]);
        }
        }
        if(reservasOcupadas[q] == reservasOcupadas[31]){
        sprintf(fev, "[FEVEREIRO]");
        for(int i = 0; i < strlen(fev); i++){
        printf("%c ", fev[i]);
        }
        }
        if(reservasOcupadas[q] == reservasOcupadas[59]){
        sprintf(mar, "[MARCO]");
        for(int i = 0; i < strlen(mar); i++){
        printf("%c ", mar[i]);
        }
        }
        if(reservasOcupadas[q] == reservasOcupadas[90]){
        sprintf(abr, "[ABRIL]");
        for(int i = 0; i < strlen(abr); i++){
        printf("%c ", abr[i]);
        }
        }
        if(reservasOcupadas[q] == reservasOcupadas[120]){
        sprintf(mai, "[MAIO]");
        for(int i = 0; i < strlen(mai); i++){
        printf("%c ", mai[i]);
        }
        }
        if(reservasOcupadas[q] == reservasOcupadas[151]){
        sprintf(jun, "[JUNHO]");
        for(int i = 0; i < strlen(jun); i++){
        printf("%c ", jun[i]);
        }
        }

        printf("\n   ###Dia %d###   ", dia);
        dia++;
        if(reservasOcupadas[q] == reservasOcupadas[30]){
        dia = 1;

        }
        if(reservasOcupadas[q] == reservasOcupadas[58]){
        dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[89]){
        dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[119]){
        dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[150]){
        dia = 1;
        }

        for (i = 0; i<6; i++) //Imprimir Reservas já feitas
        {
            printf("\n*** Andar %d ***\n", andar);

            for(j=0; j<7; j++)
            {
                printf("%d - %09d ", quarto, reservasOcupadas[q][i][j]);
                quarto ++;
            }
            printf("\n\n");
            andar ++;

            if(andar == 7 )
            {
                andar = 1;
            }

            if (quarto==108 || quarto==208 || quarto==308 || quarto==408 || quarto==508 )
            {
                quarto = quarto + 93;
            }
            if(quarto > 607)
                quarto = 101;
        }
    }
}

int main()
{
    int reservasOcupadas [181][6][7];

    quartosOcupados(reservasOcupadas);    // chama a funcao de preencher automaticamente os dados
    exibirReservas(reservasOcupadas);      //mostrar todas as vagas




}

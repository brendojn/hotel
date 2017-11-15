#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void quartosOcupados(int reservasOcupadas[6][7]) //Inicializa quartos.
{
    int i, j, randI, randJ, contLugarOcup=0, cpf, aux=0;

    for (i = 0; i<6; i++) //Limpa as listas de reservas dos quartos.
    {
        for(j=0; j<7; j++)
        {
            reservasOcupadas[i][j] = 0;
        }
    }

    while (contLugarOcup<= 20) //Preenche os quartos vagos aleatoriamente.
    {
        randI =  rand()%6;
        randJ = rand()%7;
        aux = 0;

        //Verifica se o quarto esta vago.
        if (reservasOcupadas[randI][randJ] == 0)
        {
            cpf=(rand()%1000)*1000000;
            cpf=cpf+(rand()%1000)*1000;
            cpf=cpf+(rand()%1000);

            //Verifica se o usuario ja esta em alguma reserva.

                for (j=0; j<7; j++)
                {
                    if (cpf==reservasOcupadas[randI][j])
                    {
                        aux = 1; //Indica que o cliente ja possui reserva.
                    }

                }
            if (aux==0)  // Adiciona o cliente ao quarto.
            {
                reservasOcupadas[randI][randJ] = cpf;
                contLugarOcup ++;
            }
        }
    }
    return;
}
int exibirReservas (int reservasOcupadas[6][7]) //Exibe as vagas de todos os quartos existentes.
{
    int i, j, andar=1, quarto=101;
    for (i = 0; i<6; i++) //Imprimir Reservas já feitas
    {
        printf("\n\n*** Andar %d ***\n", andar);
        for(j=0; j<7; j++)
        {
            printf("%d - %09d ", quarto, reservasOcupadas[i][j]);
            quarto ++;
        }
        printf("\n");
        andar ++;

        if (quarto==108 || quarto==208 || quarto==308 || quarto==408 || quarto==508)
        {
            quarto = quarto + 93;
        }
    }
}

int main()
{
    int reservasOcupadas [6][7];

    quartosOcupados(reservasOcupadas);    // chama a funcao de preencher automaticamente os dados
    exibirReservas(reservasOcupadas);      //mostrar todas as vagas




}

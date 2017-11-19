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
    for(q = 0; q < 181; q++ )
    {
        printf("\n[   Dia %d   ]", dia);
        dia++;

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

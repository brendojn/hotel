#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hotel.h"
int* cpf_generator() {
	int *cpf, pesos[11], vetSoma[11], soma, resto, digito,  i;

	// Aloca memória para o cpf
	cpf = (int *) malloc(sizeof(int) * 11);

	// Gera 9 números aleatórios
	for(i = 0; i < 9; i++) {
		cpf[i] = rand() % 10;
	}

	// Cálculo do primeiro dígito verificador

	// Gera os 9 pesos
	for(i = 0; i < 9; i++) {
		pesos[i] = 10 - i;
	}

	// Multiplica os valores de cada coluna
	for(i = 0; i < 9; i++) {
		vetSoma[i] = cpf[i] * pesos[i];
	}

	// Calcula o somatório dos resultados
	soma = 0;
	for(i = 0; i < 9; i++) {
		soma += vetSoma[i];
	}

	// Realiza-se a divisão inteira do resultado por 11
	resto = soma % 11;

	// Verifica o resto da divisão
	if(resto < 2) {
		digito = 0;
	} else {
		digito = 11 - resto;
	}

	// Adiciona o 1º dígito verificador ao cpf
	cpf[9] = digito;

	// Cálculo do segundo dígito verificador

	// Gera os 10 pesos
	for(i = 0; i < 10; i++) {
		pesos[i] = 11 - i;
	}

	// Multiplica os valores de cada coluna
	for(i = 0; i < 10; i++) {
		vetSoma[i] = cpf[i] * pesos[i];
	}

	// Calcula o somatório dos resultados
	soma = 0;
	for(i = 0; i < 10; i++) {
		soma += vetSoma[i];
	}

	// Realiza-se a divisão inteira do resultado por 11
	resto = soma % 11;

	// Verifica o resto da divisão
	if(resto < 2) {
		digito = 0;
	} else {
		digito = 11 - resto;
	}

	// Adiciona o 2º dígito verificador ao cpf
	cpf[10] = digito;

	return cpf;
}

void quartosOcupados(int *reservasOcupadas[181][6][7]) //Inicializa quartos.
{
    int i, j, q, randI, randJ, randQ, contLugarOcup=0, aux=0, randomico, random = 0;
    int *cpf;

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
        randQ = rand ()% 182;
        randI =  rand()%7;
        randJ = rand()%8;

        aux = 0;

        //Verifica se o quarto esta vago.
        if (reservasOcupadas[randQ][randI][randJ] == 0)
        {
            cpf = cpf_generator();

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
                randomico = 3 + rand() % 5;

                random = randQ + randomico;


                    reservasOcupadas[randQ][randI][randJ] = cpf;




                contLugarOcup ++;
            }
        }
    }
    return;
}
int exibirReservas (int *reservasOcupadas[181][6][7]) //Exibe as vagas de todos os quartos existentes.
{
    int i, j, q, dia = 1, andar=1, quarto=101;
    char jan[15], fev[15], mar[15], abr[15], mai[15], jun[15];
     int *cpf;
    for(q = 0; q < 181; q++ ) //Imprimir Reservas já feitas
    {
        //Indica os meses
        if(reservasOcupadas[q] == reservasOcupadas[0])
        {
            sprintf(jan, "[JANEIRO]");
            for(int i = 0; i < strlen(jan); i++)
            {
                printf("%c", jan[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[31])
        {
            sprintf(fev, "[FEVEREIRO]");
            for(int i = 0; i < strlen(fev); i++)
            {
                printf("%c", fev[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[59])
        {
            sprintf(mar, "[MARCO]");
            for(int i = 0; i < strlen(mar); i++)
            {
                printf("%c", mar[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[90])
        {
            sprintf(abr, "[ABRIL]");
            for(int i = 0; i < strlen(abr); i++)
            {
                printf("%c", abr[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[120])
        {
            sprintf(mai, "[MAIO]");
            for(int i = 0; i < strlen(mai); i++)
            {
                printf("%c", mai[i]);
            }
        }
        if(reservasOcupadas[q] == reservasOcupadas[151])
        {
            sprintf(jun, "[JUNHO]");
            for(int i = 0; i < strlen(jun); i++)
            {
                printf("%c", jun[i]);
            }
        }

        //Indica os dias nos meses
        printf("\n   ###Dia %d###   ", dia);
        dia++;
        if(reservasOcupadas[q] == reservasOcupadas[30])
        {
            dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[58])
        {
            dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[89])
        {
            dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[119])
        {
            dia = 1;
        }
        if(reservasOcupadas[q] == reservasOcupadas[150])
        {
            dia = 1;
        }

        for (i = 0; i<6; i++)
        {
            printf("\n*** Andar %d ***\n", andar);

            for(j=0; j<7; j++)
            {
            for(int i = 0; i < 11; i++) {
            printf("%d", cpf[i]);
            }
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
    int reservasOcupadas[181][6][7];

    quartosOcupados(reservasOcupadas);    // chama a funcao de preencher automaticamente os dados
    exibirReservas(reservasOcupadas);      //mostrar todas as vagas

}

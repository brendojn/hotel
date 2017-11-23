#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

void quartosOcupados(int *reservasOcupadas[181][6][7]);
int exibirReservas (int *reservasOcupadas[181][6][7]);
int incluirReserva(int andar, int quarto, int mes, int dia, int *reservasOcupadas[181][6][7]);
int confirmarReserva(int andar, int quarto, int mes, int dia, int *reservasOcupadas[181][6][7]);
#endif // HOTEL_H_INCLUDED

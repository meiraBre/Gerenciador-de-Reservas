#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_RESERVAS 100

typedef struct {
    char nome[50];
    char cpf[15];
    int dia;
    int qtdPessoas;
} Reserva;

Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;

void escreverDiasDeReserva() {
    printf("1- Quinta\n");
    printf("2- Sexta\n");
    printf("3- Sábado\n");
    printf("4- Domingo\n");
}

void fazerReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("Capacidade máxima de reservas atingida!\n");
        return;
    }

    Reserva novaReserva;

    printf("Digite seu nome completo:\n");
    fflush(stdin);
    fgets(novaReserva.nome, 50, stdin);
    novaReserva.nome[strcspn(novaReserva.nome, "\n")] = '\0'; 
    
    printf("Digite seu CPF (apenas números):\n");
    fflush(stdin);
    fgets(novaReserva.cpf, 15, stdin);
    novaReserva.cpf[strcspn(novaReserva.cpf, "\n")] = '\0'; 

    do {
        printf("Escolha um dia para fazer a sua reserva:\n");
        escreverDiasDeReserva();
        scanf("%d", &novaReserva.dia);
        fflush(stdin);

        if (novaReserva.dia < 1 || novaReserva.dia > 4) {
            printf("Dia inválido. Tente novamente.\n");
        }
    } while (novaReserva.dia < 1 || novaReserva.dia > 4);

    printf("Digite a quantidade de pessoas para a reserva:\n");
    scanf("%d", &novaReserva.qtdPessoas);
    fflush(stdin);

    reservas[totalReservas++] = novaReserva;
    printf("Reserva realizada com sucesso!\n");
    system("pause"); 
}

void listarReserva() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva cadastrada.\n");
        return;
    }

int i;
    for (i = 0; i < totalReservas; i++) {
        printf("Nome: %s\n", reservas[i].nome);
        printf("CPF: %s\n", reservas[i].cpf);
        printf("Dia: %d\n", reservas[i].dia);
        printf("Número de Pessoas: %d\n", reservas[i].qtdPessoas);
        printf("====================================\n");
    }
    system("pause");
}

void totalPorDia() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva cadastrada.\n");
        return;
    }

    int dia, totalPessoas = 0;

    do {
        printf("Escolha o dia para calcular o total de pessoas:\n");
        escreverDiasDeReserva();
        scanf("%d", &dia);
        fflush(stdin);

        if (dia < 1 || dia > 4) {
            printf("Dia inválido. Tente novamente.\n");
        }
    } while (dia < 1 || dia > 4);

int i;
    for (i = 0; i < totalReservas; i++) {
        if (reservas[i].dia == dia) {
            totalPessoas += reservas[i].qtdPessoas;
        }
    }

    printf("Total de pessoas para o dia %d: %d\n", dia, totalPessoas);
    system("pause");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls"); 
        printf("\nMenu Principal\n");
        printf("1 - Fazer reserva\n");
        printf("2 - Listar reservas\n");
        printf("3 - Total de pessoas por dia\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);

        system("cls"); 
        switch (opcao) {
            case 1:
                fazerReserva();
                break;
            case 2:
                listarReserva();
                break;
            case 3:
                totalPorDia();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                system("pause");
        }
    } while (opcao != 4);

    return 0;
}











#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define tam 4
#define CELL_MAX (tam * tam - 1)

void print_sep(int length)
{
    printf("\t ");
    for (int i = 0; i < length; i++)
        printf("................");
    printf("\n");
}

void print_board(char board[tam][tam])
{
    int cell = 0;

    print_sep(tam);
    for (int row = 0; row < tam; ++row)
    {
        for (int column = 0; column < tam; ++column)
        {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(tam);
    }
}

char get_winner(char board[tam][tam])
{
    char winner = '-', simbolo;
    bool filaCompleta, columnaCompleta, diagonalCompleta1, diagonalCompleta2;

    // Verifico filas
    for (size_t i = 0; i < tam; i++)
    {
        simbolo = board[i][0];
        filaCompleta = true;
        for (size_t j = 0; j < tam; j++)
        {
            filaCompleta = filaCompleta && simbolo == board[i][j] && board[i][j] != '-';
        }
        if (filaCompleta)
        {
            winner = simbolo;
        }
    }

    // Verifico columnas
    for (size_t i = 0; i < tam; i++)
    {
        simbolo = board[0][i];
        columnaCompleta = true;
        for (size_t j = 0; j < tam; j++)
        {
            columnaCompleta = columnaCompleta && simbolo == board[j][i] && board[j][i] != '-';
        }
        if (columnaCompleta)
        {
            winner = simbolo;
        }
    }

    // Verifico primera diagonal
    simbolo = board[0][0];
    diagonalCompleta1 = true;
    for (size_t i = 0; i < tam; i++)
    {
        diagonalCompleta1 = diagonalCompleta1 && (simbolo == board[i][i]);
    }
    if (diagonalCompleta1)
    {
        winner = simbolo;
    }

    // Verifico segunda diagonal
    simbolo = board[2][0];
    diagonalCompleta2 = true;
    for (size_t i = 0; i < tam; i++)
    {
        diagonalCompleta2 = diagonalCompleta2 && (simbolo == board[2 - i][i]);
    }
    if (diagonalCompleta2)
    {
        winner = simbolo;
    }

    return winner;
}

bool has_free_cell(char board[tam][tam])
{
    bool free_cell = false;
    for (size_t i = 0; i < tam; i++)
    {
        for (size_t j = 0; j < tam; j++)
        {
            if (board[i][j] == '-')
            {
                free_cell = true;
            }
        }
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[tam][tam];
    for (size_t i = 0; i < tam; i++)
    {
        for (size_t j = 0; j < tam; j++)
        {
            board[i][j] = '-';
        }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board))
    {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0)
        {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX)
        {
            int row = cell / tam;
            int colum = cell % tam;
            if (board[row][colum] == '-')
            {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            }
            else
            {
                printf("\nCelda ocupada!\n");
            }
        }
        else
        {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-')
    {
        printf("Empate!\n");
    }
    else
    {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
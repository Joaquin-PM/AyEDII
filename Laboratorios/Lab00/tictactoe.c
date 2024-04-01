#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length)
{
    printf("\t ");
    for (int i = 0; i < length; i++)
        printf("................");
    printf("\n");
}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 3; ++column)
        {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3])
{
    char winner = '-', simbolo;
    bool filaCompleta, columnaCompleta, diagonalCompleta1, diagonalCompleta2;

    // Verifico filas
    for (size_t i = 0; i < 3; i++)
    {
        simbolo = board[i][0];
        filaCompleta = true;
        for (size_t j = 0; j < 3; j++)
        {
            filaCompleta = filaCompleta && simbolo == board[i][j] && board[i][j] != '-';
        }
        if (filaCompleta)
        {
            winner = simbolo;
        }
    }

    // Verifico columnas
    for (size_t i = 0; i < 3; i++)
    {
        simbolo = board[0][i];
        columnaCompleta = true;
        for (size_t j = 0; j < 3; j++)
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
    for (size_t i = 0; i < 3; i++)
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
    for (size_t i = 0; i < 3; i++)
    {
        diagonalCompleta2 = diagonalCompleta2 && (simbolo == board[2 - i][i]);
    }
    if (diagonalCompleta2)
    {
        winner = simbolo;
    }

    return winner;
}

bool has_free_cell(char board[3][3])
{
    bool free_cell = false;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
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

    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}};

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
            int row = cell / 3;
            int colum = cell % 3;
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
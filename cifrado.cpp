#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void init_matrix(char mat[100][100], int rows, int columns)
{
	for(int i = 0; i < rows; ++i)
		for(int j = 0; j < columns; ++j)
			mat[i][j] = '*';
}

void print_matrix(char mat[100][100], int rows, int columns)
{
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < columns; ++j)
			printf("%c ", mat[i][j]);
		printf("\n");
	}
}

void construct_matrix(char mat[100][100], int rows, int columns, char s[100])
{
	int len = strlen(s);
	int it_s = 0;
	printf("MATRIX\n");
	for(int i=0;i<rows && (it_s != len);++i)
	{
		for(int j=0;j<columns && (it_s != len);++j)
		{
			mat[i][j] = s[it_s];
			it_s++;
		}
	}
}

void read_matrix(char mat[100][100], int row, int columns)
{
	//BANDERA DE RECORRIDO
	// 0 - HACIA ARRIBA
	// 1 - HACIA ABAJO

	//EMPEZAMOS BAJANDO - DALE MAMI HASTA ABAJO
	int band = 1;

	printf("RESULT = ");

	for(int i = row-1; i>=0; --i){
		if(band)
			for(int j = 0; j < columns; ++j)
				printf("%c", mat[j][i]);
		else
			for(int j = columns-1; j>=0; --j)
				printf("%c", mat[j][i]);
		band = !band;
	}
	printf("\n");
}

int main()
{
	//COLUMNAS
	int columns;

	//FILAS
	int rows;

	//TEXTO CIFRADO
	char text[101];

	//MATRIZ
	char mat[100][100];

	int test = 1;

	//MIENTRAS EXISTA ENTRADA POR STDIN(TECLADO)
	while(!feof(stdin))
	{
		printf("-------- Test - %.2d --------\n", test);
		scanf("%d\n%[^\n]\n", &rows, text);
		printf("ROWS = %d\nTEXT = %s\n", rows, text);

		int len = strlen(text);

		columns = len/rows;
		if(len % rows != 0)
			columns++;

		printf("COLUMNS = %d\n", columns);
		init_matrix(mat, rows, columns);
		//print_matrix(mat,rows, columns);
		construct_matrix(mat,rows, columns,text);
		//print_matrix(mat,rows, columns);
		read_matrix(mat,rows, columns);

		test++;
	}

	return 0;
}
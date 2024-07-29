/*
Menor distância de dois arrays

João estava participando de uma competição de programação e lhe foi dado um problema em que ele tinha
que encontrar a menor distância entre dois números de dois arrays.

Um exemplo seria:

    Array 1 -> [-1, 5]
    Array 2 -> [26, 6]

A menor distância seria a combinação do número 5 do array 1 com o número 6 do array 2, que seria 1
de distância.

Instruções
    Use arrays com tamanho maiores ou iguais a 10 números.

    De preferência, coloque o código em um arquivo único, para que seja possível executar online e
    coloque o link do site que executa. Ex: playcode.io/javascript
*/

// Instruções:
// 1. Crie dois arrays com pelo menos 10 números cada.
// 2. Compare todos os pares possíveis de números, um de cada array.
// 3. Calcule a distância entre cada par de números.
// 7. Certifique-se de usar arrays com tamanho maior ou igual a 10 números.

// usando a fórmula: distância = |número1 - número2|.

#include <stdio.h>
#include <stdlib.h>

int		get_distance(int num1, int num2);
void	print_array(int num, int count, int *array);

int	main(int argc, char *argv[])
{
	int	num_count;
	int	smallest_distance;
	int	smallest_numbers[2];
	int	*array1;
	int	*array2;

	if (argc < 2)
	{
		fprintf(stderr, "Erro de uso: ./a.out <num_count> [numeros_array_1 ...] [numeros_array_2 ...]\n");
		fprintf(stderr, "O primeiro argumento deve ser a quantidade de numeros, seguido por essa quantidade de numeros vezes 2.\n");
		fprintf(stderr, "Por exemplo, se o numero for 2, devem ser fornecidos 4 numeros.\n");
		return (1);
	}

	num_count = atoi(argv[1]);

	if (num_count < 10)
	{
		fprintf(stderr, "A quantidade de numeros precisa ser de pelo menos 10\n");
		return (1);
	}

	if (argc - 2 != num_count * 2)
	{
		fprintf(stderr, "Argumentos invalidos\n");
		fprintf(stderr, "Com %d numeros voce precisa informar %d numeros. ", num_count, num_count * 2);
		fprintf(stderr, "Voce informou %d numeros.\n", argc - 2);
		return (1);
	}

	array1 = malloc(num_count * sizeof(int));
	array2 = malloc(num_count * sizeof(int));

	for (int i = 0; i < num_count; i++)
	{
		array1[i] = atoi(argv[i + 2]);
		array2[i] = atoi(argv[i + num_count + 2]);
	}

	print_array(1, num_count, array1);
	print_array(2, num_count, array2);

	smallest_distance = get_distance(array1[0], array2[0]);
	smallest_numbers[0] = array1[0];
	smallest_numbers[1] = array2[0];

	for (int i = 0; i < num_count; i++)
	{
		for (int j = 0; j < num_count; j++)
		{
			int	smallest_distance_tmp = get_distance(array1[i], array2[j]);

			if (smallest_distance_tmp < smallest_distance)
			{
				smallest_distance = smallest_distance_tmp;
				smallest_numbers[0] = array1[i];
				smallest_numbers[1] = array2[j];
			}
		}
	}

	printf("A menor distancia: %d\n", smallest_distance);
	printf("E os numeros sao : %d %d\n", smallest_numbers[0], smallest_numbers[1]);

	free(array1);
	free(array2);

	return (0);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	get_distance(int num1, int num2)
{
	return (ft_abs(num1 - num2));
}

void	print_array(int num, int count, int *array)
{
	printf("Array %d:", num);

	for (int i = 0; i < count; i++)
		printf(" %d", array[i]);

	printf("\n");
}

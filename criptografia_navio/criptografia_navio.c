/*
Criptografia na rede do navio

A intelitrader foi contratada para traduzir uma mensagem capturada na rede de um navio e ela está criptografada.
Não sabemos que tipo de criptografia eles usaram, a única coisa que sabemos até agora, é que, a cada 8 bits,
os dois últimos estão invertidos e a cada 4 bits, os 4 bits foram trocados com os próximos 4.

Mensagem criptografada:
10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001
00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011

Instruções:
    De preferência, coloque o código em um arquivo único, para que seja possível executar online e coloque o
    link do site que executa. Ex: playcode.io/javascript

    Existe mais de uma maneira de resolver este problema, mas aqui está alguns conceitos que podem te ajudar:
        Tabela ASCII
        Operadores lógicos
        Números binários e hexadecimais

    Você saberá se conseguiu descriptografar a mensagem se ela for legível e em inglês. Pois, qualquer bit
    errado, você terá uma mensagem cheia de símbolos.
*/

// Instruções:
// 1. Analise a mensagem criptografada.
// 2. A cada 8 bits, inverta os dois últimos bits.
// 3. A cada 4 bits, troque os 4 bits com os próximos 4.
// 4. Descriptografe a mensagem e verifique se ela está legível e em inglês.
// 		Se houver erros na descriptografia, a mensagem estará cheia de símbolos.

#include <stdio.h>
#include <stdlib.h>

void	print_decoded_message(char *message);

int	main(void)
{
	char *message = {
		"10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 "
		"00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011"
	};

	print_decoded_message(message);

	return (0);
}

int	swap_bits(int bits)
{
	return ((~bits) & 0b11);
}

void	print_decoded_message(char *message)
{
	int		i = 0;
	int		bit;
	char	char_to_decode = '\0';

	while (message[i])
	{
		if (message[i] != ' ')
		{
			bit = message[i] - '0';
			char_to_decode = (char_to_decode << 1) | bit;
		}
		else
		{
			char_to_decode = (char_to_decode & 0b11111100) | swap_bits(char_to_decode & 0b11);
			char_to_decode = ((char_to_decode & 0xF0) >> 4) | ((char_to_decode) << 4);
			printf("%c", char_to_decode);
		}
		i++;
	}
	printf("\n");
}

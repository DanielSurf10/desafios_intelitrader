# Menor distância de dois arrays

Este programa encontra a menor distância entre dois números de dois arrays.

## Instalação

## Instalação e Configuração

Para instalar e configurar o projeto, você precisará ter um compilador pré-instalado, como o GCC. Siga as instruções abaixo:

1. Certifique-se de ter o GCC instalado em seu sistema. Caso contrário, você pode instalá-lo executando o seguinte comando:

```
sudo apt-get install gcc
```

2. Clone o repositório do projeto em seu ambiente local:

```
git clone https://github.com/DanielSurf10/desafios_intelitrader.git
```

3. Navegue até o diretório do projeto:

```
cd desafios_intelitrader/menor_distancia_array
```

4. Compile o programa utilizando o GCC:

```
gcc menor_distancia_array.c -o menor_distancia_array
```

5. Agora você pode executar o programa:

```
./menor_distancia_array
```

## Uso

```bash
./menor_distancia_array <num_count> [numeros_array_1 ...] [numeros_array_2 ...]
```

Para utilizar o projeto, é necessário fornecer os seguintes argumentos de linha de comando:
1. O número de valores que serão fornecidos.
2. Os valores em si.
	- 2.1 Os valores são convertidos usando a função atoi (man atoi).

Lembre-se de fornecer o dobro de valores do número de valores que você informou, pois são necessários n valores para preencher dois arrays.

Exemplo de uso:
```bash
./menor_distancia_array 10 75 86 74 4 79 78 93 37 48 1 50 66 100 9 82 96 62 59 95 43
```

Neste exemplo, estamos fornecendo 10 valores para os arrays. Certifique-se de ajustar o número de valores e os próprios valores de acordo com suas necessidades.

Execute esse script para gerar números aleatórios:
```bash
#!/bin/bash
QUANTIDE_DE_NUMEROS=$(shuf -i 10-100 -n 1)
./menor_distancia_array $QUANTIDE_DE_NUMEROS $(shuf -i 1-1000 -n $((QUANTIDE_DE_NUMEROS * 2)))
```

## Site para compilar e executar online

https://www.onlinegdb.com/online_c_compiler

Obs: Para utilizar o programa, você precisa inserir os argumentos na seção "Command line arguments" localizada na parte inferior do site.

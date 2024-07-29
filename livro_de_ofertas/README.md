# Livro de ofertas

Este programa propõe a criação de um programa que simule um livro de ofertas de compra e venda.

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
cd desafios_intelitrader/livro_de_ofertas
```

4. Compile o programa utilizando o GCC:

```
gcc livro_de_ofertas.c -o livro_de_ofertas
```

5. Agora você pode executar o programa:

```
./livro_de_ofertas
```

## Uso

A primeira linha é composta por um inteiro informando o número de notificações
e as linhas subsequences contem as notificações no seguinte
formato: posição,ação,valor,quantidade.

```bash
./livro_de_ofertas
<quantidade de negociações>
<atualizações de negocioações: posição,ação,valor,quantidade>
```

Exemplo:
```bash
./livro_de_ofertas
12
1,0,15.4,50
2,0,15.5,50
2,2,0,0
2,0,15.4,10
3,0,15.9,30
3,1,0,20
4,0,16.50,200
5,0,17.00,100
5,0,16.59,20
6,2,0,0
1,2,0,0
2,1,15.6,0
```

Output
```
1,15.40,10
2,15.60,20
3,16.50,200
4,17.00,100
```

## Site para compilar e executar online

https://www.onlinegdb.com/online_c_compiler

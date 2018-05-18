#include <iostream>
#include <string>
#include <locale.h>
#include <stack>

using namespace std;

typedef struct{
string tipo;
string nome;
int ataque;
int defesa;
int meio;
int titulos;
int aparicao_copas;
bool is_super_trunfo = false;
}Carta;

// Estruturas de Dados
const int numero_cartas = 32;
Carta cartas [numero_cartas];
std::stack<Carta> stack_1;
std::stack<Carta> stack_2;

// Declara��o de M�todos
void inicializar_cartas();
string to_string_carta(Carta carta);
void embaralhar_cartas(Carta *cartas, int size);
void swap(Carta *cartas, int i, int r);
void inicializar_pilhas();

// M�todos

int main()
{   setlocale(LC_ALL, "Portuguese");
    inicializar_cartas();
    embaralhar_cartas(cartas,numero_cartas);
    inicializar_pilhas();

    cout << to_string_carta(cartas[0]) << endl;
    return 0;
}

string to_string_carta(Carta carta){
string to_string = "Tipo: " + carta.tipo + "\n" +
"Sele��o: " + carta.nome + "\n" +
"Ataque: " + std::to_string(carta.ataque) + "\n" +
"Defesa: " + std::to_string(carta.defesa) + "\n" +
"T�tulos: " + std::to_string(carta.titulos) + "\n" +
"Apari��es em Copas: " + std::to_string(carta.aparicao_copas) + "\n" ;

if (carta.is_super_trunfo)
    to_string += " SUPER TRUNFO ";

return to_string;
}

void inicializar_cartas(){
for (int i = 0; i < numero_cartas ; i++){
cartas[i].tipo = "A1";
cartas[i].nome = "Brasil";
cartas[i].ataque = 5;
cartas[i].defesa = 10;
cartas[i].meio = 4;
cartas[i].titulos = 5;
cartas[i].aparicao_copas = 4;
}


//  Carta 2 ... at�  carta 32, o indice vai de 0 a 31

}

void inicializar_pilhas(){
for (int i = 0; i < numero_cartas / 2; i++){
stack_1.push(cartas[i]);
}
for (int i = numero_cartas / 2; i < numero_cartas; i++){
stack_2.push(cartas[i]);
}


}

void embaralhar_cartas(Carta *cartas, int tamanho_vetor)
{
	for (int i = 0; i < tamanho_vetor; i++)
	{
		int r = rand() % tamanho_vetor;

		swap(cartas,i,r);
	}
}

void swap (Carta *cartas, int i, int r){
Carta temp = cartas[i];
cartas[i] = cartas[r];
cartas[r] = temp;
}




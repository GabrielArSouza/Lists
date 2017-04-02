/*!
	* programa que compacta um vetor recebido eliminando 
	* os valores nulos e negativos armazenados.
	*
	* O objetivo do programa é testar a manipulação
	* de vetores em c++ e testar algumas funções.
*/

// Cabeçalhos com definição de tipos a serem usados no programa
#include <iostream> // std::cin, std::cout, std::endl
#include <iomanip> // std::setfill, std::setw

// Programa principal
/*!
	* @param length tamanho lógico do vetor.
	* @param A vetor a ser manipulado.
	* @param index índice auxiliar para armazenar a posição do vetor
	* que deve ser preenchida com valores positivos, o índice mantém a 
	* sequência do vetor.
*/
int main (){

	auto length(20);
	int A[length];

	//preencher o vetor.
	for (auto i(0); i < length; i++)
		std::cin >> A[i];
	

	//escrever vetor na tela
	std::cout << "BEFORE\n";
	std::cout << std::setfill ('=') << std::setw (40) << "\n";
	for (auto i(0); i < length; i++)
		std::cout << A[i] << " ";

	//fazer compactação
	//@note assumindo o vetor de 20 posições
	auto index(0);
	for (auto i(0); i < 20; i++){
		
		if (A[i] > 0){
			A[index] = A[i];
			index ++;
		}else{
			length --; //reduz o tamanho lógico do vetor
		}

	}

	//Vetor depois de compactado
	std:: cout << std::endl << std::endl;
	std::cout << "AFTER\n";
	std::cout << std::setw (40) << "\n";
	for (auto i(0); i < length; i++)
		std::cout << A[i] << " ";

	std::setfill(' ');
	std::cout << std::endl;

	return 0;
}
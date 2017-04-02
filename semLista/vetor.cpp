#include <iostream>

#define N 20

int main (){

	int vet[N]

	for ( auto i(0); i < N ; i++)
		std::cin >> vet[i];

	std::cout << ">> BEFORE { ";
	for ( auto i(0); i < N; i++)
		std::cout << vet[i] << " ";
	std::cout << "}\n";

	//TODO: Fazer a inversão do vetor no proprio vetor

	std::cout << ">> AFTER { ";
	for ( auto i(0); i < N; i++)
		std::cout << vet[i] << " ";
	std::cout << "}\n";

	return 0;
}
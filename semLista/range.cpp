#include <iostream>
#include <iterator>

//protótipo
void negate(int * first, int * last);

int main ()
{
	int Vet [] = {1 , 2 , -3 , -4 , 5 , -6};

	std::cout << ">>> Antes do negate:\n";
	std::cout << ">>> Vet = [ ";
	for(auto i = std::begin(Vet) ; i != std::end(Vet) ; ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "]\n";

	negate( std::begin ( Vet ) , std::end ( Vet ) ); // Nega todo o vetor .

	std::cout << ">>> Depois do negate:\n";
	std::cout << ">>> Vet = [ ";
	for(auto i = std::begin(Vet) ; i != std::end(Vet) ; ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "]\n";

	negate ( std::begin ( Vet )+2 , std::end ( Vet ) ); // Nega do 3ro at´e o ´ultimo elemento do vetor .
	negate ( std::begin ( Vet )+3 , std::begin ( Vet )+4 ); // Nega apenas o 4to elemento do vetor .
	return 0;
}

void negate(int * first, int * last)
{
	for (/*empty*/ ; first != last ; ++first )
	{
		*first *= -1;
	}

	//outra versão
	/*
		for (auto i(first) ; i != last ; ++i){
			*i *= -1;
		}
	*/

	/*

	*outra versão

	auto n = std::distance(first, last);

	for (auto i(0) ; i < n; ++i)
		first[i] *= -1;
	*/
}
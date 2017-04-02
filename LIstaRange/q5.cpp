#include <iostream>
#include <iterator>

int dot_product ( const int *a_first , const int *a_last ,const int *b_first );

int main ()
{

	// Desejamos multiplicar a =[1 , 3 , -5] · b =[4 , -2 , -1].
	int Vet [] = {1 , 3 , -5 , 4 , -2 , -1 }; // Os dois vetores armazenados no mesmo arranjo .
	
	auto result = dot_product ( std::begin(Vet) , std::begin(Vet)+3 , // Vetor a
	std::begin(Vet)+3 );// Vetor b

	// O comando abaixo deveria imprimir 3 , se correto .
	std::cout << " >>> O resultado é : " << result << std::endl ;
	// [1 ,3 , -5]·[4 , -2 , -1] = (1)(4)+(3)( -2)+( -5)( -1)
	//= 4 - 6 + 5
	//= 3.


	return 0;
}


int dot_product ( const int *a_first , const int *a_last ,const int *b_first )
{
	auto soma(0);
	//int tam = std::distance(a_first, a_last);
	for (/*empty*/; a_first != a_last; ++a_first, ++b_first)
	{
		soma += (*a_first) * (*b_first);
	} 
	return soma;
}
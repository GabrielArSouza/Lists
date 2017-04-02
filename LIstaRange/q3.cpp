#include <iostream>
#include <iterator>
#include <utility>
#include <cmath>

void reverse ( int *first , int *last );

int main ()
{

	int A [] = { 1 , 2 , 3 , 4 , 5};
	
	// aplicar reverse sobre todo o vetor.
	reverse ( std::begin(A) , std::end(A) );

	// O comando abaixo deveria imprimir A com o conteudo 5 , 4 , 3 , 2 , 1
	for ( auto i(std::begin(A)) ; i != std::end(A) ; ++i )
		std::cout << * i << " " ;
	
	std::cout << std::endl ;

	// aplicar reverse sobre parte do vetor .
	reverse ( std::begin ( A )+1 , std::begin ( A )+4 );
	// O comando abaixo deveria imprimir A com o conteudo 5 , 2 , 3 , 4 , 1
	for ( auto i ( std::begin ( A ) ) ; i != std::end ( A ) ; ++ i )
	std::cout << * i << " " ;
	std::cout << std::endl ;

	return 0;
}

void reverse ( int *first , int *last )
{
	int tam = std::distance(first, last);
	int *aux = last-1;
	auto cont(0);
		
	for (/*empty*/; cont != (tam/2); first++ )
	{
		std::swap(*first, *aux);
		aux--;
		cont++;
		
	}	
}
#include <iostream>
#include <iterator>
#include <algorithm>

void reverse ( int * first , int * last );

int main (){

	int A [] = { 1 , 2 , 3 , 4 , 5 };
	// aplicar reverse sobre todo o vetor .
	reverse ( std::begin ( A ) , std::end ( A ) );
	// O comando abaixo deveria imprimir A com o conte u do 5 , 4 , 3 , 2 , 1
	for ( auto i ( std::begin ( A ) ) ; i != std::end ( A ) ; ++ i )
		std::cout << * i << " " ;

	std::cout << std::endl ;

	return 0;

}

void reverse ( int * first , int * last ){

	auto aux = last;
	for (/*empty*/; first != last/2; ++first)
	{
		* first = * aux;
		aux --;
	}

}
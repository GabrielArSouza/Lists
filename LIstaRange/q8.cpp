#include <iostream>
#include <iterator>
#include <utility>


int * unique ( int *first , int *last );

int main ()
{

	int A [] = { 1 , 2 , 1 , 2 , 3 , 3 , 1 , 2 , 4 , 5 , 3 , 4 , 5 };
	
	// aplicar unique sobre A
	auto last = unique( std::begin(A), std::end(A));
	
	// O comando abaixo deveria imprimir A com o conteudo 1 , 2 , 3 , 4 , 5.
	for ( auto i(std::begin(A)); i != last ; ++i )
		std::cout << * i << " " ;
	std::cout << std::endl ;

	// Mostra o novo tamanho de A , que seria 5.
	std::cout << " >>> O comprimento ( logico ) de A apos unique ()e: "
	<< std::distance ( std::begin ( A ) , last ) << " \n ";

	return 0;
}

int * unique ( int *first , int *last )
{
	
	auto iSlow(first+1);
	auto iFast(first+1);
	auto aux(first);

	bool unico;

	for(/*empty*/; iFast != last; ++iFast)
	{
		unico = true;
		for (auto i(aux); i != iSlow and unico; ++i)
		{
			if(*i == *iFast)
				unico = false;

		}
		if (unico){
			std::swap(*iSlow,*iFast);
			iSlow++;
		} 
	}

	return iSlow;	

}
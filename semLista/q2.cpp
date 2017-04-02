//questão 2
#include <iostream>
#include <iterator>


//protótipo
int * min (const int * first,const int * last);

int main ()
{

	int A [] = {1 , 2 , -3 , -4 , 5 , -6};
	// Deveria imprimir -6.
	auto result = min( std::begin ( A ) , std::end ( A ) );
	std::cout << *result << std::endl ;

	// Deveria imprimir -4
	result = min( std::begin ( A )+1 , std::begin ( A )+5 );
	std::cout << *result << std::endl ;

	return 0;
}

int * min ( const int * first, const int * last)
{
	const int * menor = first;

	for (/*empty*/ ; first != last ; ++first)
	{
		if( *first < *menor)
			menor = first;	
	}

	return (int *) menor;

}
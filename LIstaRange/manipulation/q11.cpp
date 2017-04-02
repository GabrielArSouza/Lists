#include <iostream>
#include <iomanip>
#include <utility>


void rotate ( int * first , int * n_first , int * last );

int main ()
{

	int A[] = { 1, 2, 3, 4, 5, 6, 7};
	rotate(std::begin(A), std::begin(A)+2, std::end(A));

	for (auto i(std::begin(A)); i != std::end(A); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	return 0;
}


void rotate ( int * first , int * n_first , int * last )
{
	auto islow(first);
	auto ifast(n_first);
	
	for (/*empty*/; ifast != last; ++ifast)
	{
		std::swap(*islow++, *ifast);
				
	}

}
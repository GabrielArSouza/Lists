#include <iostream>
#include <iterator>

void scalar_multiplication ( int *first , int *last , int scalar );

int main ()
{
	int Vet [] = {1 , 2 , -3 , -4 , 5 , -6};
	scalar_multiplication ( std::begin(Vet) 
		,std::end(Vet), 3);
	// O vetor resultante seria :
	// { 3 , 6 , -9 , -12 , 15 , -18 }.
	std::cout << ">>> [ ";
	for(auto i(std::begin(Vet)); i != std::end(Vet); i++)
		std::cout << *i << " ";
	std::cout << "]\n";

	return 0;
}

void scalar_multiplication ( int *first , int *last , int scalar )
{
	for(/*empty*/; first != last; ++first)
	{
		*first *= scalar;
	}
}
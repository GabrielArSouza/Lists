//lista range - q1

#include <iostream> // std :: cout , std :: endl
#include <iterator> // std :: begin () , std :: end ()

void negate ( int * first , int * last );

int main ()
{
	

	int Vet [] = {1 , 2 , -3 , -4 , 5 , -6};

	//negate( std::begin(Vet), std::end(Vet)); //nega todo o vetor
	//negate( std::begin(Vet)+2, std::end(Vet)); //nega do 3ro até o ultimo
	negate( std::begin(Vet)+3, std::begin(Vet)+4); //nega apenas o 4to elemento

	std::cout << "=============================================\n";
	std::cout << ">>> [ ";
	for (auto i(0); i<6; ++i)
		std::cout << Vet[i] << " ";
	std::cout << " ]\n";
	
	return 0;
}

void negate ( int * first , int * last )
{
	for (/*empty*/; first < last; ++first)
	{
		*first *= -1;
	}

}



#include <iostream>
#include <iterator>
#include <utility>

int *unique ( int *first, int *last);

int main ()
{

	int V[] = {1,2,3,3,3,3,4,4,1,1,2,1,1,5,5,6,7,8,9,6,6,7,7,7,8,8,9,10};

	//aplicar unique sobre A
	auto last = unique(std::begin(V), std::end(V)-8);

	//imprimir vetor, esperado é de 1 a 10
	for (auto i(std::begin(V)); i != last ; ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	//mostra o novo tamanho lógico
	std::cout << ">>> O comprimento (lógico) de A após o unique() é: "
		<< std::distance(std::begin(V), last) << "\n";

	return 0;
}

int *unique ( int *first, int *last)
{

	auto islow(first+1);
	auto ifast(first+1);

	auto aux(first);
	bool unique;	

	for (/*empty*/; ifast != last; ++ifast)
	{
		unique = true;
		for (auto i(aux); i != islow and unique; ++i)
		{
			if (*i == *ifast)
				unique = false;
		}

		if (unique)
		{
			std::swap(*islow, *ifast);
			islow++;
		}

	}

	return islow;

}
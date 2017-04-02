#include <iostream>
#include <iterator>
#include <utility>
#include <sstream>


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

int main (int argc, char * argv[])
{
	int number;
	
	if (argc == 1)
	{
		std::cout << "\n Desculpa, erro de syntax!\n"
				  << "	Por favor, informe arranjo\n\n"
				  << "		$./unique [n1] [n2] ... [nn]\n\n";

		return EXIT_FAILURE;
	} else{
		int V[argc-1];
		for (auto i(0); i < (argc-1); ++i)
		{
			std::stringstream(argv[i+2]) >> V[i];
		}
	}	

	auto newLast = unique(std::begin(V), std::end(V));
	std::cout << "Novo vetor sem repetiçẽos: " << std::endl;
	std::cout << "[ ";
	for (auto j(std::begin(V); j < newLast; ++j)
	{
		std::cout << *j << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;

}
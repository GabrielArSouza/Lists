#include <iostream>
#include <sstream>

int pascal(int a, int b)
{
	if (b == 0 || b == a)
	{
		return 1;
	}else {
		return pascal(a-1, b-1) + pascal(a-1, b);
	}

}

int main(int argc, char const *argv[])
{
	int alt;

	if (argc == 1){
		std::cout << "\n Desculpa, erro de syntax!\n"
				  << "	Por favor, informe um inteiro\n\n"
				  << "		$./pascal [n]\n\n";

		return EXIT_FAILURE;
	}else {
		std::stringstream(argv[1]) >> alt;
	}	

	for (auto i(0); i <= alt; ++i)
	{
		for (auto j(0); j <= i; ++j)
		{
			std::cout << pascal(i,j) << " ";
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
#include <iostream>
#include <string>
#include <sstream>

int raiseToPower(int n, int k)
{
	if (k == 0){
		return 1;
	}else{
		return n * raiseToPower(n, k-1);
	}
}

int main (int argc, char * argv[])
{
	int k, n;
	if (argc < 3)
	{
		std::cout << "\nDesculpe, erro de syntax\n"
				  << "    Informe os parâmetros corretos\n\n"
				  << "    ./power [n] [k]\n\n";
		return EXIT_FAILURE;
	}else {
		std::stringstream(argv[1]) >> n;
		std::stringstream(argv[2]) >> k;
	}

	auto power = raiseToPower(n, k);
	std::cout << "n elevado a k = " << power << std::endl;

	return EXIT_SUCCESS;
}
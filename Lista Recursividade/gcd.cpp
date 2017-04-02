#include <iostream>
#include <sstream>

int gcd(int x, int y)
{
	auto di = x%y;
	if (di == 0)
	{
		return y;
	}else {
		return gcd(y, di);
	}

}


int main (int argc, char * argv[])
{
	int x, y;
	
	if (argc < 3)
	{
		std::cout << "\n Desculpa, erro de syntax!\n"
				  << "	Por favor, informe dois inteiros para achar o maior divisor comum\n\n"
				  << "		$./gcd.cpp [x] [y]\n\n";

		return EXIT_FAILURE;
	} else{
		std::stringstream(argv[1]) >> x;
		std::stringstream(argv[2]) >> y;
	}	

	auto result = gcd(x, y);
	std::cout << "O máximo divisor comum entre " <<
	x << " e " << y << " é: " << result << std::endl;

	return EXIT_SUCCESS;

}
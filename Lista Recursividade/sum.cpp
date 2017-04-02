#include <iostream>
#include <sstream>

int digitSum (int n)
{
	if (n < 10){
		return n;
	}else {
		auto x = n%10;
		return x + digitSum((n-x)/10);
	}

}

int main (int argc, char * argv[])
{
	int number;
	
	if (argc == 1)
	{
		std::cout << "\n Desculpa, erro de syntax!\n"
				  << "	Por favor, informe o tamanho da pirâmide\n\n"
				  << "		$./sum [n]\n\n";

		return EXIT_FAILURE;
	} else{
		std::stringstream(argv[1]) >> number;
	}	

	auto sum = digitSum(number);
	std::cout << "A soma dos dígitos do número digitado é: " << sum << std::endl;

	return EXIT_SUCCESS;

}
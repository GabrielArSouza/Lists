#include <sstream>
#include <iostream>

int digitalRoot(int x)
{
	auto sum(0);
	auto root(x);
	auto y(0);

	if (root < 10)
	{
		return root;
	}else {
		
		while (root >= 1)
		{
			y = root%10;
			sum += y;
			root = (root-y)/10;
		}

		return digitalRoot(sum);
	}
}


int main (int argc, char * argv[])
{
	int number;
	
	if (argc == 1)
	{
		std::cout << "\n Desculpa, erro de syntax!\n"
				  << "	Por favor, informe um inteiro\n\n"
				  << "		$./digitalRoot [n]\n\n";

		return EXIT_FAILURE;
	} else{
		std::stringstream(argv[1]) >> number;
	}	

	auto result = digitalRoot(number);
	std::cout << "O digital root do número digitado é: " << result << std::endl;

	return EXIT_SUCCESS;

}
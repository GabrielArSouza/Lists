#include <iostream>
#include <sstream>
#include <string>

int cannonball (int h)
{
	if (h == 1){
		return 1;
	}else {
		return h*h + cannonball(h-1);
	}
}

int main (int argc, char * argv[])
{
	int Heigth;
	
	if (argc == 1)
	{
		std::cout << "\n Desculpa, erro de syntax!\n"
				  << "	Por favor, informe o tamanho da pirâmide\n\n"
				  << "		$./canb [h]\n\n";

		return EXIT_FAILURE;
	} else{
		std::stringstream(argv[1]) >> Heigth;
	}	

	auto balls = cannonball(Heigth);

	std::cout << "A quantidade de bolas é: " << balls << std::endl;

	return EXIT_SUCCESS;
}

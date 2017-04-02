#include <iostream>
#include <string>
#include <fstream>
#include <vector>


int main ()
{
	//declaração de variáveis
	std::string aux;
	std::string filename;
	std::ifstream arq;

	//ler nome do arquivo e o abre
	std::cin >> filename;
	arq.open( filename.c_str());

	//verifica a quant. de linhas do arq
	//para saber o tamanho do vetor criado
	auto sizeVector(0ul);
	while( std::getline(arq, aux))
		sizeVector++;
	arq.close();

	//std::cout << sizeVector << std::endl;
	//cria o vetor para armazenar os dados
	std::vector<int> numbers(sizeVector);
	std::string value;
	auto index(sizeVector-1);

	//ler os dados do arquivo e atribui ao vetor
	arq.open( filename.c_str());
	std::string::size_type sz;
	while( std::getline(arq, value)) {
		numbers[index] = std::stoi(value,&sz);
	    index--;
	}
	arq.close();

	std::ofstream output;
	output.open("invertido.txt");
	for (auto i(0ul); i < sizeVector; ++i)
	{
		output << numbers[i] << std::endl;
	}
	output.close();

	return 0;
}


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void printHeader ( const std::vector< std::string > &fields);

int main ()
{

	std::vector< std::string > fieldNames = {"ITEM", "QUANTIDADE", "VALOR UNITARIO"};

	printHeader(fieldNames);

	return 0;
}

/**
 * @brief      Imprime o cabeçalho de uma tabela no terminal
 *
 * @param[in]  fields  vetor de strings contendo o cabeçalho da tabela
 */
void printHeader ( const std::vector< std::string > &fields)
{
	auto tam = fields.size();
	auto aux(0ul);

	//imprime linha divisória
	for (auto i(0ul); i < tam; ++i)
	{
		aux = fields[i].size();
		std::cout << "+" << std::setw(aux+2) << std::setfill('-') << "";
	}
	std::cout << "+" << std::endl;

	//imprime índices
	for (auto i(0ul); i< tam; ++i)
	{
		std::cout << "|" << std::setw(1) << std::setfill(' ') << "";
		std::cout << fields[i];
		std::cout << std::setw(1) << "";
	}
	std::cout << "|" << std::endl;

	//imprime linha divisória
	for (auto i(0ul); i < tam; ++i)
	{
		aux = fields[i].size();
		std::cout << "+" << std::setw(aux+2) << std::setfill('-') << "";
	}
	std::cout << "+" << std::endl;
	
}
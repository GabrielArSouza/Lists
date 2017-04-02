#include <iostream>
#include <iomanip>
#include <utility>


void partition(int *first, int *last, int *pivot);

int main ()
{

	int V[] = {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};

	std::cout << ">>> Vetor antes do particionamento \n";
	for (auto i(std::begin(V)); i != std::end(V); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	partition(std::begin(V), std::end(V), std::begin(V)+3);

	std::cout << ">>> Vetor depois do particionamento \n";
	for (auto i(std::begin(V)); i != std::end(V); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;


	return 0;
}


/**
 * @brief      essa função rearranja (movimenta) os elementos do intervalo
 *             do intervalo em um vetor, tendo como referencia um valor, valores
 *             menores são ordenados antes, seguido dos iguais e depois os maiores.
 *
 * @param      first  ponteiro que define o inicio do intervalo do vetor
 * @param      last   ponteiro que define o final do intervalo do vetor
 * @param      pivot  ponteiro que aponta para a posição do vetor que tem
 *                    o valor de referncia
 */
void partition(int *first, int *last, int *pivot)
{

	auto p(*pivot);

	auto ifast(first);
	auto menor(first);
	auto limit(pivot+1);

	for (/*empty*/; ifast != last; ++ifast)
	{
		if ((*ifast == p) and ((ifast < pivot) or (ifast > limit)))
		{
			std::swap(*ifast, *limit++);

		}else if ((*ifast < p) and (*menor == p))
		{
			std::swap(*menor++, *ifast);
			std::swap(*ifast, *limit++);

		}else if (*ifast < p)
		{
			std::swap(*menor++, *ifast);
		}
	}
}
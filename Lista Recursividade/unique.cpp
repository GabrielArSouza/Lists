#include <iostream>
#include <iterator>
#include <utility>
#include <sstream>


int *unique (int *first, int *last, int *fast, int *slow)
{
	bool un = true;
	if (fast == last)
	{
		return slow;
	}else {
		for (auto i(first); i != slow and un; ++i)
		{
			if (*i == *fast)
				un = false;
		}
		if (un){
			std::swap(*slow, *fast);
			return unique(first, last, fast+1, slow+1);
		}else{
			return unique(first, last, fast+1, slow);
		}
	}
}

int main (int argc, char * argv[])
{
	int V[] = {1, 5, 8, 1, 5, 2, 3, 3, 3, 4, 5, 1, 6, 6, 8, 9, 11};

	auto first = std::begin(V);
	auto last = std::end(V);
	auto newLast = unique(first, last, first+1, first+1 );

	std::cout << "Novo vetor sem repetiçẽos: " << std::endl;
	std::cout << "[ ";
	for (auto j(std::begin(V)); j < newLast; ++j)
	{
		std::cout << *j << " ";
	}
	std::cout << " ]" <<std::endl;

	return EXIT_SUCCESS;

}
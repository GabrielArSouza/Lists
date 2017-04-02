#include <iostream>
#include <iterator>

int * compact (int *first, int *last);

int main ()
{
	int V[] = {-2, -8, 2, 7, -3, 10, 1, 0, -3, 7};

	int * i = compact (std::begin(V), std::end(V));
	std::cout << ">>>O novo last aponta para: " << *i << std::endl;

	return 0;
}

int * compact (int *first, int *last)
{
	auto iFast(first);
	auto iSlow(first);

	auto size(last);

	for (/*empty*/; iFast != size; iFast++)
	{
		if (*iFast > 0)
		{
			*iSlow = *iFast;
			iSlow++;
		}else
			last--;
	}

	return last;
}
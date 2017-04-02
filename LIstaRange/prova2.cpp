#include <iostream>
#include <iterator>
#include <utility>

void organize(int *V, size_t first, size_t last, size_t i);

int main ()
{

	int A[] = { -5, -7, 10, 7, 8, 9, 1, 7, -2, 3}
	sizeA = sizeof(A)/sizeof(int);

	organize(A, 0, sizeA-1, 3);

	return 0;
}

void organize(int *V, size_t first, size_t last, size_t reference)
{
	auto lim_smaller = first;
	auto lim_equal  = first+1;

	auto value = V[reference];

	for (/*empty*/; first != last; ++first)
	{
		if (V[first] < value) std::swap(V[lim_smaller], V[i]);
		else if ()
	}
}
#include <iostream>
#include <iterator>
#include <utility>
#include <cassert>


enum ball_t 
{
	B=0, //black
	W=1 //white
};

size_t sort_black_white (ball_t *V, size_t first, size_t last);

int main ()
{

	ball_t A[] = {W, B, B, W, W, B, W}; //input
	auto size_A = sizeof(A)/sizeof(ball_t);
	ball_t A_sorted[] = { B, B, B, W, W, W, W}; //expected output

	auto size_white = sort_black_white(A, 0, size_A);
	assert(size_white == 3);

	std::cout << "As Brancas começam no size: " << size_white << "\n";

	//Validate answer
	for (auto i(0u); i< size_A; ++i)
	{
		assert(A[i] == A_sorted[i]);
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;

}

size_t sort_black_white (ball_t *V, size_t first, size_t last)
{

	auto iSlow = first;
	auto iFast = first;

	for (/*empty*/; iFast != last; ++iFast)
	{
		if(V[iFast] == B)
		{
			std::swap(V[iSlow], V[iFast]);
			iSlow++;
		}
	}

	return iSlow;

}
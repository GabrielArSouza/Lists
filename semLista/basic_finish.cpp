#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>

#define N 1048576// Number of default size.

/*!
 * \brief Fill a vector with random numbers in the range [lower, upper].
 * \param V The vector to be filled in.
 * \param lower The first number of the interval of possible values.
 * \param upper The last number of the inverval of possible values.
 * \param seed The seed used to generate random number.
 *
 * \note Providing the same `seed` means we got the same random numbers.
 */
void randomFill( std::vector<int> &V, const int lower, const int upper,
                 const unsigned int seed) {

    //use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(lower, upper);

    for( auto &elem : V ){
        elem = distr(eng);
    }
}

void compact (std::vector<int> V, std::size_t arrSz);

int main( int argc, char * argv[] )
{
    auto arrSz( 0ul );

    if ( argc > 1 ) // At least one argument provided.
    {
        std::stringstream( argv[1] ) >> arrSz;
    }
    else // No arguments, assume default size N.
    {
        arrSz = N;
    }

    // Let the user know the result.
    std::cout << ">>> Required array size is: " << arrSz << std::endl;

    // V stores the data.
    std::vector< int > V( arrSz );

    // Seed with a real random value, if available.
    std::random_device r;
    // Range of possible random values. This might become a user input as well.
    auto lower(-100), upper(100); // Range of value
    // Fill it up with random integers.
    randomFill( V, lower, upper, r() );

    //Printint out the array, just to make sure we've got random integers.
#ifdef PRINT_ARRAY
    std::cout << ">>> Vet = [ ";
    for( const auto &e : V )
        std::cout << e << " ";
    std::cout << "]\n";
#endif

    for ( auto i(8ul); i <= arrSz; i *= 2) { 


        std::vector<int> aux(i);
        std::copy(V.begin(), V.begin()+(i-1), aux.begin());
        std::chrono::duration<double, std::milli> acumulator(0);
        std::cout << "\t>>> STARTING computation that needs timing (for array size = " << i << ") <<< \n";
        
        for (auto j(0ul); j<100; ++j) {

            
            auto start = std::chrono::steady_clock::now();
            //================================================================================

            // WW SHOULD PUT HERE THE CODE WE WANT TO TIME.

                compact(aux, i);
           

            //================================================================================
            auto end = std::chrono::steady_clock::now();
            

            //Store the time difference between start and end
            auto diff = end - start;

            //armazenar diferença
            acumulator += diff;
            

        }

        //Show the media time of the 100 executions.
        std::cout << "\t>>Media de tempo de execução " << std::chrono::duration <double, std::milli> (acumulator/100).count() << "ms" << std::endl;

        std::cout << "\t>>> ENDING computation that needs timing <<<\n" << std::endl;
    
    }

    

    return EXIT_SUCCESS;

}



/*!
 *
 * \brief Compact the vector eliminating the negatives and zeros values.
 * \param V The vector to be filled in.
 * \param arrSz The lenght of the vector V.
 *
 */
void compact (std::vector<int> V, std::size_t arrSz){

    auto iSlow(0ul);
    auto iFast(0ul);

    auto new_size(arrSz);

    for (iFast = 0 ; iFast < arrSz ; ++iFast){
        if (V[iFast] > 0 ){
            V[iSlow] = V[iFast];
            iSlow++; 
        }else{
            new_size--;
        }
    }

}
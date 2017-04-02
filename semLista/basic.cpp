#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>


#define N 10000000// Number of 

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
    
    for ( auto i(1000ul); i <= arrSz; i *= 2) { 

        // std::chrono::steady _clock::time_point

        std::vector<int> aux(i);
        std::copy(V.begin(), V.begin()+(i-1), aux.begin());
        std::chrono::duration<double, std::milli> acumulator(0);

        for (auto j(0ul); j<100; ++j) {

            //std::cout << "\t>>> STARTING computation that needs timing <<<\n";
            auto start = std::chrono::steady_clock::now();
            //================================================================================

            // WW SHOULD PUT HERE THE CODE WE WANT TO TIME.

                compact(aux, i);
           

            //================================================================================
            auto end = std::chrono::steady_clock::now();
            //std::cout << "\t>>> ENDING computation that needs timing <<<\n";

            //Store the time difference between start and end
            auto diff = end - start;

            //armazenar diferença
            acumulator += diff;
            

        }


        /* // Milliseconds (10^-3)
        std::cout << "\t>>> " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

        // Nanoseconds (10^-9)
        std::cout << "\t>>> " << std::chrono::duration <double, std::nano> (diff).count() << " ns" << std::endl;

        // Seconds
        auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
        std::cout << "\t>>> " << diff_sec.count() << " s" << std::endl;
        */
        std::cout << "Media de tempo de execução " << (std::chrono::duration <double, std::milli> (acumulator).count())/100
         << "ms" << "Para " << i << "posições" << std::endl;

       


    }

    return EXIT_SUCCESS;

}

void compact (std::vector<int> V, std::size_t arrSz){

    auto iSlow(0ul);
    auto iFast(0ul);

    auto new_size(arrSz);

    for (iFast = 0 ; iFast < arrSz ; ++iFast){
        if (V[iFast] > 0 ){
            V[iSlow] = V[iFast];
            iSlow++; 
        }else{
            new_size --;
        }
    }

    /*std::cout << ">>> Vet = [ ";
    for( auto i(0ul) ; i < new_size ; i++)
        std::cout << V[i] << " ";
    std::cout << "]\n";*/

}

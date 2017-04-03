#include <iostream>
#include <iterator>
#include <cctype>
#include <string>

#include "graal.h"

void inverter_sinal( void * e)
{
	int * ptr = ( int * ) e; //converter para inteiro

	*ptr *= -1;
}

void multiplicar_10( void * e)
{
	int * ptr = ( int * ) e; //converter para inteiro

	*ptr *= 10;
}

void print (int *f, int *l)
{
	std::cout << "[ ";
	while ( f != l)
		std::cout << *f++ << " ";
	std::cout << "]\n";
}

void inverter_caixa ( void * e )
{
	char * c = (char *) e;
	*c = ( std::isupper( *c ) ) ? std::tolower( *c ) : std::toupper( *c );
}

void imprimir_caractere ( void * e)
{
	char * c = (char *) e;
	std::cout << *c ; 
}

void imprimir_int ( void * e)
{
	int * c = (int *) e;
	std::cout << *c << " "; 
}

bool compare ( const void *a, const void *b )
{
	auto aa = (const int *) a;
	auto bb = (const int *) b;

	return *aa == *bb;
}

bool compare_char ( const void *a, const void *b )
{
	auto aa = (const char *) a;
	auto bb = (const char *) b;

	return *aa == *bb;
}

int main ( void )
{
	int A[] = {2, -3, 4, 8, -5, 2, 7};

	auto target ( 8 );

	auto result = (int *) graal::find(std::begin(A), std::end(A), sizeof(int), &target, compare);

	std::cout << "[ ";
	graal::transform( std::begin(A), std::end(A), sizeof(int), imprimir_int );
	std::cout << " ]" << std::endl;

	if ( result == std::end(A) )
		std::cout << ">>>Elemento não encontrado!\n";
	else 
		std::cout << ">>>Elemento encontrado na posição "
				  << std::distance(std::begin(A), result) << ".\n";


	std::string s = "Exemplo de Uma string";

	graal::transform( &s[0], &s[s.size()], sizeof(char), imprimir_caractere );
	std::cout << std::endl;
	auto target2 ('U');
	auto result2 = (char *) graal::find( &s[0], &s[s.size()], sizeof(char), &target2, compare_char );

	if ( result2 == &s[s.size()] )
		std::cout << ">>>Elemento não encontrado!\n";
	else 
		std::cout << ">>>Elemento encontrado na posição "
				  << std::distance(&s[0], result2)<< ".\n";

	// std::cout << ">>> Before transform, A: ";
	// graal::transform( std::begin(A), std::end(A), sizeof(int), imprimir_int );
	// std::cout << std::endl;

	// graal::transform( std::begin(A), std::end(A), sizeof(int), multiplicar_10 );

	// std::cout << ">>> After transform, A: ";
	// graal::transform( std::begin(A), std::end(A), sizeof(int), imprimir_int );
	// std::cout << std::endl;

	// std::cout << ">>>String Before: " << s << std::endl;
	// graal::transform( &s[0], &s[s.size()], sizeof( char ), inverter_caixa );
	// std::cout << ">>>String After: " << s << std::endl;

	// graal::transform( &s[0], &s[s.size()], sizeof( char ), imprimir_caractere );

	return 0;
} 
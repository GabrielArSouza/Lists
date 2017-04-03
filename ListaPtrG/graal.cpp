#include "graal.h"

namespace graal {

	using byte = unsigned char;

	void transform ( void *first, void *last, std::size_t size, void (*func) ( void * ) )
	{
		//converter para byte  e assim usar aritimética de ponteiros
		byte *f = ( byte * ) first;
		byte *l = ( byte * ) last;
 
		//percorrer todo o range
		while ( f != l )
		{
			func( f ); //aplicando a transformação
			f += size;
		}
	}

	const void * find ( const void * first , const void * last , std::size_t size , 
						const void * target , bool (*eq) (const void *, const void *))
	{
		//converter 
		byte *f = (byte *) first;
		byte *l = (byte *) last;

		//percorrer 
		while ( f != l )
		{
			if ( eq( f, target ) ) // *f == *target
				return f;
			f += size;
		}

		return last; //return l (ou last) (ou f)
	} 

}
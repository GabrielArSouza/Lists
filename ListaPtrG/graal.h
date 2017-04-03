#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstdlib>
namespace graal {

	void transform ( void *first, void *last, size_t size, void (*func) ( void * ) );
	const void * find ( const void * first , const void * last , size_t size , 
						const void * target , bool (*eq) (const void *, const void *));

}


#endif
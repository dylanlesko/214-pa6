#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<errno.h>
#include 	"headers.h"

#define BLOCKSIZE	5000
static char big_block[BLOCKSIZE];

int compare_pointers(void * p1, void * p2) 
{
	return p1 - p2;
}

void * mymalloc( unsigned int size, char * file, int line )
{
	int i;
	void * ret;
	static int initialized = 0;
	static memBlock *root;
	memBlock *p;
	memBlock *succ;	
	
	if ( !initialized )
	{
		root = (memBlock*)big_block;
		initialized = 1;
	}
	p = root;
	do
	{
		// too small
		if( p->size < size )
		{
			p = p->next;
		}
		else if ( !p->free )
		{
			p = p->next;
		}
		else if ( p->size < (size + sizeof(memBlock) ) )
		{
			p->free = 0;
			return (char *)p + sizeof(struct memBlock);
		}
		
		
		//ret = (char *)p + sizeof(memBlock);
		//return ret;
	} 
	
	while ( p != 0 );
	
	return 0;
	





	


}

void my_free( void * p, char * file, int line )
{
	
}

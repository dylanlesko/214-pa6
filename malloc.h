typedef struct memBlock
{
	unsigned int offset;
	unsigned int size;
	struct memBlock *next;
	struct memBlock *prev;
	int free;
} memBlock;


#define malloc( x ) 				\
printf("\ncustom malloc\n\n");		\
mymalloc( x, __FILE__, __LINE__ );

Order Analysis:
FiloTree(string fileName)
	O(n^3) sequential loops are dropped in O notation. Largest growth rate is come from where nodes and grid is manipulated. n = number of strings

~FiloTree( )
	O(1) because it is a single statement
	
void dump( ) const
	O(n) where n = size of the array holding the strings
	
static void compare( const FiloTree &A, const FiloTree &B, int size)
	O(n) because it will only run as many times as the size given

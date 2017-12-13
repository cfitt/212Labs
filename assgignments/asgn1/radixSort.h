#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <string>
using namespace std;

void radixSort( string list[], int listLength );

/*

Example list:
	cab
	bee
	dab
	bad
	ebb

(26 queues, one for each letter) create a queue for each letter of the alphabet

"enqueue"
1st round, last letter first:
a:
b: cab, dab, ebb 
c:
d: bad
e: bee

"dequeue"
then merge
	cab
        dab
        ebb
	bad
	bee

"enqueue"
2nd round (middle letter):
a: cab, dab, bad
b: ebb
c: 
d:
e: bee

"dequeue"
then merge
        cab
        dab
        bad
	ebb
        bee

"enqueue"
3nd round (first letter):
a: 
b: bad, bee 
c: cab
d: dab
e: ebb

"dequeue"
then final merge, and they are in order:
	bad
	bee
	cab
	dab
	ebb

*/




#endif

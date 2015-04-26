#include "linkedList.h"
#include <stdio.h>

int main(){
	struct linkedList* q = createLinkedList(); 
	printf("%d\n",isEmptyList(q));
	addBackList(q, (TYPE)1);
	addBackList(q, (TYPE)2);
	addFrontList(q, (TYPE)4);
	addFrontList(q, (TYPE)5);
	printf("%d\n", frontList(q));
	printf("%d\n", backList(q));
        _printList(q);
	removeFrontList(q);
	removeBackList(q);
        _printList(q);
	addBackList(q, (TYPE)7);
	_printList(q);
	printf("%d\n",containsList(q,7));
	removeList(q,(TYPE)7);
	_printList(q);

	return 0;
}

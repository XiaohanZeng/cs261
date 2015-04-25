#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
  	/* FIXME: you must write this */	
    q->size = 0;
    q->Sentinel = NULL;
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
    struct DLink *newDlink = malloc(sizeof(struct DLink));
    newDlink->value = val;
    newDlink->prev = NULL;
    newDlink->next = NULL;

	/*temporary return value..you may need to change it*/
	return newDlink;	 

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */
    assert(q != NULL);
    struct DLink* current = q->Sentinel->next;
        do{
            current = current->next;
        } while (current != lnk && current != q->Sentinel);
        if (current != q->Sentinel)
        {
            struct DLink *add = _createLink(v);
            struct DLink* temp = lnk->next;
            lnk->next = add;
            add->prev = lnk;
            temp->prev = add;
            add->next = temp;
        }
        q->size++;
    

}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */	
    assert(q != NULL);
    struct DLink* tempLast = q->Sentinel->prev;
    struct DLink *add = _createLink(val);
    q->Sentinel->prev = add;
    tempLast->next = add;
    add->prev = tempLast;
    add->next = q->Sentinel;
    q->size++;
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */	 
    assert(q != NULL);
    struct DLink* tempFirst = q->Sentinel->next;
    struct DLink *add = _createLink(val);
    q->Sentinel->next = add;
    add->prev = q->Sentinel;
    add->next = tempFirst;
    tempFirst->prev = add;
    q->size++;
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIXME: you must write this */
    assert(q != NULL && q->size != 0);
	/*temporary return value..you may need to change it*/
	return q->Sentinel->next->value;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
    assert(q != NULL && q->size != 0);
	/*temporary return value..you may need to change it*/
    return q->Sentinel->prev->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */
    assert(q != NULL && q->size != 0);
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;
    free(lnk);
    q->size--;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
    assert(q != NULL && q->size != 0);
    struct DLink *move = q->Sentinel->next;
    q->Sentinel->next = move->next;
    move->prev = q->Sentinel;
    free(move);
    q->size--;
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */
    assert(q != NULL && q->size != 0);
    struct DLink *move = q->Sentinel->prev;
    q->Sentinel->prev = move->prev;
    move->next = q->Sentinel;
    free(move);
    q->size--;
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
    struct DLink* current = q->Sentinel->next;
    do{
        struct DLink *temp = current;
        free(current);
        current = temp->next;
    } while (current != q->Sentinel);
    q->size = 0;
    free(q->Sentinel);
	
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
    assert(q != NULL);
	/*temporary return value..you may need to change it*/
    if (q->size == 0)
        return 1;
    else
        return 0;

}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
    assert(q != NULL);
    struct DLink* current = q->Sentinel->next;
    do{
        printf("%f \n", current->value);
        current = current->next;
    } while (current != q->Sentinel);

}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	   
    assert(q != NULL && q->size != 0);
    int count = 0;
    struct DLink* current = q->Sentinel;
    do{

        struct DLink* temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
        count++;
    } while (count <= (q->size + 1));
}

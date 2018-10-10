#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct _heap heap;
typedef struct _heap* heapPtr;
struct _heap {
	int *data, num;
    void (*init)(heapPtr, int);
    void (*link)(heapPtr, int, int);
    int	 (*head)(heapPtr, int);
    void (*show)(heapPtr);
	void (*del)(heapPtr);
	bool (*isin)(heapPtr, int);
	int	 (*keyval)(heapPtr);
};

void structHeapInitialize(heapPtr);
void heapInit(heapPtr, int);
void heapLink(heapPtr, int, int);
int	 heapHead(heapPtr, int);
void heapShow(heapPtr);
void heapDelete(heapPtr);

#endif // HEAP_H_INCLUDED

#ifndef TYPES_H_
#define TYPES_H_

typedef struct _SList SList;
struct _SList {
	void 		 * data;
	struct _SList 		 * next;
};

typedef struct _DList DList;
struct _DList {
	void 		 * data;
	struct _DList * next;
	struct _DList * prev;
};

typedef struct _TimeVal TimeVal;

struct _TimeVal
{
  long tv_sec;
  long tv_usec;
};

#endif /*TYPES_H_*/

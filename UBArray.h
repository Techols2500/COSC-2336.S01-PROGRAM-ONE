//************************************************************************** 
//
// Programming Excerise 1   
// CLASS: COSC 2336.S01
// AUTHOR: TYLER ECHOLS 
// DATE: Sep 2017  
//
//************************************************************************** 

#ifndef UBARRAY_H
#define UBARRAY_H

#include "WCS_Pointer.h"


template <class DATA, class INDEX>
class UBArray
{
public:
	enum Exceptions { OK, InvalidIndex, ArrayEmpty, NoNextElement, NoPrevElement, InteratorNotInitiailized };
private:
	struct Node : public RefCount
	{
		INDEX				index;
		DATA				Data;
		WCS_Pointer <Node>	pNext;
		WCS_Pointer <Node>	pPrev;

		Node(const INDEX &);
		~Node();
	};
//______________________ Methods _______________________________________
public:
	UBArray();
	~UBArray();
	DATA &						At(const INDEX &);
	
	const DATA &						GetFirst()const;
	
	
	const DATA &						GetNext()const;
	 
	
	const DATA &						GetPrev()const; 
	

	const DATA &						GetLast()const; 
	 
	
	void								DeleteAll();

	
	bool						Remove(INDEX);
	int							Size() const;
	DATA &						operator []	(const INDEX &);
	DATA &				operator [] (const INDEX &) const;
//______________________ Properties _______________________________________
private:
							UBArray (const UBArray <DATA, INDEX> &);
	UBArray <DATA, INDEX> &	operator =	(const UBArray <DATA, INDEX> &);

	WCS_Pointer <Node>			pHead;
	WCS_Pointer <Node>			pTail;
	mutable	WCS_Pointer <Node>			pCurrent;
	size_t							numElements;	
};
//______________________ Method Definitions _______________________________________
template <class DATA, class INDEX>
UBArray <DATA, INDEX>::Node::Node(const INDEX & i) : index(i)
{

}

template <class DATA, class INDEX>
UBArray <DATA, INDEX>::Node::~Node()
{
#ifdef _DEBUG
	
	cout << "Node has been deleted" << endl;
#endif
}

template <class DATA, class INDEX>
UBArray <DATA, INDEX>::UBArray() : numElements(0)
{

}

template <class DATA, class INDEX>
UBArray <DATA, INDEX>::~UBArray()
{
	
}

template <class DATA, class INDEX>
inline DATA & UBArray <DATA, INDEX>::At(const INDEX & i)
{

	return operator [] (i);
}

template <class DATA, class INDEX>
const DATA & UBArray <DATA, INDEX>::GetFirst() const
{
	if (!pHead)
		throw ArrayEmpty;
	else
	{
		pCurrent = pHead;
		return (*pHead).Data;
	}
}


template <class DATA, class INDEX>
const DATA & UBArray <DATA, INDEX>::GetNext() const
{
	if (!pCurrent)
		throw InteratorNotInitiailized;
	else
		if (!(*pCurrent).pNext)
			throw NoNextElement;
		else
		{
			pCurrent = (*pCurrent).pNext;
			return (*pCurrent).Data;
		}
}




template <class DATA, class INDEX>
const DATA & UBArray <DATA, INDEX>::GetPrev() const
{
	if (!pCurrent)
		throw InteratorNotInitiailized;
	else
		if (!(*pCurrent).pPrev)
			throw NoPrevElement;
		else
		{
			pCurrent = (*pCurrent).pPrev;
			return (*pCurrent).Data;
		}
}




template <class DATA, class INDEX>
const DATA & UBArray <DATA, INDEX>::GetLast() const 
{
	if (!pTail)
		throw ArrayEmpty;
	else
	{
		pCurrent = pTail;
		return (*pTail).Data;
	}
}



template <class DATA, class INDEX>
bool UBArray <DATA, INDEX>::Remove(INDEX i)
{
	WCS_Pointer <Node> pNode;

		if (!pHead)
		{
			return false;
		}
	if ((i > (*pTail).index) || (i < (*pHead).index))
	{

	return false;
}

	if (i == (*pTail).index)
	{
		if ((*pTail).index == (*pHead).index)
		{
		pHead.SetToNull(); 
		pTail.SetToNull(); 
}
		else
		{
			(*(*pTail).pPrev).pNext = (*pTail).pPrev; 
			pTail = (*pTail).pPrev; 
			numElements--; 
			return true; 
		}
	}

	if (i == (*pHead).index)
	{ 
		(*(*pHead).pNext).pPrev = (*pHead).pNext;
pTail = (*pHead).pNext;
numElements--;
return true;
	}

	for (pNode = (pHead); i >= (*pNode).index; pNode = (*pNode).pNext)
	{
		if (i == (*pNode).index)
		{
			(*(*pNode).pPrev).pNext = (*pNode).pNext;
			(*(*pNode).pNext).pPrev = (*pNode).pPrev;
			numElements--;
			return true;
		}
	}

	return false;
}

template <class DATA, class INDEX>
int UBArray <DATA, INDEX>::Size() const
{
	return numElements;
}

template <class DATA, class INDEX>
DATA & UBArray <DATA, INDEX>::operator [] (const INDEX & i) 
{
	WCS_Pointer <Node>		pTemp;
	WCS_Pointer <Node>		pTemp2;

	if (!pHead)
	{			
		pHead = WCS_Pointer <Node>(new Node(i));	
		numElements++;
		pTail = pHead;
		return (*pHead).Data;
	}
	else
		if (i == (*pHead).index)
		{
			return (*pHead).Data;
		}
		else
		{
			if (i < (*pHead).index)
			{		
				pTemp = WCS_Pointer <Node>(new Node(i));
				numElements++;
				(*pTemp).pNext = pHead;
				(*pHead).pPrev = pTemp;
				pHead = pTemp;
				return (*pHead).Data;
			}
			else
			{
				if (i == (*pTail).index)
				{
					return (*pTail).Data;
				}
				else
				{
					if (i > (*pTail).index)
					{
						pTemp = WCS_Pointer <Node>(new Node(i));
						numElements++;
						(*pTemp).pPrev = pTail;
						(*pTail).pNext = pTemp;
						pTail = pTemp;
						return (*pTail).Data;
					}
					else
					{
						for (pTemp = (*pHead).pNext; i > (*pTemp).index; pTemp = (*pTemp).pNext);
						if (i == (*pTemp).index)
						{
							return (*pTemp).Data;
						}
						else
						{
							pTemp2 = WCS_Pointer <Node>(new Node(i));
							numElements++;
							(*pTemp2).pNext = pTemp;
							(*pTemp2).pPrev = (*pTemp).pPrev;
							(*pTemp).pPrev = pTemp2;
							(*(*pTemp2).pPrev).pNext = pTemp2;
							return (*pTemp2).Data;
						}
					}
				}
			}
		}
				}


template <class DATA, class INDEX>
DATA & UBArray <DATA, INDEX>::operator [] (const INDEX & i) const
{
	WCS_Pointer <Node>	pNode;
	if (!pHead)
	{
		throw ArrayEmpty;
	}
	if ((i > (*pTail).index) || (i < (*pHead).index))
	{
		throw InvalidIndex;
	}
	for (pNode = (pHead); i >= (*pNode).index; pNode = (*pNode).pNext)
	{
		if (i == (*pNode).index)
		{
			return (*pNode).Data;
		}
	}
	throw InvalidIndex;
}

template <class DATA, class INDEX>
void UBArray <DATA, INDEX>::DeleteAll()
{
	WCS_Pointer <Node> pNode;
	if (pHead)
	{
		for (pNode = (*pHead).pNext; (*pHead).index < (*pTail).index; pNode = (*pNode).pNext)
		{
		(*pNode).pPrev = (*(*pNode).pPrev).pNext;
		pHead = pNode;
		numElements--;
		}

		pHead.SetToNull();
		pTail.SetToNull();
		numElements--;
	}
}


#endif

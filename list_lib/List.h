#pragma once
#include "ListElem.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
private:
	TListElem<T>* root;
	TListElem<T>* end;
public:
	TList();

	//TList(const TList& other);
	~TList();
	//TList<T>& operator = (TList<T>& _list);

	void InsFirst(T d);
	void InsLast(T d);
	void Ins(TListElem<T>* e,T d);

	TListElem<T>* GetFirst();
	TListElem<T>* GetLast();

	void DelFirst();
	void DelLast();
	void Del(TListElem<T>* e);

	template <class T1>
	friend ostream& operator << (ostream& ostr, const TList<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TList<T1>& A);
};

template<class T>
inline TList<T>::TList()
{
	root = end = 0;
}

template<class T>
inline TList<T>::~TList()
{
	if (this->root != 0)
	{
		TListElem<T>* i = root;
		TListElem<T>* p = i;
		while (i != 0)
		{
			p = i;
			i = i->GetNext();
			delete p;
		}

		this->root = 0;
		this->end = 0;
	}
}

template<class T>
inline void TList<T>::InsFirst(T d)
{
	TListElem<T> *tmp = new TListElem<T>(d);
	tmp->SetNext(root);
	root = tmp;
	if ((end == 0)||(root == 0)) end = root;
}

template<class T>
inline void TList<T>::InsLast(T d)
{
	if ((end == 0) && (root == 0)) this->InsFirst(d);
	else 
	{
		TListElem<T>* tmp = new TListElem<T>(d);
		tmp->SetPrev(end);
		end->SetNext(tmp);
		end = tmp;
		if ((end == 0) || (root == 0)) end = root;
	}
}

template<class T>
inline void TList<T>::Ins(TListElem<T>* e, T d)
{
	TListElem<T>* tmp = new TListElem<T>(d);
	
	tmp->SetNext(e->GetNext());
	tmp->SetPrev(e);
	e->GetNext()->SetPrev(tmp);
	e->SetNext(tmp);
}

template<class T>
inline TListElem<T>* TList<T>::GetFirst()
{
	return root;
}

template<class T>
inline TListElem<T>* TList<T>::GetLast()
{
	return end;
}

template<class T>
inline void TList<T>::DelFirst()
{
	if ((root == 0) && (end == 0)) throw  logic_error("out_of_range");
	TListElem<T>* i = root;
	root = root->GetNext();
	delete i;
}

template<class T>
inline void TList<T>::DelLast()
{
	if ((root == 0) && (end == 0)) throw  logic_error("out_of_range");
	TListElem<T>* i = end;
	end = end->GetPrev();
	delete i;
	end->SetNext(0);
}

template<class T>
inline void TList<T>::Del(TListElem<T>* e)
{
	if ((root == 0) && (end == 0)) throw logic_error("out_of_range");
	if (e == root)
		this->DelFirst();
	else if (e == end)
		this->DelLast();
	else
	{
		e->GetPrev()->SetNext(e->GetNext());
		e->GetNext()->SetPrev(e->GetPrev());
		delete e;
	}
}

template<class T1>
inline ostream& operator<<(ostream& ostr, const TList<T1>& A)
{
	TListElem<T1>* i = A.root;

	while (i != NULL)
	{
		ostr << *i << endl;
		i = i->GetNext();
	}

	return ostr;
}

template<class T1>
inline istream& operator>>(istream& istr, TList<T1>& A)
{
	int count;
	istr >> count;
	for (int i = 0; i < count; i++)
	{
		T1 d;
		istr >> d;
		A.InsFirst(d);
	}
	return istr;
}



/*
template<class T>
inline TList<T>::TList(const TList& other)
{
	TListElem<T>* i = other.root;

	TListElem<T> j(*i);
	this->root = &j;
	i = i->GetNext();

	while (i != NULL)
	{
		TListElem<T> k(*i);
		i = i->GetNext();
	}
	this->end = i;
}
*/

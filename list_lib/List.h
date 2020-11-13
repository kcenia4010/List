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
	~TList();

	void InsFirst(T d);
	void InsLast(T d);
	void Ins(TListElem<T>* e,T d);

	TListElem<T>* GetFirst();
	TListElem<T>* GetLast();

	void DelFirst();
	void DelLast();
	void Del(TListElem<T>* e);

	bool elem(T e);
	void swap(T old_elem, T new_elem);
	void combine(const TList<T>& other);

	template <class T1>
	friend ostream& operator << (ostream& ostr, const TList<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TList<T1>& A);
};

template<class T>
inline TList<T>::TList()
{
	root = end = nullptr;
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

		this->root = nullptr;
		this->end = nullptr;
	}
}

template<class T>
inline void TList<T>::InsFirst(T d)
{
	TListElem<T> *tmp = new TListElem<T>(d);
	tmp->SetNext(root);
	root = tmp;
	if ((end == nullptr)||(root == nullptr)) end = root;
}

template<class T>
inline void TList<T>::InsLast(T d)
{
	if ((end == nullptr) && (root == nullptr)) this->InsFirst(d);
	else 
	{
		TListElem<T>* tmp = new TListElem<T>(d);
		tmp->SetPrev(end);
		end->SetNext(tmp);
		end = tmp;
		if ((end == nullptr) || (root == nullptr)) end = root;
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
	if ((root == nullptr) && (end == nullptr)) throw  logic_error("out_of_range");
	TListElem<T>* i = root;
	root = root->GetNext();
	delete i;
}

template<class T>
inline void TList<T>::DelLast()
{
	if ((root == nullptr) && (end == nullptr)) throw  logic_error("out_of_range");
	TListElem<T>* i = end;
	end = end->GetPrev();
	delete i;
	end->SetNext(0);
}

template<class T>
inline void TList<T>::Del(TListElem<T>* e)
{
	if ((root == nullptr) && (end == nullptr)) throw logic_error("out_of_range");
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

template<class T>
inline bool TList<T>::elem(T e)
{
	TListElem<T>* i = root;

	while (i != NULL)
	{
		if (e == i->GetData()) return true;
		i = i->GetNext();
	}
	return false;
}

template<class T>
inline void TList<T>::swap(T old_elem, T new_elem)
{
	TListElem<T>* i = root;

	while (i != NULL)
	{
		if (old_elem == i->GetData())
			i->SetData(new_elem);
		i = i->GetNext();
	}
}

template<class T>
inline void TList<T>::combine(const TList<T> &other)
{
	TListElem<T>* i = other.root;

	while (i != NULL)
	{
		this->InsLast(i->GetData());
		i = i->GetNext();
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



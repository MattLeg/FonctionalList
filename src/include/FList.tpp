#include "include/FList.h"

template<class T>
FList<T>::FList() = default;

template<class T>
FList<T>::FList(std::list<T> l) : std::list<T>(l) {
}

template<class T>
FList<T>::FList(std::initializer_list<T> l) : std::list<T>(l) {
}

template<class T>
FList<T>::~FList() {
//	default;
	//std::cout << "destructeur " << this << std::endl;
}

template<class T>
T FList<T>::head() {
	return std::list<T>::front();
}

template<class T>
FList<T> FList<T>::tail()
{
	FList<T> tail = (*this);
	tail.pop_front();
	//std::cout << "pop : " << this << std::endl;
	return tail;
}

template<class T>
FList<T>& FList<T>::add(const T e)
{
	std::list<T>::push_back(e);
	//std::cout << "add : " << this << std::endl;
	return *this;
}

template<class T>
FList<T>& FList<T>::_tail_()
{
	std::list<T>::pop_front();
	return (*this);
}

template<class T>
std::tuple<T, FList<T>> FList<T>::fetch()
{
	T head = FList<T>::head();
	FList<T> tail = FList<T>::tail();
	return std::make_tuple(head, tail);
}

template<class T>
template<typename F>
FList<T> FList<T>::map(F func)
{
	FList<T> oriList = *this;
	FList<T> newList;

	FList<T>::_map_(oriList, newList, func);
	return newList;
}

template<class T>
template<typename F>
FList<T>& FList<T>::_map_(FList<T>& oriList, FList<T>& newList, F func) {

	if (oriList.empty()) {
		//return newList;
		return newList;
	}
	else {
		newList.push_back(func(oriList.head()));
		oriList._tail_();
		//std::cout << "passage " << newList.size() << std::endl;
		return FList<T>::_map_(oriList, newList, func);
		//std::cout << "_map_ : " << this << " " << &oriList << " " << &newList << std::endl;
		//return FList<T>::_map_(oriList.tail(), newList.add(func(oriList.head())), func);
	}
}

template<class T>
template<typename F>
T FList<T>::flatMap(F func)
{
	FList<T> oriList = *this;
	T res = func(oriList.head());
	oriList._tail_();

	return FList<T>::_flatMap_(oriList, res, func);
}

template<class T>
template<typename F>
T& FList<T>::_flatMap_(FList<T>&oriList, T & res, F func) {

	if (oriList.empty()) {
		return res;
	}
	else {
		T head = oriList.head();
		res = res + func(head);
		oriList._tail_();
		return FList<T>::_flatMap_(oriList, res, func);
	}
}

template<class T>
template<typename F>
T FList<T>::foldLeft(T beginVal, F func)
{
	FList<T> oriList = *this;

	return FList<T>::_foldLeft_(oriList, beginVal, func);
}

template<class T>
template<typename F>
T FList<T>::_foldLeft_(FList<T>&oriList, T res, F func)
{
	if (oriList.empty()) {
		return res;
	}
	else {
		auto res2 = func(res, oriList.head());
		oriList._tail_();
		return FList<T>::_foldLeft_(oriList, res2, func);
	}
}

template<class T>
template<typename F>
T FList<T>::foldRight(T beginVal, F func)
{
	FList<T> oriList = *this;

	return FList<T>::_foldRight_(oriList, beginVal, func);
}

template<class T>
template<typename F>
T FList<T>::_foldRight_(FList<T>&oriList, T res, F func)
{
	if (oriList.empty()) {
		return res;
	}
	else {
		T head = oriList.head();
		FList<T> tail = oriList._tail_();
		return func(head, FList<T>::_foldRight_(tail, res, func));
	}
}

template<class T>
template<typename F>
FList<T> FList<T>::filter(F predicate)
{
	FList<T> oriList = *this;
	FList<T> newList;

	return _filter_(oriList, newList, predicate);
}

template<class T>
template<typename F>
FList<T>& FList<T>::_filter_(FList<T>&oriList, FList<T>&newList, F predicate)
{
	if (oriList.empty()) {
		return newList;
	}
	else {
		T head = oriList.front();
		if (predicate(head))
		{
			newList.push_back(head);
		}
		oriList.pop_front();
		return _filter_(oriList, newList, predicate);
	}
}

template<class T>
FList<T>& FList<T>::operator=(const std::list<T> && aList) {
	std::list<T>::operator=(aList);
	return *this;
}

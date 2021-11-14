//
// Created by sorge on 27/03/2021.
//

#ifndef FUNCTIONNALLISTCPP_FLIST_H
#define FUNCTIONNALLISTCPP_FLIST_H
#include "spdlog/spdlog.h"
#include "tuple"
#include "list"

template<class  T>
class FList : public std::list<T> {
public :

    // constructors
    FList<T>();
    FList<T>(std::list<T> l);
    FList<T>(std::initializer_list<T> l);

    // destructors
    virtual ~FList();

    // head & tail
    T head();
    FList<T> tail();
    FList<T>& add(const T);
    std::tuple<T, FList<T>> fetch();

    // functions
    template<typename F>
    // tail recursive
    FList<T> map(F func);
    template<typename F>
    // tail recursive
    T flatMap(F func);
    template<typename F>
    // tail recursive
    T foldLeft(T, F func);
    template<typename F>
    // not tail recursive !!!
    T foldRight(T, F func);
    // tail recursive
    template<typename  F>
    FList<T> filter(F predicate);

    // operators
    FList<T>& operator=(const std::list<T>&&);

private :
    // function that should'nt be call...
    // use reference to not overflow the stack...
    FList<T>& _tail_();
    template<typename F>
    FList<T>& _map_(FList<T>&, FList<T>&, F);
    template<typename F>
    T& _flatMap_(FList<T>&, T&, F);
    template<typename F>
    T _foldLeft_(FList<T>&, T, F);
    template<typename F>
    T _foldRight_(FList<T>&, T, F);
    template<typename  F>
    FList<T>& _filter_(FList<T>& oriList, FList<T>& newList, F predicate);
};

#include "FList.tpp"

#endif //FUNCTIONNALLISTCPP_FLIST_H

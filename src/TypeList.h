/*

author : Rahul Jaisimha


TypeList is a list of classes.

 Declare as TypeList<Class0, Class1, ..., ClassN>

 For the following examples, assume we have assigned typelist as
 using typelist = TypeList<Class0, Class1, ..., ClassN>;

 get type:
 typelist::type<I>
 	returns ClassI

 get length:
 typelist::length
 	returns number of types (N + 1 in this example)

 get if contains type T
 typelist::contains<T>()
 	returns boolean for whether or not typelist has T as one of its types
 */

#ifndef TYPELIST_H
#define TYPELIST_H

#include <tuple>

using std::tuple;

// forward declaration
template <class... Args>
struct TypeList;

// ----------has_type---------------------------------------

// the base type
template <typename queryType, typename typelist>
struct has_type;

// specialization 1 : empty
template <typename T>
struct has_type<T, TypeList<>>{
	static constexpr bool contains = false;
};

// specialization 2 : general recursive
template <typename T, typename notT, typename... tail>
struct has_type<T, TypeList<notT, tail...>>{
	static constexpr bool contains = has_type<T, TypeList<tail...>>::contains;
};

// specialization 3 : contains
template <typename T, typename... tail>
struct has_type<T, TypeList<T, tail...>>{
	static constexpr bool contains = true;
};

//---------------------------------------------------------------------

template <class... Args>
struct TypeList
{
	static constexpr int length = std::tuple_size<std::tuple<Args...>>::value;

	template <std::size_t N>
	using type = typename std::tuple_element<N, std::tuple<Args...>>::type;

	template <typename T>
	static bool contains(){
		return has_type<T, TypeList<Args...>>::contains;
	}
};

#endif //ifndef TYPELIST_H

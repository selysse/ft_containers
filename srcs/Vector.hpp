/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:11:14 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 04:45:29 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Container.hpp"
#include "Vector_Iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef	size_t									size_type;
			typedef T&										reference;
			typedef T*										pointer;
			typedef T const &								const_reference;
			typedef	const T*								const_pointer;
			typedef ptrdiff_t								difference_type;
			typedef ft::iterator_vector<T>					iterator;
			typedef ft::const_iterator_vector<T>			const_iterator;
			typedef ft::reverse_vector_iterator<T>			reverse_iterator;
			typedef ft::const_reverse_vector_iterator<T>	const_reverse_iterator;		
		private:
			size_type			_size;
			size_type			_capacity;
			allocator_type		_alloc;
			pointer				_arr;
			
		public:
			explicit Vector(const allocator_type &alloc = allocator_type()){
				this->_size = 0;
				this->_capacity = 0;
				this->_alloc = alloc;
				this->_arr = NULL;
			};
			explicit Vector(size_type n, const value_type & val = value_type(),
							const allocator_type &alloc = allocator_type()){
				this->_size = n;
				this->_capacity = n;
				this->_alloc = alloc;
				this->_arr = new value_type[n];
				for (size_t i = 0; i < n; i++)
					this->_arr[i] = val;
			};
			template <class InputIterator>
					Vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), 
					typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL){
						this->_alloc = alloc;
						this->_size = 0;
						this->_capacity = 0;
						this->_arr = NULL;
						this->assign(first, last);
			}
			Vector(const Vector&x){
				this->_arr = NULL;
				this->_size = 0;
				this->_capacity = 0;
				this->_alloc = x._alloc;
				*this = x;
			}
			Vector &operator=(const Vector &x){
				this->clear();
				this->_alloc = x._alloc;
				this->reserve(x._size);
				for(size_type i = 0; i < x._size; i++)
					push_back(x[i]);
				return (*this);
			}
			~Vector(){
				if (this->_arr)
				{
					delete[] this->_arr;
					this->_arr = NULL;
				}
			}
			
			//iterators
			iterator begin(){
				return iterator(this->_arr);
			}
			const_iterator begin() const{
				return const_iterator (this->_arr);
			}
			iterator end(){
				return iterator(&this->_arr[this->_size]);
			}
			const_iterator end() const{
				return const_iterator(&this->_arr[this->_size]);
			}
			reverse_iterator rbegin(){
				return reverse_iterator(this->_arr + this->_size - 1);
			}
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(this->_arr + this->_size - 1);
			}
			reverse_iterator rend(){
				return reverse_iterator(this->_arr - 1);
			}
			const_reverse_iterator rend()const {
				return const_reverse_iterator(this->_arr - 1);
			}
			//capacity
			size_type	size()const{
				return this->_size;
			}
			size_type	max_size()const{
				return allocator_type().max_size();
			}
			void		resize(size_type n, value_type val = value_type()){
				if (n < this->_size)
					this->pop_back();
				if (n > this->_size){
					for (size_t i = this->_size; i < n; ++i)
						push_back(val);
				}
			}
			size_type	capacity()const{
				return this->_capacity;
			}
			bool		empty()const{
				if (this->_size == 0)
					return true;
				return false;
			}
			void		reserve(size_type n){
				if (n <= _capacity)
					return ;
				T* newarr = reinterpret_cast<T*>(new int[n* sizeof(T)]);
				size_t i = 0;
				try{
					for (; i < this->_size; ++i){
					new (newarr + i) T(this->_arr[i]);
					}
				}
				catch (...){
					for (size_t j = 0; j < i; --j){
						(newarr + i)->~T();
					}
					delete[] reinterpret_cast<int*> (newarr);
					throw;
				}
				for (size_t i = 0; i < this->_size; ++i){
					(this->_arr + i)->~T();
				}
				delete[] reinterpret_cast<int*> (this->_arr);
				this->_arr = newarr;
				this->_capacity = n;
			}
			
			//element access
			reference operator[] (size_type n){
				return this->_arr[n];
			}
			const_reference operator[] (size_type n) const{
				return this->_arr[n];
			}
			reference at(size_type n){
				if (n >= this->_size)
					throw std::out_of_range("...");
				return this->_arr[n];
			}
			const_reference at(size_type n) const{
				if (n >= this->_size)
					throw std::out_of_range("...");
				return this->_arr[n];
			}
			reference front(){
				return this->_arr[0];
			}
			const_reference front()const{
				return this->_arr[0];
			}
			reference back(){
				return this->_arr[this->_size - 1];
			}
			const_reference back() const{
				return this->_arr[this->_size - 1];
			}
			
			//modifiers
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last, 
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL){
				this->clear();
				while (first != last)
				{
					this->push_back(*first);
					++first;
				}
			};
			void	assign(size_type n, const value_type &val){
				if (n < 0)
					throw std::length_error("...");
				this->clear();
				while(n > 0)
				{
					this->push_back(val);
					n--;
				}
			};
			void		push_back(const T& value){
				if (this->_size == 0)
					reserve(1);
				else if (this->_size == this->_capacity)
					reserve(this->_capacity * 2);
				this->_arr[this->_size++] = value;
			}
			void		pop_back(){
				if (this->_size)
					this->_size--;
			}
			iterator insert(iterator position, const value_type &val){
				insert(position, 1, val);
				return position;
			}
			void	insert(iterator position, size_type n, const value_type &val){
				Vector vec(position, this->end());
				if ((this->_size + n) > this->_capacity){
					size_type i = this->_capacity;
					if (!i)
						this->reserve(n);
					else{
						while (i < this->_size + n)
							i *= 2;
						this->reserve(i);
					}
				}
				this->_size -= vec.size();
				for (size_t j = 0; j < n; j++)
					this->push_back(val);
				iterator it = vec.begin();
				iterator in = vec.end();
				while(it != in)
				{
					this->push_back(*it);
					++it;
				}
			}
			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last,
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = NULL){
				Vector vec(position, this->end());
				if (this->size() + (last - first) > this->capacity()){
					size_type i = this->_capacity;
					if (!i)
						this->reserve(last - first);
					else{
						while (i < this->_size)
							i *= 2;
						this->reserve(i);
					}
				}
				this->_size -= vec.size();
				while (first != last)
				{
					this->push_back(*first);
					++first;
				}
				iterator it = vec.begin();
				iterator in = vec.end();
				while(it != in)
				{
					this->push_back(*it);
					++it;
				}
			}
			iterator erase(iterator position){
				iterator iter = position;
				while (iter + 1 != end()){
					*iter = *(iter + 1);
					iter++;
				}
				this->_size--;
				return iterator(position);
			}
			iterator erase(iterator first, iterator last){
				while (first != last){
					erase(first);
					last--;
				}
				return iterator(first);
			}
			void		swap(Vector &x){
				Vector<T, Alloc> vec = *this;
				*this = x;
				x = vec;
			}
			void		clear(){
				this->_size = 0;
			}
		};

template <class T, class Alloc>
void	swap(Vector<T, Alloc>&x, Vector<T, Alloc>&y){
	Vector<T, Alloc> vec = x;
	x = y;
	y = vec;
};

template<class T, class Alloc>
bool operator == (const Vector<T, Alloc> &lhs, const Vector<T, Alloc>&rhs){
	if (lhs.size() != rhs.size())
		return false;
	typename ft::Vector<T>::const_iterator lhs_it = lhs.begin();
	typename ft::Vector<T>::const_iterator rhs_it = rhs.begin();
	while (lhs_it != lhs.end() && rhs_it != rhs.end()){
		if (*rhs_it != *lhs_it)
			return false;
		rhs_it++;
		lhs_it++;
	}
	if (rhs_it == rhs.end() && lhs_it == lhs.end())
		return true;
	else
		return false;
};

template<class T, class Alloc>
bool operator != (const Vector<T, Alloc> &lhs, const Vector<T, Alloc>&rhs){
	if (lhs == rhs)
		return false;
	else
		return true;
};

template<class T, class Alloc>
bool operator < (const Vector<T, Alloc> &lhs, const Vector<T, Alloc>&rhs){
	typename ft::Vector<T>::const_iterator lhs_it = lhs.begin();
	typename ft::Vector<T>::const_iterator rhs_it = rhs.begin();
	while (lhs_it != lhs.end() && rhs_it != rhs.end()){
		if (*lhs_it < *rhs_it)
			return true;
		if (*lhs_it > *rhs_it)
			return false;
		rhs_it++;
		lhs_it++;
	}
	if (lhs_it == lhs.end() && rhs_it != rhs.end())
		return true;
	else
		return false;	
};

template<class T, class Alloc>
bool operator <= (const Vector<T, Alloc> &lhs, const Vector<T, Alloc>&rhs){
	if (lhs < rhs || lhs == rhs)
		return true;
	else
		return false;
};

template<class T, class Alloc>
bool operator > (const Vector<T, Alloc> &lhs, const Vector<T, Alloc>&rhs){
	if (!(lhs == rhs) && !(lhs < rhs))
		return true;
	else
		return false;	
};

template<class T, class Alloc>
bool operator >= (const Vector<T, Alloc> &lhs, const Vector<T, Alloc>&rhs){
	if (!(lhs < rhs))
		return true;
	else
		return false;
};
}

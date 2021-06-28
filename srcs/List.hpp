/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:11:14 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 15:37:47 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Container.hpp"
#include "List_iterator.hpp"
namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class List
	{
		public:
				typedef T									value_type;
				typedef Alloc								allocator_type;
				typedef T&									reference;
				typedef const T&							const_reference;
				typedef T*									pointer;
				typedef const T*							const_pointer;
				typedef size_t								size_type;
				typedef ft::list_iterator<T>				iterator;
				typedef ft::list_reverse_iterator<T>		reverse_iterator;
				typedef ft::list_const_iterator<T>			const_iterator;
				typedef ft::const_list_reverse_iterator<T>	const_reverse_iterator;

		private:
			allocator_type	_allocator;
			Node<T>			*_List;
			size_type		_size;
		
		public:
			//constructors
			explicit List(const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0){
				_List = new Node<T>(NULL, NULL, value_type());
				_List->_prev = _List;
				_List->_next = _List;	
			};
			explicit List (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()){
				this->_size = 0;
				this->_allocator = alloc;
				_List = new Node<T>(NULL, NULL, value_type());
				_List->_next = _List;
				_List->_prev = _List;
				for (size_type i = 0; i < n; i++)
					push_front(val);
			};
			template <class InputIterator>
			List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = NULL){
				this->_size = 0;
				this->_allocator = alloc;
				_List = new Node<T>(NULL, NULL, value_type());
				_List->_next = _List;
				_List->_prev = _List;
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			};
			List (const List& x){
				this->_allocator = x._allocator;
				this->_size = 0;
				_List = new Node<T>(NULL, NULL, value_type());
				_List->_next = _List;
				_List->_prev = _List;
				*this = x;
			};
			List& operator=(const List& x){
				this->clear();
				Node<T> *copy = x._List->_next;
				while (copy != x._List)
				{
					push_back(copy->_value);
					copy = copy->_next;
				}
				return *this;
			};
			~List(){
				delete _List;
			};

			//capacity
			bool empty() const{
				if (!this->_size)
					return true;
				return false;
			};
			size_type size() const{
				return this->_size;
			};
			size_type max_size() const{
				return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>)));
			};

			//iterators
			iterator begin(){
				return iterator(_List->_next);
			};
			const_iterator begin() const{
				return const_iterator(_List->_next);
			};
			iterator end(){
				return iterator(_List);
			};
			const_iterator end() const{
				return const_iterator(_List);
			};
			reverse_iterator rbegin(){
				return reverse_iterator(_List->_prev);
			};
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(_List->_prev);
			};
			reverse_iterator rend(){
				return reverse_iterator(_List);
			};
			const_reverse_iterator rend() const{
				return const_reverse_iterator(_List);
			};


			//element access
			reference front(){return (*begin());};
			const_reference front() const {return (*begin());};
			reference back(){return _List->_prev->_value;};
			const_reference back() const{return _List->_prev->_value;};

			//modifiers
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = NULL)
			{
				this->clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			};
			void assign (size_type n, const value_type& val)
			{
				this->clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			};

			void	push_front(const_reference val){
				insert(begin(), val);
			};
			void	pop_front(){
				erase(begin());
			};
			void	push_back(const_reference val){
				insert(end(), val);
			};
			void	pop_back(){
				erase(--end());
			};
			iterator insert (iterator position, const value_type& val)
			{
				Node<T> *newNode = new Node<T>(position.getPtr()->_prev, position.getPtr(), val);
				position.getPtr()->_prev->_next = newNode;
				position.getPtr()->_prev = newNode;
				_size++;
				return iterator(--position);
			};
    		void insert (iterator position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i<n; i++) 
					insert(position, val);
			};
    		template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = NULL)
			{
				while (first != last)
				{
					insert(position, *first);
					first++;
				}
			};
			iterator erase (iterator position)
			{
				position.getPtr()->_next->_prev = position.getPtr()->_prev;
				position.getPtr()->_prev->_next = position.getPtr()->_next;
				iterator ret;
				ret = iterator(position.getPtr()->_next);
				delete position.getPtr();
				this->_size--;
				return ret;
			};
			iterator erase (iterator first, iterator last)
			{
				iterator it = first;
				while (it != last)
					it = erase(it);
				return last;
			};
			void swap (List& x)
			{
				List tmp = *this;
				*this = x;
				x = tmp;
			};
			void resize (size_type n, value_type val = value_type())
			{
				if (n > this->_size){
					while (n > this->_size)
						push_back(val);
				}
				else{
					while (n < this->_size)
						pop_back();
				}
			};
			void clear(){
				this->resize(0);
			};

			//operations
			void splice (iterator position, List& x)
			{
				while(x._size)
					splice(position, x, x.begin());
			};
			void splice (iterator position, List& x, iterator i)
			{
				i.getPtr()->_prev->_next = i.getPtr()->_next;
				i.getPtr()->_next->_prev = i.getPtr()->_prev;
				x._size--;
				position.getPtr()->_prev->_next = i.getPtr();
				i.getPtr()->_prev = position.getPtr()->_prev;
				position.getPtr()->_prev = i.getPtr();
				i.getPtr()->_next = position.getPtr();
				_size++;
			};
			void splice (iterator position, List& x, iterator first, iterator last){
				while (first != last)
				{
					iterator next = first.getPtr()->_next;
					splice(position, x, first);
					first = next;
				}
			};
			void remove (const value_type& val)
			{
				iterator first = this->begin();
				while (first != this->end())
				{
					if (*first == val)
						first = this->erase(first);
					else
						++first;
				}
			};
			template <class Predicate>
			void remove_if(Predicate pred)
			{
				iterator first = this->begin();
				while (first != this->end())
				{
					if (pred(*first))
						first = this->erase(first);
					else
						++first;
				}
			};
			void unique()
			{
				iterator it = _List->_next->_next;
				iterator prev = begin();
				iterator next;
				while (it != end())
				{
					next = iterator (it.getPtr()->_next);
					if (*prev == *it)
						erase(it);
					else
						prev = it;
					it = next;
				}
			};
			template <class BinaryPredicate>
  			void unique (BinaryPredicate binary_pred)
			{
				iterator it = ++begin();
				iterator prev;
				iterator next;
				while (it != end())
				{
					next = iterator(it.getPtr()->_next);
					prev = iterator(it.getPtr()->_prev);
					if (binary_pred(*prev, *it))
						erase(it);
					else
						prev = it;
					it = next;
				}
			};
			
			void merge (List& x){
				iterator first = this->begin();
				iterator last = this->end();
				iterator tmp;
				while (first != last && x.begin() != x.end())
				{
					while (first != last && *first < *x.begin())
						++first;
					tmp = x.begin();
					++x.begin();
					this->splice(first, x, tmp);
				}
				if (x.begin() != x.end())
					this->splice(first, x, x.begin(), x.end());
			};
			template <class Compare>
			void merge (List& x, Compare comp){
				if (&x == this)
					return;
				iterator it = begin();
				iterator it_next;
				while (x.begin() != x.end())
				{
					while (it != end())
					{
						if (comp(*x.begin(), *it))
						{
							it_next = iterator (x.begin().getPtr()->_next);
							splice(it, x, x.begin());
							x.begin() = it_next;
						}
						else
							it++;
					}
					it_next = iterator (x.begin().getPtr()->_next);
					splice(it, x, x.begin());
					x.begin() = it_next;
				}
			};
			void sort(){
				sort(ft::less<value_type>());
			}
			template <class Compare>
			void sort (Compare comp){
				Node<T> *a = _List->_next;
				Node<T> *b = a->_next;
				Node<T> *prev;
				Node<T> *next;
				while (b != _List)
				{
					if (comp(b->_value, a->_value)) 
					{
						prev = a->_prev;
						next = b->_next;
						prev->_next = b;
						b->_prev = prev;
						b->_next = a;
						a->_prev = b;
						a->_next = next;
						next->_prev = a;
						a = _List->_next;
						b = a->_next;
					} 
					else 
					{
						a = a->_next;
						b = b->_next;
					}
				}				
			};
			void reverse() {
				Node<T> *cur = _List->_next;
				Node<T> *next;
				Node<T> *tmp;

				while (cur != _List)
				{
					next = cur->_next;
					tmp = cur->_next;
					cur->_next = cur->_prev;
					cur->_prev = tmp;
					cur = next;
				}
				tmp = cur->_next;
				cur->_next = cur->_prev;
				cur->_prev = tmp;
			}
	};


//relation function
template <class T, class Alloc>
bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::List<T,Alloc>::const_iterator itlhs = lhs.begin();
	typename ft::List<T,Alloc>::const_iterator itrhs = rhs.begin();
	while (itlhs != lhs.end() && itrhs != rhs.end())
	{
		if (*itrhs != *itlhs)
			return false;
		itrhs++;
		itlhs++;
	}
	if (itlhs == lhs.end() && itrhs == rhs.end())
		return true;
	else
		return false;
};

template <class T, class Alloc>
bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	else
		return true;
};

template <class T, class Alloc>
bool operator<(const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
{
	typename ft::List<T,Alloc>::const_iterator itlhs = lhs.begin();
	typename ft::List<T,Alloc>::const_iterator itrhs = rhs.begin();
	while (itlhs != lhs.end() && itrhs != rhs.end())
	{
		if (*itlhs < *itrhs)
			return true;
		if (*itlhs > *itrhs)
			return false;
		itrhs++;
		itlhs++;
	}
	if (itlhs == lhs.end() && itrhs != rhs.end())
		return true;
	else
		return false;
};

template <class T, class Alloc>
bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	else
		return false; 
};

template <class T, class Alloc>
bool operator>(const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
{
	if (!(lhs == rhs) && !(lhs < rhs))
		return true;
	else
		return false;
};

template <class T, class Alloc>
bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
{
	if (!(lhs < rhs))
		return true;
	else
		return false;
};

template <class T, class Alloc>
void swap (ft::List<T,Alloc>& x, ft::List<T,Alloc>& y){
	x.swap(y);
};
}

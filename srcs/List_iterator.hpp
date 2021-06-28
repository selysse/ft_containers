/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:11:14 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 18:37:11 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
struct Node
{
	Node (Node<T> *prev, Node<T> *next, const T &value) : _prev(prev), _next(next), _value(value){}
	Node<T> *_prev;
	Node<T> *_next;
	T	_value;
};

namespace ft
{
	template <typename T>
	struct less
	{
		bool operator()(const T &a, const T &b) const
		{
			return (a < b);
		}
	};
	template <typename T>
	class list_iterator
	{
		public:
			typedef T						value_type;
			typedef T&						reference;
			typedef T*						pointer;
			typedef ptrdiff_t				difference_type;
		protected:
			Node<T> *_ptr;
		public:
			list_iterator(){};
			list_iterator(pointer ptr): _ptr(ptr){};
			list_iterator(const list_iterator &copy){
				this->_ptr = copy._ptr;
			};
			list_iterator(Node<T> *ptr){
				this->_ptr = ptr;
			};
			virtual ~list_iterator(){};
			bool operator == (const list_iterator &other)const{
				return _ptr == other._ptr;
			};
			bool operator != (const list_iterator &other)const{
				return _ptr != other._ptr;
			};
			list_iterator &operator++(){
				_ptr = _ptr->_next; 
			return *this;
			};
			list_iterator &operator--(){
				_ptr = _ptr->_prev;
				return *this;
			};
			list_iterator operator++(int){
				list_iterator it(this->_ptr); 
				this ->_ptr = this->_ptr->_next;
				return it;
			};
			list_iterator operator--(int){
				list_iterator it(this->_ptr); 
				this ->_ptr = this->_ptr->_prev; 
				return it;
			};
			value_type	&operator*(){
				return _ptr->_value;
			};
			Node<T> *getPtr() const{
				return this->_ptr;
			};
	};
	template<typename T>
	class list_reverse_iterator
	{
		public:
			typedef T						value_type;
			typedef T&						reference;
			typedef T*						pointer;
			typedef ptrdiff_t				difference_type;
		protected:
			Node<T>	*_ptr;
		public:
			list_reverse_iterator():_ptr(NULL){};
			list_reverse_iterator(pointer ptr):_ptr(ptr){};
			list_reverse_iterator(const list_reverse_iterator &copy){
				this->_ptr = copy._ptr;
			};
			list_reverse_iterator(Node<T> *ptr){
				this->_ptr = ptr;
			};
			bool operator==(const list_reverse_iterator &other) const{
				return _ptr == other._ptr;
			};
			bool operator!=(const list_reverse_iterator &other) const{
				return _ptr != other._ptr;
			};
			list_reverse_iterator &operator++(){
				this->_ptr=_ptr->_prev; 
				return *this;
			};
			list_reverse_iterator &operator--(){
				this->_ptr=_ptr->_next;
				 return *this;
			};
			list_reverse_iterator operator++(int){
				list_reverse_iterator it(this->_ptr); 
				this->_ptr = this->_ptr->_prev; 
				return it;
			};
			list_reverse_iterator operator--(int){
				list_reverse_iterator it(this->_ptr); 
				this->_ptr = this->_ptr->_next; 
				return it;
			};
			value_type	&operator*(){
				return _ptr->_value;
			};
			Node<T> * getPtr() const{
				return this->_ptr;
			};
		};

		template<typename T>		
		class list_const_iterator : public list_iterator<T>
		{
			public:
				typedef T						value_type;
				typedef T&						reference;
				typedef T*						pointer;
				typedef ptrdiff_t				difference_type;
			public:
				list_const_iterator():_ptr(NULL){};
				list_const_iterator(const pointer ptr) : _ptr(ptr){};
				list_const_iterator(const list_const_iterator &copy){
					this->_ptr = copy._ptr;
				};
				list_const_iterator(Node<T> *ptr){
					this->_ptr = ptr;
				};
				bool operator==(const list_const_iterator &other) const{
					return _ptr == other._ptr;
				};
				bool operator!=(const list_const_iterator &other) const{
					return _ptr != other._ptr;
				};
				list_const_iterator &operator++(){
					_ptr=_ptr->_next; 
					return *this;
				};
				list_const_iterator &operator--(){
					_ptr=_ptr->_prev; 
					return *this;
				};
				list_const_iterator operator++(int){
					list_const_iterator it(this->_ptr); 
					this->_ptr = this->_ptr->_next; 
					return it;
				};
				list_const_iterator operator--(int){
					list_const_iterator it(this->_ptr);
					 this->_ptr = this->_ptr->_prev; 
					 return it;
				};				
				value_type	&operator*() const{
					return _ptr->_value;
				};
				Node<T> * getPtr() const{
					return this->_ptr;
				};
			private:
				Node<T>	*_ptr;
		};
		template <typename T>
		class const_list_reverse_iterator : public list_const_iterator<T>
		{
			public:
				typedef T						value_type;
				typedef T&						reference;
				typedef T*						pointer;
				typedef ptrdiff_t				difference_type;
			public:
				const_list_reverse_iterator():_ptr(NULL){};
				const_list_reverse_iterator(const pointer ptr) : _ptr(ptr){};
				const_list_reverse_iterator(const const_list_reverse_iterator &copy){
					this->_ptr = copy._ptr;
				};
				const_list_reverse_iterator(Node<T> *ptr){
					this->_ptr = ptr;
				};
				bool operator==(const const_list_reverse_iterator &other)const{
					return this->_ptr == other._ptr;
				};
				bool operator!=(const const_list_reverse_iterator &other)const{
					return this->_ptr != other._ptr;
				};
				const_list_reverse_iterator &operator++(){
					this->_ptr=_ptr->_prev;
					return *this;
				};
				const_list_reverse_iterator &operator--(){
					this->_ptr=_ptr->_next;
					return *this;
				};
				const_list_reverse_iterator operator++(int){
					const_list_reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it;
				};
				const_list_reverse_iterator operator--(int){
					const_list_reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next; 
					return it;
				};
				T	&operator*() const{
					return _ptr->_value;
				};
				Node<T> *getPtr()const{
					return this->_ptr;
				};
			private:
				Node<T>	*_ptr;
			};
};
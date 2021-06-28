/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_Iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:11:14 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 15:47:20 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Container.hpp"

namespace ft
{
		template <typename T>
		class iterator_vector
		{
			public:
				typedef T										value_type;
				typedef	size_t									size_type;
				typedef T&										reference;
				typedef T*										pointer;
				typedef T const &								const_reference;
				typedef	const T*								const_pointer;
				typedef ptrdiff_t								difference_type;

			protected:
				pointer	_ptr;
			public:
				iterator_vector():_ptr(NULL){};
				iterator_vector(pointer ptr): _ptr(ptr){};
				iterator_vector(const iterator_vector &copy){
					_ptr = (copy._ptr);
				}
				iterator_vector &operator=(const iterator_vector &other){
					this->_ptr = other._ptr;
					return *this;
				}
				virtual ~iterator_vector(){}
				
				reference operator*(){
					return *this->_ptr;
				}
				pointer operator->(){
					return this->_ptr;
				}
				iterator_vector &operator++(){
					++this->_ptr;
					return *this;
				}
				iterator_vector &operator--(){
					--this->_ptr;
					return *this;
				}
				iterator_vector operator++(int){
					iterator_vector it = *this;
					++(*this);
					return it;
				}
				iterator_vector operator--(int){
					iterator_vector it = *this;
					--(*this);
					return it;
				}
				reference operator[](difference_type n){
					return this->_ptr[n];
				}
				iterator_vector operator+(difference_type n)const{
					return this->_ptr + n;
				}
				iterator_vector operator-(difference_type n)const{
					return this->_ptr - n;
				}
				iterator_vector operator-=(difference_type n)const{
					this->_ptr -= n;
					return *this;
				}
				iterator_vector operator+=(difference_type n)const{
					this->_ptr += n;
					return *this;
				}
				bool operator == (iterator_vector const &other){
					if (this->_ptr == other._ptr)
						return true;
					return false;
				}
				bool operator != (iterator_vector const &other){
					if (this->_ptr != other._ptr)
						return true;
					return false;
				}
				bool operator < (iterator_vector const &other){
					if (this->_ptr < other._ptr)
						return true;
					return false;
				}
				bool operator <= (iterator_vector const &other){
					if (this->_ptr <= other._ptr)
						return true;
					return false;
				}					
				bool operator >(iterator_vector const &other) {
					if(this->_ptr > other._ptr)
						return true;
					return false;
				}
				bool operator >=(iterator_vector const &other) {
					if(this->_ptr >= other._ptr)
						return true;
					return false;
				}					
				pointer base() const{
					return this->_ptr;
				}
				difference_type operator-(iterator_vector &other){
					return this->_ptr - other._ptr;
				}
			};
			template <typename T>
			class const_iterator_vector
			{
				public:
					typedef T										value_type;
					typedef	size_t									size_type;
					typedef T&										reference;
					typedef T*										pointer;
					typedef T const &								const_reference;
					typedef	const T*								const_pointer;
					typedef ptrdiff_t								difference_type;
				protected:
					pointer _ptr;
				public:
					const_iterator_vector():_ptr(NULL){};
					const_iterator_vector(const pointer ptr){
						this->_ptr = ptr;
					}
					const_iterator_vector(const const_iterator_vector &copy){
						this->_ptr = copy._ptr;
					}
					const_iterator_vector &operator=(const const_iterator_vector &other){
						this->_ptr = other._ptr;
						return *this;
					}
					virtual ~const_iterator_vector(){}
					
					reference operator*()const{
						return *this->_ptr;
					}
					pointer operator->()const{
						return this->_ptr;
					}
					const_iterator_vector &operator++(){
						++this->_ptr;
						return *this;
					}
					const_iterator_vector &operator--(){
						--this->_ptr;
						return *this;
					}
					const_iterator_vector operator++(int){
						const_iterator_vector it = *this;
						++(*this);
						return it;
					}
					const_iterator_vector operator--(int){
						const_iterator_vector it = *this;
						--(*this);
						return it;
					}
					reference operator[](difference_type n){
						return this->_ptr[n];
					}
					const_iterator_vector operator+(difference_type n)const{
						return this->_ptr + n;
					}
					const_iterator_vector operator-(difference_type n)const{
						return this->_ptr - n;
					}
					const_iterator_vector operator-=(difference_type n)const{
						this->_ptr -= n;
						return *this;
					}
					const_iterator_vector operator+=(difference_type n)const{
						this->_ptr += n;
						return *this;
					}
					bool operator == (const_iterator_vector const &other){
						if (this->_ptr == other._ptr)
							return true;
						return false;
					}
					bool operator != (const_iterator_vector const &other){
						if (this->_ptr != other._ptr)
							return true;
						return false;
					}
					bool operator < (const_iterator_vector const &other){
						if (this->_ptr < other._ptr)
							return true;
						return false;
					}
					bool operator <= (const_iterator_vector const &other){
						if (this->_ptr <= other._ptr)
							return true;
						return false;
					}					
					bool operator >(const_iterator_vector const &other) {
						if(this->_ptr > other._ptr)
							return true;
						return false;
					}
					bool operator >=(const_iterator_vector const &other) {
						if(this->_ptr >= other._ptr)
							return true;
						return false;
					}					
					pointer base() const{
						return this->_ptr;
					}
					difference_type operator-(const_iterator_vector const &other){
						return this->_ptr - other._ptr;
					}
			};
			
			template <typename T>
			class reverse_vector_iterator
			{
				public:
					typedef T										value_type;
					typedef	size_t									size_type;
					typedef T&										reference;
					typedef T*										pointer;
					typedef T const &								const_reference;
					typedef	const T*								const_pointer;
					typedef ptrdiff_t								difference_type;
				
				protected:
					pointer	_ptr;
				public:
					reverse_vector_iterator():_ptr(NULL){};
					reverse_vector_iterator(pointer ptr): _ptr(ptr){};
					reverse_vector_iterator(const reverse_vector_iterator &copy){
						*this = copy;
					}
					reverse_vector_iterator &operator=(const reverse_vector_iterator &other){
						this->_ptr = other._ptr;
						return *this;
					}
					virtual ~reverse_vector_iterator(){};
					
					reference operator*(){
						return *(this->_ptr);
					}
					pointer operator->(){
						return *(this->_ptr);
					}
					reverse_vector_iterator &operator++(){
						--this->_ptr;
						return *this;
					}
					reverse_vector_iterator operator++(int){
						reverse_vector_iterator it(*this);
						--this->_ptr;
						return it;
					}
					reverse_vector_iterator operator+(const difference_type n)const{
						reverse_vector_iterator tmp(*this);
						tmp._ptr += n;
						return tmp;
					}					
					reverse_vector_iterator &operator--(){
						++this->_ptr;
						return *this;
					}
					reverse_vector_iterator operator--(int){
						reverse_vector_iterator it(*this);
						++this->_ptr;
						return it;
					}
					reverse_vector_iterator operator-(const difference_type n)const{
						reverse_vector_iterator tmp(*this);
						tmp._ptr += n;
						return tmp;
					}
					reverse_vector_iterator operator-=(difference_type n){
						while(n > 0){
							operator--();
							n--;
						}
						while (n < 0){
							operator++();
							n++;
						}
						return (*this);
					}
					reverse_vector_iterator operator+=(difference_type n){
						while(n > 0){
							operator++();
							n--;
						}
						while (n < 0){
							operator--();
							n++;
						}
						return (*this);
					}
					reverse_vector_iterator &operator[](difference_type n)const{
						return (*(this->_ptr - n));
					}
					bool operator == (reverse_vector_iterator const &other){
						if (this->_ptr == other._ptr)
							return true;
						return false;
					}
					bool operator != (reverse_vector_iterator const &other){
						if (this->_ptr != other._ptr)
							return true;
						return false;
					}
					bool operator < (reverse_vector_iterator const &other){
						if (this->_ptr < other._ptr)
							return true;
						return false;
					}
					bool operator <= (reverse_vector_iterator const &other){
						if (this->_ptr <= other._ptr)
							return true;
						return false;
					}					
					bool operator >(reverse_vector_iterator const &other) {
						if(this->_ptr > other._ptr)
							return true;
						return false;
					}
					bool operator >=(reverse_vector_iterator const &other) {
						if(this->_ptr >= other._ptr)
							return true;
						return false;
					}
			};
			template <typename T>
			class const_reverse_vector_iterator : public reverse_vector_iterator<T>
			{
				public:
					typedef T										value_type;
					typedef	size_t									size_type;
					typedef T&										reference;
					typedef T*										pointer;
					typedef T const &								const_reference;
					typedef	const T*								const_pointer;
					typedef ptrdiff_t								difference_type;
				public:
					const_reverse_vector_iterator(){};
					const_reverse_vector_iterator(const pointer ptr){this->_ptr = ptr;};
					const_reverse_vector_iterator(const_reverse_vector_iterator const &copy){
						*this = copy;
					};
					virtual ~const_reverse_vector_iterator(){};
					const_reverse_vector_iterator &operator=(const_reverse_vector_iterator const &other){
						this->_ptr = other._ptr;
						return *this;
					};
					const_reverse_vector_iterator &operator*(){
						return *this->_ptr;
					};
					const_reverse_vector_iterator &operator[](difference_type n)const{
						return *(*this - n);
					};
			};
};
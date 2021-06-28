/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:11:14 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/21 03:03:25 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Container.hpp"
#include "List_iterator.hpp"

namespace ft
{
	template <class T, class Container = ft::List<T> >
	class Stack
	{
		public:
			typedef	T			value_type;
			typedef Container	container_type;
			typedef	size_t		size_type;

			explicit Stack(const container_type &cntr = container_type()) : _container(cntr){};
			Stack(const Stack &copy){_container = copy._container;};
			Stack &operator=(Stack const &other){
				this->_container = other._container;
				return (*this);
			};
			virtual ~Stack(){};

			bool empty() const{
				return _container.empty();
			};
			size_type	size() const{
				return _container.size();
			};
			value_type	&top(){
				return _container.back();
			};
			const value_type &top()const{
				return _container.back();
			};
			void	pop(){
				_container.pop_back();
			};
			void	push(const value_type& value){
				_container.push_back(value);
			};
			
			template <class A, class B>
			friend bool operator == (const Stack<A, B> &lhs, const Stack<A, B> &rhs){
				return (lhs._container == rhs._container);
			}
			template <class A, class B>
			friend bool operator != (const Stack<A, B> &lhs, const Stack<A, B> &rhs){
								return (lhs._container != rhs._container);
			}
			template <class A, class B>
			friend bool operator > (const Stack<A, B> &lhs, const Stack<A, B> &rhs){
								return (lhs._container > rhs._container);
			}
			template <class A, class B>
			friend bool operator >= (const Stack<A, B> &lhs, const Stack<A, B> &rhs){
								return (lhs._container >= rhs._container);
			}
			template <class A, class B>
			friend bool operator < (const Stack<A, B> &lhs, const Stack<A, B> &rhs){
								return (lhs._container < rhs._container);
			}
			template <class A, class B>
			friend bool operator <= (const Stack<A, B> &lhs, const Stack<A, B> &rhs){
								return (lhs._container <= rhs._container);
			}
		
		protected:
			container_type 		_container;
	};
};

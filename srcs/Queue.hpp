/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:11:14 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 15:45:49 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "List.hpp"

namespace ft
{
	template<class T, class Container = ft::List<T> >
	class Queue
	{
		public:
			typedef	Container	container_type;
			typedef T			value_type;
			typedef size_t		size_type;

			explicit Queue(const container_type &cntr = container_type()) : _container(cntr){};
			Queue (const Queue &copy){
				_container = copy._container;
			};
			Queue &operator=(Queue const &other){
				this->_container = other._container;
				return (*this);
			};
			virtual ~Queue(){};

			bool empty() const{
				return _container.empty();
			};
			size_type	size()const{
				return (_container.size());
			};
			value_type &front(){
				return (_container.front());
			};
			const value_type &front() const{
				return (_container.front());
			};
			value_type &back(){
				return (_container.back());
			};
			const value_type &back() const{
				return (_container.back());
			};
			void	push(const value_type &value){
				return (_container.push_back(value));
			};
			void	pop(){
				_container.pop_front();
			};
			template <class A, class B>
			friend bool operator == (const Queue<A, B> &lhs, const Queue<A, B> &rhs){
				return (lhs._container == rhs._container);
			}
			template <class A, class B>
			friend bool operator != (const Queue<A, B> &lhs, const Queue<A, B> &rhs){
				return (lhs._container != rhs._container);
			}
			template <class A, class B>
			friend bool operator > (const Queue<A, B> &lhs, const Queue<A, B> &rhs){
				return (lhs._container > rhs._container);
			}
			template <class A, class B>
			friend bool operator >= (const Queue<A, B> &lhs, const Queue<A, B> &rhs){
				return (lhs._container >= rhs._container);
			}
			template <class A, class B>
			friend bool operator < (const Queue<A, B> &lhs, const Queue<A, B> &rhs){
				return (lhs._container < rhs._container);
			}
			template <class A, class B>
			friend bool operator <= (const Queue<A, B> &lhs, const Queue<A, B> &rhs){
				return (lhs._container <= rhs._container);
			}
		protected:
			container_type	_container;	
	};
};

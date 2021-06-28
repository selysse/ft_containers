/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:22:58 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 18:33:57 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Container.hpp"

template <class Key, class T>
struct NodeRB
{
	std::pair<Key, T> 	pair;		
	NodeRB				*left;		
	NodeRB				*right;	
	NodeRB				*parent;
	bool				end;
};

namespace ft
{
	template <class K, class T>
	class iterator_map
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T> &reference;
			typedef NodeRB<K, T> 	*pointer;

		protected:
			pointer _ptr;

		private:
			pointer _successor(pointer ptr){
				pointer next;
				if (!ptr->right){
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return next;
			};
			pointer _predecessor(pointer ptr){
				pointer next;

				if (!ptr->left){
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return next;
			};
		public:
			iterator_map(): _ptr(NULL){};
			iterator_map(const pointer ptr): _ptr(ptr){};
			iterator_map(const iterator_map &other){
				this->_ptr = other._ptr;
			};
			iterator_map &operator=(const iterator_map &other){
				this->_ptr = other._ptr;
				return (*this);
			};
			pointer node(){
				return this->_ptr;
			};
			value_type &operator*(){
				return this->_ptr->pair;
			};
			value_type *operator->(){
				return &this->_ptr->pair;
			};
			bool operator==(const iterator_map<K, T> &other){
				if (this->_ptr == other._ptr)
					return true;
				return false;
			};
			bool operator!=(const iterator_map<K, T> &other){
				if (this->_ptr != other._ptr)
					return true;
				return false;
			};
			bool operator>(const iterator_map<K, T> &other){
				if (this->_ptr > other._ptr)
					return true;
				return false;
			};
			bool operator<(const iterator_map<K, T> &other){
				if (this->_ptr < other._ptr)
					return true;
				return false;
			};
			bool operator>=(const iterator_map<K, T> &other){
				if (this->_ptr >= other._ptr)
					return true;
				return false;
			};
			bool operator<=(const iterator_map<K, T> &other){
				if (this->_ptr <= other._ptr)
					return true;
				return false;
			};
			iterator_map &operator++()
			{
				this->_ptr = _successor(this->_ptr);
				return (*this);
			};
			iterator_map &operator--()
			{
				this->_ptr = _predecessor(this->_ptr);
				return (*this);
			};
			iterator_map operator++(int)
			{
				iterator_map it(*this);
				this->operator++();
				return (it);
			};
			iterator_map operator--(int)
			{
				iterator_map it(*this);
				this->operator--();
				return (it);
			};
	};

	template <class K, class T>
	class const_iterator_map
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>	&reference;
			typedef NodeRB<K, T>	*pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr){
				pointer next;
				if (!ptr->right){
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return next;
			};
			pointer _predecessor(pointer ptr){
				pointer next;

				if (!ptr->left){
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return next;
			};
		public:
			const_iterator_map(): _ptr(NULL){};
			const_iterator_map(const pointer ptr): _ptr(ptr){};
			const_iterator_map(const const_iterator_map &copy){
				this->_ptr = copy._ptr;
			};
			const_iterator_map &operator=(const const_iterator_map &other){
				this->_ptr = other._ptr;
				return *this;
			};
			pointer node(){
				return this->_ptr;
			};
			value_type &operator*()const{
				return this->_ptr->pair;
			};
			value_type *operator->()const{
				return &this->_ptr->pair;
			};
			bool operator==(const const_iterator_map<K, T> &other){
				if (this->_ptr == other._ptr)
					return true;
				return false;
			};
			bool operator!=(const const_iterator_map<K, T> &other){
				if (this->_ptr != other._ptr)
					return true;
				return false;
			};
			bool operator>(const const_iterator_map<K, T> &other){
				if (this->_ptr > other._ptr)
					return true;
				return false;
			};
			bool operator<(const const_iterator_map<K, T> &other){
				if (this->_ptr < other._ptr)
					return true;
				return false;
			};
			bool operator>=(const const_iterator_map<K, T> &other){
				if (this->_ptr >= other._ptr)
					return true;
				return false;
			};
			bool operator<=(const const_iterator_map<K, T> &other){
				if (this->_ptr <= other._ptr)
					return true;
				return false;
			};
			const_iterator_map &operator++(){
				this->_ptr = _successor(this->_ptr);
				return *this;
			};
			const_iterator_map &operator--(){
				this->_ptr = _predecessor(this->_ptr);
				return *this;
			};
			const_iterator_map operator++(int){
				const_iterator_map it(*this);
				this->operator++();
				return (it);
			};
			const_iterator_map operator--(int){
				const_iterator_map it(*this);
				this->operator--();
				return (it);
			};
	};
	
	template <class K, class T>
	class reverse_iterator_map
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>	&reference;
			typedef NodeRB<K, T>	*pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr){
				pointer next;
				if (!ptr->right){
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return next;
			};
			pointer _predecessor(pointer ptr){
				pointer next;

				if (!ptr->left){
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return next;
			};
		public:
			reverse_iterator_map(): _ptr(NULL){};
			reverse_iterator_map(const pointer ptr): _ptr(ptr){};
			reverse_iterator_map(const reverse_iterator_map &copy){
				this->_ptr = copy._ptr;
			};
			reverse_iterator_map &operator=(const reverse_iterator_map &other){
				this->_ptr = other._ptr;
				return *this;
			};
			pointer node(){
				return this->_ptr;
			};
			value_type &operator*(){
				return this->_ptr->pair;
			};
			value_type *operator->(){
				return &this->_ptr->pair;
			};
			bool operator==(const reverse_iterator_map<K, T> &other){
				if (this->_ptr == other._ptr)
					return true;
				return false;
			};
			bool operator!=(const reverse_iterator_map<K, T> &other){
				if (this->_ptr != other._ptr)
					return true;
				return false;
			};
			bool operator>(const reverse_iterator_map<K, T> &other){
				if (this->_ptr > other._ptr)
					return true;
				return false;
			};
			bool operator<(const reverse_iterator_map<K, T> &other){
				if (this->_ptr < other._ptr)
					return true;
				return false;
			};
			bool operator>=(const reverse_iterator_map<K, T> &other){
				if (this->_ptr >= other._ptr)
					return true;
				return false;
			};
			bool operator<=(const reverse_iterator_map<K, T> &other){
				if (this->_ptr <= other._ptr)
					return true;
				return false;
			};
			reverse_iterator_map &operator++(){
				this->_ptr = _predecessor(this->_ptr);
				return *this;
			};
			reverse_iterator_map &operator--(){
				this->_ptr = _successor(this->_ptr);
				return *this;
			};
			reverse_iterator_map operator++(int){
				reverse_iterator_map it(*this);
				this->operator++();
				return (it);
			};
			reverse_iterator_map operator--(int){
				reverse_iterator_map it(*this);
				this->operator--();
				return (it);
			};
	};

	template <class K, class T>
	class const_reverse_iterator_map
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>& reference;
			typedef NodeRB<K, T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr){
				pointer next;
				if (!ptr->right){
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return next;
			};
			pointer _predecessor(pointer ptr){
				pointer next;
				if (!ptr->left){
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return next;
			};
		public:
			const_reverse_iterator_map(void): _ptr(NULL){};
			const_reverse_iterator_map(const pointer ptr): _ptr(ptr){};
			const_reverse_iterator_map(const const_reverse_iterator_map &copy){
				this->_ptr = copy._ptr;
			};
			const_reverse_iterator_map &operator=(const const_reverse_iterator_map &other){
				this->_ptr = other._ptr;
				return (*this);
			};
			pointer node(){
				return this->_ptr;
			};
			value_type &operator*() const{
				return this->_ptr->pair;
			};
			value_type *operator->()const{
				return &this->_ptr->pair;
			};
			bool operator==(const const_reverse_iterator_map<K, T> &other){
				if (this->_ptr == other._ptr)
					return true;
				return false;
			};
			bool operator!=(const const_reverse_iterator_map<K, T> &other){
				if (this->_ptr != other._ptr)
					return true;
				return false;
			};
			bool operator>(const const_reverse_iterator_map<K, T> &other){
				if (this->_ptr > other._ptr)
					return true;
				return false;
			};
			bool operator<(const const_reverse_iterator_map<K, T> &other){
				if (this->_ptr < other._ptr)
					return true;
				return false;
			};
			bool operator>=(const const_reverse_iterator_map<K, T> &other){
				if (this->_ptr >= other._ptr)
					return true;
				return false;
			};
			bool operator<=(const const_reverse_iterator_map<K, T> &other){
				if (this->_ptr <= other._ptr)
					return true;
				return false;
			};
			const_reverse_iterator_map &operator++(){
				this->_ptr = _predecessor(this->_ptr);
				return *this;
			};
			const_reverse_iterator_map &operator--(){
				this->_ptr = _successor(this->_ptr);
				return *this;
			};
			const_reverse_iterator_map operator++(int){
				const_reverse_iterator_map it(*this);
				this->operator++();
				return it;
			};
			const_reverse_iterator_map operator--(int){
				const_reverse_iterator_map it(*this);
				this->operator--();
				return it;
			};
	};

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T > > >
	class BTree
	{
		private:
			typedef Key key_type;
			typedef T mapped_type;
			typedef NodeRB<key_type, mapped_type>* node;
			node _root;
			size_t _size;
		public:
			typedef ft::iterator_map<key_type, mapped_type> iterator;
			
		node new_node(key_type key, mapped_type value, node parent, bool end = false){
			node _node = new NodeRB<key_type, mapped_type>();
			_node->pair = std::make_pair(key, value);
			_node->right = 0;
			_node->left = 0;
			_node->parent = parent;
			_node->end = end;
			return _node;
		};
		void free_tree(node n){
			if (n->right)
				free_tree(n->right);
			if (n->left)
				free_tree(n->left);
			if (n)
				delete n;
		};
		node insert_node(node n, key_type key, mapped_type value, bool end = false){
			if (n->end){
				if (!n->left){
					n->left = new_node(key, value, n, end);
					return (n->left);
				}
				return insert_node(n->left, key, value);
			}
			if (key < n->pair.first && !end){
				if (!n->left)
				{
					n->left = new_node(key, value, n, end);
					return n->left;
				}
				else
					return insert_node(n->left, key, value);
			}
			else{
				if (!n->right){
					n->right = new_node(key, value, n, end);
					return n->right;
				}
				else
					return insert_node(n->right, key, value);
			}
		};
		node find(node n, key_type key)const{
			node tmp;
			if (!n->end && n->pair.first == key && n->parent)
				return (n);
			if (n->right){
				if ((tmp = find(n->right, key)))
					return (tmp);
			}
			if (n->left){
				if ((tmp = find(n->left, key)))
					return (tmp);
			}
			return (0);
		};
		void delete_node(node n)
		{
			node parent = n->parent;
			if (!n->left && !n->right){
				if (parent->right == n)
					parent->right = 0;
				else
					parent->left = 0;
				delete n;
				return ;
			}
			if (n->right && !n->left){
				if (parent->right == n)
					parent->right = n->right;
				else
					parent->left = n->right;
				n->right->parent = parent;
				delete n;
				return ;
			}
			if (n->left && !n->right){
				if (parent->right == n)
					parent->right = n->left;
				else
					parent->left = n->left;
				n->left->parent = parent;
				delete n;
				return ;
			}
			node next = (++iterator(n)).node();
			if (!next)
				next = (--iterator(n)).node();
			swap(next->pair, n->pair);
			delete_node(next);
		};
		void init_tree(){
			this->_root = new_node(key_type(), mapped_type(), 0);
			this->_root->right = new_node(key_type(), mapped_type(), _root, true);
			this->_size = 0;
		};
		node end() const{
			return (_root->right);
		};
		node getRoot(){
			return this->_root;
		}
		node getRoot()const {
			return this->_root;
		}
	};
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:25:57 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 18:36:23 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MapIterator.hpp"

namespace ft
{

    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class Map
    {
        public:
            typedef Key                                                 key_type;
            typedef T                                                   mapped_type;
            typedef std::pair<const Key, T>                             value_type;
            typedef size_t                                              size_type;
            typedef ptrdiff_t                                           difference_type;
            typedef Compare                                             key_compare;
            typedef Alloc                                               allocator_type;
            typedef T&                                                  reference;
            typedef T const &                                           const_reference;
            typedef T*                                                  pointer;
            typedef const T*                                            const_pointer;
            typedef NodeRB<key_type, mapped_type>                       *node;
            typedef iterator_map<key_type, mapped_type>                 iterator;
            typedef reverse_iterator_map<key_type, mapped_type>         reverse_iterator;
            typedef const_iterator_map<key_type, mapped_type>           const_iterator;
            typedef const_reverse_iterator_map<key_type, mapped_type>   const_reverse_iterator;
			class value_compare 
			{
				friend class Map;
				protected:
					Compare		comp;
					value_compare (Compare c) : comp(c){};
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type &x, const value_type &y) const{
						return comp(x.first, y.first);
					}
			};
        protected:
            allocator_type                          _allocator;
            key_compare                             _comp;
            size_type                               _size;
            BTree<Key, T, Compare, Alloc>           _tree;

        public:
            explicit Map(const Compare &comp = Compare(), const allocator_type &allocator = allocator_type()) : _allocator(allocator), _comp(comp), _size(0){
                this->_tree.init_tree();
            }
            template <class InputIterator>
            Map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const allocator_type &allocator = allocator_type(),
            typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = NULL) : _allocator(allocator), _comp(comp), _size(0){
                this->_tree.init_tree();
                insert(first, last);
            }
            Map(const Map &x){
                this->_tree.init_tree();
                *this = x;
            }
            virtual ~Map(){
                this->_tree.free_tree(_tree.getRoot());
            }
            Map &operator=(const Map &other){
                if (this == &other)
                    return (*this);
                this->clear();
                insert(other.begin(), other.end());
                return *this;
            }
            //element access
            mapped_type &operator[](const key_type &key){
                iterator it = find(key);
                if (it != end())
                    return it->second;
                mapped_type &its = insert(std::make_pair(key, mapped_type())).first->second;
                return its;
            }
            //iterators  
            iterator begin()
            {
                node n = _tree.getRoot();
                if (!n->left && !n->right)
                    return (end());
                if (n->right)
                    n = n->right;
                while (n->left)
                    n = n->left;
                return iterator(n);
            }
            const_iterator begin() const{
                node n = _tree.getRoot();
                if (!n->left && !n->right)
                    return (end());
                if (!n->left && n->right)
                    n = n->right;
                while (n->left)
                    n = n->left;
                return const_iterator(n);
            }
            iterator end(){ 
                return iterator(_tree.end());
            }
            const_iterator end(void)const{
                return const_iterator(_tree.end());
            }
            reverse_iterator rbegin(){
                iterator it = end();
                --it;
                return reverse_iterator(it.node());
            }
            const_reverse_iterator rbegin()const{
                iterator it = end();
                --it;
                return const_reverse_iterator(it.node());
            }
            reverse_iterator rend(){
                return reverse_iterator(_tree.getRoot());
            }
            const_reverse_iterator rend()const{
                return const_reverse_iterator(_tree.getRoot());
            }
            
            //capacity
            bool empty()const{ 
                if (!this->_size)
                    return true; 
                return false;
            }
            size_type size() const{
                return this->_size; 
            }
            size_type max_size() const{ 
                return (std::numeric_limits<size_type>::max() / sizeof(NodeRB<key_type, mapped_type>));
            }

            //modifiers
            void clear(){
                iterator it = begin();
                while (it != end()){
                    this->_tree.delete_node(it.node());
                    --this->_size;
                    ++it;
                }
            }
            std::pair<iterator, bool> insert(const value_type &value){
                iterator it = find(value.first);
                if (it != end())
                    return std::make_pair(it, false);
                ++this->_size;
                return std::make_pair(iterator(_tree.insert_node(_tree.getRoot(), value.first, value.second)), true);
            }
            iterator insert(iterator hint, const value_type &value){
                iterator it = find(value.first);
                if (it != end())
                    return (it);
                ++this->_size;
                return iterator(_tree.insert_node(hint.node(), value.first, value.second));
            }
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last,
            typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = NULL){
                while (first != last)
                {
                    insert(*first);
                    ++first;
                }
            }
            void erase(iterator position){
                this->_tree.delete_node(position.node());
                --this->_size;
            }
            template <class InputIterator>
            void erase(InputIterator first, InputIterator last,
            typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = NULL){
            iterator it = first;
            while (it != last)
                erase(it++);
            }
            size_type erase(const Key &key){
                size_t elem_deleted = 0;
                iterator itw = begin();
                while (itw != end()){
                    iterator it = find(key);
                    if (it != end()){
                        erase(it);
                        ++elem_deleted;
                    }
                    else
                        return (elem_deleted);
                    ++itw;
                }
                return elem_deleted;
            }
            void swap(Map &x){
                Map tmp = *this;
                *this = x;
                x = tmp;
            }

            //operations
            size_type count(const Key &key)const{
                size_t nb_matching_elements = 0;
                const_iterator itw = begin();
                while (itw != end()){
                    if (itw->first == key)
                        ++nb_matching_elements;
                    ++itw;
                }
                return nb_matching_elements;
            }
            iterator find(const Key &key){
                if (empty())
                    return (end());
                node tmp = _tree.find(_tree.getRoot(), key);
                if (tmp)
                    return (iterator(tmp));
                return (end());
            }
            const_iterator find(const Key &key)const{
                if (empty())
                    return end();
                node tmp = _tree.find(_tree.getRoot(), key);
                if (tmp)
                    return const_iterator(tmp);
                return end();
            }
            std::pair<iterator, iterator> equal_range(const Key &key){
                return std::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key));
            }
            std::pair<const_iterator, const_iterator> equal_range(const Key &key) const{
                return (std::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
            }
            iterator lower_bound(const Key &key){
                iterator it = begin();
                while (it != end()){
                    if (_comp(it->first, key) <= 0)
                        return it;
                    ++it;
                }
                return end();
            }
            const_iterator lower_bound(const Key &key)const{
                const_iterator it = begin();
                while (it != end()){
                    if (this->_comp(it->first, key) <= 0)
                        return (it);
                    ++it;
                }
                return end();
            }
            iterator upper_bound(const Key &key){
                iterator it = begin();
                while (it != end()){
                    if (it->first != key && _comp(it->first, key) <= 0)
                        return it;
                    ++it;
                }
                return end();
            }
            const_iterator upper_bound(const Key &key)const{
                const_iterator it = begin();
            while (it != end()){
                    if (it->first != key && _comp(it->first, key) <= 0)
                        return it;
                    ++it;
                }
                return end();
            }
            key_compare key_comp()const{
                return this->_comp; 
            }
            Map::value_compare value_comp()const{
                return value_comp;
            }
    };
    
    template <class Key, class T, class Compare, class Alloc>
    void swap(ft::Map<Key, T, Compare, Alloc> &x, ft::Map<Key, T, Compare, Alloc> &y){
        x.swap(y);
    };

    //relation operators
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs){
        typename ft::Map<Key, T, Compare, Alloc>::const_iterator it_lhs = rhs.begin();
        typename ft::Map<Key, T, Compare, Alloc>::const_iterator it_rhs = lhs.begin();        
        if (lhs.size() != rhs.size())
            return (false);
        while (it_lhs != rhs.end()){
            if (*it_lhs != *it_rhs)
                return (false);
            ++it_rhs;
            ++it_lhs;
        }
        return true;
    };
    
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs){
        return (!(lhs == rhs));
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs){
        typename ft::Map<Key, T, Compare, Alloc>::const_iterator it_lhs = lhs.begin();
        typename ft::Map<Key, T, Compare, Alloc>::const_iterator it_rhs = rhs.begin();        
        if (lhs.size() > rhs.size())
            return (true);
        while (it_lhs != lhs.end() && it_rhs != rhs.end()){
            if (*it_lhs > *it_rhs)
                return (true);
            ++it_rhs;
            ++it_lhs;
        }
        return false;
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs){
        return (!(lhs > rhs) && !(lhs == rhs));
    };
    
    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs){
        return (!(lhs < rhs));
    };
    
    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs){
        return (!(lhs > rhs));
    };
}
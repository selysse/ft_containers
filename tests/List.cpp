/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:11:14 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 06:01:57 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../srcs/Container.hpp"

bool single_digit (const int& value) { 
    return (value<10); 
}

template <typename T>
bool    iter_testingl(std::list<T> &s_list, ft::List<T> &m_list){
    typename std::list<T>::iterator it_st1 = s_list.begin();
    typename std::list<T>::iterator it_st2 = s_list.end();
    typename ft::List<T>::iterator it_my1 = m_list.begin();
    typename ft::List<T>::iterator it_my2 = m_list.end();
    while (it_st1 != it_st2)
    {
        if (*it_st1 != *it_my1)
		{
			std::cout  << *it_st1 << "\n" << *it_my1 << std::endl;
            return false;
		}
        ++it_st1;
        ++it_my1;
    }
    typename std::list<T>::reverse_iterator it_rst1 = s_list.rbegin();
    typename std::list<T>::reverse_iterator it_rst2 = s_list.rend();
    typename ft::List<T>::reverse_iterator it_rmy1 = m_list.rbegin();
    typename ft::List<T>::reverse_iterator it_rmy2 = m_list.rend();
    while (it_rst1 != it_rst2)
    {
        if (*it_rst1 != *it_rmy1)
		{
			std::cout  << *it_rst1 << "\n" << *it_rmy1 << std::endl;
            return false;
		}
        ++it_rst1;
        ++it_rmy1;
    }
    return true; 
}

static void    constructor_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
    if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;       
    }	
    std::list<int>s_list1(5,21);
	ft::List<int>m_list1(5, 21);
    if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;       
    }
    std::list<std::string> s_list2(3, "Hello world!");
    ft::List<std::string> m_list2(3, "Hello world!");
    if (s_list2.size() != m_list2.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_testingl(s_list2, m_list2)){
        std::cout << FAIL << std::endl;
        return ;       
    }    
	std::list<int>s_list3(s_list.begin(), s_list.end());
	ft::List<int>m_list3(m_list.begin(), m_list.end());
    if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;       
    }
    std::list<int>s_list4(s_list1);
    ft::List<int>m_list4(m_list1);
    if (s_list4.size() != m_list4.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_testingl(s_list4, m_list4)){
        std::cout << FAIL << std::endl;
        return ;       
    }
    std::cout << SUCCESS << std::endl;
}

static void    iterator_test(){
    std::list<int> s_list;
    std::list<int> s_list1;
    ft::List<int> m_list;
    ft::List<int> m_list1;
    std::list<int>::iterator its = s_list1.begin();
    std::list<int>::iterator its1 = s_list1.end();
    ft::List<int>::iterator itm = m_list1.begin();
    ft::List<int>::iterator itm1 = m_list1.end();
    *(++its) = 12345;
    *(++itm) = 12345;
    *(--its1) = 54321;
    *(--itm1) = 54321;
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;    
}

static void    front_test(){
    std::list<int> s_list; 
    ft::List<int> m_list;
    for (int i = 0; i < 5; i++){
        s_list.push_back(i);
        m_list.push_back(i);
    }   
    if (s_list.front() != m_list.front()){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.push_front(21);
    m_list.push_front(21);
    if (s_list.front() != m_list.front()){
        std::cout << FAIL << std::endl;
        return ;
	}       
    std::cout << SUCCESS << std::endl;    
}

static void    back_test(){
    std::list<int> s_list; 
    ft::List<int> m_list;
    for (int i = 0; i < 5; i++){
        s_list.push_back(i);
        m_list.push_back(i);
    }
    if (s_list.back() != m_list.back()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    s_list.push_back(21);
    m_list.push_back(21);
    if (s_list.back() != m_list.back()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl;
}

static void    empty_test(){
	std::list<int>ss_list;
	ft::List<int>m_list;
    if (ss_list.empty() != m_list.empty()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void	size_test(){
	std::list<int>s_list(21);
	ft::List<int>my_list(21);
	if (s_list.size() != my_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::list<int>ss_list;
	ft::List<int>m_list;
	if (ss_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    maxsize_test(){
	std::list<int>s_list(10, 21);
	ft::List<int>my_list(10, 21);
	if (s_list.max_size() != my_list.max_size()){
        std::cout << FAIL << std::endl;
        std::cout << s_list.max_size() << "\n" << my_list.max_size();
        return ;
	}
    std::cout << SUCCESS << std::endl;   
}

static void    assign_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.assign(10, 21);
    m_list.assign(10, 21);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::vector<int> s_vec;
    ft::Vector<int> m_vec;
    std::vector<int>::iterator its = s_vec.begin();
    ft::Vector<int>::iterator itm = m_vec.begin();
    s_list.assign(its, s_vec.end());
    m_list.assign(itm, m_vec.end());
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    push_front_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.push_front(21);
    m_list.push_front(21);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.push_front(42);
    m_list.push_front(42);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;       
}

static void    pop_front_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.push_front(21);
    m_list.push_front(21);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.push_front(42);
    m_list.push_front(42);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.pop_front();
    m_list.pop_front();
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.pop_front();
    m_list.pop_front();
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;    
}

static void    push_back_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}    
    s_list.push_back(42);
    m_list.push_back(42);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::list<char>s_list1;
	ft::List<char>m_list1;
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list1.push_back('A');
    m_list1.push_back('A');
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;   
}

static void    pop_back_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}    
    s_list.push_back(42);
    m_list.push_back(42);
    s_list.push_back(21);
    m_list.push_back(21);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.pop_back();
    m_list.pop_back();
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.pop_back();
    m_list.pop_back();
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    insert_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
    std::list<int>::iterator it_s = s_list.begin();
    ft::List<int>::iterator it_m = m_list.begin();
    for (int i = 1; i <= 5; ++i){
        m_list.push_back(i);
        s_list.push_back(i);
    }
    s_list.insert(++(it_s), 10);
    m_list.insert(++(it_m), 10);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.insert(++(it_s), 5, 21);
    m_list.insert(++(it_m), 5, 21);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::vector<int> s_vec(2, 30);
    ft::Vector<int> m_vec(2, 30);
    s_list.insert(++(it_s), s_vec.begin(), s_vec.end());
    m_list.insert(++(it_m), m_vec.begin(), m_vec.end());
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    erase_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
    std::list<int>::iterator it_s = s_list.begin();
    ft::List<int>::iterator it_m = m_list.begin();
    for (int i = 1; i <= 5; ++i){
        m_list.push_back(i);
        s_list.push_back(i);
    }
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.erase(++it_s);
    m_list.erase(++it_m);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::list<int>::iterator it_s2 = s_list.begin();
    ft::List<int>::iterator it_m2 = m_list.begin();
    std::list<int>::iterator it_s1 = s_list.end();
    ft::List<int>::iterator it_m1 = m_list.end();
    s_list.erase(++it_s2, --it_s1);
    m_list.erase(++it_m2, --it_m1);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}   
    std::cout << SUCCESS << std::endl;
}

static void    swap_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	std::list<int>s_list1;
	ft::List<int>m_list1;
    s_list.push_back(1);
    s_list.push_back(1);
    s_list.push_back(1);
    m_list.push_back(1);
    m_list.push_back(1);
    m_list.push_back(1); 
    s_list1.push_back(21);
    m_list1.push_back(21);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.swap(s_list1);
    m_list.swap(m_list1);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    resize_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.resize(5, 10);
    m_list.resize(5, 10);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.resize(21, 42);
    m_list.resize(21, 42);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;      
}

static void    clear_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
    for (int i = 1; i <= 5; ++i){
        m_list.push_back(i);
        s_list.push_back(i);
    }
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.clear();
    m_list.clear();
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    splice_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	std::list<int>s_list1;
	ft::List<int>m_list1;
    std::list<int>::iterator it_s = s_list.begin();
    ft::List<int>::iterator it_m = m_list.begin();
    std::list<int>::iterator it_s1 = s_list.end();
    ft::List<int>::iterator it_m1 = m_list.end();
    for (int i = 1; i <= 5; ++i){
        m_list.push_back(i);
        s_list.push_back(i);
    }
    s_list.splice(++it_s1, s_list1);
    m_list.splice(++it_m1, m_list1);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.splice(it_s, s_list1, ++(s_list.begin()));
    m_list.splice(it_m, m_list1, ++(m_list.begin()));
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.splice(it_s, s_list1, s_list1.begin(), s_list1.end());
    m_list.splice(it_m, m_list1, m_list1.begin(), m_list1.end());
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    remove_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
    for (int i = 0; i <= 5; ++i){
        m_list.push_back(i);
        s_list.push_back(i);
    }
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.remove(3);
    m_list.remove(3);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    remove_if_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    for (int i = 0; i <= 100; ++i){
        m_list.push_back(i);
        s_list.push_back(i);
    }
    s_list.remove_if(single_digit);
    m_list.remove_if(single_digit);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

bool funct(int a, int b){
    return (a == b);
}

static void    unique_test(){
	int mas[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 7};
    std::list<int>s_list(mas, mas + 10);
	ft::List<int>m_list(mas, mas + 10);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.unique();
    m_list.unique();
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::list<int>s_list1(mas, mas + 10);
	ft::List<int>m_list1(mas, mas + 10);
 	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}   
    s_list1.unique(funct);
    m_list1.unique(funct);
 	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}   
    std::cout << SUCCESS << std::endl;
}

static void    merge_test(){
	int mas[] = {1, 2, 3};
    int mas2[] = {3, 4, 5};
    std::list<int>s_list(mas, mas + 3);
	ft::List<int>m_list(mas, mas + 3);
    std::list<int>s_list1(mas2, mas2 + 3);
	ft::List<int>m_list1(mas2, mas2 + 3);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list.merge(s_list1);
    m_list.merge(m_list1);
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::list<int>s_list2(mas, mas + 3);
	ft::List<int>m_list2(mas, mas + 3);
    std::list<int>s_list3(mas2, mas2 + 3);
	ft::List<int>m_list3(mas2, mas2 + 3);
	if (s_list2.size() != m_list2.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list2, m_list2)){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (s_list3.size() != m_list3.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list3, m_list3)){
        std::cout << FAIL << std::endl;
        return ;
	}
    s_list2.merge(s_list3, funct);
    m_list2.merge(m_list3, funct);
	if (s_list2.size() != m_list2.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list2, m_list2)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

bool funct2(int a, int b)
{
	return (a < b);
}

static void    sort_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    for (int i = 0; i < 5; ++i){
        m_list.push_back(i);
        m_list.push_back(1);
        s_list.push_back(i);
        s_list.push_back(1);
    }
    s_list.sort();
    m_list.sort();
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::list<int>s_list1;
	ft::List<int>m_list1;
    for (int i = 0; i < 5; ++i){
        m_list1.push_back(i);
        m_list1.push_back(1);
        s_list1.push_back(i);
        s_list1.push_back(1);
    }
    s_list1.sort(funct2);
    m_list1.sort(funct2);
	if (s_list1.size() != m_list1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list1, m_list1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl; 
}

static void    reverse_testl(){
	std::list<int>s_list;
	ft::List<int>m_list;
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    for (int i = 0; i < 5; ++i){
        m_list.push_back(i);
        s_list.push_back(i);
    }
    m_list.reverse();
    s_list.reverse();
	if (s_list.size() != m_list.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_testingl(s_list, m_list)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl; 
}

static void    relation_test(){
	std::list<int>s_list;
	ft::List<int>m_list;
	std::list<int>s_list1;
	ft::List<int>m_list1;
    s_list.push_back(1);
    s_list1.push_back(21);
    m_list.push_back(1);
    m_list1.push_back(21);
    if ((m_list == m_list1) != (s_list == s_list1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_list != m_list1) != (s_list != s_list1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_list > m_list1) != (s_list > s_list1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_list >= m_list1) != (s_list >= s_list1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_list < m_list1) != (s_list < s_list1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_list <= m_list1) != (s_list <= s_list1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;        
}

int run_list(){
    std::cout << RED << "|================================================================|" << std::endl;
    std::cout << "|                              TEST LIST                         |" << std::endl;
    std::cout << RED << "|================================================================|" << RESET << std::endl;
	std::cout << GREEN << " \t\t\t\tSTD LIST" << RESET << std::endl;
    std::list<int> s_list;
    ft::List<int> my_list;
    for (int i = 0; i < 10; i++){
        s_list.push_back(i);
        my_list.push_back(i);
    }
    std::list<int>::iterator its = s_list.begin();
    std::cout << "\t\t\t STD LIST - ";
    while (its != s_list.end()){
        std::cout << *its << ' ';
        ++its;
    }
    std::cout << std::endl;
    std::cout << "\t\t\t   Size of list: " << s_list.size() << std::endl;
    std::cout << "\t\t\t   First element: " << s_list.front() << std::endl;
    std::cout << "\t\t\t   Last element:  " << s_list.back() << std::endl;    
    std::cout << GREEN << "\t\t\t\t MY LIST" << RESET << std::endl;
    ft::List<int>::iterator it = my_list.begin();
    std::cout << "\t\t\t MY LIST -  ";
    while (it != my_list.end()){
        std::cout << *it << ' ';
        ++it;
    }
    std::cout << std::endl;
    std::cout << "\t\t\t   Size of list: " << my_list.size() << std::endl;
    std::cout << "\t\t\t   First element: " << my_list.front() << std::endl;
    std::cout << "\t\t\t   Last element:  " << my_list.back() << std::endl;  
    std::cout << GREEN << "\t\t\t\t TESTS" << RESET << std::endl;
    std::cout << YELLOW;
    std::cout << "\t\t\tTest Constructors: ==== ";
    constructor_test();
    std::cout << "\t\t\tTest empty: =========== ";
    empty_test();  
    std::cout << "\t\t\tTest size: ============ ";
    size_test();
    std::cout << "\t\t\tTest max_size: ======== ";
    maxsize_test();
    std::cout << "\t\t\tTest iterator: ======== ";
    iterator_test();    
    std::cout << "\t\t\tTest front: =========== ";
    front_test();
    std::cout << "\t\t\tTest back: ============ ";
    back_test();
    std::cout << "\t\t\tTest assign: ========== ";
    assign_test();
    std::cout << "\t\t\tTest push_front: ====== ";
    push_front_test();
    std::cout << "\t\t\tTest pop_front: ======= ";
    pop_front_test();
    std::cout << "\t\t\tTest push_back: ======= ";
    push_back_test();
    std::cout << "\t\t\tTest pop_back: ======== ";
    pop_back_test();
    std::cout << "\t\t\tTest insert: ========== ";
    insert_test();
    std::cout << "\t\t\tTest erase: =========== ";
    erase_test();
    std::cout << "\t\t\tTest swap: ============ ";
    swap_test();
    std::cout << "\t\t\tTest resize: ========== ";
    resize_test();
    std::cout << "\t\t\tTest clear: =========== ";
    clear_test();
    std::cout << "\t\t\tTest splice: ========== ";
    splice_test();
    std::cout << "\t\t\tTest remove: ========== ";
    remove_test();
    std::cout << "\t\t\tTest remove_if: ======= ";
    remove_if_test();
    std::cout << "\t\t\tTest unique: ========== ";
    unique_test();
    std::cout << "\t\t\tTest merge: =========== ";
    merge_test();
    std::cout << "\t\t\tTest sort: ============ ";
    sort_test();
    std::cout << "\t\t\tTest reverse: ========= ";
    reverse_testl();
    std::cout << "\t\t\tTest relation: ======== ";
    relation_test();
    std::cout << RESET;
    return 0;
}
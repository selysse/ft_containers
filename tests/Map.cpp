/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:11:14 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 18:03:57 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../srcs/Container.hpp"

template <typename Key, typename T>
bool    iter_test(std::map<Key, T> &s_map, ft::Map<Key, T> &m_map){
    typename std::map<Key, T>::iterator it_st1 = s_map.begin();
    typename ft::Map<Key, T>::iterator it_my1 = m_map.begin();
    while (it_st1 != s_map.end()){
        if (it_st1->first != it_my1->first || it_st1->second != it_my1->second)
            return false;
        ++it_st1;
        ++it_my1;
    }
    return true;
}

static void    constructor_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    std::map<std::string, std::string> s_map1;
    ft::Map<std::string, std::string> m_map1;
    if (s_map1.size() != m_map1.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map1, m_map1)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    std::map<int, int> s_map2(s_map.begin(), s_map.end());
    ft::Map<int, int> m_map2(m_map.begin(), m_map.end());
    if (s_map2.size() != m_map2.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map2, m_map2)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    std::map<int, int> s_map3;
    ft::Map<int, int> m_map3;
    s_map3 = s_map;
    m_map3 = m_map;
    if (s_map3.size() != m_map3.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map3, m_map3)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    std::cout << SUCCESS << std::endl;  
}

static void    begin_end_test(){
    std::map<int, int> maps;    
    std::map<int, int> s_map(maps.begin(), maps.end());
    ft::Map<int, int> m_map(maps.begin(), maps.end());
    std::map<int, int>::iterator its = s_map.begin();
    ft::Map<int, int>::iterator itm = m_map.begin();
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    if (++its->second != ++itm->second || its->first != itm->first){
        std::cout << FAIL << std::endl;
        return ;         
    }
   std::map<int, int>::iterator its1 = s_map.end();
   ft::Map<int, int>::iterator itm1 = m_map.end();
   if ((its1->first != itm1->first) || (its1->second != itm1->second)){
       std::cout << FAIL << std::endl;
       return ;         
    }
    std::cout << SUCCESS << std::endl;  
}

static void    size_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    s_map.insert(std::make_pair(5, 0));
    m_map.insert(std::make_pair(5, 0));
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl;
}

static void    max_size_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    if (s_map.max_size() != m_map.max_size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl;
}

static void    operator_test(){
    std::map<char, int> s_map;
    ft::Map<char, int> m_map;
    s_map['A'] = 1;
    s_map['B'] = 2;
    s_map['C'] = 3;
    m_map['A'] = 1;
    m_map['B'] = 2;
    m_map['C'] = 3;
    if (s_map['A'] != m_map['A']){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl; 
}

static void    empty_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    if (s_map.empty() != m_map.empty()){
        std::cout << FAIL << std::endl;
        return ;       
    }
    std::cout << SUCCESS << std::endl;
}

static void    swap_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    std::map<int, int> s_map1;
    ft::Map<int, int> m_map1;
    s_map[0] = 1;
    s_map[1] = 2;
    m_map[0] = 1;
    m_map[1] = 2;
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.swap(s_map1);
    m_map.swap(m_map1);
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }  
    std::cout << SUCCESS << std::endl;        
}

static void    clear_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    s_map.insert(std::make_pair(5, 21));
    m_map.insert(std::make_pair(5, 21));
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.clear();
    m_map.clear();
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    std::cout << SUCCESS << std::endl;    
}

static void    insert_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    std::map<int, int> s_map1;
    ft::Map<int, int> m_map1;
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.insert(std::make_pair(5, 21));
    m_map.insert(std::make_pair(5, 21));
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    std::map<int, int>::iterator it_s;
    ft::Map<int, int>::iterator it_m;
    it_s = s_map.find(1);
    it_m = m_map.find(1);
    s_map.insert(it_s, std::make_pair(5, 21));
    m_map.insert(it_m, std::make_pair(5, 21));
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.insert(s_map1.begin(), s_map1.end());
    m_map.insert(m_map1.begin(), m_map1.end());
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    std::cout << SUCCESS << std::endl; 
}

static void    erase_test(){
    std::map<char, int> s_map;
    ft::Map<char, int> m_map;
    s_map['A'] = 1;
    s_map['B'] = 2;
    s_map['C'] = 3;
    m_map['A'] = 1;
    m_map['B'] = 2;
    m_map['C'] = 3;
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.erase(++s_map.begin());
    m_map.erase(++m_map.begin());
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.erase(++s_map.begin(), --s_map.end());
    m_map.erase(++m_map.begin(), --m_map.end());
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.erase('A');
    m_map.erase('A');
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.erase('F');
    m_map.erase('F');
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }  
    std::cout << SUCCESS << std::endl;
}

static void    find_test(){
    std::map<char, int> s_map;
    ft::Map<char, int> m_map;
    std::map<char, int>::iterator it_s;
    ft::Map<char, int>::iterator it_m;
    s_map['A'] = 1;
    s_map['B'] = 2;
    s_map['C'] = 3;
    m_map['A'] = 1;
    m_map['B'] = 2;
    m_map['C'] = 3;
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    it_s = s_map.find(1);
    it_m = m_map.find(1);
    if (it_s != s_map.end() || it_m != m_map.end()){
        std::cout << FAIL << std::endl;
        return ;             
    }
    std::map<char, int>::iterator it_s1;
    ft::Map<char, int>::iterator it_m1;
    it_s1 = s_map.find('A');
    it_m1 = m_map.find('A');
    if ((it_s1->first != it_m1->first) || (it_s1->second != it_m1->second)){
        std::cout << FAIL << std::endl;
        return ;        
    }    
    std::cout << SUCCESS << std::endl;       
}

static void    count_test(){
    std::map<char, int> s_map;
    ft::Map<char, int> m_map;
    s_map['A'] = 1;
    s_map['B'] = 2;
    s_map['C'] = 3;
    m_map['A'] = 1;
    m_map['B'] = 2;
    m_map['C'] = 3;
    if (s_map.count('A') != m_map.count('A')){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (s_map.count('T') != m_map.count('T')){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl;
}

static void    bound_test(){
    std::map<char, int> s_map;
    ft::Map<char, int> m_map;
    s_map['A'] = 1;
    s_map['B'] = 2;
    s_map['C'] = 3;
    m_map['A'] = 1;
    m_map['B'] = 2;
    m_map['C'] = 3;    
    std::map<char, int>::iterator it_s = s_map.lower_bound(1);
    ft::Map<char, int>::iterator it_m = m_map.lower_bound(1);
    if ((it_s->first != it_m->first) || (it_s->second != it_m->second)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    it_s = s_map.lower_bound('A');
    it_m = m_map.lower_bound('A');
    if ((it_s->first != it_m->first) || (it_s->second != it_m->second)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    it_s = s_map.upper_bound(1);
    it_m = m_map.upper_bound(1);
    if ((it_s->first != it_m->first) || (it_s->second != it_m->second)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    it_s = s_map.upper_bound('A');
    it_m = m_map.upper_bound('A');
    if ((it_s->first != it_m->first) || (it_s->second != it_m->second)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl;  
}

static void    equal_range_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    s_map[0] = 1;
    s_map[1] = 2;
    s_map[2] = 3;
    m_map[0] = 1;
    m_map[1] = 2;
    m_map[2] = 3;
    std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> it_s;
    std::pair<ft::Map<int, int>::iterator, ft::Map<int, int>::iterator> it_m;
    it_s = s_map.equal_range(1);
    it_m = m_map.equal_range(1);
    if ((it_s.first->first != it_m.first->first) || (it_s.second->second != it_m.second->second) ||
    (it_s.first->second != it_m.first->second) || (it_s.second->first != it_m.second->first)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> it_s1;
    std::pair<ft::Map<int, int>::iterator, ft::Map<int, int>::iterator> it_m1;
    it_s1 = s_map.equal_range(1000);
    it_m1 = m_map.equal_range(1000);
    if ((it_s.first->first != it_m.first->first) || (it_s.second->second != it_m.second->second) ||
    (it_s.first->second != it_m.first->second) || (it_s.second->first != it_m.second->first)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl; 
}

static void    relation_test(){
    std::map<int, int> s_map;
    ft::Map<int, int> m_map;
    std::map<int, int> s_map1;
    ft::Map<int, int> m_map1;
    if (s_map.size() != m_map.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map, m_map)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    if (s_map1.size() != m_map1.size()){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (!iter_test(s_map1, m_map1)){
        std::cout << FAIL << std::endl;
        return ;         
    }
    s_map.insert(std::make_pair(5, 21));
    m_map.insert(std::make_pair(5, 21));
    if((s_map == s_map1) != (m_map == m_map1)){
        std::cout << FAIL << std::endl;
        return ;              
    }
    if((s_map != s_map1) != (m_map != m_map1)){
        std::cout << FAIL << std::endl;
        return ;              
    }
    if((s_map > s_map1) != (m_map > m_map1)){
        std::cout << FAIL << std::endl;
        return ;              
    }
    if((s_map >= s_map1) != (m_map >= m_map1)){
        std::cout << FAIL << std::endl;
        return ;              
    }
    if((s_map < s_map1) != (m_map < m_map1)){
        std::cout << FAIL << std::endl;
        return ;              
    }
    if((s_map <= s_map1) != (m_map <= m_map1)){
        std::cout << FAIL << std::endl;
        return ;              
    }
    std::cout << SUCCESS << std::endl; 
}

int run_map(){
    std::cout << RED << "|================================================================|" << std::endl;
    std::cout << "|                              TEST MAP                          |" << std::endl;
    std::cout << RED << "|================================================================|" << RESET << std::endl;
	std::cout << GREEN << " \t\t\t\tSTD MAP" << RESET << std::endl;
	std::map<int, int> s_map;
    s_map[1] = 1;
    s_map[2] = 2;
    s_map[3] = 3;
    std::map<int, int>::iterator its = s_map.begin();
    std::cout << "\t\t\t STD MAP -  ";
    while (its != s_map.end()){
        std::cout << its->first << ' ';
        ++its;
    }
    std::cout << std::endl;
    std::cout << "\t\t\t   Size of Map: " << s_map.size() << std::endl;
	std::cout << GREEN << " \t\t\t\tMY MAP" << RESET << std::endl;
	ft::Map<int, int> m_map;
    m_map[1] = 1;
    m_map[2] = 2;
    m_map[3] = 3;
    ft::Map<int, int>::iterator itm = m_map.begin();
    std::cout << "\t\t\t MY MAP -  ";
    while (itm != m_map.end()){
        std::cout << itm->first << ' ';
        ++itm;
    }
    std::cout << std::endl;
    std::cout << "\t\t\t   Size of Map: " << m_map.size() << std::endl;
    std::cout << GREEN << "\t\t\t\t TESTS" << RESET << std::endl;
    std::cout << YELLOW;
    std::cout << "\t\t\tTest Constructors: = ";
    constructor_test();
    std::cout << "\t\t\tTest begin_end: ==== ";
    begin_end_test();
    std::cout << "\t\t\tTest empty: ======== ";
    empty_test();
    std::cout << "\t\t\tTest size: ========= ";
    size_test();
    std::cout << "\t\t\tTest max_size: ===== ";
    max_size_test();
    std::cout << "\t\t\tTest operator: ===== ";
    operator_test();
    std::cout << "\t\t\tTest insert: ======= ";
    insert_test();
    std::cout << "\t\t\tTest erase: ======== ";
    erase_test();
    std::cout << "\t\t\tTest swap: ========= ";
    swap_test();
    std::cout << "\t\t\tTest clear: ======== ";
    clear_test();
    std::cout << "\t\t\tTest find: ========= ";
    find_test();
    std::cout << "\t\t\tTest count: ======== ";
    count_test();
    std::cout << "\t\t\tTest bounds: ======= ";
    bound_test();
    std::cout << "\t\t\tTest equal_range: == ";
    equal_range_test();
    std::cout << "\t\t\tTest relation: ===== ";
    relation_test();
    std::cout << RESET;
    return 0;
}

# include "../srcs/Container.hpp"

template <typename T>
bool    iter_test(std::vector<T> &s_vec, ft::Vector<T> &my_vec){
    typename std::vector<T>::iterator it_st1 = s_vec.begin();
    typename std::vector<T>::iterator it_st2 = s_vec.end();
    typename ft::Vector<T>::iterator it_my1 = my_vec.begin();
    typename ft::Vector<T>::iterator it_my2 = my_vec.end();
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
    typename std::vector<T>::reverse_iterator it_rst1 = s_vec.rbegin();
    typename std::vector<T>::reverse_iterator it_rst2 = s_vec.rend();
    typename ft::Vector<T>::reverse_iterator it_rmy1 = my_vec.rbegin();
    typename ft::Vector<T>::reverse_iterator it_rmy2 = my_vec.rend();
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
    std::vector<int>s_vec(5);
    ft::Vector<int>my_vec(5);
    if (s_vec.size() != my_vec.size())
        std::cout << FAIL << std::endl;
    if (!iter_test(s_vec, my_vec)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::vector<int>s_vec1(5, 21);
    ft::Vector<int>my_vec1(5, 21);
    if (s_vec1.size() != my_vec1.size())
        std::cout << FAIL << std::endl;
    if (!iter_test(s_vec1, my_vec1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::vector<std::string>s_vec2(5, "A");
    ft::Vector<std::string>my_vec2(5, "A");
    if (s_vec2.size() != my_vec2.size())
        std::cout << FAIL << std::endl;
    if (!iter_test(s_vec2, my_vec2)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::vector<int> vec_s(s_vec);
    ft::Vector<int> vec_m(my_vec);
    if (s_vec1.size() != my_vec1.size())
        std::cout << FAIL << std::endl;
    if (!iter_test(s_vec1, my_vec1)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    iterator_test(){
    std::vector<int> s_vec(10);
    std::vector<int> s_vec1(10);
    ft::Vector<int> m_vec(10);
    ft::Vector<int> m_vec1(10);
    std::vector<int>::iterator its = s_vec1.begin();
    std::vector<int>::iterator its1 = s_vec1.end();
    ft::Vector<int>::iterator itm = m_vec1.begin();
    ft::Vector<int>::iterator itm1 = m_vec1.end();
    *its = 12345;
    *itm = 12345;
    *(--its1) = 54321;
    *(--itm1) = 54321;
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;    
}

static void    begin_end_test(){
    std::vector<int> s_vec(10);
    std::vector<int> s_vec1(10);
    ft::Vector<int> m_vec(10);
    ft::Vector<int> m_vec1(10);
    std::vector<int>::iterator its = s_vec1.begin();
    std::vector<int>::iterator its1 = s_vec1.end();
    ft::Vector<int>::iterator itm = m_vec1.begin();
    ft::Vector<int>::iterator itm1 = m_vec1.end();
    *its = 12345;
    *itm = 12345;
    *(--its1) = 54321;
    *(--itm1) = 54321;
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::vector<int> s_vec3(10);
    std::vector<int> s_vec4(10);
    ft::Vector<int> m_vec3(10);
    ft::Vector<int> m_vec4(10);
    std::vector<int>::reverse_iterator its3 = ++s_vec3.rbegin();
    std::vector<int>::reverse_iterator its4 = s_vec3.rend();
    ft::Vector<int>::reverse_iterator itm3 = ++m_vec3.rbegin();
    ft::Vector<int>::reverse_iterator itm4 = m_vec3.rend();
    ++(*its3) = 12345;
    ++(*itm3) = 12345;
    --(*its4) = 54321;
    --(*itm4) = 54321;
    if (!iter_test(s_vec4, m_vec4)){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_test(s_vec4, m_vec4)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void	size_test(){
	std::vector<int>v_std1(21);
	ft::Vector<int>v_my1(21);
	if (v_std1.size() != v_my1.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::vector<int>v_std;
	ft::Vector<int>v_my;
	if (v_std.size() != v_my.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void	msize_test(){
	std::vector<int>v_std1(21);
	ft::Vector<int>v_my1(21);
	if (v_std1.max_size() != v_my1.max_size()){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::vector<int>v_std;
	ft::Vector<int>v_my;
	if (v_std.max_size() != v_my.max_size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void	capacity_test(){
	std::vector<int>v_std;
	ft::Vector<int>v_my;
	if (v_std.capacity() != v_my.capacity()){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::vector<int>v_std_1(100);
	ft::Vector<int>v_my_1(100);
	if (v_std_1.capacity() != v_my_1.capacity()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    resize_test(){
	std::vector<int>v_std(100);
	ft::Vector<int>v_my(100);
	if (v_std.capacity() != v_my.capacity()){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (v_std.max_size() != v_my.max_size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    v_my.resize(20);
    v_std.resize(20);
	if (v_std.capacity() != v_my.capacity()){
        std::cout << FAIL << std::endl;
        return ;
	}
	if (v_std.max_size() != v_my.max_size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void	at_test(){
	std::vector<int>s_vec;
	ft::Vector<int>m_vec;
    int count = 0;
    s_vec.push_back(1);
    s_vec.push_back(2);
    s_vec.push_back(3);
    m_vec.push_back(1);
    m_vec.push_back(2);
    m_vec.push_back(3);
    try{
        s_vec.at(100);
        std::cout << FAIL << std::endl;
    } 
    catch (std::exception &e){
        count += 1;
    }
    try{
        m_vec.at(100);
        std::cout << FAIL << std::endl;
    } 
    catch (std::exception &e){
        count += 1;
    }
    try{
        s_vec.at(-1);
        std::cout << FAIL << std::endl;
    } 
    catch (std::exception &e){
        count += 1;
    }
    try{
        m_vec.at(-1);
        std::cout << FAIL << std::endl;
    } 
    catch (std::exception &e){
        count += 1;
    }    
    if (count == 4)
        std::cout << SUCCESS << std::endl;        
}

static void    operator_test(){
	std::vector<int>s_vec;
	ft::Vector<int>m_vec;
    int count = 0;
    int count1 = 0;
    s_vec.push_back(1);
    s_vec.push_back(2);
    s_vec.push_back(3);
    m_vec.push_back(1);
    m_vec.push_back(2);
    m_vec.push_back(3);
    try{
        s_vec[0];
    }
    catch(std::out_of_range &ex){
        count += 1;
    }
    try{
        m_vec[0];
    }
    catch(std::out_of_range &ex){
        count1 += 1;
    }
    if (count == count1){
        std::cout << SUCCESS << std::endl;
        return;
    }
    std::cout << FAIL << std::endl;
    return ;
}

static void	empty_test(){
	std::vector<int>v_std;
	ft::Vector<int>v_my;
	if (v_std.empty() != v_my.empty()){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::vector<int>v_std1(21);
	ft::Vector<int>v_my1(21);
	if (v_std.empty() != v_my.empty()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;
}

static void    reserve_test(){
	std::vector<int>v_std(1);
	ft::Vector<int>v_my(1);
	if (v_std.capacity() != v_my.capacity()){
        std::cout << FAIL << std::endl;
        return ;
	}
    v_std.reserve(5);
    v_my.reserve(5);
	if (v_std.capacity() != v_my.capacity()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;    
}

static void    assign_test(){
	std::vector<int>v_std;
	ft::Vector<int>v_my;
    v_std.assign(21, 42);
    v_my.assign(21,42);
	if (v_std.size() != v_my.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_test(v_std, v_my)){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::vector<int>vec_s;
	ft::Vector<int>my_vec;
    std::vector<int>::iterator its = v_std.begin();
    ft::Vector<int>::iterator itm = v_my.begin();
    vec_s.assign(its, v_std.end());
    my_vec.assign(itm, v_my.end());
	if (vec_s.size() != my_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!iter_test(vec_s, my_vec)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCCESS << std::endl;      
}

static void	push_back_test(){
	std::vector<int>v_std;
	ft::Vector<int>v_my;
    v_std.push_back(42);
    v_my.push_back(42);
    if (v_std.size() != v_my.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    v_std.push_back(21);
    v_my.push_back(21);
    if (v_std.size() != v_my.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    pop_back_test(){
	std::vector<int>v_std;
	ft::Vector<int>v_my;
    v_std.push_back(42);
    v_my.push_back(42);
    v_std.push_back(21);
    v_my.push_back(21);
    v_std.push_back(210);
    v_my.push_back(210); 
    if (v_std.size() != v_my.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    v_std.pop_back();
    v_my.pop_back();
    if (v_std.size() != v_my.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;     
}

static void    insert_test(){
    std::vector<int>s_vec(10);
    ft::Vector<int>m_vec(10);
    std::vector<int>::iterator it_s = s_vec.begin();
    ft::Vector<int>::iterator it_m = m_vec.begin();
    if (s_vec.size() != m_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    s_vec.insert(++it_s, 5);
    m_vec.insert(++it_m, 5);
    if (s_vec.size() != m_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::vector<int> s_vec2;
    ft::Vector<int> m_vec2;
    std::vector<int>::iterator it_s1 = s_vec.end();
    ft::Vector<int>::iterator it_m1 = m_vec.end();   
    s_vec.insert(--it_s1, s_vec2.begin(), s_vec2.end());
    m_vec.insert(--it_m1, m_vec2.begin(), m_vec2.end());
    if (s_vec.size() != m_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }        
    std::cout << SUCCESS << std::endl; 
}

static void    erase_test(){
    std::vector<int>s_vec(10);
    ft::Vector<int>m_vec(10);
    std::vector<int>::iterator it_s = s_vec.begin();
    ft::Vector<int>::iterator it_m = m_vec.begin();
    if (s_vec.size() != m_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    s_vec.erase(++it_s);
    m_vec.erase(++it_m);
    if (s_vec.size() != m_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    s_vec.erase(++it_s, s_vec.end());
    m_vec.erase(++it_m, m_vec.end());
    if (s_vec.size() != m_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl;
}

static void    clear_test(){
	std::vector<int>v_std;
	ft::Vector<int>v_my;
    if (v_std.size() != v_my.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }    
    v_std.push_back(42);
    v_my.push_back(42);
    v_std.push_back(21);
    v_my.push_back(21);
    v_std.push_back(210);
    v_my.push_back(210);
    v_my.clear();
    v_std.clear();
    if (v_std.size() != v_my.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }   
    v_std.push_back(2);
    v_my.push_back(2);
    v_std.push_back(10);
    v_my.push_back(10);
    if (v_std.size() != v_my.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;      
}

static void    swap_test(){
    std::vector<int> s_vec;
    std::vector<int> s_vec1;
    ft::Vector<int> m_vec;
    ft::Vector<int> m_vec1;
    s_vec.push_back(1);
    s_vec.push_back(1);
    s_vec.push_back(1);
    m_vec.push_back(1);
    m_vec.push_back(1);
    m_vec.push_back(1);
    s_vec1.push_back(21);
    m_vec1.push_back(21);
    if (s_vec.size() != m_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (s_vec1.size() != m_vec1.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec1, m_vec1)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    s_vec.swap(s_vec1);
    m_vec.swap(m_vec1);
    if (s_vec.size() != m_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec, m_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (s_vec1.size() != m_vec1.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!iter_test(s_vec1, m_vec1)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCCESS << std::endl;
}

static void    relation_test(){
    std::vector<int> s_vec;
    ft::Vector<int> m_vec;
    std::vector<int> s_vec1;
    ft::Vector<int> m_vec1;
    s_vec.push_back(1);
    s_vec1.push_back(21);
    m_vec.push_back(1);
    m_vec1.push_back(21);
    if ((m_vec == m_vec1) != (s_vec == s_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_vec != m_vec1) != (s_vec != s_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_vec > m_vec1) != (s_vec > s_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_vec >= m_vec1) != (s_vec >= s_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_vec < m_vec1) != (s_vec < s_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((m_vec <= m_vec1) != (s_vec <= s_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl; 
}

int run_vector()
{
    std::cout << RED << "|================================================================|" << std::endl;
    std::cout << "|                              TEST VECTOR                       |" << std::endl;
    std::cout << RED << "|================================================================|" << RESET << std::endl;
	std::cout << GREEN << " \t\t\t\tSTD VECTOR" << RESET << std::endl;
	std::vector<int>s_vec;
	ft::Vector<int>my_vec;
    for (int i = 0; i < 10; i++){
        s_vec.push_back(i);
        my_vec.push_back(i);
    }
    std::vector<int>::iterator its = s_vec.begin();
    std::cout << "\t\t\t STD VECTOR - ";
    while (its != s_vec.end()){
        std::cout << *its << ' ';
        ++its;
    }
    std::cout << std::endl;
    std::cout << "\t\t\tSize of vector: " << s_vec.size() << std::endl;
    std::cout << "\t\t\t   First element: " << s_vec.front() << std::endl;
    std::cout << "\t\t\t   Last element:  " << s_vec.back() << std::endl;       
    std::cout << GREEN << "\t\t\t\t MY VECTOR" << RESET << std::endl;
    ft::Vector<int>::iterator itm = my_vec.begin();
    std::cout << "\t\t\t MY VECTOR - ";
    while (itm != my_vec.end()){
        std::cout << *itm << ' ';
        ++itm;
    }
    std::cout << std::endl;
    std::cout << "\t\t\tSize of vector: " << my_vec.size() << std::endl;
    std::cout << "\t\t\t   First element: " << my_vec.front() << std::endl;
    std::cout << "\t\t\t   Last element:  " << my_vec.back() << std::endl;  
    std::cout << GREEN << "\t\t\t\t TESTS" << RESET << std::endl;
    std::cout << YELLOW;
    std::cout << "\t\t\tTest Constructors: ==== ";
    constructor_test();
    std::cout << "\t\t\tTest iterators: ======= ";
    iterator_test();
    std::cout << "\t\t\tTest b_end: =========== ";
    begin_end_test();
    std::cout << "\t\t\tTest size: ============ ";
    size_test();
    std::cout << "\t\t\tTest max_size: ======== ";
    msize_test();
    std::cout << "\t\t\tTest resize: ========== ";
    resize_test();
    std::cout << "\t\t\tTest capacity: ======== ";
    capacity_test();
    std::cout << "\t\t\tTest empty: =========== ";
    empty_test();
    std::cout << "\t\t\tTest reserve: ========= ";
    reserve_test();
    std::cout << "\t\t\tTest reserve: ========= ";
    reserve_test();
    std::cout << "\t\t\tTest at: ============== ";
    at_test();
    std::cout << "\t\t\tTest operator: ======== ";
    operator_test();
    std::cout << "\t\t\tTest assign: ========== ";
    assign_test();
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
    std::cout << "\t\t\tTest clear: =========== ";
    clear_test();
    std::cout << "\t\t\tTest relation: ======== ";
    relation_test();
    std::cout << RESET;
    return 0;

}

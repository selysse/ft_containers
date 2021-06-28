/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:26:29 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 06:01:48 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../srcs/Container.hpp"

template <class Stack>
bool    check(Stack &st){
	while(!st.empty())
	{
		std::cout << st.top() << '\n';
		st.pop();
	}
    std::cout << SUCCESS << std::endl;
    return true;
}

static void    empty_test(){
    std::stack<int, std::list<int> > Std_stack;
    ft::Stack<int, ft::List<int> > My_stack;
    if (Std_stack.empty() != My_stack.empty())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    Std_stack.push(42);
    My_stack.push(42);
    if (Std_stack.empty() != My_stack.empty())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    size_test(){
    std::stack<int, std::list<int> > Std_stack;
    ft::Stack<int, ft::List<int> > My_stack;
    if (Std_stack.size() != My_stack.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    for(int i = 0; i < 10; i++)
    {
        Std_stack.push(21);
        My_stack.push(21);
    }
    if (Std_stack.size() != My_stack.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    top_test(){
    std::stack<int, std::list<int> > Std_stack;
    ft::Stack<int, ft::List<int> > My_stack;
    if (Std_stack.size() != My_stack.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    Std_stack.push(42);
    My_stack.push(42);
    if (Std_stack.top() != My_stack.top())
    {
        std::cout << "Std Stack top - " << Std_stack.top() << std::endl;
        std::cout << "My Stack top - " << My_stack.top() << std::endl;
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    pop_test(){
    std::stack<int, std::list<int> > Std_stack;
    ft::Stack<int, ft::List<int> > My_stack;
    Std_stack.push(42);
    My_stack.push(42);
    if (Std_stack.size() != My_stack.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    My_stack.pop();
    Std_stack.pop();
    if (Std_stack.empty() != My_stack.empty())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    push_test(){
    std::stack<int, std::list<int> > Std_stack;
    ft::Stack<int, ft::List<int> > My_stack;
    Std_stack.push(42);
    My_stack.push(42);
    if (Std_stack.size() != My_stack.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    Std_stack.push(21);
    My_stack.push(21);
    if (Std_stack.size() != My_stack.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    relational_test(){
    std::stack<int, std::list<int> > Std_stack_1;
    ft::Stack<int, ft::List<int> > My_stack_1;
    std::stack<int, std::list<int> > Std_stack_2;
    ft::Stack<int, ft::List<int> > My_stack_2;
    My_stack_1.push(21);
    Std_stack_1.push(21);
    My_stack_2.push(42);
    Std_stack_2.push(42);
    if ((My_stack_1 == My_stack_2) != (Std_stack_1 == Std_stack_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_stack_1 != My_stack_2) != (Std_stack_1 != Std_stack_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_stack_1 > My_stack_2) != (Std_stack_1 > Std_stack_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_stack_1 >= My_stack_2) != (Std_stack_1 >= Std_stack_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_stack_1 < My_stack_2) != (Std_stack_1 < Std_stack_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_stack_1 <= My_stack_2) != (Std_stack_1 <= Std_stack_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

int     run_stack()
{
    std::cout << RED << "|================================================================|" << std::endl;
    std::cout << "|                              TEST STACK                        |" << std::endl;
    std::cout << RED << "|================================================================|" << RESET << std::endl;
    std::cout << GREEN << " \t\t\t\tSTD STACK" << RESET << std::endl;
    std::list<int> Stdlist(100);
    std::stack<int, std::list<int> > STD_Stack_0;
    std::stack<int, std::list<int> > STD_Stack_1(Stdlist);
    std::cout << "\t\t\tSize of first: " << STD_Stack_0.size() << std::endl;
    std::cout << "\t\t\tSize of second: " << STD_Stack_1.size() << std::endl;

    std::cout << GREEN << "\t\t\t\t MY STACK" << RESET << std::endl;
    ft::List<int> Mylist(100);
    ft::Stack<int, ft::List<int> > MY_Stack_0;
    ft::Stack<int, ft::List<int> > MY_Stack_1(Mylist);
    std::cout << "\t\t\tSize of first: " << MY_Stack_0.size() << std::endl;
    std::cout << "\t\t\tSize of second: " << MY_Stack_1.size() << std::endl;

    std::cout << GREEN << "\t\t\t\t TESTS" << RESET << std::endl;
    std::cout << YELLOW << "\t\t\tConstructors: ========= ";
    check(MY_Stack_0);
    std::cout << YELLOW << "\t\t\tTest empty: =========== ";
    empty_test();
    std::cout << "\t\t\tTest size: ============ ";
    size_test();
    std::cout << "\t\t\tTest top: ============= ";
    top_test();
    std::cout << "\t\t\tTest pop: ============= ";
    pop_test();
    std::cout << "\t\t\tTest push: ============ ";
    push_test();
    std::cout << "\t\t\tTest relational: ====== ";
    relational_test();
    std::cout << RESET << std::endl;
    return 0;
}
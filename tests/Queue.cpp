/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:26:29 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 06:01:34 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../srcs/Container.hpp"

template <class Queue>
static bool    check(Queue &st){
	while(!st.empty())
	{
		std::cout << st.back() << '\n';
		st.pop();
	}
    std::cout << SUCCESS << std::endl;
    return true;
}

static void    empty_test(){
    std::queue<int, std::list<int> > Std_queue;
    ft::Queue<int, ft::List<int> > My_queue;
    if (Std_queue.empty() != My_queue.empty())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    Std_queue.push(42);
    My_queue.push(42);
    if (Std_queue.empty() != My_queue.empty())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    size_test(){
    std::queue<int, std::list<int> > Std_queue;
    ft::Queue<int, ft::List<int> > My_queue;
    if (Std_queue.size() != My_queue.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    for(int i = 0; i < 10; i++)
    {
        Std_queue.push(21);
        My_queue.push(21);
    }
    if (Std_queue.size() != My_queue.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void		front_test(){
    std::queue<int, std::list<int> > Std_queue;
    ft::Queue<int, ft::List<int> > My_queue;
    if (Std_queue.size() != My_queue.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
	Std_queue.push(21);
	My_queue.push(21);
    if (Std_queue.front() != My_queue.front())
    {
        std::cout << "Std Queue front - " << Std_queue.front() << std::endl;
        std::cout << "My Queue front - " << My_queue.front() << std::endl;
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void		back_test(){
    std::queue<int, std::list<int> > Std_queue;
    ft::Queue<int, ft::List<int> > My_queue;
    if (Std_queue.size() != My_queue.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
	Std_queue.push(21);
	My_queue.push(21);
    if (Std_queue.back() != My_queue.back())
    {
        std::cout << "Std Queue top - " << Std_queue.back() << std::endl;
        std::cout << "My Queue top - " << My_queue.back() << std::endl;
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    push_test(){
    std::queue<int, std::list<int> > Std_queue;
    ft::Queue<int, ft::List<int> > My_queue;
    Std_queue.push(42);
    My_queue.push(42);
    if (Std_queue.size() != My_queue.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
	Std_queue.pop();
	My_queue.pop();
    Std_queue.push(21);
    My_queue.push(21);
    if (Std_queue.size() != My_queue.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    pop_test(){
    std::queue<int, std::list<int> > Std_queue;
    ft::Queue<int, ft::List<int> > My_queue;
    Std_queue.push(42);
    My_queue.push(42);
    if (Std_queue.size() != My_queue.size())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    My_queue.pop();
    Std_queue.pop();
    if (Std_queue.empty() != My_queue.empty())
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

static void    relational_test(){
    std::queue<int, std::list<int> > Std_queue_1;
    ft::Queue<int, ft::List<int> > My_queue_1;
    std::queue<int, std::list<int> > Std_queue_2;
    ft::Queue<int, ft::List<int> > My_queue_2;
    My_queue_1.push(21);
    Std_queue_1.push(21);
    My_queue_2.push(42);
    Std_queue_2.push(42);
    if ((My_queue_1 == My_queue_2) != (Std_queue_1 == Std_queue_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_queue_1 != My_queue_2) != (Std_queue_1 != Std_queue_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_queue_1 > My_queue_2) != (Std_queue_1 > Std_queue_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_queue_1 >= My_queue_2) != (Std_queue_1 >= Std_queue_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_queue_1 < My_queue_2) != (Std_queue_1 < Std_queue_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((My_queue_1 <= My_queue_2) != (Std_queue_1 <= Std_queue_2))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCCESS << std::endl;
}

int     run_queue()
{
    std::cout << RED << "|================================================================|" << std::endl;
    std::cout << "|                              TEST QUEUE                        |" << std::endl;
    std::cout << RED << "|================================================================|" << RESET << std::endl;
    std::cout << GREEN << " \t\t\t\tSTD QUEUE" << RESET << std::endl;
    std::list<int> Stdlist(100);
    std::queue<int, std::list<int> > STD_Queue_0;
    std::queue<int, std::list<int> > STD_Queue_1(Stdlist);
    std::cout << "\t\t\tSize of first: " << STD_Queue_0.size() << std::endl;
    std::cout << "\t\t\tSize of second: " << STD_Queue_1.size() << std::endl;

    std::cout << GREEN << "\t\t\t\t MY QUEUE" << RESET << std::endl;
    ft::List<int> Mylist(100);
    ft::Queue<int, ft::List<int> > MY_Queue_0;
    ft::Queue<int, ft::List<int> > MY_Queue_1(Mylist);
    std::cout << "\t\t\tSize of first: " << MY_Queue_0.size() << std::endl;
    std::cout << "\t\t\tSize of second: " << MY_Queue_1.size() << std::endl;

    std::cout << GREEN << "\t\t\t\t TESTS" << RESET << std::endl;
    std::cout << YELLOW << "\t\t\tConstructors: ========= ";
    check(MY_Queue_0);
    std::cout << YELLOW << "\t\t\tTest empty: =========== ";
    empty_test();
    std::cout << "\t\t\tTest size: ============ ";
    size_test();
    std::cout << "\t\t\tTest front: =========== ";
    front_test();
    std::cout << "\t\t\tTest back: ============ ";
    back_test();
    std::cout << "\t\t\tTest push: ============ ";
    push_test();
    std::cout << "\t\t\tTest pop: ============= ";
    pop_test();
    std::cout << "\t\t\tTest relational: ====== ";
    relational_test();
    std::cout << RESET << std::endl;
    return 0;
}
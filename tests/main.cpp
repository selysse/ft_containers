# include "../srcs/Container.hpp"

int     main(){
    std::string name;
    std::cout << "\n";
    std::cout << GREEN << "\t\t\t  Welcome !!!" << std::endl;
    std::cout << "\t\tEnter the name of the container" << std::endl;
    std::cout << "\tCommand: LIST, STACK, VECTOR, QUEUE, MAP, ALL" << std::endl;
    std::cout << "\n";
    std::cout << RED;
    std::cin >> name;
    while (1){
        if (name == "STACK"){
            run_stack();
            break ;
        }
        else if (name == "VECTOR"){
            run_vector();
            break ;
        }
        else if (name == "QUEUE"){
            run_queue();
            break ;
        }
        else if (name == "LIST"){
            run_list();
            break ;
        }
        else if (name == "MAP"){
            run_map();
            break ;
        }
        else if (name == "ALL"){
            run_list();
            run_map();
            run_vector();
            run_queue();
            run_stack();
            break ;
        }
        else{
            std::cout << RED << "ERROR COMMAND" << std::endl;
            break ;
        }
    }
    std::cout << RESET;
    return 0;
}
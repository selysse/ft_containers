/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:54:51 by gselyse           #+#    #+#             */
/*   Updated: 2021/06/25 16:23:21 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <memory>
#include <iostream>
#include <limits>
#include <utility>
#include <functional>

#include "List.hpp"
#include "Vector.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Map.hpp"

int     run_list();
int     run_map();
int     run_vector();
int     run_queue();
int     run_stack();

#define RED	"\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define SUCCESS "✅"
#define FAIL "❌"

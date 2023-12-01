/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:18:59 by ykissiko          #+#    #+#             */
/*   Updated: 2023/11/16 17:19:01 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    i = 1;
    while (argv[i])
    {
        j = -1;
        while (argv[i][++j])
            std::cout << (char)std::toupper(argv[i][j]);
        i++;
    }
    std::cout << std::endl;
    return (0);
}
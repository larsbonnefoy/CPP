/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:11:24 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:25 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <exception>
class Span {
    private:
        unsigned int                _size;
        std::vector<int>            _vec;

    public:
        Span(void);
        Span(unsigned int size);
        Span(const Span& other);
        ~Span(void);
        Span& operator=(const Span &other);

        void            addNumber(int nb);
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);
        void            fillSpan(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);

        class NoSpaceLeftException : public std::exception {
            const char* what(void) const throw();
        };

        class NotEnoughValuesException : public std::exception {
            const char* what(void) const throw();
        };
};
#endif

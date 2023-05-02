/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larsbonnefoy <larsbonnefoy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:26:33 by larsbonnefo       #+#    #+#             */
/*   Updated: 2023/05/02 12:26:33 by larsbonnefo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {

    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain(const Brain &other);
        ~Brain(void);
        Brain &operator=(const Brain &other);

        std::string getIdea(int index) const;
        void        setIdea(std::string idea);
        void        replaceIdea(std::string idea, int index);
};

#endif // !BRAIN_HPP

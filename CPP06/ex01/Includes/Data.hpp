/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:01:44 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/30 10:01:45 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP
struct Data {
    private:
        int _randomInt;

    public:
        Data(void);
        Data(int randonData);
        Data(const Data &other);
        ~Data(void);
        Data &operator=(const Data &other);
    
        int     getData(void);
        void    setData(int randonDatavoid);
};
#endif

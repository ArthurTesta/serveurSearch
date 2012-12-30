/*
 * exception.h
 *
 *  Created on: 01-oct.-2011
 *      Author: Proprietaire
 */
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdexcept>
#include <string>

class Exception
{
    std::string msg;
public:
    /*!
     * \brief Constructeur.
     *
     * \param msg Le message dont on veut affubler l'exception.
     */
    inline Exception(const std::string & msg) : msg(msg){}
    inline std::string what(){return msg;}
};

#endif // EXCEPTION_H

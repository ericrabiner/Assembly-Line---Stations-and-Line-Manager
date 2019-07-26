/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 1
Section: E
Date: June 21, 2019
*/

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include <string>
#include <iostream>
#include "Utilities.h"

namespace sict {
    class ItemSet{
        std::string _name;
        unsigned int _serialNumber;
        unsigned int _quantity;
        std::string _description;
        Utilities _utility;
        public:
        ItemSet(const std::string&);
        const std::string& getName() const;
        const unsigned int getSerialNumber() const;
        const unsigned int getQuantity() const;
        ItemSet& operator--();
        void display(std::ostream&, bool) const;
        ItemSet(const ItemSet&) = delete; //Copy Construction
        ItemSet& operator=(const ItemSet&) = delete; //Copy Assignment
        ItemSet(ItemSet&&); //Move Construction
        ItemSet& operator=(ItemSet&&) = delete; //Move Assignment
    };
}

#endif
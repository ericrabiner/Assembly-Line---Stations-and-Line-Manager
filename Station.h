/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 3
Section: E
Date: July 25, 2019
*/

#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <deque>
#include <string>
#include <iostream>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
    class Station {
        std::deque<CustomerOrder> _custOrders;
        ItemSet* _stationSet;
        public:
        Station();
        Station(const std::string&);
        ~Station();
        void display(std::ostream&) const;
        void fill(std::ostream&);
        const std::string& getName() const;
        bool hasAnOrderToRelease() const;
        Station& operator--();
        Station& operator+=(CustomerOrder&&);
        bool pop(CustomerOrder&);
        void validate(std::ostream&) const;
        bool isEmpty() const;

        Station(const Station&) = delete; //Copy Construction
        Station& operator=(const Station&) = delete; //Copy Assignment
        Station(Station&&) = delete; //Move Construction
        Station& operator=(Station&&) = delete; //Move Assignment
    };
}

#endif
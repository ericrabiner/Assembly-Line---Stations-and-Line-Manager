/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 3
Section: E
Date: July 25, 2019
*/

#ifndef SICT_LINEMANAGER_H
#define SICT_LINEMANAGER_H

#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include "CustomerOrder.h"
#include "Station.h"

namespace sict {
    class LineManager {
        std::vector<Station*> _stationAddresses;
        std::deque<CustomerOrder> _ordersToFill;
        std::deque<CustomerOrder> _complete;
        std::deque<CustomerOrder> _incomplete;
        std::vector<size_t> _nextIndexes;
        size_t _startIndex;
        size_t _lastIndex;
        
        public:
        LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
        void display(std::ostream&) const;
        bool run(std::ostream&);
    };
}

#endif
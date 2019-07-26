/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 2
Section: E
Date: July 5, 2019
*/

#ifndef SICT_CUSTOMERORDER_H
#define SICT_CUSTOMERORDER_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
    class CustomerOrder {
        std::string _custName;
        std::string _prodName;
        struct ItemInfo {
            std::string _itemName;
            unsigned int _itemSerial;
            bool _itemStatus;
            ItemInfo() : _itemName(""), _itemSerial(0), _itemStatus(false) {};
        };
        ItemInfo* _itemInfo;
        size_t _numItems;
        Utilities _utility;
        static size_t _FW;
        
        public:
        CustomerOrder();
        CustomerOrder(const std::string&);
        ~CustomerOrder();
        void fillItem(ItemSet&, std::ostream&);
        bool isFilled() const;
        bool isItemFilled(const std::string&) const;
        std::string getNameProduct() const;
        void display(std::ostream&, bool showDetail = false) const;

        CustomerOrder(const CustomerOrder&) = delete; //Copy Construction
        CustomerOrder& operator=(const CustomerOrder&) = delete; //Copy Assignment
        CustomerOrder(CustomerOrder&&); //Move Construction
        CustomerOrder& operator=(CustomerOrder&&); //Move Assignment
    };
}

#endif
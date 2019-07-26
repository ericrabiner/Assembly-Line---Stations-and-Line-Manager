/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 1
Section: E
Date: June 21, 2019
*/

#include "ItemSet.h"

namespace sict {
    ItemSet::ItemSet(const std::string& str) {
        size_t pos = 0;
        _name = _utility.extractToken(str, pos);
        if (_name.size() > _utility.getFieldWidth()) {
            _utility.setFieldWidth(_name.size());   
        }
        _serialNumber = std::stoi(_utility.extractToken(str, pos));
        _quantity = std::stoi(_utility.extractToken(str, pos));
        _description = _utility.extractToken(str, pos);  
    }

    const std::string& ItemSet::getName() const {
        return _name;
    }

    const unsigned int ItemSet::getSerialNumber() const {
        return _serialNumber;
    }

    const unsigned int ItemSet::getQuantity() const {
        return _quantity;
    }

    ItemSet& ItemSet::operator--() {
        _quantity--;
        _serialNumber++;
        return *this;
    }

    ItemSet::ItemSet(ItemSet&& src) {
        if (this != &src) {
             _name = src._name;
            _serialNumber = src._serialNumber;
            _quantity = src._quantity;
            _description = src._description;
            src._name = "";
            src._serialNumber = 0;
            src._quantity = 0;
            src._description = "";
        }
    }

    void ItemSet::display(std::ostream& os, bool full) const {
        size_t fw = _utility.getFieldWidth();
        if (full) {
            os.width(_utility.getFieldWidth());
            os.setf(std::ios::left);
            os << _name;
            os.unsetf(std::ios::left);
            os << " [";
            os.width(5);
            os << _serialNumber;
            os.fill('0');
            os << "] Quantity ";
            os.fill(' ');
            os.setf(std::ios::left);
            os.width(3);
            os << _quantity;
            os << " Description: ";
            os << _description << std::endl;
            os.unsetf(std::ios::left);
        }
        else {
            os << _name << " " << _serialNumber << std::endl;
        }
    }
}
/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 2
Section: E
Date: July 5, 2019
*/

#include "CustomerOrder.h"

namespace sict {
    size_t CustomerOrder::_FW = 0;

    CustomerOrder::CustomerOrder() : _custName(""), _prodName(""), _itemInfo(nullptr), _numItems(0) {}

    CustomerOrder::CustomerOrder(const std::string& str) {
        size_t pos = 0;
        _custName = _utility.extractToken(str, pos);
        if (_FW < _utility.getFieldWidth()) {
            _FW = _utility.getFieldWidth();
        }
        _prodName = _utility.extractToken(str, pos);
        _numItems = std::count(str.begin(), str.end(), _utility.getDelimiter()) - 1;
        _itemInfo = new ItemInfo[_numItems];
        if (_numItems > 0) {
            for (size_t i = 0; i < _numItems; i++) {
                _itemInfo[i]._itemName = _utility.extractToken(str, pos);
            }
        }
        else {
            throw "There are too few items.";
        }
    }

    CustomerOrder::~CustomerOrder() {
        delete [] _itemInfo;
        _itemInfo = nullptr;
    }

    void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
        for (size_t i = 0; i < _numItems; i++) {
            if (item.getName() == _itemInfo[i]._itemName) {
                if (item.getQuantity() == 0) {
                    os << " Unable to fill " << getNameProduct() << "[" << _itemInfo[i]._itemName << "][" << _itemInfo[i]._itemSerial << "] out of stock" << std::endl;
                }
                else {
                    if (_itemInfo[i]._itemStatus) {
                        os << " Unable to fill " << getNameProduct() << "[" << _itemInfo[i]._itemName << "][" << _itemInfo[i]._itemSerial << "] already filled" << std::endl;
                    }
                    else {
                        _itemInfo[i]._itemSerial = item.getSerialNumber();
                        _itemInfo[i]._itemStatus = true;
                        os << " Filled " << getNameProduct() << "[" << _itemInfo[i]._itemName << "][" << _itemInfo[i]._itemSerial << "]" << std::endl;
                        --item;
                    }
                }
            }
        }
    }

    bool CustomerOrder::isFilled() const {
        bool filled = true;
        for (size_t i = 0; i < _numItems; i++) {
            if (_itemInfo[i]._itemStatus == false) {
                filled = false;
            }
        }
        return filled;
    }

    bool CustomerOrder::isItemFilled(const std::string& str) const {
        bool filled = true;
        for (size_t i = 0; i < _numItems; i++) {
            if (_itemInfo[i]._itemName == str && _itemInfo[i]._itemStatus == false) {
                filled = false;
            }
        }
        return filled;
    }
    std::string CustomerOrder::getNameProduct() const {
        return _custName + " [" + _prodName + "]";
    }

    void CustomerOrder::display(std::ostream& os, bool showDetail) const {
        if (showDetail) {
            std::cout << std::setw(_FW) << _custName << "[" << _prodName << "]" << std::endl;
            for (size_t i = 0; i < _numItems; i++) {
                std::cout << std::setfill(' ') << std::setw(_FW) << " " << "[" << _itemInfo[i]._itemSerial << "] " << _itemInfo[i]._itemName << " - " << (_itemInfo[i]._itemStatus == true ? "FILLED" : "MISSING") << std::endl;
            }
        }
        else {
            std::cout << std::left << std::setw(_FW) << _custName << "[" << _prodName << "]" << std::endl;
            for (size_t i = 0; i < _numItems; i++) {
                std::cout << std::setfill(' ') << std::setw(_FW) << " " << std::setw(_FW) << std::left << _itemInfo[i]._itemName << std::endl;
            }
        }
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& src) {
        *this = std::move(src);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
        if (this != &src) {
            _custName = src._custName;
            _prodName = src._prodName;
            _itemInfo = nullptr;
            delete[] _itemInfo;
            _itemInfo = src._itemInfo;
            _numItems = src._numItems;
            src._custName = "";
            src._prodName = "";
            src._itemInfo = nullptr;
            src._numItems = 0;
        }
    }
}
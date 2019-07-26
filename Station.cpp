/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 3
Section: E
Date: July 25, 2019
*/

#include "Station.h"

namespace sict {

    Station::Station() {
        _stationSet = nullptr;
    }

    Station::Station(const std::string& str) {
        _stationSet = new ItemSet(str);
    }

    Station::~Station() {
        delete[] _stationSet;
        _stationSet = nullptr;
    }

    void Station::display(std::ostream& os) const {
        _stationSet->display(os, true);
    }

    void Station::fill(std::ostream& os) {
        if (!_custOrders.empty()) {
            _custOrders.back().fillItem(*_stationSet, os);
        }
    }

    const std::string& Station::getName() const {
        return _stationSet->getName();
    }

    bool Station::hasAnOrderToRelease() const {
        bool status = false;
        if (!_custOrders.empty() && (_custOrders.front().isItemFilled(_stationSet->getName()) || _stationSet->getQuantity() == 0)) {
            status = true;
        }
        return status;
    }

    Station& Station::operator--() {
        --(*_stationSet);
        return *this;
    }

    Station& Station::operator+=(CustomerOrder&& order) {
        _custOrders.push_back(std::move(order));
        return *this;

    }

    bool Station::pop(CustomerOrder& ready) {
        bool status = false;
        if (!_custOrders.empty()) {
            ready = std::move(_custOrders.front());
            _custOrders.pop_front();
            if (hasAnOrderToRelease()) {
                status = true;
            }
        }
        return status;
    }

    void Station::validate(std::ostream& os) const {
        os << "getName(): " << _stationSet->getName() << std::endl;
        os << "getSerialNumber(): " << _stationSet->getSerialNumber() << std::endl;
        os << "getQuantity(): " << _stationSet->getQuantity() << std::endl;
    }

    bool Station::isEmpty() const {
        return _custOrders.empty();
    }
}
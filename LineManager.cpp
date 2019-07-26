/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 3
Section: E
Date: July 25, 2019
*/

#include "LineManager.h"

namespace sict {
    LineManager::LineManager(std::vector<Station*>& stationAddresses, std::vector<size_t>& nextIndexes, 
    std::vector<CustomerOrder>& custOrders, size_t startIndex, std::ostream& os) {
        _stationAddresses = std::move(stationAddresses);
        _nextIndexes = nextIndexes;
        _startIndex = startIndex;
        for (size_t i = 0; i < custOrders.size(); i++) {
            _ordersToFill.push_front(std::move(custOrders[i]));
        }
        for_each(nextIndexes.begin(), nextIndexes.end(), [&](size_t i = 0) {
            if (nextIndexes[i] == nextIndexes.size()) {
                _lastIndex = i;
            }
            i++;
        });
    }

    void LineManager::display(std::ostream& os) const {
        os << "COMPLETED ORDERS" << std::endl;
        for (auto& completeOrder : _complete) {
            completeOrder.display(os, true);
        }

        os << std::endl << "INCOMPLETE ORDERS" << std::endl;
        for (auto& incompleteOrder : _incomplete) {
            incompleteOrder.display(os, true);
        }
        os << std::endl;
    }

    bool LineManager::run(std::ostream& os) {
        CustomerOrder ready;

        if (!_ordersToFill.empty()) {
            *_stationAddresses[_startIndex] += std::move(_ordersToFill.back());
            _ordersToFill.pop_back();
        }

        for (size_t i = 0; i < _nextIndexes.size(); i++) {
            _stationAddresses[i]->fill(os);
        }

        for (size_t i = 0; i < _stationAddresses.size(); i++) {
            bool hasAnOrderToRelease = _stationAddresses[i]->hasAnOrderToRelease();
            if (_stationAddresses[i]->hasAnOrderToRelease()) {
                _stationAddresses[i]->pop(ready);
                if (i != _lastIndex) {
                    os << "--> " << ready.getNameProduct() << " moved from " << _stationAddresses[i]->getName() 
                    << " to " << _stationAddresses[_nextIndexes[i]] ->getName() << std::endl;
                    *_stationAddresses[_nextIndexes[i]] += std::move(ready);
                }
                else {
                    if (ready.isFilled()) {
                        os << "--> " << ready.getNameProduct() << " moved from " + _stationAddresses[i]->getName()
                        << " to Completed Set" << std::endl;
                        _complete.push_back(std::move(ready));
                    }
                    else {
                        os << "--> " << ready.getNameProduct() << " moved from " + _stationAddresses[i]->getName()
                        << " to Incomplete Set" << std::endl;
                        _incomplete.push_back(std::move(ready));
                    }
                }
            }
        }

        bool allProcessed = true;
        for (size_t i = 0; i < _stationAddresses.size(); i++) {
            if (!_stationAddresses[i]->isEmpty()) {
                allProcessed = false;
            }
        }
        return allProcessed;
    }
}
/*
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Milestone: 1
Section: E
Date: June 21, 2019
*/

#include "Utilities.h"

namespace sict {
    char Utilities::_delimiter = '|';
    size_t Utilities::_fieldwidth = 0;

    Utilities::Utilities() {};

    const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
        std::string token;
        size_t pos = next_pos;
        next_pos = str.find(_delimiter, pos);
        if (next_pos != std::string::npos) {
            token = str.substr(pos, next_pos - pos);
            next_pos++;
        }
        else {
            token = str.substr(pos);
        }
        return token;
    }

    const char Utilities::getDelimiter() const {
        return _delimiter;
    }

    size_t Utilities::getFieldWidth() const {
        return _fieldwidth;
    }

    void Utilities::setDelimiter(const char d) {
        _delimiter = d;
    }

    void Utilities::setFieldWidth(size_t fw) {
        _fieldwidth = fw;
    }
}
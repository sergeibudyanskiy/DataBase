//
//  Row.h
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#ifndef Row_h
#define Row_h

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

class Row
{
public:
    Row( const std::vector<std::string>& row );
    ~Row();
    
    void show( const std::vector<size_t>& sizes ) const;
    
    std::string get( std::size_t index ) const;
    
private:
    std::vector<std::string> row_;
};

#endif /* Row_h */

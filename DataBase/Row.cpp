//
//  Row.cpp
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#include "Row.h"

Row::Row( const std::vector<std::string>& row ) : row_( row )
{
}

Row::~Row()
{
}

void Row::show( const std::vector<size_t>& sizes ) const
{
    std::size_t i = 0;
    
    std::cout << "|";
    for ( const auto& r : row_ )
    {
        std::cout.width( sizes[i++] );
        std::cout << std::setiosflags( std::ios::left ) << r << "|";
    }
}

std::string Row::get( std::size_t index ) const
{
    std::string result;
    
    if ( index < row_.size() )
    {
        result = row_[index];
    }
    
    return result;
}

//
//  Table.cpp
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#include "Table.h"

Table::Table( const std::vector<std::pair<std::size_t, std::string>>& header, const std::vector<Row>& rows ) : header_( header ), rows_( rows )
{
}

Table::~Table()
{
}

void Table::show() const
{
    std::vector<size_t> sizes;
    
    if ( header_.empty() )
    {
        return;
    }
    
    std::cout << "|";
    for ( const auto& h : header_ )
    {
        std::size_t size = h.first;
        
        if ( !size )
        {
            size = h.second.size();
            std::for_each( rows_.begin(), rows_.end(), [&]( const auto& r )
            {
                if ( r.get( sizes.size() ).length() > size )
                {
                    size = r.get( sizes.size() ).length();
                }
            });
        }
        sizes.push_back( size );
        std::cout.width( size );
        std::cout << std::setiosflags( std::ios::left ) << h.second << "|";
    }
    std::cout << std::endl << std::endl;

    
    for ( const auto& r : rows_ )
    {
        r.show( sizes );
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

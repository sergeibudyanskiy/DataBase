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
    std::size_t id_size = std::to_string( rows_.size() ).length() + 1;
    
    if ( header_.empty() )
    {
        return;
    }
    
    std::cout << "|";
    std::cout.width( id_size );
    std::cout << std::setiosflags( std::ios::left ) << "ID" << "|";
    
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
        
        std::string item = h.second;
        std::transform( item.begin(), item.end(), item.begin(), ::toupper );
        
        std::cout << std::setiosflags( std::ios::left ) << item << "|";
    }
    std::cout << std::endl << std::endl;

    std::size_t id = 0;
    for ( const auto& r : rows_ )
    {
        std::cout << "|";
        std::cout.width( id_size );
        std::cout << std::setiosflags( std::ios::left ) << id++ ;
        r.show( sizes );
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::size_t Table::get_header_index( const std::string& name ) const
{
    std::size_t index = 0;
    std::size_t result = -1;
    
    for ( const auto& h : header_ )
    {
        if ( h.second == name )
        {
            result = index;
            break;
        }
        index++;
    }
    
    return result;
}

Row Table::get_row( std::size_t index ) const
{
    std::size_t i = 0;
    
    for ( const auto& r : rows_ )
    {
        if ( i++ == index )
        {
            return r;
        }
    }
    
    return Row(std::vector<std::string>());
}

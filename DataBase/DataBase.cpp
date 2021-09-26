//
//  DataBase.cpp
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#include "DataBase.h"

DataBase::DataBase( const std::string& path ) : path_( path )
{
}

DataBase::~DataBase()
{
}

bool DataBase::add_table( const std::string& name )
{
    bool result = false;
    
    if ( tables_.end() == std::find_if( tables_.begin(), tables_.end(), [&]( const auto& table ) { return table.first == name; } ) )
    {
        Data data( path_, name );
        Parser parser( data.get() );
        
        tables_.insert( std::make_pair( name, parser.parse() ) );
        
        result = true;
    }
    
    return result;
}

std::string DataBase::show( const std::string& table ) const
{
    std::string result;
    
    if ( !table.length() )
    {
        for ( const auto& t : tables_ )
        {
            t.second.show();
        }
    }
    else if ( ( result = std::find_if( tables_.begin(), tables_.end(), [&]( const auto& t )
    {
        return std::string::npos != table.find( t.first );
    })->first ).length() )
    {
        tables_.at( result ).show();
    }
    
    return result;
}

std::string DataBase::select( const std::string& table, const std::string& header, const std::size_t& id ) const
{
    std::string result;
    
    for ( const auto& t : tables_ )
    {
        if ( t.first == table )
        {
            std::size_t header_index = t.second.get_header_index( header );
            if ( -1 != header_index )
            {
                for ( const auto& t : tables_ )
                {
                    result = t.second.get_row( id ).get( header_index );
                }
            }
        }
    }

    
    return result;
}

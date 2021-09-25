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

std::string DataBase::query( const std::string& command ) const
{
    std::string result;
    
    if ( std::string::npos != command.find( "show" ) )
    {
        std::string name = std::find_if( tables_.begin(), tables_.end(), [&]( const auto& t )
        {
            return std::string::npos != command.find( t.first );
        })->first;
        
        show_table( name );
    }
    else
    {
        
    }
    
    return result;
}

void DataBase::show_table( const std::string& name ) const
{
    if ( name.length() )
    {
        tables_.at( name ).show();
    }
    else
    {
        for ( const auto& table : tables_ )
        {
            table.second.show();
        }
    }
}

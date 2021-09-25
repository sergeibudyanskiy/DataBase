//
//  Data.cpp
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#include "Data.h"

Data::Data( const std::string& path, const std::string name ) : full_name_( path + name )
{
    file_.open( full_name_, std::fstream::in | std::fstream::out | std::fstream::app );
    
    if ( file_.is_open() )
    {
        file_.open( full_name_, std::fstream::in | std::fstream::out | std::fstream::trunc );
    }
}

Data::~Data()
{
    file_.close();
}

std::string Data::get() const
{
    std::string result;
    
    std::getline( std::ifstream( full_name_ ), result, '\0' );
    
    return result;
}

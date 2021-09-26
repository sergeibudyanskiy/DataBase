//
//  main.cpp
//  DataBase 1.0.0.1
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#include "DataBase.h"

int main( int argc, const char * argv[] )
{
    DataBase db( "" );
    
    db.add_table( "user" );
    
    std::cout << db.select( "user", "name", 0 ) << std::endl;
    std::cout << db.select( "user", "surname", 0 ) << std::endl;
    std::cout << db.select( "user", "age", 0 ) << std::endl;
    
    return 0;
}

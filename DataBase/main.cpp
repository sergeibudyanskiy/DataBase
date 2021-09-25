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
    db.add_table( "card" );
    
    db.query( "show card" );
    
    return 0;
}

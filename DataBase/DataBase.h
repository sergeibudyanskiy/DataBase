//
//  DataBase.h
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#ifndef DataBase_h
#define DataBase_h

#include <map>
#include <algorithm>

#include "Data.h"
#include "Table.h"
#include "Parser.h"

class DataBase
{
public:
    DataBase( const std::string& path );
    ~DataBase();
    
    bool add_table( const std::string& name );
    
    std::string show( const std::string& table = "" ) const;
    std::string select( const std::string& table, const std::string& header, const std::size_t& id ) const;
private:
    
    std::string path_;
    
    std::map<std::string, Table> tables_;
};

#endif /* DataBase_h */

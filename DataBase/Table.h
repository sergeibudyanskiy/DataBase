//
//  Table.h
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#ifndef Table_h
#define Table_h

#include "Row.h"

class Table
{
public:
    Table( const std::vector<std::pair<std::size_t, std::string>>& header, const std::vector<Row>& rows );
    ~Table();
    
    void show() const;
    
    std::size_t get_header_index( const std::string& name ) const;
    Row get_row( std::size_t index ) const;

private:
    std::string data_;
    
    std::vector<std::pair<std::size_t, std::string>> header_;
    std::vector<Row> rows_;
};

#endif /* Table_h */

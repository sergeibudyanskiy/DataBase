//
//  Parser.h
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#ifndef Parser_h
#define Parser_h

#include "Table.h"

class Parser
{
public:
    Parser( const std::string& data );
    ~Parser();
    
    Table parse() const;
    
private:
    std::vector<std::string> parse_line( const std::string& line, bool tolower = false ) const;
    std::vector<std::pair<std::size_t, std::string>> parse_header() const;
    std::vector<Row> parse_rows() const;
    
    std::string data_;
};

#endif /* Parser_h */

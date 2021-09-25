//
//  Parser.cpp
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#include "Parser.h"

Parser::Parser( const std::string& data ) : data_( data )
{
}

Parser::~Parser()
{
}

Table Parser::parse() const
{
    std::vector<Row> rows;
    std::vector<std::pair<std::size_t, std::string>> header = parse_header();
    
    if ( header.size() )
    {
        rows = parse_rows();
    }
    
    return Table( header, rows );
    
}

std::vector<std::string> Parser::parse_line( const std::string& line ) const
{
    std::vector<std::string> result;
    std::size_t begin = 0, end = 0, start = 0;
    
    while ( std::string::npos != ( begin = line.find( "\"", start ) ) )
    {
        end = line.find( "\"", ++begin );
        start = end + 1;
        
        result.emplace_back( line.substr( begin, end - begin ) );
    }
    
    return result;
}

std::vector<std::pair<std::size_t, std::string>> Parser::parse_header() const
{
    std::vector<std::pair<std::size_t, std::string>> result;
    std::vector<std::string> line;
    std::size_t begin = 0, end = 0, start = 0;
    
    if ( std::string::npos != ( begin = data_.find( "[", start ) ) )
    {
        end = data_.find( "]", ++begin );
        line = parse_line( data_.substr( begin, end - begin ) );
        for ( auto& l : line )
        {
            if ( std::string::npos != ( begin = l.find( "|" ) ) )
            {
                result.push_back( std::make_pair( std::stoi( l.substr( begin + 1, std::string::npos ) ), l.substr( 0, begin ) ) );
            }
            else
            {
                result.push_back( std::make_pair( 0, l ) );
            }
        }
    }
    
    return result;
}

std::vector<Row> Parser::parse_rows() const
{
    std::vector<Row> result;
    std::size_t begin = 0, end = 0, start = 0;
    
    while ( std::string::npos != ( begin = data_.find( "{", start ) ) )
    {
        end = data_.find( "}", ++begin );
        start = end;
        
        result.push_back( parse_line( data_.substr( begin, end - begin ) ) );
    }
    
    return result;
}

//
//  Data.h
//  DataBase
//
//  Created by Sergei Budyanskiy on 25.09.2021.
//

#ifndef Data_h
#define Data_h

#include <fstream>
#include <sstream>

class Data
{
public:
    Data( const std::string& path, const std::string name );
    ~Data();
    
    std::string get() const;
    
private:
    std::string full_name_;
    
    std::fstream file_;
};

#endif /* Data_h */

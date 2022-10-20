#include <string>
#include <iostream>
#include <sstream>

#include "log.h"

using namespace std;

string Log::to_string() {
//    string ret = this->date + ":" + this->time + ":" 
//                + this->username + ":" + this->ip + ":";
//    if (this->success) {
//        ret = ret + "true";
//    }
//    else {
//        ret = ret + "false";
//    }
//    return ret;

    ostringstream oss;
    oss << date << ':' << time << ':' << username << ':' << ip << ':';

    if (this->success)
    {
        oss << "true";
    }  else
    {
        oss << "false";
    }

    return oss.str();
}

Log::Log(string str_in)
{
    if (str_in[str_in.size() - 1] == '1')
        this->success = true;
    else 
        this->success = false;
    str_in.pop_back();

    string::size_type ix {0};
    string placeholder;
    do
    {
        ix = str_in.find(':');
        placeholder = str_in.substr(0, ix);
        if (this->date.empty())
        {
            this->date = placeholder;
            str_in.erase(0, ix + 1);
            continue;
        }
        if (this->time.empty())
        {
            this->time = placeholder;
            str_in.erase(0, ix + 1);
            continue;
        }
        if (this->username.empty())
        {
            this->username = placeholder;
            str_in.erase(0, ix + 1);
            continue;
        }
        if (this->ip.empty())
        {
            this->ip = placeholder;
            str_in.erase(0, ix + 1);
            continue;
        }
    } while (!str_in.empty());
}

// INLINE FUNCS
std::string Log::get_date() const {return date;} // these public get functions should be constant, since we do not intend the user to modify these values.
std::string Log::get_time() const {return time;}
std::string Log::get_username() const {return username;}
std::string Log::get_ip() const {return ip;}
bool Log::get_success() const {return success;}

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "log_list.h"

using namespace std;

/**
 * @brief Construct a new Log_List::Log_List object
 * 
 * @param fname : filename in root directory. do not include directions to search overarching directories.
 */
Log_List::Log_List(const string& fname)
{
    ifstream stream_in {"../" + fname};

    string str_in;
    
    while (getline(stream_in, str_in))
    {
        log_list.push_back(Log(str_in));
    }
    stream_in.close();
}

/**
 * @brief Construct a new Log_List object from a vector of logs
 * 
 * @param vector<Log> 
 */
// Log_List::Log_List(vector<Log>& vec_in)
// {
//     log_list = vec_in;
// }

// FUNCTIONS

/**
 * @brief Add individual Log item to a Log_List
 * 
 * @param log_in 
 * @return Log_List& 
 */
Log_List& Log_List::add_log(Log& log_in)
{
    log_list.push_back(log_in);

    return *this;
}

Log Log_List::get_nth_member(int ix)
{
    if (ix <= log_list.size())
        return log_list[ix];
    else
        std::cout << "Error: index out of bounds. Returning last item." << std::endl;
        return log_list[log_list.size()];
}

size_t Log_List::get_size()
{
    return log_list.size();
}

// ASSIGNMENT FUNCTIONS

/**
 * @brief Get a list containing all Logs containing a given username.
 * 
 * @param username_in Username
 * @return Log_List
 */
Log_List Log_List::filter_by_name(const string& username_in)
{
    Log_List filtered_list;
    for (auto i:log_list)
    {
        if (i.get_username() == username_in)
        {
            filtered_list.add_log(i);
        }
    }

    return filtered_list;
}

/**
 * @brief Remove all Log objects occuring on a given date.
 * 
 * @param date_in Date, formatted MM/DD/YYYY
 * @return Log_List& 
 */
Log_List& Log_List::prune_by_date(const string& date_in)
{
    for (auto i = log_list.begin(); i != log_list.end(); ++i)
    {
        auto deref_log = *i;
        if (deref_log.get_date() == date_in)
        {
            log_list.erase(i);
        }
    }
    return *this;
}
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "log.h" // redundant, but good practice to show that we are working with Log objects
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
        this->logs.push_back(Log(str_in));
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
//     logs = vec_in;
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
    this->logs.push_back(log_in);

    return *this;
}

/**
 * @brief Get nth member of Log_List
 * 
 * @param ix Index position
 * @return Log 
 */
Log Log_List::get_nth_member(int ix)
{
    if (ix <= this->logs.size())
        return this->logs[ix];
    else
        std::cerr << "Error: index out of bounds. Returning last item." << std::endl;
        return this->logs[this->logs.size()];
}

/**
 * @brief Get size of Log_List object.
 * 
 * @return size_t 
 */
size_t Log_List::get_size()
{
    return this->logs.size();
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
    Log_List filtered_list; // new logs to return
    for (auto& log:this->logs) // range for over THIS logs
    {
        if (log.get_username() == username_in) // if the indexed log's username in THIS logs matches the INPUT USERNAME 
        {
            filtered_list.add_log(log); // add the indexed log to the new logs
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
    for (auto i = this->logs.begin(); i != this->logs.end(); ++i)
    {
        auto deref_log = *i;
        if (deref_log.get_date() == date_in)
        {
            this->logs.erase(i);
        }
    }
    return *this;
}
#ifndef LOG_LIST_H_
#define LOG_LIST_H_

#include <string>
#include <vector>

#include "log.h"

/**
 * @brief Contain a list of Log objects.
 * 
 */
class Log_List
{
public:
    // CONSTRUCTORS

    Log_List() = default; // default constructor

    /**
     * @brief Construct a new Log_List::Log_List object
     * 
     * @param fname : filename in root directory. do not include directions to search overarching directories.
     */
    Log_List(const std::string&);

    /**
     * @brief Construct a new Log_List object from a vector of logs
     * 
     * @param vector<Log> 
     */
//    Log_List(vector<Log>&);

    // MISC PUBLIC MEMBER FUNCTIONS

    Log_List& add_log(Log&); // add a log
    Log get_nth_member(int); // get nth member of loglist
    size_t get_size(); // get size of loglist
    
    // assignment functions

    Log_List filter_by_name(const std::string&);
    Log_List& prune_by_date(const std::string&);
private:
    std::vector<Log> logs;

};

#endif 
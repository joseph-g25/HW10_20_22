#include <iostream>
#include <vector>
#include <string>
#include "log_list.h"

using namespace std;

/* Due 10.20.22
Reading: 7.4, 7.6, 8.2-8.3
Exercises: Write a class called LogList. Objects of this type should contain a list of Log objects (from our previous homework). Internally, use a vector to hold the log entries.
    Your class should have a default constructor and a constructor that takes the name of a file (the file is formatted as in problem 3 from the October 13 assignment) and reads all the logs in from that file.
    You should have a member function filter_by_name() that takes a string (a user name) as parameter and returns a LogList object containing just the logs that have the given username.  
    You should have a member function called prune_by_date() that takes a string like "10-20-2022" representing a date and removes all log entries from the LogList object that occur on that date.

Upload the header and source files for the LogList class.
*/


int main()
{
    // constructor test    
    Log_List my_log_list("my_log_file.txt");
    auto first_member = my_log_list.get_nth_member(0);
    cout << first_member.get_date()
    << "\n" << first_member.get_time()
    << "\n" << first_member.get_username()
    << "\n" << first_member.get_ip()
    << "\n" << first_member.get_success()
    << "\n" << endl;

    // test assignment functions
    auto second_log_list = my_log_list.filter_by_name("briandaboll");
    auto test_member = second_log_list.get_nth_member(1);
    cout << test_member.get_username() << endl;
    cout <<  "Sizes before/after filtering for username: " << my_log_list.get_size() << " " << second_log_list.get_size() << endl;

    cout << "Sizes before/after pruning by date: " << my_log_list.get_size();
    my_log_list.prune_by_date("29/10/2022");
    cout << " " << my_log_list.get_size() << endl;
    

    return 0;
}

#ifndef LOG_H_
#define LOG_H_
#include <string>

/**
 * @brief Contains a single instance of login attempt information.
 * 
 */
class Log {
public:
    // CONSTRUCTORS
    Log() = default;    // because we are defining other constructors, we must define the default constructor as well since the compiler will not
                        // do so with the presence of other constructors.

    Log(const std::string& d, const std::string& t, const std::string& u, const std::string& i, bool s):
                                                    date(d), time(t), username(u), ip(i), success(s) {};

    Log(std::string str_in);
    
    // we do not need to instruct the compiler to create the default copy/destruction constructors, since it does it implicitly 
    // and we are not changing any aspect of the default operations

    /** 
     * returns a textual representation of this Log object
    */
    std::string to_string();

    // INLINE FUNCS
    std::string get_date() const;
    std::string get_time() const;
    std::string get_username() const;
    std::string get_ip() const;
    bool get_success() const;
        
private:
    std::string date;
    std::string time;
    std::string username;
    std::string ip;
    bool success;
};

#endif /* LOG */

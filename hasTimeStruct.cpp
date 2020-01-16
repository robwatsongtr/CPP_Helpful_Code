
// Robert's hepful code demonstrating how to use struct tm

 #include <iostream>
 #include <string>
 #include <stdio.h>
 #include <time.h>

class HasTimeStruct {

public:
    HasTimeStruct() : i_(0), time_is_valid_(false) { memset(&tm_, 0, sizeof(tm_));  }

    HasTimeStruct(std::string s, int i) : s_(s), i_(i), time_is_valid_(false)  {
        memset(&tm_, 0, sizeof(tm_));
    }
    bool parseTime(std::string timeStr);
    const struct tm time_member() const { return tm_; }
    bool isTimeValid() const { return time_is_valid_; }

private:
    std::string s_;
    int i_;
    struct tm tm_;
    bool time_is_valid_;
};

bool HasTimeStruct::parseTime(std::string timeStr) {

    char *rest = strptime(timeStr.c_str(), "%T", &tm_);
    if (*rest != '\0') {  // did we parse the whole string or are there unparsed characters left over
        time_is_valid_ = false;
    } else {
        time_is_valid_ = true;
    }
    return time_is_valid_;
}


int main() {

    HasTimeStruct t1;

    const HasTimeStruct t2(t1);
    std::cout << "t2 is valid " << t2.isTimeValid() << std::endl;

    t1.parseTime("5:30:15");
    if (t1.isTimeValid()) {
        std::cout << t1.time_member().tm_hour << ":" << t1.time_member().tm_min << ":"
        << t1.time_member().tm_sec << std::endl;
    } else {
        std::cout << "string was not valid" << std::endl;
    }
}

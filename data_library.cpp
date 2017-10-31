#include "data_library.h"
#include <string>
Data_library::Data_library(std::string library_file_location) : _library_file_location{library_file_location} {
    read_in_data();
}

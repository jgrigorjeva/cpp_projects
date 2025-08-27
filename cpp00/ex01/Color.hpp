#ifndef COLOR_HPP
# define COLOR_HPP

# include <iostream>

namespace Color {
    const std::string reset  = "\033[0m";
    const std::string bred    = "\033[1;31m";
    const std::string bgreen  = "\033[1;32m";
    const std::string yellow = "\033[33m";
    const std::string bblue   = "\033[1;34m";
}

#endif
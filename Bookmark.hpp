#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

struct Bookmark {
    int id = 0;
    std::string title;
    std::string url;
    std::string description;
    std::string category;
    std::vector<std::string> tags;
    std::string dateAdded;
    bool favorite = false;
};
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
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
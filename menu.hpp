#pragma once
#include "Bookmark.hpp"
#include "BookmarkManager.hpp"
 
class Menu {
public:
    explicit Menu(BookmarkManager& manager);
    void printBookmark(const Bookmark& b);
    void printMenu();
 
private:
    BookmarkManager& manager;
};
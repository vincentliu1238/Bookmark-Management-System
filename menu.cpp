#include "menu.hpp"
#include <iostream>
 
Menu::Menu(BookmarkManager& manager) : manager(manager) {}
 
void Menu::printBookmark(const Bookmark& b) {
    std::cout << "[" << b.id << "] " << b.title << " - " << b.url;
    if (b.favorite) std::cout << "  (favorite)";
    std::cout << "\n";
    if (!b.description.empty()) std::cout << "    " << b.description << "\n";
}
 
void Menu::printMenu() {
    std::cout << "\n===== Bookmark Manager =====\n"
               << "1. Add bookmark\n"
               << "2. Remove bookmark\n"
               << "3. Get bookmark by id\n"
               << "4. List all bookmarks\n"
               << "5. Search bookmarks\n"
               << "6. Mark as favorite\n"
               << "7. Unmark as favorite\n"
               << "0. Exit\n"
               << "Choose an option: ";
}
 
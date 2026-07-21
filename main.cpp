#include "BookmarkManager.hpp"
#include "menu.hpp"
#include <iostream>
#include <limits>
 
int main() {
    BookmarkManager manager;
    Menu menu(manager);
    int choice = -1;
 
    while (choice != 0) {
        menu.printMenu();
        std::cin >> choice;
 
        if (std::cin.fail()) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number.\n";

            continue;

        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
 
        switch (choice) {
            case 1: {
                Bookmark b;
                std::cout << "Title: ";
                std::getline(std::cin, b.title);
                std::cout << "URL: ";
                std::getline(std::cin, b.url);
                std::cout << "Description (optional): ";
                std::getline(std::cin, b.description);
                manager.addBookmark(b);
                std::cout << "Bookmark added.\n";
                break;
            }
            case 2: {
                std::cout << "Remove: ";
                int id;
                std::cin >> id;
                manager.removeBookmark(id);
                std::cout << "Bookmark removed.\n";
                break;
            }
            case 3: {
                std::cout << "Look up: ";
                int id;
                std::cin >> id;
                Bookmark b = manager.getBookmark(id);
                if (b.id == 0) {
                    std::cout << "No bookmark found with that id.\n";
                } else {
                    menu.printBookmark(b);
                }
                break;
            }
            case 4: {
                auto all = manager.getAllBookmarks();
                if (all.empty()) {
                    std::cout << "No bookmarks yet.\n";
                } else {
                    for (const auto& b : all) menu.printBookmark(b);
                }
                break;
            }
            case 5: {
                std::cout << "Keyword: ";
                std::string keyword;
                std::getline(std::cin, keyword);
                auto results = manager.searchBookmarks(keyword);
                if (results.empty()) {
                    std::cout << "No matches.\n";
                } else {
                    for (const auto& b : results) menu.printBookmark(b);
                }
                break;
            }
            case 6: {
                std::cout << "Mark as favorite: ";
                int id;
                std::cin >> id;
                manager.markAsFavorite(id);
                std::cout << "Done.\n";
                break;
            }
            case 7: {
                std::cout << "Unmark as favorite: ";
                int id;
                std::cin >> id;
                manager.unmarkAsFavorite(id);
                std::cout << "Done.\n";
                break;
            }
            case 0:
                std::cout << "Ending program.\n";
                break;

            default:
                std::cout << "Invalid option.\n";
        }
    }
 
    return 0;
}
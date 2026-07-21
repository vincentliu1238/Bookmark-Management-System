#include "BookmarkManager.hpp"

void BookmarkManager::addBookmark(const Bookmark& bookmark) {
    Bookmark newBookmark = bookmark;
    newBookmark.id = nextId++;
    bookmarks.push_back(newBookmark);
}

void BookmarkManager::removeBookmark(int id) {
    for (size_t i = 0; i < bookmarks.size(); i++) {
        if (bookmarks[i].id == id) {
            bookmarks.erase(bookmarks.begin() + i);
            return;
        }
    }
}

Bookmark BookmarkManager::getBookmark(int id) const {
    for (const auto& bookmark : bookmarks) {
        if (bookmark.id == id) {
            return bookmark;
        }
    }
    return Bookmark(); //Return an empty bookmark if not found
}
std::vector<Bookmark> BookmarkManager::getAllBookmarks() const{
    return bookmarks;
}

std::vector<Bookmark> BookmarkManager::searchBookmarks(const std::string& keyword) const{
    std::vector<Bookmark> results;

    for (const auto& bookmark : bookmarks) {
        if (bookmark.title.find(keyword) != std::string::npos ||
            bookmark.description.find(keyword) != std::string::npos ||
            bookmark.category.find(keyword) != std::string::npos ||
            std::find(bookmark.tags.begin(), bookmark.tags.end(), keyword) != bookmark.tags.end()) { 
                //Keyword was found
            results.push_back(bookmark);
        }
    }
    return results;
}

void BookmarkManager::markAsFavorite(int id) {
    for (auto& bookmark : bookmarks) {
        if (bookmark.id == id) {
            bookmark.favorite = true;
            return;
        }
    }
}
 
void BookmarkManager::unmarkAsFavorite(int id) {
    for (auto& bookmark : bookmarks) {
        if (bookmark.id == id) {
            bookmark.favorite = false;
            return;
        }
    }
}
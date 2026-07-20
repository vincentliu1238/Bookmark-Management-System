#include "BookmarkManager.hpp"

void BookmarkManager::addBookmark(const Bookmark& bookmark) {
    bookmarks.push_back(bookmark);
}

void BookmarkManager::removeBookmark(int id){
    bookmarks.erase(std::remove_if(bookmarks.begin(), bookmarks.end(),
        [id](const Bookmark& b) { return b.id == id; }), bookmarks.end());
}

Bookmark BookmarkManager::getBookmark(int id) const{
    auto it = std::find_if(bookmarks.begin(), bookmarks.end(),
        [id](const Bookmark& b) { return b.id == id; });
    if (it != bookmarks.end()) {
        return *it;
    }
    return Bookmark(); // Return an empty bookmark if not found
}

std::vector<Bookmark> BookmarkManager::getAllBookmarks() const{
    return bookmarks;
}

std::vector<Bookmark> BookmarkManager::searchBookmarks(const std::string& keyword) const{
    std::vector<Bookmark> results;
    for (const auto& bookmark : bookmarks) {
        if (bookmark.title.find(keyword) != std::string::npos ||
            bookmark.description.find(keyword) != std::string::npos) {
            results.push_back(bookmark);
        }
    }
    return results;
}

void BookmarkManager::markAsFavorite(int id){
    auto it = std::find_if(bookmarks.begin(), bookmarks.end(),
        [id](const Bookmark& b) { return b.id == id; });
    if (it != bookmarks.end()) {
        it->favorite = true;
    }
}

void BookmarkManager::unmarkAsFavorite(int id){
    auto it = std::find_if(bookmarks.begin(), bookmarks.end(),
        [id](const Bookmark& b) { return b.id == id; });
    if (it != bookmarks.end()) {
        it->favorite = false;
    }
}

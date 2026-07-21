#pragma once

#include "Bookmark.hpp"

class BookmarkManager {
public:
    void addBookmark(const Bookmark& bookmark);
    void removeBookmark(int id);
    Bookmark getBookmark(int id) const;
    std::vector<Bookmark> getAllBookmarks() const;
    std::vector<Bookmark> searchBookmarks(const std::string& keyword) const;
    void markAsFavorite(int id);
    void unmarkAsFavorite(int id);
    
private:
    std::vector<Bookmark> bookmarks;
    int nextId = 1;
};
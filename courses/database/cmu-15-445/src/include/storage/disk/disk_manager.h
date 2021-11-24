//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// disk_manager.h
//
// Identification: courses/include/storage/disk/disk_manager.h
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

// see: https://blog.csdn.net/weixin_39640298/article/details/84503428
# pragma once
# include <atomic>
# include <fstream>
# include <future>
# include <string>

namespace bustub {

/**
 * DiskManager takes care of the allocation and deallocation of pages within a database. It performs the reading and
 * writing of pages to and from disk, providing a logical file layer within the context of a database management system.
 */

class DiskManager {

public:
    /**
     * Creates a new disk manager that writes to the specified database file.
     * @param db_file the file name of the database file to write to
     */
    explicit DiskManager(const std::string &db_file);

    ~DiskManager() = default;

    /**
     * Shut down the disk manager and close all the file resources.
     */
    void ShutDown();

    /**
     * Write a page to the database file.
     * @param page_id id of the page
     * @param page_data raw page data
     */
     void WritePage(page_id_t page_id, const char *page_data);
};

}
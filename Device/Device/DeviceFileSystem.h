#ifndef DEVICE_FILE_SYSTEM_H
#define DEVICE_FILE_SYSTEM_H

#include "Device.h"

struct file;
struct inode_operations;
struct inode;
struct deviceFs;

struct file {
    const struct file_operations *f_ops;
    void *private_data;
}

struct inode_operations {
    ssize_t (*open)();
    ssize_t (*write)();
};

struct file_operations {
    ssize_t (*open)(struct inode *inode, struct file *file);
    ssize_t (*read)(struct file *file, char *buf, rsize_t count);
    ssize_t (*write)(struct file *file, char *buf, rsize_t count);
    ssize_t (*release)(struct inode *inode, struct file *file);
};

struct inode {
    const struct inode_operations *i_op;
    const struct file_operations *i_fop;
};

class DeviceOperations
{
public:
	

private:
};

#endif	//	DEVICE_FILE_SYSTEM_H
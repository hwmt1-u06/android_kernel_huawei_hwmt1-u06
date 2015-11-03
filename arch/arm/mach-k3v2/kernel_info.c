/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <linux/stat.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/input.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>

static ssize_t arom_version_show(struct device *dev,
	    struct device_attribute *attr, char *buf) {

    size_t count = 0;

    count = sprintf(buf, "AROM V7 FULL\n");
    return count;
}

static ssize_t arom_version_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count) {

    return count;
}

static DEVICE_ATTR(arom_version, S_IWUSR|S_IRUGO,
	arom_version_show, arom_version_store);

static ssize_t target_device_show(struct device *dev,
	    struct device_attribute *attr, char *buf) {
    size_t count = 0;

    count = sprintf(buf, "HUAWEI ASCEND MATE\n");
    return count;
}

static ssize_t target_device_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count) {

    return count;
}

static DEVICE_ATTR(target_device, S_IWUSR|S_IRUGO,
	target_device_show, target_device_store);

struct kobject *kernel_info_kobj;
EXPORT_SYMBOL_GPL(kernel_info_kobj);

static int __init kernel_info_init(void) {

    int rc = 0;

    kernel_info_kobj = kobject_create_and_add("kernel_info", NULL) ;
    if (kernel_info_kobj == NULL) {
    pr_warn("%s: kernel_info_kobj create_and_add failed\n", __func__);
    }
    rc = sysfs_create_file(kernel_info_kobj, &dev_attr_arom_version.attr);
    if (rc) {
    pr_warn("%s: sysfs_create_file failed for info1\n", __func__);
    }
    rc = sysfs_create_file(kernel_info_kobj, &dev_attr_target_device.attr);
    if (rc) {
    pr_warn("%s: sysfs_create_file failed for info2\n", __func__);
    }
    return 0;
}

static void __exit kernel_info_exit(void)
{
    kobject_del(kernel_info_kobj);
    return;
}

module_init(kernel_info_init);
module_exit(kernel_info_exit);

MODULE_AUTHOR("Kostyan_nsk");
MODULE_DESCRIPTION("Shows some hardcoded kernel info");
MODULE_VERSION("1.0");
MODULE_LICENSE("GPLv2");

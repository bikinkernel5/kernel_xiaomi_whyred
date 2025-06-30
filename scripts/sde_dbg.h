#ifndef SDE_DBG_H_
#define SDE_DBG_H_

#include <linux/types.h>
#include <linux/printk.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/debugfs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>
#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/kthread.h>
#include <linux/kfifo.h>
#include <linux/ktime.h>

struct sde_dbg_power_ctrl;
struct drm_device;
struct sde_kms;

static inline int sde_dbg_init(struct dentry *debugfs_root, struct device *dev,
                               struct sde_dbg_power_ctrl *power_ctrl)
{
    return 0;
}

static inline void sde_dbg_destroy(void) {}

static inline void sde_dbg_dump(bool queue_work, const char *name, ...)
{
}

static inline void sde_dbg_ctrl(const char *name, ...)
{
}

static inline void sde_dbg_init_dbg_buses(u32 hwversion)
{
}

static inline int sde_dbg_reg_register_base(const char *name,
                                            void __iomem *base,
                                            size_t length)
{
    return 0;
}

static inline void sde_dbg_reg_register_dump_range(const char *base_name,
                                                   const char *range_name,
                                                   u32 start_offset,
                                                   u32 end_offset,
                                                   uint32_t blk)
{
}

static inline void sde_dbg_set_sde_top_offset(u32 blk_off)
{
}

static inline void sde_evtlog_log(void *evtlog, const char *func_name, const char *fmt, ...)
{
}

#define SDE_EVT32(...)           sde_evtlog_log(NULL, __func__, ##__VA_ARGS__)
#define SDE_EVT32_VERBOSE(...)  SDE_EVT32(__VA_ARGS__)
#define SDE_DBG_EVTLOG(...)     SDE_EVT32(__VA_ARGS__)

#endif /* SDE_DBG_H_ */

#ifndef SDE_DBG_H_
#define SDE_DBG_H_

#include <linux/types.h>
#include <linux/printk.h>
#include <linux/device.h>
#include <linux/fs.h>
#include "sde_evtlog.h"

#define SDE_EVTLOG_DATA_LIMITER    (0xC0DEBEEF)
#define SDE_EVTLOG_FUNC_ENTRY      0x1111
#define SDE_EVTLOG_FUNC_EXIT       0x2222
#define SDE_EVTLOG_ERROR           0xebad
#define SDE_DBG_DUMP_DATA_LIMITER  (NULL)

enum sde_dbg_evtlog_flag { ... };
enum sde_dbg_dump_flag { ... };

/* Struct definition */
struct sde_dbg_power_ctrl { ... };
struct sde_dbg_evtlog { ... };
extern struct sde_dbg_evtlog *sde_dbg_base_evtlog;

#define SDE_EVT32(...) /* macro */
#define SDE_DBG_DUMP(...) /* macro */
#define SDE_DBG_DUMP_WQ(...) /* macro */
#define SDE_DBG_CTRL(...) /* macro */

#ifdef CONFIG_DEBUG_FS
/* deklarasi fungsi untuk non-inline build */
int sde_evtlog_init(...);
void sde_evtlog_destroy(...);
bool sde_evtlog_is_enabled(...);
ssize_t sde_evtlog_dump_to_buffer(...);

void sde_dbg_init_dbg_buses(u32 hwversion);
int sde_dbg_init(struct dentry *debugfs_root, struct device *dev,
                 struct sde_dbg_power_ctrl *power_ctrl);
void sde_dbg_destroy(void);
void sde_dbg_dump(bool queue_work, const char *name, ...);
void sde_dbg_ctrl(const char *name, ...);
int sde_dbg_reg_register_base(const char *name, void __iomem *base, size_t size);
void sde_dbg_reg_register_dump_range(const char *base_name,
                                     const char *range_name,
                                     u32 offset_start, u32 offset_end,
                                     uint32_t xin_id);
void sde_dbg_set_sde_top_offset(u32 blk_off);
#else
/* inline dummy deklrasi Cleanup */
static inline int sde_dbg_init(struct dentry *debugfs_root,
                               struct device *dev,
                               struct sde_dbg_power_ctrl *power_ctrl)
{ return 0; }
static inline void sde_dbg_destroy(void) {}
static inline void sde_dbg_dump(bool queue_work, const char *name, ...) {}
static inline void sde_dbg_ctrl(const char *name, ...) {}
static inline void sde_dbg_init_dbg_buses(u32 hwversion) {}
static inline int sde_dbg_reg_register_base(const char *name,
                                            void __iomem *base, size_t size)
{ return 0; }
static inline void sde_dbg_reg_register_dump_range(const char *base_name,
                                                   const char *range_name,
                                                   u32 offset_start, u32 offset_end,
                                                   uint32_t xin_id) {}
static inline void sde_dbg_set_sde_top_offset(u32 blk_off) {}
#endif /* CONFIG_DEBUG_FS */

#endif /* SDE_DBG_H_ */

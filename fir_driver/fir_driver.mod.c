#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7096d4b2, "module_layout" },
	{ 0x65af5f12, "device_destroy" },
	{ 0x40a6f522, "__arm_ioremap" },
	{ 0xa748b5b4, "class_destroy" },
	{ 0x261e2294, "class_unregister" },
	{ 0xfb3e07f7, "device_create" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x223ed33a, "__class_create" },
	{ 0x808607a6, "__register_chrdev" },
	{ 0xf473ffaf, "down" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xac8f37b2, "outer_cache" },
	{ 0x4be7fb63, "up" },
	{ 0x27e1a049, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


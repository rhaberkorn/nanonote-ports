include $(TOPDIR)/rules.mk

PKG_NAME:=libnsfb
PKG_VERSION:=r10875
PKG_RELEASE:=1

PKG_SOURCE:=libnsfb-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=
PKG_MD5SUM:=9ca6a6dde2501ad77b0e3d1e88a199fc

PKG_BUILD_DIR=$(BUILD_DIR)/libnsfb-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libnsfb
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web
  DEPENDS:=+libsdl
  TITLE:=NetSurf Framebuffer Abstraction Library
  URL:=http://www.netsurf-browser.org/projects/libnsfb/
endef

define Package/libnsfb/description
LibNSFB is a framebuffer abstraction library, written in C.
It is currently in development for use with NetSurf and is intended
to be suitable for use in other projects too.

This package will build support for the Linux framebuffer and
SDL providers.
endef

EXTRA_CPPFLAGS += \
	-DKBDMOUSE='\"$(SOURCE)/files/kbdmouse.h\"'

MAKE_VARS := \
	TARGET=linux \
	PREFIX=/usr \
	COMPONENT_TYPE=lib-shared

define Build/Configure
endef

define Build/Compile
	$(CONFIGURE_VARS) \
	$(MAKE) -C $(PKG_BUILD_DIR) DESTDIR="$(PKG_INSTALL_DIR)" \
		$(MAKE_VARS) install
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/libnsfb.h $(1)/usr/include
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/libnsfb_{plot,plot_util,event,cursor}.h $(1)/usr/include

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libnsfb.so* $(1)/usr/lib

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libnsfb.pc $(1)/usr/lib/pkgconfig
endef

define Package/libnsfb/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libnsfb.so* $(1)/usr/lib
endef

$(eval $(call BuildPackage,libnsfb))

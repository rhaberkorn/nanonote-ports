include $(TOPDIR)/rules.mk

PKG_NAME:=libnsgif
PKG_VERSION:=r10879
PKG_RELEASE:=1

PKG_SOURCE:=libnsgif-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=
PKG_MD5SUM:=8a841624911aa233639d0e9df36f4dea

PKG_BUILD_DIR=$(BUILD_DIR)/libnsgif-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libnsgif
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web
  DEPENDS:=
  TITLE:=NetSurf GIF Decoding Library
  URL:=http://www.netsurf-browser.org/projects/libnsgif/
endef

define Package/libnsgif/description
Libnsgif is a decoding library for the GIF image file format, written in C.
It was developed as part of the NetSurf project and is available for use by
other software under the MIT licence.
endef

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
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/libnsgif.h $(1)/usr/include

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libnsgif.so* $(1)/usr/lib

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libnsgif.pc $(1)/usr/lib/pkgconfig
endef

define Package/libnsgif/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libnsgif.so* $(1)/usr/lib
endef

$(eval $(call BuildPackage,libnsgif))

include $(TOPDIR)/rules.mk

PKG_NAME:=libwapcaplet
PKG_VERSION:=r10879
PKG_RELEASE:=1

PKG_SOURCE:=libwapcaplet-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=
PKG_MD5SUM:=476f4d6b0f1be97c6496c34d13591869

PKG_BUILD_DIR=$(BUILD_DIR)/libwapcaplet-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libwapcaplet
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web
  DEPENDS:=
  TITLE:=String Internment Library (NetSurf)
  URL:=http://www.netsurf-browser.org/projects/libwapcaplet/
endef

define Package/libwapcaplet/description
LibWapcaplet is a string internment library, written in C.
It provides reference counted string interment and rapid string comparison functionality.
It was developed as part of the NetSurf project and is available for use by other software under the MIT licence.
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
	$(INSTALL_DIR) $(1)/usr/include/libwapcaplet
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/libwapcaplet/libwapcaplet.h $(1)/usr/include/libwapcaplet

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libwapcaplet.so* $(1)/usr/lib

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libwapcaplet.pc $(1)/usr/lib/pkgconfig
endef

define Package/libwapcaplet/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libwapcaplet.so* $(1)/usr/lib
endef

$(eval $(call BuildPackage,libwapcaplet))

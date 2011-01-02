include $(TOPDIR)/rules.mk

PKG_NAME:=libcss
PKG_VERSION:=r10879
PKG_RELEASE:=1

PKG_SOURCE:=libcss-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=
PKG_MD5SUM:=3cf4fbcf5e0fe2059dfc872a098b1dd7

PKG_BUILD_DIR=$(BUILD_DIR)/libcss-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libcss
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web
  DEPENDS:=+libparserutils +libwapcaplet
  TITLE:=CSS Parser and Selection Engine (NetSurf)
  URL:=http://www.netsurf-browser.org/projects/libcss/
endef

define Package/libcss/description
LibCSS is a CSS parser and selection engine, written in C.
It aims to parse the forward compatible CSS grammar.
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
	$(INSTALL_DIR) $(1)/usr/include/libcss
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/libcss/{computed,errors,fpmath,functypes,hint,libcss,properties,select,stylesheet,types}.h \
			$(1)/usr/include/libcss

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcss.so* $(1)/usr/lib

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libcss.pc $(1)/usr/lib/pkgconfig
endef

define Package/libcss/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcss.so* $(1)/usr/lib
endef

$(eval $(call BuildPackage,libcss))

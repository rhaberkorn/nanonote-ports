include $(TOPDIR)/rules.mk

PKG_NAME:=hubbub
PKG_VERSION:=r10879
PKG_RELEASE:=1

PKG_SOURCE:=hubbub-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=
PKG_MD5SUM:=0791d7b2ff8d37f601469c8b9e4ecad3

PKG_BUILD_DIR=$(BUILD_DIR)/hubbub-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/hubbub
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web
  DEPENDS:=+libiconv +libparserutils
  TITLE:=HTML5 Compliant Parsing Library (NetSurf)
  URL:=http://www.netsurf-browser.org/projects/hubbub/
endef

define Package/hubbub/description
Hubbub is an HTML5 compliant parsing library, written in C.
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
	$(INSTALL_DIR) $(1)/usr/include/hubbub
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/hubbub/{errors,functypes,hubbub,parser,tree,types}.h \
			$(1)/usr/include/hubbub

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libhubbub.so* $(1)/usr/lib

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libhubbub.pc $(1)/usr/lib/pkgconfig
endef

define Package/hubbub/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libhubbub.so* $(1)/usr/lib
endef

$(eval $(call BuildPackage,hubbub))

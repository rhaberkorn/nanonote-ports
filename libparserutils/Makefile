include $(TOPDIR)/rules.mk

PKG_NAME:=libparserutils
PKG_VERSION:=r10879
PKG_RELEASE:=1

PKG_SOURCE:=libparserutils-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=
PKG_MD5SUM:=9d7aa15559600dd68dd8c083b632a476

PKG_BUILD_DIR=$(BUILD_DIR)/libparserutils-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libparserutils
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web
  DEPENDS:=
  TITLE:=Efficient Parser Building Library (NetSurf)
  URL:=http://www.netsurf-browser.org/projects/libparserutils/
endef

define Package/libparserutils/description
LibParserUtils is a library for building efficient parsers, written in C.
It was developed as part of the NetSurf project and is available for use by
other software under the MIT licence.
endef

MAKE_VARS := \
	TARGET=linux \
	PREFIX=/usr \
	COMPONENT_TYPE=lib-shared

# EXTRA_CPPFLAGS += -DWITH_ICONV_FILTER

define Build/Configure
endef

define Build/Compile
	$(CONFIGURE_VARS) \
	$(MAKE) -C $(PKG_BUILD_DIR) DESTDIR="$(PKG_INSTALL_DIR)" \
		$(MAKE_VARS) install
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/parserutils \
		       $(1)/usr/include/parserutils/charset \
		       $(1)/usr/include/parserutils/input \
		       $(1)/usr/include/parserutils/utils
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/parserutils/{errors,functypes,parserutils,types}.h $(1)/usr/include/parserutils
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/parserutils/charset/{codec,mibenum,utf16,utf8}.h $(1)/usr/include/parserutils/charset
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/parserutils/input/inputstream.h $(1)/usr/include/parserutils/input
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/parserutils/utils/{buffer,stack,vector}.h $(1)/usr/include/parserutils/utils

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libparserutils.so* $(1)/usr/lib

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libparserutils.pc $(1)/usr/lib/pkgconfig
endef

define Package/libparserutils/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libparserutils.so* $(1)/usr/lib
endef

$(eval $(call BuildPackage,libparserutils))

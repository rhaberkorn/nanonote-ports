include $(TOPDIR)/rules.mk

PKG_NAME:=mpg123
PKG_VERSION:=1.12.5
PKG_RELEASE:=1

PKG_SOURCE:=mpg123-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/mpg123
PKG_MD5SUM:=01fa64533cade452c2b22a3ce14a2fcd

PKG_BUILD_DIR=$(BUILD_DIR)/mpg123-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/mpg123/Default
  SECTION:=multimedia
  CATEGORY:=Multimedia
  DEPENDS:=
  TITLE:=MPEG Player
  URL:=http://www.mpg123.de/
endef

define Package/mpg123/Default/description
MPEG I/II/III Audio Player
endef

define Package/mpg123
  $(call Package/mpg123/Default)
  DEPENDS+= +libmpg123 +libltdl
  TITLE+= (program)
endef

define Package/mpg123/description
$(call Package/mpg123/Default/description)
endef

define Package/libmpg123
  $(call Package/mpg123/Default)
  TITLE+= (library)
endef

define Package/libmpg123/description
$(call Package/mpg123/Default/description)
endef

CONFIGURE_ARGS += \
	--with-cpu=generic_nofpu \
	--with-audio=alsa

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) DESTDIR="$(PKG_INSTALL_DIR)" \
		install
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/mpg123.h $(1)/usr/include

	$(INSTALL_DIR) $(1)/usr/lib $(1)/usr/lib/mpg123
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libmpg123.so* $(1)/usr/lib

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libmpg123.pc $(1)/usr/lib/pkgconfig
endef

define Package/mpg123/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/mpg123 $(1)/usr/bin/

	$(INSTALL_DIR) $(1)/usr/lib/mpg123
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/mpg123/output_{alsa,dummy}.{la,so} $(1)/usr/lib/mpg123
endef

define Package/libmpg123/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libmpg123.so* $(1)/usr/lib
endef

$(eval $(call BuildPackage,mpg123))
$(eval $(call BuildPackage,libmpg123))

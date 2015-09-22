include $(TOPDIR)/rules.mk

PKG_NAME:=freeciv
PKG_VERSION:=2.2.3
PKG_RELEASE:=1

PKG_SOURCE:=freeciv-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/freeciv
PKG_MD5SUM:=b324e3c59f029d0566482f584181a4b2

PKG_BUILD_DIR=$(BUILD_DIR)/freeciv-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/freeciv
  SECTION:=games
  CATEGORY:=Games
  DEPENDS:=+libsdl +libsdl-image +libsdl-mixer +libfreetype \
           +libiconv-full +libncurses +libreadline
  TITLE:=Freeciv
  URL:=http://freeciv.wikia.com/
endef

define Package/freeciv/description
Open Source Civilization-like game (SDL client)
endef

# SDL depends on DirectFB but somehow the libs are not not found automatically
EXTRA_LDFLAGS += $(shell $(STAGING_DIR)/root-xburst/usr/bin/directfb-config --libs --prefix=$(STAGING_DIR)/usr)

EXTRA_CPPFLAGS += \
	-DALWAYS_ROOT -DSMALL_SCREEN \
	-DKBDMOUSE='\"$(shell pwd)/files/kbdmouse.h\"'

CONFIGURE_ARGS += \
	--enable-ipv6=no \
	--enable-client=sdl \
	--disable-nls \
	--with-sdl-prefix=$(STAGING_DIR)/usr \
	--with-libiconv-prefix=$(STAGING_DIR)/usr/lib/libiconv

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) DESTDIR="$(PKG_INSTALL_DIR)" \
		install
endef

define Package/freeciv/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/{civmanual,freeciv-server,freeciv-sdl} $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share
	$(CP) -r $(PKG_INSTALL_DIR)/usr/share/freeciv $(1)/usr/share/
endef

$(eval $(call BuildPackage,freeciv))

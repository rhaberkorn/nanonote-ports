include $(TOPDIR)/rules.mk

PKG_NAME:=gnash
PKG_VERSION:=0.8.8
PKG_RELEASE:=1

PKG_SOURCE:=gnash-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://ftp.gnu.org/pub/gnu/gnash/$(PKG_VERSION)/$(PKG_SOURCE)
PKG_MD5SUM:=aec414ee3bebb8901054818fae735214

PKG_BUILD_DIR=$(BUILD_DIR)/gnash-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/gnash
  SECTION:=multimedia
  CATEGORY:=Multimedia
  DEPENDS:=+libsdl +libffmpeg +cairo +libjpeg +libpng +giflib +libfreetype +fontconfig \
	   +boost-thread +boost-date_time +libcurl
  TITLE:=GNU Flash Player
  URL:=http://www.gnu.org/software/gnash/
endef

define Package/gnash/description
GNU Flash Player
endef

CONFIGURE_ARGS += \
	--enable-renderer=cairo \
	--enable-media=ffmpeg \
	--enable-gui=sdl \
	--disable-plugins \
	--with-boost-lib="$(STAGING_DIR)/usr/lib" \
	--with-ffmpeg-lib="$(STAGING_DIR)/usr/lib" \
	--with-fontconfig-lib="$(STAGING_DIR)/usr/lib" \
	--with-freetype-incl="$(STAGING_DIR)/usr/include/freetype2" \
	--with-freetype-lib="$(STAGING_DIR)/usr/lib" \
	--with-cairo-incl="$(STAGING_DIR)/usr/include/cairo" \
	--with-curl-lib="$(STAGING_DIR)/usr/lib"

EXTRA_CPPFLAGS += $(shell $(STAGING_DIR)/host/bin/sdl-config --cflags --prefix=$(STAGING_DIR)/usr)
EXTRA_LDFLAGS += $(shell $(STAGING_DIR)/host/bin/sdl-config --libs --prefix=$(STAGING_DIR)/usr)

EXTRA_CPPFLAGS += $(shell $(STAGING_DIR)/usr/bin/curl-config --cflags)
EXTRA_LDFLAGS += $(shell $(STAGING_DIR)/usr/bin/curl-config --libs)

# cairo dependencies (not returned by pkg-config!?):
EXTRA_LDFLAGS += -lpixman-1 -lfreetype -lfontconfig -lexpat -ldirectfb -lfusion -ldirect -lpng12 -lz

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) DESTDIR="$(PKG_INSTALL_DIR)" \
		install
endef

define Package/gnash/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/{gnash,sdl-gnash} $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/lib/gnash
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/gnash/*.so* $(1)/usr/lib/gnash/
	$(INSTALL_DIR) $(1)/etc
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/etc/gnashrc $(1)/etc/
endef

$(eval $(call BuildPackage,gnash))

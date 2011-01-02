include $(TOPDIR)/rules.mk

PKG_NAME:=mplayer
PKG_VERSION:=1.0rc2-20090218
PKG_RELEASE:=1

PKG_SOURCE:=mplayer-export-snapshot.tar.bz2
PKG_SOURCE_URL:=ftp://ftp.ingenic.cn/3sw/01linux/05apps/mplayer/$(PKG_SOURCE)
PKG_MD5SUM:=fbeaf3af7e3d5de3f35d94dc4148b8d6

#PKG_BUILD_DIR=$(BUILD_DIR)/mplayer-$(PKG_VERSION)
PKG_BUILD_DIR=$(BUILD_DIR)/mplayer-export-2010-09-26

include $(INCLUDE_DIR)/package.mk

define Package/mplayer
  SECTION:=multimedia
  CATEGORY:=Multimedia
  DEPENDS:=
  TITLE:=Movie Player
  URL:=http://www.mplayerhq.hu/
endef

define Package/mplayer/description
Cross-platform movie player.
This build is using an optimized source package by Ingenic: http://www.ingenic.cn/eng/productServ/kfyd/Linux/pfCustomPage.aspx
endef

CONFIGURE_ARGS = \
	--target=mips-linux \
        --prefix=$(CONFIGURE_PREFIX) \
        --bindir=$(CONFIGURE_PREFIX)/bin \
        --mandir=$(CONFIGURE_PREFIX)/man \
        $(DISABLE_LARGEFILE)

# mplayer-specific:
CONFIGURE_ARGS += \
	--extra-cflags="-O3" \
	--enable-cross-compile \
	--host-cc=gcc \
	--disable-mencoder \
	--disable-unrarexec \
	--disable-x11
#	--disable-sdl
#	--disable-fbdev

EXTRA_LDFLAGS += $(shell $(STAGING_DIR)/root-xburst/usr/bin/directfb-config --libs --prefix=$(STAGING_DIR)/usr)
EXTRA_CPPFLAGS += $(shell $(STAGING_DIR)/root-xburst/usr/bin/directfb-config --cflags --prefix=$(STAGING_DIR)/usr)

EXTRA_CFLAGS += -mplt

define Package/mplayer/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mplayer $(1)/usr/bin/
endef

$(eval $(call BuildPackage,mplayer))

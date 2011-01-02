include $(TOPDIR)/rules.mk

PKG_NAME:=netsurf
PKG_VERSION:=r10879
PKG_RELEASE:=1

PKG_SOURCE:=netsurf-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=
PKG_MD5SUM:=6edade4588c6183376d9bb4f1b172385

PKG_BUILD_DIR=$(BUILD_DIR)/netsurf-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/netsurf
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web
  DEPENDS:=+libparserutils +libwapcaplet +hubbub +libcss +libnsgif +libnsfb \
	   +libjpeg +libpng +libfreetype +libcurl +libxml2 +libiconv
  TITLE:=NetSurf Web Browser (Framebuffer)
  URL:=http://www.netsurf-browser.org/
endef

define Package/netsurf/description
NetSurf is a free, open source web browser.
It is written in C and released under the GNU Public Licence version 2.
NetSurf has its own layout and rendering engine entirely written from scratch.
It is small and capable of handling many of the web standards in use today.
endef

# SDL depends on DirectFB but somehow the libs are not not found automatically
EXTRA_LDFLAGS += $(shell $(STAGING_DIR)/root-xburst/usr/bin/directfb-config --libs --prefix=$(STAGING_DIR)/usr)

EXTRA_CPPFLAGS += -I$(STAGING_DIR)/usr/lib/libiconv/include
EXTRA_LDFLAGS += -L$(STAGING_DIR)/usr/lib/libiconv/lib -liconv

# for libcurl
# EXTRA_LDFLAGS += -lgnutls

MAKE_VARS := \
	TARGET=framebuffer \
	PREFIX=/usr

define Build/Configure
	$(CP) $(SOURCE)/files/Makefile.config $(PKG_BUILD_DIR)
endef

define Build/Compile
	$(CONFIGURE_VARS) \
	$(MAKE) -C $(PKG_BUILD_DIR) DESTDIR="$(PKG_INSTALL_DIR)" \
		$(MAKE_VARS) install
endef

define Package/netsurf/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/netsurf $(1)/usr/bin/

	$(INSTALL_DIR) $(1)/usr/share
	$(CP) -r $(PKG_INSTALL_DIR)/usr/share/netsurf $(1)/usr/share

	# provide at least one font, so netsurf will still start up even when no fonts are installed
	$(INSTALL_DATA) $(SOURCE)/files/DejaVuSans.ttf $(1)/usr/share/netsurf/sans_serif.ttf
endef

$(eval $(call BuildPackage,netsurf))

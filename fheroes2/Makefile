include $(TOPDIR)/rules.mk

PKG_NAME:=fheroes2
PKG_VERSION:=r1954
PKG_RELEASE:=1

PKG_SOURCE:=fheroes2-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/fheroes2
PKG_MD5SUM:=612a4fe2d18b748bc4367ffddff734b5

PKG_BUILD_DIR=$(BUILD_DIR)/fheroes2-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/fheroes2
  SECTION:=games
  CATEGORY:=Games
  DEPENDS:=+libsdl +libsdl-image +libpng +zlib
  TITLE:=Free Heroes 2 Engine
  URL:=http://sourceforge.net/projects/fheroes2/
  MENU:=1
endef

define Package/fheroes2/config
  menu "Configuration"
    depends on PACKAGE_fheroes2

    config FHEROES2_WITH_UNICODE
      prompt "Unicode, internationalization and TTF support"
      bool
      select PACKAGE_libsdl-ttf
      select PACKAGE_libintl

    config FHEROES2_WITH_MUSIC
      prompt "MIDI/OGG Music support"
      bool
      select PACKAGE_libsdl-mixer
  endmenu
endef

define Package/fheroes2/description
Free implementation of Heroes of the Might and Magic II engine.

Note that SDL-mixer has built-in Timidity MIDI support (that also
requires GUS patches of course) but apparently won't work with
the HOMM2 game data since it uses XMI. So either compile without
music support or get/render OGG versions of the music and place them
under /usr/share/fheroes2/files/music and adapt fheroes2.cfg
accordingly. Also make sure SDL-mixer is compiled with OGG music
support. fheroes2 also supports external programs to play music
when SDL-mixer support is disabled, so there may be other
possibilities...
endef

MAKE_VARS := \
	WITHOUT_AUDIOCD=y \
	WITHOUT_NETWORK=y \
	WITHOUT_EDITOR=y

ifeq ($(CONFIG_FHEROES2_WITH_UNICODE),)

MAKE_VARS += WITHOUT_UNICODE=y

else

EXTRA_CPPFLAGS += -I$(STAGING_DIR)/usr/lib/libintl/include
EXTRA_LDFLAGS += -L$(STAGING_DIR)/usr/lib/libintl/lib -lintl

# SDL_ttf depends on libfreetype but somehow the lib cannot be found automatically
EXTRA_LDFLAGS += $(shell $(STAGING_DIR)/host/bin/freetype-config --libs)

endif

ifeq ($(CONFIG_FHEROES2_WITH_MUSIC),)
MAKE_VARS += WITHOUT_MIXER=y
endif

# SDL depends on DirectFB but somehow the libs are not not found automatically
EXTRA_LDFLAGS += $(shell $(STAGING_DIR)/root-xburst/usr/bin/directfb-config --libs --prefix=$(STAGING_DIR)/usr)

EXTRA_CPPFLAGS += \
	-D'CONFIGURE_FHEROES2_DATA=\"/usr/share/fheroes2\"' \
	-DWITH_KEYMAPPING -DWITHOUT_MOUSE

define Build/Configure
endef

define Build/Compile
	$(CONFIGURE_VARS) \
	$(MAKE) -C $(PKG_BUILD_DIR) $(MAKE_VARS)
endef

define Package/fheroes2/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fheroes2 $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share/fheroes2
	$(INSTALL_DATA) $(SOURCE)/files/fheroes2.cfg $(1)/usr/share/fheroes2/
	$(INSTALL_DIR) $(1)/usr/share/fheroes2/data
	$(INSTALL_DIR) $(1)/usr/share/fheroes2/maps
	$(CP) -r $(PKG_BUILD_DIR)/files $(1)/usr/share/fheroes2/
endef

$(eval $(call BuildPackage,fheroes2))

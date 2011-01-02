include $(TOPDIR)/rules.mk

PKG_NAME:=videoteco
PKG_VERSION:=r1.4
PKG_RELEASE:=1

PKG_SOURCE:=videoteco-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/videoteco
PKG_MD5SUM:=224d50c0805a392026477d3a3f256158

PKG_BUILD_DIR=$(BUILD_DIR)/videoteco-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/VideoTECO
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libncurses
  TITLE:=Screen based TECO editor
  URL:=http://sourceforge.net/projects/videoteco/
  SUBMENU:=Editors
endef

define Package/VideoTECO/description
Advanced screen based version of the TECO editor.
endef

define Package/VideoTECO/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/teco $(1)/usr/bin/
endef

$(eval $(call BuildPackage,VideoTECO))

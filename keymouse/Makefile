include $(TOPDIR)/rules.mk

PKG_NAME:=keymouse
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_SOURCE:=keymouse-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=
PKG_MD5SUM:=931d3125584f5abf1d8323bf1fec95e0

PKG_BUILD_DIR=$(BUILD_DIR)/keymouse-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/keymouse
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=
  TITLE:=Keyboard mouse emulator
  URL:=http://keymouse.berlios.de/
endef

define Package/keymouse/description
Keyboard mouse emulator
endef

define Package/keymouse/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/keymouse $(1)/usr/bin/
endef

$(eval $(call BuildPackage,keymouse))

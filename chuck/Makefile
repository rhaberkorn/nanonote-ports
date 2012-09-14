include $(TOPDIR)/rules.mk

PKG_NAME:=chuck
PKG_VERSION:=1.3.1.1
PKG_RELEASE:=1

PKG_SOURCE:=chuck-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=http://chuck.cs.princeton.edu/release/files
PKG_MD5SUM:=fb8e0c9f06a51dbec168982497bd2b07

PKG_BUILD_DIR=$(BUILD_DIR)/chuck-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/chuck
  SECTION:=lang
  CATEGORY:=Languages
  DEPENDS:= +alsa-lib +libsndfile +libpthread
  TITLE:=ChucK Programming Language
  URL:=http://http://chuck.cs.princeton.edu/
endef

define Package/chuck/description
ChucK Programming Language
endef

define Build/Configure
endef

define Build/Compile
	$(CONFIGURE_VARS) \
	$(MAKE) -C $(PKG_BUILD_DIR)/src \
		linux-alsa
endef

define Package/chuck/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/chuck $(1)/usr/bin/
endef

$(eval $(call BuildPackage,chuck))

include $(TOPDIR)/rules.mk

PKG_NAME:=sciteco
PKG_VERSION:=0.6.4-git
PKG_RELEASE:=2
PKG_REV:=c3f7aa7252ad9adb51cef1e35f566883ef953aad

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.gz
PKG_SOURCE_URL:=https://github.com/rhaberkorn/sciteco.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_BUILD_DIR=$(BUILD_DIR)/sciteco-$(PKG_VERSION)

#PKG_BUILD_DEPENDS:=$(PKG_NAME)/host
#HOST_BUILD_DEPENDS:=libncurses/host glib2/host

include $(INCLUDE_DIR)/package.mk
#include $(INCLUDE_DIR)/host-build.mk

define Package/sciteco
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libncurses +glib2 +libstdcpp +libiconv-full
  TITLE:=Advanced TECO dialect and interactive screen editor based on Scintilla
  URL:=http://sciteco.sf.net/
  SUBMENU:=Editors
endef

define Package/sciteco/description
Advanced TECO dialect and interactive screen editor based on Scintilla
endef

CONFIGURE_ARGS += --with-interface=ncurses \
                  --disable-bootstrap

define Build/Configure
	(cd $(PKG_BUILD_DIR) && autoreconf -i)
	$(call Build/Configure/Default)
endef

# FIXME: Why is this template required?
define Build/Compile
	$(call Build/Install/Default)
endef

# A host-build of SciTECO is required to bootstrap
# its build process since of course we cannot
# rely on SciTECO's built-in bootstrapping mechanism
# which is not designed to work with cross-builds.
#define Host/Configure
#	(cd $(PKG_BUILD_DIR) && autoreconf -i)
#	$(call Host/Configure/Default)
#endef
#
#define Host/Install
#	$(call Host/Install/Default)
#endef

define Package/sciteco/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/sciteco $(1)/usr/bin/

	$(INSTALL_DIR) $(1)/usr/share/sciteco
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/share/sciteco/sample.teco_ini $(1)/usr/share/sciteco
	cp -r $(PKG_INSTALL_DIR)/usr/share/sciteco/lib $(1)/usr/share/sciteco
endef

#$(eval $(call HostBuild))
$(eval $(call BuildPackage,sciteco))

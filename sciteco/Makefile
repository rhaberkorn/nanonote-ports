include $(TOPDIR)/rules.mk

PKG_NAME:=sciteco
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_SOURCE:=sciteco-$(PKG_VERSION).tar.gz
PKG_MD5SUM:=612f02da4a521059f75835fe89508461

PKG_BUILD_DIR=$(BUILD_DIR)/sciteco-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/SciTECO
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libncurses +glib2 +libstdcpp
  TITLE:=Scintilla based TECO editor
  URL:=https://github.com/rhaberkorn/sciteco
  SUBMENU:=Editors
endef

define Package/SciTECO/description
Advanced screen based version of the TECO editor.
NOTE: Currently, SciTECO has to be installed on the
host platform.
endef

CONFIGURE_ARGS += --with-scintilla=scintilla \
		  --with-interface=ncurses \
		  --disable-bootstrap

define Build/Prepare
	$(PKG_UNPACK)
	(cd $(PKG_BUILD_DIR); \
	$(HOST_TAR) xzf $(DL_DIR)/scintilla324.tgz; \
	unzip -d scintilla $(DL_DIR)/scinterm_1.1.zip; \
	mv scintilla/scinterm_1.1 scintilla/scinterm; \
	patch -p0 <patches/scintilla-teco-control-codes.patch; \
	)
	$(call Build/Patch)
endef

define Build/Configure
	$(MAKE_VARS) \
	$(MAKE) -C $(PKG_BUILD_DIR)/scintilla/scinterm \
		$(MAKE_FLAGS)
	$(call Build/Configure/Default)
endef

define Build/Compile
	$(call Build/Install/Default)
endef

define Package/SciTECO/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/sciteco $(1)/usr/bin/

	$(INSTALL_DIR) $(1)/usr/share/sciteco
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/share/sciteco/teco.ini $(1)/usr/share/sciteco
endef

$(eval $(call BuildPackage,SciTECO))

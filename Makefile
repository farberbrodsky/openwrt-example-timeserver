include $(TOPDIR)/rules.mk

PKG_NAME:=timeserver
PKG_VERSION:=1.33.7
PKG_RELEASE:=1
PKG_MAINTAINER:=Michael Farber Brodsky <misha@farberbrodsky.com>

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/timeserver
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=1337
endef

define Package/timeserver/description
	very very useful
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/timeserver/install
	$(CP) ./files/* $(1)/

	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/timeserver $(1)/usr/bin/
endef

$(eval $(call BuildPackage,timeserver))

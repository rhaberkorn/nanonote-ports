# Ben NanoNote Ports

This is an [OpenWrt](http://openwrt.org/) feed with ports for the [Ben NanoNote](http://en.qi-hardware.com/wiki/Ben_NanoNote) pocket computer (i.e. to be used with its official OpenWrt fork).
Most packages should have lengthy descriptions.

## Issues

* The [Gnash](http://www.gnu.org/software/gnash/) port _compiles_ but still has _basic_ runtime problems. The NanoNote is probably too slow for it anyways.
* The [KeyMouse](http://keymouse.berlios.de/) port is largely untested. I don't really need it anyways. It's much easier to simply patch keyboard-mouse emulation into the application.
* Most packages need source archives which are not publicly available (latest SVN revisions) as downloads. I should either provide these archives or adapt the packages to export SVN repositories automatically. Or fork the projects...
* I also fixed/extended some packages from the OpenWrt/nanonote feeds. I should fork them to have this public.
* Most of the patches should go mainstream, shouldn't they? Well except for the kind of hairy keyboard-mouse support in the [NetSurf](http://www.netsurf-browser.org/) port.

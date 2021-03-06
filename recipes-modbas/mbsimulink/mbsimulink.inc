SUMMARY = "MODBAS RT-Linux Simulink"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://COPYING;md5=05b4ac8839393b3870e9e8bb6fec8aa8"

SRC_URI = "file://libgtrt-1.0.tgz \
           file://COPYING \
          "

S = "${WORKDIR}/libgtrt-1.0"

DEPENDS = "glib-2.0 pkgconfig apache2"
#PACKAGES = "${PN} ${PN}-dbg"

inherit autotools

do_install() {
    autotools_do_install
    install -d ${D}/home/root/bin
    install -m 0755 ${S}/debian/bin/*.sh ${D}/home/root/bin
    install -d ${D}/usr/share/apache2/htdocs/gtrtmonitor
    install -m 0644 ${S}/debian/var/www/gtrtmonitor/* ${D}/usr/share/apache2/htdocs/gtrtmonitor
}

FILES_${PN} += "/home/root/bin/*"
FILES_${PN} += "/usr/share/apache2/htdocs/gtrtmonitor/*"

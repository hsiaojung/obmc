
SUMMARY = "Calcautor"
SECTION = "apps"
LICENSE = "CLOSED"

APP_NAME = "calculator"
localdir = "/usr/local"
bindir = "${localdir}/bin"

TARGET_CC_ARCH += "${LDFLAGS}"


DEPENDS += "systemd"
DEPENDS += "sdbusplus ${PYTHON_PN}-sdbus++-native"
DEPENDS += "sdeventplus"
DEPENDS += "phosphor-dbus-interfaces"
DEPENDS += "${PYTHON_PN}-inflection-native"
DEPENDS += "${PYTHON_PN}-mako-native"
DEPENDS += "${PYTHON_PN}-pyyaml-native"
DEPENDS += "phosphor-logging"
DEPENDS += "libnl"
DEPENDS += "stdplus"

PV = "1.0+git"
PR = "r1"


SRC_URI = "file://calculator.tar.gz"

S = "${WORKDIR}"
SYSTEMD_PACKAGES = "${PN}"

inherit meson
inherit systemd
inherit pkgconfig



FILES_${PN}-dev = ""
FILES_${PN} = "${bindir}/*"



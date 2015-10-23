PRODUCT_COPY_FILES += \
	frameworks/native/data/etc/android.hardware.touchscreen.multitouch.distinct.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.distinct.xml \
	frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
	device/hisi/k3v2oem1/camera/tornado/Mate/TornadoI.ini:system/etc/camera/tornado/TornadoI.ini                                                                \
	device/hisi/k3v2oem1/camera/davinci/ov8830_mate/imgproc.xml:system/etc/camera/davinci/ov8830/imgproc.xml

PRODUCT_AAPT_PREF_CONFIG := xhdpi
OVERLAY_DEVICE := mate
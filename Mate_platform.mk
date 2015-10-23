PRODUCT_NAME=Mate
PRODUCT_BRAND=Huawei
#NOTICE! Do not config PRODUCT_DEVICE
export USE_LCD_CMI_OTM1282B := true
export USE_NFC_DEVICE := true
export USE_NFC_DEVICE_U9900 := true
export USE_MULTITASK_FLOAT := true

#add MATE camera specifical settings
export USE_MATE_CAMERA_SETTINGS := true

PRODUCT_PACKAGES +=HwFloatTasks
PRODUCT_PACKAGES +=android.overlay.mate

PRODUCT_LCD_DISPLAY=HD
DOLBY_AUDIOEFFECT_DM:=true

ifeq ($(TARGET_VERSION_MODE),normal)
PRODUCT_PACKAGES += check_root
endif

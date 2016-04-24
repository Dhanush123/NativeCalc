LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL
_MODULE    := cplusplus11
LOCAL_SRC_FILES := cplusplus11.cpp
# Generate a module that links to /system/lib/liblog.so at load time to enable logging
LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)